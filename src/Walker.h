#pragma once

class Walker
{
    private :
        double x,y,z;

    public :
        void Walk();
	double B();
	
        Walker(double initX, double initY, double initZ);
        virtual ~Walker();
};
