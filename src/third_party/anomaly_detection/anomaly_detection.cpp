/**
 * Copyright (c) 2015, Jozef Stefan Institute, Quintelligence d.o.o. and contributors
 * All rights reserved.
 *
 * This source code is licensed under the FreeBSD license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "anomaly_detection.h"

#define MAX_INVALID_LEN 100

namespace TAd {

//TFloatWndVec::TFloatWndVec(const int MaxLen) {
//    MaxWndLen = MaxLen;
//    StartValidData = 0;
//}
//void TFloatWndVec::Reset() {
//    Vals.Clr();
//    StartValidData = 0;
//}
//void TFloatWndVec::Add(const TUInt64& Tm, const double Val) {
//    Vals.Add(TPair<TUInt64, TFlt>(Tm, Val));
//    if (MaxWndLen > 0) {
//        while (Vals.Len() - StartValidData > MaxWndLen) {
//            StartValidData++;
//        }
//        if (StartValidData > MAX_INVALID_LEN) {
//            Vals.DelMemCpy(0, StartValidData - 1);
//            StartValidData = 0;
//        }
//    }
//}


TExtremeValuesDetector::TExtremeValuesDetector() {
    MaxWndLen = -1;
    MaxWndLenMSec = -1;
    StartValidData = 0;
}

TExtremeValuesDetector::TExtremeValuesDetector(const int Len, bool IsMsec) {
    MaxWndLen = (IsMsec ? -1 : Len);
    MaxWndLenMSec = (IsMsec ? Len : -1);
    StartValidData = 0;
}


bool TExtremeValuesDetector::Add(const TUInt64& Tm, const double Val) {
    // TODO run detection
    bool Res = true;
    Vals.Add(TPair<TUInt64, TFlt>(Tm, Val));
    if (MaxWndLen > 0) {
        while (Vals.Len() - StartValidData > MaxWndLen) {
            StartValidData++;
        }
        if (StartValidData > MAX_INVALID_LEN) {
            Vals.DelMemCpy(0, StartValidData - 1);
            StartValidData = 0;
        }
    } else if (MaxWndLenMSec > 0) {
        TUInt64 limit = Tm;
        limit = limit - MaxWndLenMSec;
        while (Vals[StartValidData].Val1 < limit) {
            StartValidData++;
        }
        if (StartValidData > MAX_INVALID_LEN) {
            Vals.DelMemCpy(0, StartValidData - 1);
            StartValidData = 0;
        }
    }
    return Res;
}

void TExtremeValuesDetector::Reset() {
    Vals.Clr();
    StartValidData = 0;
}

/////////////////////////////////////////////////////////////////////

TValueTrendDetector::TValueTrendDetector() {
}

/////////////////////////////////////////////////////////////////////

TFlowRateDetector::TFlowRateDetector() {
}

}
