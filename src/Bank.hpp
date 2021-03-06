/*
 * bank.hpp
 *
 *  Created on: Feb 12, 2020
 *      Author: ml2au
 */

#ifndef BANK_HPP_
#define BANK_HPP_
#include <cstddef>

#include "types.hpp"

#include <queue>
#include "PhysicalComponent.hpp"
#include "Packet.hpp"
#include "Subarray.hpp"

class Bank:public PhysicalComponent{
private:
	std::queue <Packet<PlacementPacket>*>* getNextBankQ_dragonfly(ID_TYPE dstBankAddr);

public:
	ID_TYPE selfIndex = 0;
	u64 numSubToSubPackets = 0;
	u64 numBankToBankPackets = 0;
	u64 numSegTSVPackets = 0;
	u64 numRowActivations = 0;
	//u64 numInFlightPackets = 0;

	u64 stalledSub = 0;

	std::vector<Subarray *> subarrayVector;

	HIST_ELEM_TYPE histogram[G_NUM_HIST_ELEMS];

	std::queue <Packet<PlacementPacket>* > packetQ;
	std::queue <Packet<PlacementPacket>*>* upperLayerQ = nullptr;
	std::queue <Packet<PlacementPacket>*>* lowerLayerQ = nullptr;

	Bank(ID_TYPE l_id, PhysicalComponent * l_parent);
	~Bank();

	void producePackets();
	void routePacketsOneCycle();


	void initLayerQ();
	u64 runLocalHist();
};





#endif
