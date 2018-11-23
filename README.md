# wxVcashGUI
A multiplatform GUI for Vcash, a decentralized currency for the internet (https://vcash.info/).

# Building vcash

In order to build wxVcashGUI, you will need to build firstly vcash.

## On Linux

You can build vcash by using the script at:

https://github.com/vcashcommunity/vcash-scripts/tree/vanilla

The resulting build will be located at ~/vcash/.

## On Windows using Microsoft Visual Studio 2015

These are instructions for building a Windows 64 bits executable and this procedure
has been tested on Windows 10 x64 with MSVC14 (Visual Studio 2015).

Follow the following instructions to build vcash with Microsoft Visual Studio:

https://github.com/vcashcommunity/vcash/blob/vanilla/platforms/windows/README.md

For building with Visual Studio 2015, the only difference with respect to those instructions is to use the following command to build boost:
```
b2 -j3 toolset=msvc-14.0 address-model=64 architecture=x86 link=static threading=multi runtime-link=static --with-system --stagedir=stage/x64
```


# Building and installing wxWidgets

## On linux
Download source code of wxWidgets: https://github.com/wxWidgets/wxWidgets/releases/download/v3.1.0/wxWidgets-3.1.0.tar.bz2

Uncompress this file and cd to corresponding directory:
```
cd wxWidgets-3.1.0
```

Make a build directory , configure and build:
```
cd build
mkdir gtk
cd gtk
../../configure --enable-unicode --enable-debug --disable-shared
make
```

Go for a cup of coffee :) .

Install wxWidgets:
```
sudo make install
wx-config --version
```


## On Windows using Microsoft Visual Studio 2015

Download source code of wxWidgets: https://github.com/wxWidgets/wxWidgets/releases/download/v3.1.0/wxWidgets-3.1.0.zip

Uncompress this file to folder C:\wxWidgets-3.1.0

Open a Visual Studio x64 native tools command prompt (** choose the right prompt or compilation will fail **).

cd to directory C:\wxWidgets-3.1.0\build\msw:
```
cd C:\wxWidgets-3.1.0\build\msw
```

Enter the following command to build wxWidgets:
```
nmake /f makefile.vc BUILD=release TARGET_CPU=X64 RUNTIME_LIBS=static
```

and go for a cup of coffee :) .


# Downloading wxVcashGUI

## On linux

Download wxVcashGUI from https://github.com/vcashcommunity/wxVcashGUI/archive/vanilla.zip and uncompress this file inside your ~/vcash/src folder.


## On Windows

Download wxVcashGUI from https://github.com/vcashcommunity/wxVcashGUI/archive/vanilla.zip and uncompress this file inside your vcash-vanilla folder (C:\vcash-vanilla).


# Building libqrencode

libqrencode (https://github.com/fukuchi/libqrencode) library must be built previously in directory deps.

## On Linux

cd to that directory:
```
cd ~/vcash/src/wxVcashGUI-vanilla/deps
```

Clone libqrencode library:
```
git clone https://github.com/fukuchi/libqrencode
```

Build the library:
```
cd libqrencode
cmake CMakeLists.txt
make
```

## On Windows

Download the library from https://github.com/fukuchi/libqrencode/archive/master.zip 

Uncompress this file to folder C:\vcash-vanilla\wxVcashGUI-vanilla\deps
and rename folder libqrencode-master to libqrencode.

cd to libqrencode directory:
```
cd C:\vcash-vanilla\wxVcashGUI-vanilla\deps\libqrencode
```

Build the library:
```
nmake /f makefile.vc
```


# Building wxVcashGUI

## On Linux

cd to wxVcashGUI directory:
```
cd ~/vcash/src/wxVcashGUI-vanilla
```

Enter the following commands:
```
cmake CMakeLists.txt
make
```

## On Windows using Microsoft Visual Studio 2015

cd to wxVcashGUI directory:
```
cd C:\vcash-vanilla\wxVcashGUI-vanilla
```

Enter the following command:
```
nmake /f makefile.vc BUILD=release TARGET_CPU=X64 RUNTIME_LIBS=static USE_THREADS=1
```

Enjoy your GUI for Vcash!


# Adding support for custom URL vcash protocol

## On Linux

Create the following text file:
```
gedit  ~/.local/share/applications/vcash.desktop
```
      
The contents of this file should be as follows, but replacing paths with those used in your computer:                        
```
[Desktop Entry]
Version=1.0
Type=Application
Exec=<path to vcash executable folder>/vcash --url=%u
Icon=<path to vcash icon>
Terminal=false
Categories=Crypto
MimeType=x-scheme-handler/vcash;
Name=Vcash
Comment=Vcash
```

Edit the following text file:
```
gedit ~/.local/share/applications/mimeapps.list
```
                        
and add the following contents in section `Default Applications` (or create this section if it isn't yet in the file):
```
[Default Applications]
x-scheme-handler/vcash=vcash.desktop
```

Enter the following command:
```
sudo update-desktop-database
```
                        
Test the protocol by clicking this vcash link: `vcash://VaEkBynLcMdos1DgfTrtBuwNaFYoJWswR6?amount=25&zerotime=true` and tip me ;-)
                        
## On Windows
                 
Create with a text editor a file with extension `.reg` and the following contents, but replacing paths to `vcash.exe` with those used in your computer:
```
REGEDIT4

[HKEY_CLASSES_ROOT\Vcash]
@="URL:vcash"
"URL Protocol"=""

[HKEY_CLASSES_ROOT\Vcash\DefaultIcon]
@="\"C:\\vcash-vanilla\\wxVcashGUI\\vc_mswu_x64\\vcash.exe""

[HKEY_CLASSES_ROOT\Vcash\shell]

[HKEY_CLASSES_ROOT\Vcash\shell\open]

[HKEY_CLASSES_ROOT\Vcash\shell\open\command]
@="\"C:\\vcash-vanilla\\wxVcashGUI\\vc_mswu_x64\\vcash.exe\" --url=\"%1\""
```

Save this file and double click on it to import its contents into the Windows Registry.                       

Test the protocol by clicking this vcash link: `vcash://VaEkBynLcMdos1DgfTrtBuwNaFYoJWswR6?amount=25&zerotime=true` and tip me ;-)
