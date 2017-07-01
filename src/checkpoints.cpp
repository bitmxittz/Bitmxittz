// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    // How many times we expect transactions after the last checkpoint to
    // be slower. This number is a compromise, as it can't be accurate for
    // every system. When reindexing from a fast disk with a slow CPU, it
    // can be up to 20, while when downloading from a slow network with a
    // fast multicore CPU, it won't be much higher than 1.
    static const double fSigcheckVerificationFactor = 5.0;

    struct CCheckpointData {
        const MapCheckpoints *mapCheckpoints;
        int64 nTimeLastCheckpoint;
        int64 nTransactionsLastCheckpoint;
        double fTransactionsPerDay;
    };

    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        (  0, uint256("0x6226e1da4d049f3e132af0a7265c1e05d90035e0afdf8cec3a65a6353c30b1c5"))
        (  1, uint256("0x7c04eff57e8c1fff3160ee2ae3888733e93334d95f72641f2527e2855ac97931"))
        (  2, uint256("0x2504d0fe55ceb7a0520934492a6c38ccf8f70cafc07f4bb113af9f603352ec85"))
        (  3, uint256("0x2758f6df2442dbb7f89ac19e47da81fb91915627fac302d7deb862687c885866"))
        (  4, uint256("0x7460fedef97560e99ac41752fca49d79f1098720142fbfdc4016a55a53b7c424"))
        (  5, uint256("0x02fd96716e28f13aceb4c5a1be5bdcf166354675ff3e4e23c30f48ab6ad2792a"))
        (  6, uint256("0x7b78b9c2e9f9a32abe42b3cf8d2a988e5db52772e790747cd29e29d57aa84236"))
        (  7, uint256("0x8fc71ed571618a4c51d3e9cee521d133e88121bb3cc1f9c1cb92321b9eaa4e61"))
        (  8, uint256("0x3ce919a0eeab2930d6b74cf04d661dd99200dae37e337274a89cb87ac8513454"))
        (  9, uint256("0xd358782d6723729b6d12bc8e70394ab91763b791b3174bae9bd9fb0a77900f15"))
        (  10, uint256("0x4e93722ab84d398bc7708f46196a012286de2f3b74753f05525b0a533ab90985"))
        (  11, uint256("0x702271c7507a6399d4c20215e1d9c5aeb7f9a98ccc76e69ef437214e85c206b6"))
        (  12, uint256("0x25f1aa7a4442affbb94992e3ee8dc005b9b51d8efbf9051b8291f54419becf70"))
        (  13, uint256("0xb334da77914dc754ec2989b6c9146b4cd4ffcfee71b279cc0f2c2126eda5c44b"))
        (  14, uint256("0xa5cf41187868bb8817a8d7dc098b129d6c157b9fd0239f14754a049ed7565433"))
        (  15, uint256("0xbd432b959a9d3a07db4a2cbf26ffb8b298ed99d03a1df0f1dd19fe27e89c3de2"))
        (  16, uint256("0x4c08b837886f1d08913d7b9e742c87f1a2351bf3449a33e7fccfbba25e2ba9e2"))
        (  17, uint256("0xc2c7c58db758c77b47768ab0a89db45bc8aca13a438b75de72094707ea33ef5b"))
        (  18, uint256("0xf4bbd5474bc1d74e28e91cde4c7338936d2dffab9f8f22b9961106e754ca21f6"))
        (  19, uint256("0x466a7fb314f40d10c0e043218d79c34b2bf105120f77536f72f49e86964d1d04"))
        (  20, uint256("0xaad0a3da75f92ba9c34e86ee68488f81f6236372781b5fc075339c765336611d"))
        (  21, uint256("0x2b12e2bdf389dbed289b16a0e7e4c6384550166ca58260ad86b0761e6b1400ee"))
        (  22, uint256("0xb3a99e972aba8a38bd4c8e63ca9406da98f4feb08d7a1f95b7606eb3d2e699e5"))
        (  23, uint256("0xd1f6646795256e53918dc0953d4ce24bc9584e9798a33f14ef6ecd50ea1c921d"))
        (  24, uint256("0x70e6e0abcd04914bfc896fcd819d60a40e72f63c81dcbc226f6bd8556edb85c9"))
        (  25, uint256("0xc617370be24b060bc7d6f45a7282793f67a7240d67312b1d7d5357db8bbc9e3e"))
        (  26, uint256("0xc2750e976e755fddc11fa761c82c2bb18e5b166644270dbcc0aff488c8509cd3"))
        (  27, uint256("0x6b4fab32f0f7e3a3b53ec9f92dd806e1fdf6744c5e70ff7a16006493e70c2708"))
        (  28, uint256("0x0d43eba2e7e8235d98740b2bbce6e608c351c01275e44ad9b0f554e0aa771aed"))
        (  29, uint256("0x462d2abb6ed4cc08033d0d6f51edf641112695d0ad9f869e40d85e12f1f5f006"))
        (  30, uint256("0x9e8b4fc21a33f741fe6892b671a9327b0f3a6a73a370d3827ae1612308f3cd28"))
        (  31, uint256("0xafbd88020d9faeb349e0f3957fd6f1acccccfc808816eba473589a0d908d83d4"))
        ;
    static const CCheckpointData data = {
        &mapCheckpoints,
        1498723551, // * UNIX timestamp of last checkpoint block
        32,    // * total number of transactions between genesis and last checkpoint
                    //   (the tx=... number in the SetBestChain debug.log lines)
        1000.0     // * estimated number of transactions per day after checkpoint
    };

    static MapCheckpoints mapCheckpointsTestnet =
        boost::assign::map_list_of
        (   0, uint256("0x"))
        ;
    static const CCheckpointData dataTestnet = {
        &mapCheckpointsTestnet,
        //1365458829,
        //547,
        //576
    };

    const CCheckpointData &Checkpoints() {
        if (fTestNet)
            return dataTestnet;
        else
            return data;
    }

    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (!GetBoolArg("-checkpoints", true))
            return true;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
        if (i == checkpoints.end()) return true;
        return hash == i->second;
    }

    // Guess how far we are in the verification process at the given block index
    double GuessVerificationProgress(CBlockIndex *pindex) {
        if (pindex==NULL)
            return 0.0;

        int64 nNow = time(NULL);

        double fWorkBefore = 0.0; // Amount of work done before pindex
        double fWorkAfter = 0.0;  // Amount of work left after pindex (estimated)
        // Work is defined as: 1.0 per transaction before the last checkoint, and
        // fSigcheckVerificationFactor per transaction after.

        const CCheckpointData &data = Checkpoints();

        if (pindex->nChainTx <= data.nTransactionsLastCheckpoint) {
            double nCheapBefore = pindex->nChainTx;
            double nCheapAfter = data.nTransactionsLastCheckpoint - pindex->nChainTx;
            double nExpensiveAfter = (nNow - data.nTimeLastCheckpoint)/86400.0*data.fTransactionsPerDay;
            fWorkBefore = nCheapBefore;
            fWorkAfter = nCheapAfter + nExpensiveAfter*fSigcheckVerificationFactor;
        } else {
            double nCheapBefore = data.nTransactionsLastCheckpoint;
            double nExpensiveBefore = pindex->nChainTx - data.nTransactionsLastCheckpoint;
            double nExpensiveAfter = (nNow - pindex->nTime)/86400.0*data.fTransactionsPerDay;
            fWorkBefore = nCheapBefore + nExpensiveBefore*fSigcheckVerificationFactor;
            fWorkAfter = nExpensiveAfter*fSigcheckVerificationFactor;
        }

        return fWorkBefore / (fWorkBefore + fWorkAfter);
    }

    int GetTotalBlocksEstimate()
    {
        if (!GetBoolArg("-checkpoints", true))
            return 0;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        return checkpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (!GetBoolArg("-checkpoints", true))
            return NULL;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}