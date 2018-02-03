#pragma once

class Walker
{
    private :
        double x,y,z;

    public :


        void Walk();

        Walker(double initX, double initY, double initZ);
        virtual ~Walker();
};
