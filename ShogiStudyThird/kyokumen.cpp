﻿#include "stdafx.h"
#include "kyokumen.h"
#include "usi.h"
#include "bb_kiki.h"

using namespace koma;

const std::array<std::uint8_t, 95> prime_bammen = {
	static_cast<std::uint8_t>(Koma::g_Kyou),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::g_Fu),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::s_Fu),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::s_Kyou),
	static_cast<std::uint8_t>(Koma::g_Kei),static_cast<std::uint8_t>(Koma::g_Kaku),static_cast<std::uint8_t>(Koma::g_Fu),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::s_Fu),static_cast<std::uint8_t>(Koma::s_Hi),static_cast<std::uint8_t>(Koma::s_Kei),
	static_cast<std::uint8_t>(Koma::g_Gin),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::g_Fu),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::s_Fu),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::s_Gin),
	static_cast<std::uint8_t>(Koma::g_Kin),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::g_Fu),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::s_Fu),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::s_Kin),
	static_cast<std::uint8_t>(Koma::g_Ou),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::g_Fu),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::s_Fu),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::s_Ou),
	static_cast<std::uint8_t>(Koma::g_Kin),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::g_Fu),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::s_Fu),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::s_Kin),
	static_cast<std::uint8_t>(Koma::g_Gin),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::g_Fu),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::s_Fu),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::s_Gin),
	static_cast<std::uint8_t>(Koma::g_Kei),static_cast<std::uint8_t>(Koma::g_Hi),static_cast<std::uint8_t>(Koma::g_Fu),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::s_Fu),static_cast<std::uint8_t>(Koma::s_Kaku),static_cast<std::uint8_t>(Koma::s_Kei),
	static_cast<std::uint8_t>(Koma::g_Kyou),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::g_Fu),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::s_Fu),static_cast<std::uint8_t>(Koma::None),static_cast<std::uint8_t>(Koma::s_Kyou),
	0u,0u,0u,0u,0u,0u,0u,
	0u,0u,0u,0u,0u,0u,0u
};

const std::array<Koma, 11> sStepKomas = { Koma::s_Fu, Koma::s_Kei, Koma::s_Gin, Koma::s_Kin, Koma::s_Ou, Koma::s_nFu, Koma::s_nKyou, Koma::s_nKei, Koma::s_nGin, Koma::s_nKaku, Koma::s_nHi };
const std::array<Koma, 5> sDashKomas = { Koma::s_Kyou, Koma::s_Kaku, Koma::s_Hi, Koma::s_nKaku, Koma::s_nHi };
const std::array<Koma, 11> gStepKomas = { Koma::g_Fu, Koma::g_Kei, Koma::g_Gin, Koma::g_Kin, Koma::g_Ou, Koma::g_nFu, Koma::g_nKyou, Koma::g_nKei, Koma::g_nGin, Koma::g_nKaku, Koma::g_nHi };
const std::array<Koma, 5> gDashKomas = { Koma::g_Kyou, Koma::g_Kaku, Koma::g_Hi, Koma::g_nKaku, Koma::g_nHi };

Kyokumen::Kyokumen():
	Kyokumen(prime_bammen,true){}

Kyokumen::Kyokumen(const std::array<koma::Koma, 81>& ban, const std::array<unsigned, 7>& smochi, const std::array<unsigned, 7>& gmochi,bool teban)
	: bammen({0}), isSente(teban)
{
	for (size_t i = 0; i < ban.size(); i++) {
		bammen[i] = static_cast<uint8_t>(ban[i]);
	}
	for (size_t i = 0; i < smochi.size(); i++) {
		bammen[i + 81ull] = static_cast<uint8_t>(smochi[i]);
	}
	for (size_t i = 0; i < gmochi.size(); i++) {
		bammen[i + 88ull] = static_cast<uint8_t>(gmochi[i]);
	}
	reflectBitboard();
}

Kyokumen::Kyokumen(const std::array < std::uint8_t, 95 >& bammen, bool teban)
	:bammen(bammen), isSente(teban)
{
	reflectBitboard();
}

Kyokumen::Kyokumen(std::array < std::uint8_t, 95 > && bammen, bool teban)
	:bammen(std::move(bammen)),isSente(teban)
{
	reflectBitboard();
}

Kyokumen::Kyokumen(const std::vector<std::string>& tokens) {
	if (tokens[1] == "startpos") {
		bammen = prime_bammen;
		isSente = true;
	}
	else {
		assert(tokens[1] == "sfen");
		//盤面
		std::vector<std::string> usiban(usi::split(tokens[2], '/'));
		int dan = 0;
		for (auto& line : usiban) {
			int suji = 8;
			for (auto c = line.begin(), end = line.end(); c != end; ++c) {
				if ('0' < *c&&* c <= '9') {
					for (int num = *c - '0'; num > 0; --num) {
						setKoma(XYtoPos(suji, dan), Koma::None);
						--suji;
					}
				}
				else {
					if (*c == '+') {
						++c;
						setKoma(XYtoPos(suji, dan), promote(usi::usiToKoma(*c)));
					}
					else {
						setKoma(XYtoPos(suji, dan), usi::usiToKoma(*c));
					}
					--suji;
				}
			}
			++dan;
		}
		//手番
		isSente = (tokens[3] == "b");
		//持ち駒
		for (size_t t = static_cast<size_t>(Position::SQm_Min); t <= static_cast<size_t>(Position::SQm_Max); t++) {
			bammen[t] = 0;
		}
		auto mStr = tokens[4];
		if (mStr.front() != '-') {
			for (auto c = mStr.begin(), end = mStr.end(); c != end; ++c) {
				unsigned num = 1;
				if (*c == '1') {
					c++;
					num = *c - '0' + 10u;
					c++;
				}
				else if ('1' < *c && *c <= '9') {
					num = *c - '0';
					c++;
				}
				bammen[MochiToMpos(usi::usiToMochi(*c), std::isupper(*c))] = num;
			}
		}
	}
	reflectBitboard();
}

std::string Kyokumen::toSfen()const {
	std::string usi = "sfen ";
	//sq
	for (int y = 0; y < 9; y++) {
		int nonecount = 0;
		for (int x = 8; x >= 0; x--) {
			if (bammen[x * 9ull + y] != static_cast<std::uint8_t>(Koma::None)) {
				if (nonecount != 0) {
					usi += std::to_string(nonecount);
					nonecount = 0;
				}
				usi += usi::komaToUsi(getKoma(static_cast<Position>(x * 9 + y)));
			}
			else {
				nonecount++;
			}
		}
		if (nonecount != 0) {
			usi += std::to_string(nonecount);
		}
		if (y < 8)usi += '/';
	}
	usi += ' ';
	usi += usi::tebanToUsi(teban());
	usi += ' ';
	//mochi
	bool wrote_mochi = false;
	for (auto mpos : { Position::m_sHi,Position::m_sKaku,Position::m_sKin,
		Position::m_sGin,Position::m_sKei,Position::m_sKyou,Position::m_sFu,
		Position::m_gHi,Position::m_gKaku,Position::m_gKin,
		Position::m_gGin,Position::m_gKei,Position::m_gKyou,Position::m_gFu }) 
	{
		auto num = bammen[mpos];
		if (num > 0) {
			if (num > 1) {
				usi += std::to_string(num);
			}
			usi += usi::mposToUsi(mpos);
			wrote_mochi = true;
		}
	}
	if (!wrote_mochi) {
		usi += '-';
	}
	usi += " 1 ";
	return usi;
}

koma::Position Kyokumen::proceed(const Move move) {
	const unsigned from = move.from(), to = move.to();
	const bool prom = move.promote();
	Position captured = Position::SQm_Num;
	//sente,gote,allBB
	if (teban()) { //先手
		if (koma::isInside(from)) { //元位置が盤内ならそのビットを消す
			senteKomaBB.reset(from);
		}
		senteKomaBB.set(to); //行き先のビットを立てる
		goteKomaBB.reset(to); //行き先の敵盤ビットを下げる
	}
	else { //後手
		if (koma::isInside(from)) {
			goteKomaBB.reset(from);
		}
		goteKomaBB.set(to);
		senteKomaBB.reset(to);
	} //全体
	allKomaBB = senteKomaBB | goteKomaBB;

	//eachKomaBB,bammen
	if (koma::isInside(from)) {//盤上の駒を動かす場合
		const Koma fromKoma = getKoma(from);
		const Koma toKoma = getKoma(to);
		Bitboard& fromKomaBB = eachKomaBB[static_cast<size_t>(fromKoma)];
		fromKomaBB.reset(from);	//BB from
		bammen[from] = static_cast<std::uint8_t>(Koma::None);	//ban from
		if (prom) {//成る場合
			Koma fromPromKoma = promote(fromKoma);
			Bitboard& fromPromKomaBB = eachKomaBB[static_cast<size_t>(fromPromKoma)];
			fromPromKomaBB.set(to);	//BB to
			bammen[to] = static_cast<std::uint8_t>(fromPromKoma);//ban to
		}
		else {//成らない場合
			fromKomaBB.set(to);		//BB to
			bammen[to] = static_cast<std::uint8_t>(fromKoma);	//ban to
		}
		if (toKoma != Koma::None) {//駒を取っていた場合 
			Bitboard& toKomaBB = eachKomaBB[static_cast<size_t>(toKoma)];
			toKomaBB.reset(to);//BB cap
			Position capMpos = captured = KomaToMpos(toKoma);
			bammen[capMpos]++;//mban cap
			//bammen[to]は後で更新される
		}
	}
	else {//駒台から打つ場合
		const Koma fromKoma = MposToKoma(static_cast<Position>(from));
		Bitboard& fromKomaBB = eachKomaBB[static_cast<size_t>(fromKoma)];
		fromKomaBB.set(to);		//BB to
		bammen[from]--;		//mban from
		bammen[to] = static_cast<std::uint8_t>(fromKoma);	//ban to
	}
	isSente = !isSente;
	return captured;
}

bool Kyokumen::isDeclarable()const {
	using namespace koma;
	//王手チェックはしないのでこの関数を呼ぶ前に確認しておくこと(パフォーマンス向上のため)
	if (teban()) {
		//宣言側の玉が敵陣三段目以内
		if (sOuPos() % 9 > 3) {
			return false;
		}
		Bitboard tekijinSenteBB = senteKomaBB & bbmask::Dan1to3;
		//宣言側の敵陣三段目以内の駒が玉含めずに10枚以上存在する (玉含めて11枚以上)
		if (tekijinSenteBB.popcount() <= 10) {
			return false;
		}
		//宣言側の駒の点数が、大駒5点 小駒1点 玉0点で計算して、28点以上(後手は27点以上)
		int komapoint = 0;
		for (unsigned pos = tekijinSenteBB.pop_first(); pos < tekijinSenteBB.size(); pos = tekijinSenteBB.pop_first()) {
			const Koma koma = getKoma(pos);
			switch (koma) {
			case Koma::s_Fu:
			case Koma::s_Kyou:
			case Koma::s_Kei:
			case Koma::s_Gin:
			case Koma::s_Kin:
			case Koma::s_nFu:
			case Koma::s_nKyou:
			case Koma::s_nKei:
			case Koma::s_nGin:
				komapoint += 1;
				break;
			case Koma::s_Hi:
			case Koma::s_Kaku:
			case Koma::s_nHi:
			case Koma::s_nKaku:
				komapoint += 5;
				break;
			}
		}
		if (komapoint >= 28)
			return true;
		else return false;
	}
	else {
		//宣言側の玉が敵陣三段目以内
		if (gOuPos() % 9 > 3) {
			return false;
		}
		Bitboard tekijinGoteBB = goteKomaBB & bbmask::Dan7to9;
		//宣言側の敵陣三段目以内の駒が玉含めずに10枚以上存在する (玉含めて11枚以上)
		if (tekijinGoteBB.popcount() <= 10) {
			return false;
		}
		//宣言側の駒の点数が、大駒5点 小駒1点 玉0点で計算して、27点以上(先手は28点以上)
		int komapoint = 0;
		for (unsigned pos = tekijinGoteBB.pop_first(); pos < tekijinGoteBB.size(); pos = tekijinGoteBB.pop_first()) {
			const Koma koma = getKoma(pos);
			switch (koma) {
			case Koma::g_Fu:
			case Koma::g_Kyou:
			case Koma::g_Kei:
			case Koma::g_Gin:
			case Koma::g_Kin:
			case Koma::g_nFu:
			case Koma::g_nKyou:
			case Koma::g_nKei:
			case Koma::g_nGin:
				komapoint += 1;
				break;
			case Koma::g_Hi:
			case Koma::g_Kaku:
			case Koma::g_nHi:
			case Koma::g_nKaku:
				komapoint += 5;
				break;
			}
		}
		if (komapoint >= 27)
			return true;
		else return false;
	}
}

std::vector<Bitboard> Kyokumen::getSenteOuCheck(const Move m)const {
	std::vector<Bitboard> kusemono;
	const unsigned ouPos = sOuPos();
	const unsigned from = m.from();
	const unsigned to = m.to();
	//親局面が存在しない、または玉自身が動いた場合は全体を調べる
	if (from == Position::NullMove || to==ouPos) {
		return getSenteOuCheck();
	}
	//fromでどいたところから空き王手がないか調べる
	if (isInside(from)) {
		Bitboard fpBB = pinMaskSente(from);
		if (fpBB != bbmask::AllOne) {
			fpBB.set(from);
			kusemono.push_back(fpBB);
		}
	}
	//toに移動した駒が玉に効いているか調べる
	const Koma movedKoma = getKoma(to);
	if (isDashable(movedKoma)) {
		Bitboard kiki = BBkiki::getDashKiki(allKomaBB, movedKoma, to);
		if ((kiki & getEachBB(Koma::s_Ou)).any()) {
			kiki.set(to);
			kiki &= BBkiki::getDashKiki(allKomaBB, sgInv(movedKoma), ouPos);
			kusemono.push_back(kiki);
		}
	}
	if(isSteppable(movedKoma)) {
		Bitboard tpBB = Bitboard(to);
		tpBB &= BBkiki::getStepKiki(sgInv(movedKoma), ouPos);
		if (tpBB.any()) {
			kusemono.push_back(tpBB);
		}
	}
	return kusemono;
}

std::vector<Bitboard> Kyokumen::getGoteOuCheck(const Move m)const {
	std::vector<Bitboard> kusemono;
	const unsigned ouPos = gOuPos();
	const unsigned from = m.from();
	const unsigned to = m.to();
	//親局面が存在しない、または玉自身が動いた場合は全体を調べる
	if (from == Position::NullMove || to == ouPos) {
		return getGoteOuCheck();
	}
	//fromでどいたところから空き王手がないか調べる
	if (koma::isInside(from)) {
		Bitboard fpBB = pinMaskGote(from);
		if (fpBB != bbmask::AllOne) {
			fpBB.set(from);
			kusemono.push_back(fpBB);
		}
	}
	//toに移動した駒が玉に効いているか調べる
	const Koma movedKoma = getKoma(to);
	if (isDashable(movedKoma)) {
		Bitboard kiki = BBkiki::getDashKiki(allKomaBB, movedKoma, to);
		if ((kiki & getEachBB(Koma::g_Ou)).any()) {
			kiki.set(to);
			kiki &= BBkiki::getDashKiki(allKomaBB, sgInv(movedKoma), ouPos);
			kusemono.push_back(kiki);
		}
	}
	if(isSteppable(movedKoma)) {
		Bitboard tpBB = Bitboard(to);
		tpBB &= BBkiki::getStepKiki(sgInv(movedKoma), ouPos);
		if (tpBB.any()) {
			kusemono.push_back(tpBB);
		}
	}
	return kusemono;
}

std::vector<Bitboard> Kyokumen::getSenteOuCheck()const {
	std::vector<Bitboard> kusemono;
	const unsigned ouPos = sOuPos();
	for (const Koma koma : gStepKomas) {
		Bitboard kusemonoBB = BBkiki::getStepKiki(sgInv(koma), ouPos) & getEachBB(koma);
		if (kusemonoBB.any()) {
			kusemono.push_back(kusemonoBB);
			break;
		}
	}
	for (const Koma koma : gDashKomas) {
		Bitboard kikiBB = BBkiki::getDashKiki(allKomaBB, sgInv(koma), ouPos);
		Bitboard eBB = kikiBB & getEachBB(koma);
		if (eBB.any()) {
			for (unsigned i = eBB.pop_first(); i != eBB.size(); i = eBB.pop_first()) {
				Bitboard kusemonoBB = BBkiki::getDashKiki(allKomaBB, koma, i) & kikiBB;
				kusemonoBB.set(i);
				kusemono.push_back(kusemonoBB);
			}
		}
	}
	return kusemono;
}

std::vector<Bitboard> Kyokumen::getGoteOuCheck()const {
	std::vector<Bitboard> kusemono;
	const unsigned ouPos = gOuPos();
	for (const Koma koma : sStepKomas) {
		Bitboard kusemonoBB = BBkiki::getStepKiki(sgInv(koma), ouPos) & getEachBB(koma);
		if (kusemonoBB.any()) {
			kusemono.push_back(kusemonoBB);
			break;
		}
	}
	for (const Koma koma : sDashKomas) {
		Bitboard kikiBB = BBkiki::getDashKiki(allKomaBB, sgInv(koma), ouPos);
		Bitboard eBB = kikiBB & getEachBB(koma);
		if (eBB.any()) {
			for (unsigned i = eBB.pop_first(); i != eBB.size(); i = eBB.pop_first()) {
				Bitboard kusemonoBB = BBkiki::getDashKiki(allKomaBB, koma, i) & kikiBB;
				kusemonoBB.set(i);
				kusemono.push_back(kusemonoBB);
			}
		}
	}
	return kusemono;
}

Bitboard Kyokumen::pinMaskSente(const unsigned pos)const {
	const unsigned ouPos = sOuPos();
	Bitboard dpBB(allKomaBB);
	dpBB.reset(pos);
	for (Koma ek : gDashKomas) {
		Bitboard kikiBB = BBkiki::getDashKiki(dpBB, sgInv(ek), ouPos);
		Bitboard eBB = kikiBB & getEachBB(ek);
		if (eBB.any() && kikiBB.test(pos)) {
			Bitboard result;
			for (unsigned i = eBB.pop_first(); i != eBB.size(); i = eBB.pop_first()) {
				result |= kikiBB & BBkiki::getDashKiki(dpBB, ek, i);
				result.set(i);
			}
			return result;
		}
	}
	return bbmask::AllOne;
}

Bitboard Kyokumen::pinMaskGote(const unsigned pos)const {
	const unsigned ouPos = gOuPos();
	Bitboard dpBB(allKomaBB);
	dpBB.reset(pos);
	for (Koma ek : sDashKomas) {
		Bitboard kikiBB = BBkiki::getDashKiki(dpBB, sgInv(ek), ouPos);
		Bitboard eBB = kikiBB & getEachBB(ek);
		if (eBB.any() && kikiBB.test(pos)) {
			Bitboard result;
			for (unsigned i = eBB.pop_first(); i != eBB.size(); i = eBB.pop_first()) {
				result |= kikiBB & BBkiki::getDashKiki(dpBB, ek, i);
				result.set(i);
			}
			return result;
		}
	}
	return bbmask::AllOne;
}

bool Kyokumen::operator==(const Kyokumen& rhs) const {
	if (senteKomaBB == rhs.senteKomaBB && goteKomaBB == rhs.goteKomaBB && bammen == rhs.bammen)
		return true;
	else 
		return false;
}

void Kyokumen::reflectBitboard() {
	//bitboard
	for (auto& bb : eachKomaBB) {
		bb.all_reset();
	}
	for (int i = 0; i < 81; i++) {
		if (getKoma(i) != koma::Koma::None)
			eachKomaBB[bammen[i]].set(i);
	}
	senteKomaBB.all_reset();
	for (size_t i = static_cast<size_t>(koma::Koma::s_Min); i < static_cast<size_t>(koma::Koma::s_Num); i++) {
		senteKomaBB |= eachKomaBB[i]; //先手の駒をすべて集めたbb
	}
	goteKomaBB.all_reset();
	for (size_t i = static_cast<size_t>(koma::Koma::g_Min); i < static_cast<size_t>(koma::Koma::g_Num); i++) {
		goteKomaBB |= eachKomaBB[i]; //後手の駒をすべて集めたbb
	}
	allKomaBB = senteKomaBB | goteKomaBB;//全体のbbは先後のものを合成する
}