#pragma once

#include <map>
#include <QDebug>


class IWalk
{
public:
    virtual IWalk* startWalking()=0;
    virtual ~IWalk()
    {}
};


class FastWalking : public IWalk
{
public:
    IWalk* startWalking()override
    {
        qDebug()<<"fast walking";
        return this;
    }
};

class SlowWalking : public IWalk
{
public:
    IWalk* startWalking()override
    {
        qDebug()<<"slow walking";
        return this;
    }
};


class IWalkFactory
{
public:
    virtual IWalk* newWalking()=0;
    virtual ~IWalkFactory(){};
};

class FastWalkingFactory : public IWalkFactory
{
public:
    IWalk* newWalking()override
    {
        walk = new FastWalking;
        return std::move(walk);
    }
    ~FastWalkingFactory()
    {
        delete walk;
    }

private:
    IWalk* walk;
};

class SlowWalkingFactory : public IWalkFactory
{
public:
    IWalk* newWalking()override
    {
        walk = new SlowWalking;
        return std::move(walk);
    }
    ~SlowWalkingFactory()
    {
        delete walk;
    }

private:
    IWalk* walk;
};


class WalkFactory
{
public:
    enum walkMode
    {
        Fast,
        Slow
    };
    WalkFactory()
    {
        walkFactories[Fast] = new FastWalkingFactory;
        walkFactories[Slow] = new SlowWalkingFactory;
    }
    ~WalkFactory()
    {
        delete walkFactories[Fast];
        delete walkFactories[Slow];
    }
    IWalk* newWalking(walkMode mode)
    {
        return walkFactories[mode]->newWalking();
    }

private:
    std::map<int, IWalkFactory*> walkFactories;
};
