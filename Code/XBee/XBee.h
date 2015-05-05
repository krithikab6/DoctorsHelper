/* Copyright (c) 2012 Tristan Hughes, MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
 * and associated documentation files (the "Software"), to deal in the Software without restriction, 
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, 
 * sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is 
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or 
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
 
#ifndef XBee_H
#define XBee_H 

#include "mbed.h"
#include <string>
/** XBee interface class for configuring, sending and recieving data using an XBee */
class XBee
{
private:
    PinName _tx;
    PinName _rx;
    PinName _reset;
public:
    /** Configure serial data pin.
      * @param tx The serial tx pin the XBee is conected to.
      * @param rx The serial rx pin the XBee is conected to.
      * @param reset The pin connected to the XBee reset pin.
      */
    XBee(PinName tx, PinName rx, PinName reset);
    ~XBee();
    /** Puts the XBee into config mode.
      * @return Returns 1 on success.
      */
    int configMode();
    /** Gets the serial number/mac address of the XBee and places it into serial_no.
      * @param serial_no array to store the serial of XBee (must be 8 long).
      * @return Returns 1 on success.
      */
    int getSerial(int*);
    /** Sets the encryption key to the one stored in security_key.
      * @param key Pointer to the network key to set.
      * @return Returns 1 on success.
      */
    int setKey(int*);
    /** Sets the id of the PAN network for the XBee to use
      * @param pan_id The id of the PAN for the XBee to use.
      * @return Returns 1 on success.
      */
    int setPanID(int);
    /** Writes the settings to the Non volatile memory on the XBee
      * @param key Pointer to the network key to set.
      * @return Returns 1 on success.
      */
    int writeSettings();
    /** Exits config mode
      * @return Returns 1 on success.
      */
    int exitConfigMode();
    /** Sends data in the send_Data buffer.
      * @param data_buf Pointer to the buffer of data to send.
      * @returns 1 on success.
      */
    int sendData(string);
    /** Recieves data sent to the XBee.
      * @param data_buf Pointer to the buffer to put recieved data into.
      * @param numchar Number of characters to read. If 0, will use the size of data_buf.
      */
    void recieveData(string, int);
        /** Resets the XBee.
      */
    void reset();
    
    void setBaud(int);

};

#endif