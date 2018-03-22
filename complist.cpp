#include "complist.h"

CompList::CompList():
    mfr(""), make(""),
    RType("Desktop"),
    PS(0), MB("ATX"),
    USB(0), in_stock(0),
    Price(0)
{
}
CompList::CompList(QString recMfr, QString recMake, QString kType, int recPS, QString kMB, int recUSB, int rec_in_stock, int recPrice):
    mfr(recMfr), make(recMake),
    RType(kType), PS(recPS),
    MB(kMB), USB(recUSB),
    in_stock(rec_in_stock),
    Price(recPrice)
{
}

void CompList::setMfr(const QString recMfr)
{
    mfr = recMfr;
}

QString CompList::getMfr() const
{
    return mfr;
}

void CompList::setMake(const QString recMake)
{
    make = recMake;
}

QString CompList::getMake() const
{
    return make;
}

void CompList::setRType(const QString kType)
{
    RType = kType;
}

QString CompList::getRType() const
{
    return RType;
}



void CompList::setPS(const int recPS)
{
    PS = recPS;
}

int CompList::getPS() const
{
    return PS;
}

void CompList::setMB(const QString kMB)
{
    MB = kMB;
}

QString CompList::getMB() const
{
    return MB;
}



void CompList::setUSB(const int rUSB)
{
    USB = rUSB;
}

int CompList::getUSB() const
{
    return USB;
}

void CompList::set_in_stock(const int rec_in_stock)
{
    in_stock = rec_in_stock;
}

int CompList::get_in_stock() const
{
    return in_stock;
}

void CompList::setPrice(const double rPrice)
{
    Price = rPrice;
}

double CompList::getPrice() const
{
    return Price;
}
