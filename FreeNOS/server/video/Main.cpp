/*
 * Copyright (C) 2009 Niek Linnenbank
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <KernelLog.h>
#include <DeviceServer.h>
#include "VGA.h"
#include <iostream>
int main(int argc, char **argv)
{
    KernelLog log;
    DeviceServer server("/dev/video");

    server.registerDevice(new VGA(server.getNextInode()), "vga0");

    std::cout<<"I'm coming ,son of bitch!" << std::endl;
    // Initialize
    const FileSystem::Result result = server.initialize();
    if (result != FileSystem::Success)
    {
        ERROR("failed to initialize: result = " << (int) result);
        return 1;
    }

    // Start serving requests.
    return server.run();
}
