/*
 * The main function of the loader.
 *
 * Copyright (c) 2013, Shikhin Sethi
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation 
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following conditions:
 *
 *     * The above copyright notice and this permission notice shall be included in
 *       all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <UART.h>

// The version.
#define VERSION_MAJOR 0
#define VERSION_MINOR 1

/*
 * The Main function for the laoder.
 */
void Main()
{
    // Initialize UART.
    UARTInit();

    // Tart loader protocol.

    // Output major version, followed by minor.
    UARTTransmit(VERSION_MAJOR); UARTTransmit(VERSION_MINOR);

    // If 'OK' wasn't transmitted, just go into an infinite loop.
    if((char)UARTRecieve() != 'O' || (char)UARTRecieve() != 'K')
    {
        // Loop.
        for(;;);
    }
}
