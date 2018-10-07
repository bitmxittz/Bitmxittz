Bitmxittz integration/staging tree
================================

https://www.bitmxittz.com

Copyright (c) 2009-2014 Bitcoin Developers

Copyright (c) 2011-2014 Litecoin Developers

Copyright (c) 2017-2019 Bitmxittz Developers

What is Bitmxittz?
----------------

Bitmxittz is a lite version of Bitcoin using scrypt as a proof -of-work, proof-of-stake 0% algorithm.
 - 15 second block targets
 - subsidy halves in 26-27 blocks
 - ~10000 total coins
 - last proof-of-work block #27
 - proof-of-stake 0% interest

The rest is the same as Bitcoin.
 - 1 coins per block
 - 10 blocks to retarget difficulty

For more information, as well as an immediately useable, binary version of
the Bitmxittz client sofware, see https://www.bitmxittz.com or http://www.bitmxittz.com.

License
-------

Bitmxittz is released under the terms of the MIT license. See `COPYING` for more
information https://bitmxittz.mit-license.org/ or see http://opensource.org/licenses/MIT.

Development process
-------------------

Developers work in their own trees, then submit pull requests when they think
their feature or bug fix is ready.

If it is a simple/trivial/non-controversial change, then one of the Bitmxittz
development team members simply pulls it.

If it is a *more complicated or potentially controversial* change, then the patch
submitter will be asked to start a discussion with the devs and community.

The patch will be accepted if there is broad consensus that it is a good thing.
Developers should expect to rework and resubmit patches if the code doesn't
match the project's coding conventions (see `doc/coding.txt`) or are
controversial.

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/bitmxittz-project/bitmxittz/tags) are created
regularly to indicate new official, stable release versions of Bitmxittz.

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test. Please be patient and help out, and
remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write unit tests for new code, and to
submit new unit tests for old code.

Unit tests for the core code are in `src/test/`. To compile and run them:

    cd src; make -f makefile.unix test

Unit tests for the GUI code are in `src/qt/test/`. To compile and run them:

    qmake BITCOIN_QT_TEST=1 -o Makefile.test bitcoin-qt.pro
    make -f Makefile.test
    ./bitmxittz-qt_test


Compilation
-----------

Compile Bitmxittz QT wallet or Daemon on windows, linux

### Compile Daemon on Linux

use "sudo" if you are not root user.

    apt-get update

    apt-get upgrade

If low on RAM

    dd if=/dev/zero of=/swapfile bs=1024 count=1024288

    nano /etc/fstab
Or
    vim /etc/fstab

Add this at the bottom of /etc/fstab: /swapfile none swap sw 0 0

To edit, press "Insert" if you using vim.

To save and exit, if using nano press "cntr+O" then "cntl+x", if using vim press "Esc" type ":wq" hit "Enter".

    apt-get install ntp unzip git build-essential libssl-dev libdb-dev libdb++-dev libboost-all-dev libqrencode-dev aptitude && aptitude install miniupnpc libminiupnpc-dev

    git clone https://github.com/bitmxittz/Bitmxittz

    cd Bitmxittz/src/leveldb

    chmod 0755 build_detect_platform

    make clean

    make libleveldb.a libmemenv.a

    cd

    cd Bitmxittz/src

    make -f makefile.unix clean

    make STATIC=1 -f makefile.unix bitmxittzd  

-or-  

    make -f makefile.unix bitmxittzd

    strip bitmxittzd

    cp bitmxittzd /usr/bin

    bitmxittzd & cd ~/.bitmxittz

    nano bitmxittz.conf 

or 

    vim bitmxittz.conf

    rpcuser=YOUR_RPC_USERNAME
    rpcpassword=YOUR_STRONG_PASSWORD
    rpcallowip=127.0.0.1
    port=14433
    rpcport=14432
    daemon=1
    server=1
    listen=1
    testnet=0
    txindex=1
    timeout=30000
    rpctimeout=30000
    addnode=nd1.bitmxittz.com
    addnode=nd2.bitmxittz.com
    addnode=nd3.bitmxittz.com
    addnode=nd4.bitmxittz.com
    addnode=nd5.bitmxittz.com

if using nano cntr+O then cntl+x, if using vim Esc :wq Enter, to save and exit.

    cd

    bitmxittzd

    bitmxittzd getinfo

    bitmxittzd getpeerinfo


### Compile QT wallet on Linux


### Compile Daemon on Windows


### Compile QT wallet on Windows
