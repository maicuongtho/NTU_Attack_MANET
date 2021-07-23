//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package ntuattack.hackedmodules.networklayer.ipv4;
import inet.networklayer.ipv4.Ipv4;
module hacked_IPv4 extends Ipv4
{
    parameters: 
        //#Labels for the potential attacks that affect this module
        @dropping;	// Dropping attack in IPv4 Layer
        @delay;		// Delay attack in IPv4 Layer
        
        //# Normal parameters
        @display("i=block/routing,red;i2=status/excl3");
	    @class(hacked_IPv4);
	    
	    //# Dropping attack statistics
	    @signal[droppings](type=long); // Signal for number of packet discarded
	    @statistic[droppings](title="Number of drops"; record=count, vector; interpolationmode=none); // Record the number of packet discarded
	    
	    //# Packet received attack statistics
	    @signal[rcvdPkt](type=long); // Signal for number of packet received
	    @statistic[rcvdPkt](title="Number of packet received"; record=count, vector; interpolationmode=none); // Record the number of packet received
	    
	    //# Delay attack statistics
	    @signal[delayed](type=long); // Signal for number of packet delayed
	    @statistic[delayed](title="Number of packet delayed"; record=count, vector; interpolationmode=none); // Record the number of packet delayed
}