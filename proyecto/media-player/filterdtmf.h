#ifndef FILTERDTMF_H
#define FILTERDTMF_H




enum VerticalDTMFValue{
    V697 = 697,
    V770 = 770,
    V852 = 852,
    V941 = 941
};

enum HorizontalDTMFValue{
    H1209 = 1209,
    H1336 = 1336,
    H1477 = 1477,
    H1633 = 1633
};


class FilterDTMF
{
    double *V;
    double *H;
    double *historyV;
    unsigned int sizeV;
    unsigned int lastV;

    double *historyH;
    unsigned int sizeH;
    unsigned int lastH;

public:
    FilterDTMF(VerticalDTMFValue freqV,HorizontalDTMFValue freqH);
    void put(double);
    double getH();
    double getV();
    bool detected();
    ~FilterDTMF();

};

#endif // FILTERDTMF_H
