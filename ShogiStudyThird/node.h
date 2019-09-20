#pragma once
#include "move.h"
#include <shared_mutex>
#include <atomic>
#include <vector>

using s_mutex = std::shared_mutex;
using s_lock = std::shared_lock<std::shared_mutex>;
using p_lock = std::lock_guard<std::shared_mutex>;

class SearchNode {
public:
	enum class State : std::int8_t {
		NotExpanded, LimitExpanded, LimitExpandedTerminal, ExpandedInQSearch, Expanded, CheckMate, Declare, Repetitoin,
		NE = NotExpanded, LE = LimitExpanded, LT = LimitExpandedTerminal, EQ = ExpandedInQSearch,
		EX = Expanded, CM = CheckMate, DC=Declare, RP = Repetitoin
	};
private:
	static double repEval;
	static double T_depth;
	static double T_eval;
public:
	static double setRepEval(const double e) { repEval = e; }
	static double setT(const double T_d, const double T_e) { T_depth = T_d; T_eval = T_e; }
public:
	SearchNode(const Move& move);
	SearchNode(const SearchNode&) = delete;
	SearchNode(SearchNode&&) = delete;

	SearchNode* addChild(const Move& move);

	SearchNode* choiceNode(const double pip, const double T_choice)const;
	void updateNode();
	void updateMateNode();
	void setEvaluation(const double evaluation) { eval = evaluation; }
	double getChoiceEvaluation()const { return state == State::RP ? repEval : eval.load(); }

	void setMate();
	void setUchiFuMate();
	void setDeclare();

	bool isNotExpanded()const { return state == State::NE; }
	bool isQSTerminal()const { return state == State::LT; }
	bool isLeaf()const { return state == State::NE || state == State::LE || state == State::LT || state == State::EQ; }

	std::vector<SearchNode*> children;
	Move move;
	std::atomic<State> state;
	std::atomic<double> eval;
	std::atomic<double> mass;
};

double SearchNode::repEval = 0;