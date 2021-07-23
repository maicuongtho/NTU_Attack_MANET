An Efficient Scheme for Detection and Prevention of Black Hole Attacks in AODV-Based MANETs
Muhammad Salman Pathan 1 , Jingsha He 2 , Nafei Zhu 3 , Zulfiqar Ali Zardari 4 , Muhammad Qasim Memon 5 ,
Aneeka Azmat 6
-----------------------------
MDBM: T HE P ROPOSED S CHEME
-------------------------------------
The proposed scheme works with an objective to detect the
black hole attacks and prevent the network from their harm.
This scheme is the modification of AODV routing protocol
where the concept of fake RREQ packets [41] is included. The
fake RREQ packets are broadcasted in the network before the
actual route discovery. The reason behind doing so is to trace
most of the malicious nodes in the network before the
transmission of data, to prevent the data loss. In the proposed
approach, an empirical format was designed for the fake
request packet as presented in Fig. 2. This packet contains
fields like Type, Reserved, Request ID and the Target Address
which is completely fake and doesn‟t exist in the network. The
fake RREQ packets last for a certain time period, similar to the
real RREQ packets of AODV. Fig. 3 shows the real RREQ
packet format used in the proposed scheme. The only
difference as compared to the main format of RREQ packet is
the addition of the Alert field which includes the list of
malicious nodes. The authors have also modified the format of
RREP packet of AODV to find the addresses of the nodes that
generates RREP packet. In order to implement this mechanism,
the structure of RREP packet is modified and an extra field is
added into it called as RREP Generator Address. This field
holds the address of a particular node which will generate the
reply packet. When a node will reply to the RREQ packet, its
address will be copied into this field, so that the source node
can trace the address of the RREP generator node. Fig. 4 shows
the structure of the modified RREP packet.