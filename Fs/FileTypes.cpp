/*
*   Copyright © Ben D.
*   dbapps2@gmail.com
*
*   This is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <Fs/FileTypes.h>

const string FileTypes::Read = "rb";

const string FileTypes::Write = "w";

const string FileTypes::ReadWrite = "rw";

const string FileTypes::Append = "a+";

const int FileTypes::Eof = -2;

const int FileTypes::SeekfBegin = 0;

const int FileTypes::SeekfEnd = 2;

const int FileTypes::SeekCurrent = 1;

const int FileTypes::RWXU = 0000700;

const int FileTypes::RU = 0000400;

const int FileTypes::WU = 0000200;

const int FileTypes::XU = 0000100;

const int FileTypes::RWXG = 0000070;

const int FileTypes::RG = 0000040;

const int FileTypes::WG = 0000020;

const int FileTypes::XG = 0000010;

const int FileTypes::RWXO = 0000007;

const int FileTypes::RO = 0000004;

const int FileTypes::WO = 0000002;

const int FileTypes::XO = 0000001;

const int FileTypes::SUID = 0004000;

const int FileTypes::SGID = 0002000;

const int FileTypes::SVTX = 0001000;

