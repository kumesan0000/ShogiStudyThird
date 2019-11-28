﻿#include "stdafx.h"
#include "node.h"
#include <cmath>
#include <algorithm>
#include <limits>

double SearchNode::mateMass = 1;
double SearchNode::mateScore = 34000.0;
double SearchNode::mateScoreBound = 30000.0;
double SearchNode::mateOneScore = 20.0;
double SearchNode::repetitionScore = -100;
double SearchNode::Tc_const = 60;
double SearchNode::Tc_mp = 30;
double SearchNode::Tc_mc = 20;
bool SearchNode::Tc_mc_expectable_variance = false;
double SearchNode::T_eval = 40;
double SearchNode::T_depth = 90;
double SearchNode::MassMax_QS = 8;

SearchNode::SearchNode(const Move& move)
	:move(move), expanded(false)
{
	state = State::N;
	eval = 0;
	mass = 0;
}

size_t SearchNode::deleteTree() {
	if (children.empty()) {
		return 0;
	}
	std::vector<SearchNode*> nodes = children;
	children.clear();
	size_t delnum = nodes.size();
	while (!nodes.empty()) {
		SearchNode* node = nodes.back();
		nodes.pop_back();
		delnum += node->children.size();
		nodes.insert(nodes.end(), node->children.begin(), node->children.end());
		delete node;
	}
	state = State::N;
	return delnum;
}

SearchNode* SearchNode::addChild(const Move& move) {
	SearchNode* child = new SearchNode(move);
	children.push_back(child);
	return child;
}

void SearchNode::setMateVariation(const double childmin) {
	if (childmin > 0) {
		eval = -childmin + mateOneScore;
		const double moves = (mateScore - childmin) / mateOneScore;
		mass = mateMass + moves;
	}
	else {
		eval = -childmin - mateOneScore;
		const double moves = (mateScore + childmin) / mateOneScore;
		mass = mateMass + moves;
	}
}

void SearchNode::setMate() {
	auto const from = move.from();
	if (from == koma::Position::m_sFu || from == koma::Position::m_gFu) {
		eval = mateScore;
	}
	else {
		eval = -mateScore;
	}
	mass = mateMass;
	state = State::T;
}

void SearchNode::setDeclare() {
	eval = mateScore;
	mass = mateMass;
	state = State::T;
}

void SearchNode::setRepetition(const double m) {
	eval = repetitionScore;
	mass = m;
	state = State::T;
}

void SearchNode::setRepetitiveCheck(const double m) {
	eval = mateScore;
	mass = m;
	state = State::T;
}

double SearchNode::getT_c() const {
	if (Tc_mp != 0) {
		if (Tc_mc != 0) {
			return Tc_const + Tc_mp * (mass - 1) * Tc_mc * getTcMcVariance();
		}
		else {
			return Tc_const + Tc_mp * (mass - 1);
		}
	}
	else {
		if (Tc_mc != 0) {
			return Tc_const + Tc_mc * getTcMcVariance();
		}
		else {
			return Tc_const;
		}
	}
}

double SearchNode::getTcMcVariance()const {
	if (setTcmc_expectable_flag) {
		std::vector<double> cmasses;
		double mean = 0;
		for (const auto& child : children) {
			const double m = child->mass;
			cmasses.push_back(m);
			mean += m;
		}
		mean /= cmasses.size();
		double variance = 0;
		for (const auto& m : cmasses) {
			variance += (m - mean) * (m - mean);
		}
		return std::sqrt(variance / cmasses.size());
	}
	else {
		std::vector<std::pair<double,double>> ems;
		double min = std::numeric_limits<double>::max();
		for (const auto& child : children) {
			const double e = child->eval;
			ems.push_back(std::make_pair(e, child->mass.load()));
			if (e < min) {
				min = e;
			}
		}
		double Z = 0;
		for (auto& e : ems) {
			const double exp = std::exp(-(e.first - min) / T_depth);
			Z += exp;
			e.first = exp;
		}
		const double mean = mass - 1;
		double variance = 0;
		for (const auto& e : ems) {
			variance += (e.second - mean) * (e.second - mean) * e.first;
		}
		return std::sqrt(variance / Z);
	}
}