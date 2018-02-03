#pragma once


class NormalVariable
{
    private :
        std::default_random_engine generator;
        std::normal_distribution<double> distribution;
    public :
        double nextVal();

        NormalVariable(double avg, double stdDev);
        virtual ~NormalVariable();

};
