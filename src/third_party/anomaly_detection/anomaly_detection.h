/**
 * Copyright (c) 2015, Jozef Stefan Institute, Quintelligence d.o.o. and contributors
 * All rights reserved.
 *
 * This source code is licensed under the FreeBSD license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef ANOMALY_DETECTION_H_
#define ANOMALY_DETECTION_H_

#include "base.h"
#include "mine.h"

namespace TAd {

//class TFloatWndVec {
//private:
//    TVec<TPair<TUInt64, TFlt>> Vals;
//    TInt MaxWndLen;
//    TInt StartValidData;
//public:
//    TFloatWndVec(const int MaxLen);
//    void Add(const TUInt64& Tm, const double Val);    
//    void Reset();
//};

class TExtremeValuesDetector {
private:
    TVec<TPair<TUInt64, TFlt>> Vals;
    TInt MaxWndLen;
    TInt MaxWndLenMSec;
    TInt StartValidData;
public:
    TExtremeValuesDetector();
    TExtremeValuesDetector(const int Len, bool IsMsec);
    bool Add(const TUInt64& Tm, const double Val);
    void Reset();
};

class TValueTrendDetector {
private:
    TVec<TPair<TUInt64, TFlt>> Vals;
    TInt CurrWnd;
    TInt HistWnd;
    TInt StartValidData;
public:
    TValueTrendDetector();
};

class TFlowRateDetector {
private:
public:
    TFlowRateDetector();
};

}

#endif
