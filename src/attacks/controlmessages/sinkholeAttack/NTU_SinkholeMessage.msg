//
// Message interchanged between sinkhole attack controller and the corresponding hacked
// modules. In this case NA_AODV
//
// @see NTU_SinkholeAttack, NTU_AODV
//
// @author thomc
// @date 10/3/2020
message NTU_SinkholeMessage {
    bool sinkOnlyWhenRouteInTable; 	// TRUE indicates that only RREQ for routes that are in routing table are answered as the best route across the sink node.
    								// A false value indicates that all the sinkhole node will answer to all the RREQ with fake routes. 
    double sinkholeAttackProbability;  	//Probability for announcing a fake route when a RREQ is received. Value in [0,1]
    double seqnoAdded; 					// Sequence number.
    int numHops;
}
