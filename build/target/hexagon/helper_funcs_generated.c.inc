int32_t HELPER(A4_tlbmatch)(CPUHexagonState *env, int64_t RssV, int32_t RtV)
{
    int32_t PdV = 0;
    { fHIDE(size4u_t TLBHI; size4u_t TLBLO; size4u_t MASK; size4u_t SIZE;) MASK = 0x07ffffff; TLBLO = fGETUWORD(0,RssV); TLBHI = fGETUWORD(1,RssV); SIZE = fMIN(6,fCL1_4(~fBREV_4(TLBLO))); MASK &= (0xffffffff << 2*SIZE); PdV = f8BITSOF(fGETBIT(31,TLBHI) && ((TLBHI & MASK) == (RtV & MASK))); }
    return PdV;
}

int64_t HELPER(S4_vrcrotate_acc)(CPUHexagonState *env, int64_t RxxV, int64_t RssV, int32_t RtV, int32_t uiV)
{
    { fHIDE(int i; int tmpr; int tmpi; unsigned int control;) fHIDE(int sumr; int sumi;) sumr = 0; sumi = 0; control = fGETUBYTE(uiV,RtV); for (i = 0; i < 8; i += 2) { tmpr = fGETBYTE(i ,RssV); tmpi = fGETBYTE(i+1,RssV); switch (control & 3) { case 0: sumr += tmpr; sumi += tmpi; break; case 1: sumr += tmpi; sumi -= tmpr; break; case 2: sumr -= tmpi; sumi += tmpr; break; case 3: sumr -= tmpr; sumi -= tmpi; break; fHIDE(default: fatal("C is broken!");) } control = control >> 2; } fSETWORD(0,RxxV,fGETWORD(0,RxxV) + sumr); fSETWORD(1,RxxV,fGETWORD(1,RxxV) + sumi); }
    return RxxV;
}

int64_t HELPER(S4_vrcrotate)(CPUHexagonState *env, int64_t RssV, int32_t RtV, int32_t uiV)
{
    int64_t RddV = 0;
    { fHIDE(int i; int tmpr; int tmpi; unsigned int control;) fHIDE(int sumr; int sumi;) sumr = 0; sumi = 0; control = fGETUBYTE(uiV,RtV); for (i = 0; i < 8; i += 2) { tmpr = fGETBYTE(i ,RssV); tmpi = fGETBYTE(i+1,RssV); switch (control & 3) { case 0: sumr += tmpr; sumi += tmpi; break; case 1: sumr += tmpi; sumi -= tmpr; break; case 2: sumr -= tmpi; sumi += tmpr; break; case 3: sumr -= tmpr; sumi -= tmpi; break; fHIDE(default: fatal("C is broken!");) } control = control >> 2; } fSETWORD(0,RddV,sumr); fSETWORD(1,RddV,sumi); }
    return RddV;
}

int32_t HELPER(M7_wcmpyrw)(CPUHexagonState *env, int64_t RssV, int64_t RttV, uint32_t pkt_need_commit)
{
    int32_t RdV = 0;
    { fHIDE(size16s_t acc128;)fHIDE(size16s_t tmp128;)fHIDE(size8s_t acc64;)tmp128 = fCAST8S_16S(fMPY32SS(fGETWORD(0, RssV), fGETWORD(0, RttV)));acc128 = fCAST8S_16S(fMPY32SS(fGETWORD(1, RssV), fGETWORD(1, RttV)));acc128 = fSUB128(tmp128,acc128);acc128 = fSHIFTR128(acc128, 31);acc64 = fCAST16S_8S(acc128);RdV = fSATW(acc64);}
    return RdV;
}

int32_t HELPER(M7_wcmpyrwc)(CPUHexagonState *env, int64_t RssV, int64_t RttV, uint32_t pkt_need_commit)
{
    int32_t RdV = 0;
    { fHIDE(size16s_t acc128;)fHIDE(size16s_t tmp128;)fHIDE(size8s_t acc64;)tmp128 = fCAST8S_16S(fMPY32SS(fGETWORD(0, RssV), fGETWORD(0, RttV)));acc128 = fCAST8S_16S(fMPY32SS(fGETWORD(1, RssV), fGETWORD(1, RttV)));acc128 = fADD128(tmp128,acc128);acc128 = fSHIFTR128(acc128, 31);acc64 = fCAST16S_8S(acc128);RdV = fSATW(acc64);}
    return RdV;
}

int32_t HELPER(M7_wcmpyiw)(CPUHexagonState *env, int64_t RssV, int64_t RttV, uint32_t pkt_need_commit)
{
    int32_t RdV = 0;
    { fHIDE(size16s_t acc128;)fHIDE(size16s_t tmp128;)fHIDE(size8s_t acc64;)tmp128 = fCAST8S_16S(fMPY32SS(fGETWORD(0, RssV), fGETWORD(1, RttV)));acc128 = fCAST8S_16S(fMPY32SS(fGETWORD(1, RssV), fGETWORD(0, RttV)));acc128 = fADD128(tmp128,acc128);acc128 = fSHIFTR128(acc128, 31);acc64 = fCAST16S_8S(acc128);RdV = fSATW(acc64);}
    return RdV;
}

int32_t HELPER(M7_wcmpyiwc)(CPUHexagonState *env, int64_t RssV, int64_t RttV, uint32_t pkt_need_commit)
{
    int32_t RdV = 0;
    { fHIDE(size16s_t acc128;)fHIDE(size16s_t tmp128;)fHIDE(size8s_t acc64;)tmp128 = fCAST8S_16S(fMPY32SS(fGETWORD(1, RssV), fGETWORD(0, RttV)));acc128 = fCAST8S_16S(fMPY32SS(fGETWORD(0, RssV), fGETWORD(1, RttV)));acc128 = fSUB128(tmp128,acc128);acc128 = fSHIFTR128(acc128, 31);acc64 = fCAST16S_8S(acc128);RdV = fSATW(acc64);}
    return RdV;
}

int32_t HELPER(M7_wcmpyrw_rnd)(CPUHexagonState *env, int64_t RssV, int64_t RttV, uint32_t pkt_need_commit)
{
    int32_t RdV = 0;
    { fHIDE(size16s_t acc128;)fHIDE(size16s_t tmp128;)fHIDE(size16s_t const128;)fHIDE(size8s_t acc64;)tmp128 = fCAST8S_16S(fMPY32SS(fGETWORD(0, RssV), fGETWORD(0, RttV)));acc128 = fCAST8S_16S(fMPY32SS(fGETWORD(1, RssV), fGETWORD(1, RttV)));const128 = fCAST8S_16S(fCONSTLL(0x40000000));acc128 = fSUB128(tmp128,acc128);acc128 = fADD128(acc128,const128);acc128 = fSHIFTR128(acc128, 31);acc64 = fCAST16S_8S(acc128);RdV = fSATW(acc64);}
    return RdV;
}

int32_t HELPER(M7_wcmpyrwc_rnd)(CPUHexagonState *env, int64_t RssV, int64_t RttV, uint32_t pkt_need_commit)
{
    int32_t RdV = 0;
    { fHIDE(size16s_t acc128;)fHIDE(size16s_t tmp128;)fHIDE(size16s_t const128;)fHIDE(size8s_t acc64;)tmp128 = fCAST8S_16S(fMPY32SS(fGETWORD(0, RssV), fGETWORD(0, RttV)));acc128 = fCAST8S_16S(fMPY32SS(fGETWORD(1, RssV), fGETWORD(1, RttV)));const128 = fCAST8S_16S(fCONSTLL(0x40000000));acc128 = fADD128(tmp128,acc128);acc128 = fADD128(acc128,const128);acc128 = fSHIFTR128(acc128, 31);acc64 = fCAST16S_8S(acc128);RdV = fSATW(acc64);}
    return RdV;
}

int32_t HELPER(M7_wcmpyiw_rnd)(CPUHexagonState *env, int64_t RssV, int64_t RttV, uint32_t pkt_need_commit)
{
    int32_t RdV = 0;
    { fHIDE(size16s_t acc128;)fHIDE(size16s_t tmp128;)fHIDE(size16s_t const128;)fHIDE(size8s_t acc64;)tmp128 = fCAST8S_16S(fMPY32SS(fGETWORD(0, RssV), fGETWORD(1, RttV)));acc128 = fCAST8S_16S(fMPY32SS(fGETWORD(1, RssV), fGETWORD(0, RttV)));const128 = fCAST8S_16S(fCONSTLL(0x40000000));acc128 = fADD128(tmp128,acc128);acc128 = fADD128(acc128,const128);acc128 = fSHIFTR128(acc128, 31);acc64 = fCAST16S_8S(acc128);RdV = fSATW(acc64);}
    return RdV;
}

int32_t HELPER(M7_wcmpyiwc_rnd)(CPUHexagonState *env, int64_t RssV, int64_t RttV, uint32_t pkt_need_commit)
{
    int32_t RdV = 0;
    { fHIDE(size16s_t acc128;)fHIDE(size16s_t tmp128;)fHIDE(size16s_t const128;)fHIDE(size8s_t acc64;)tmp128 = fCAST8S_16S(fMPY32SS(fGETWORD(1, RssV), fGETWORD(0, RttV)));acc128 = fCAST8S_16S(fMPY32SS(fGETWORD(0, RssV), fGETWORD(1, RttV)));const128 = fCAST8S_16S(fCONSTLL(0x40000000));acc128 = fSUB128(tmp128,acc128);acc128 = fADD128(acc128,const128);acc128 = fSHIFTR128(acc128, 31);acc64 = fCAST16S_8S(acc128);RdV = fSATW(acc64);}
    return RdV;
}

int64_t HELPER(A7_croundd_ri)(CPUHexagonState *env, int64_t RssV, int32_t uiV)
{
    int64_t RddV = 0;
    { fHIDE(size16s_t rndbit_128;) fHIDE(size16s_t tmp128;) fHIDE(size16s_t src_128;) if (uiV == 0) { RddV = RssV; } else if ((RssV & (size8s_t)((1LL << (uiV - 1)) - 1LL)) == 0) { src_128 = fCAST8S_16S(RssV); rndbit_128 = fCAST8S_16S(1LL); rndbit_128 = fSHIFTL128(rndbit_128, uiV); rndbit_128 = fAND128(rndbit_128, src_128); rndbit_128 = fSHIFTR128(rndbit_128, 1); tmp128 = fADD128(src_128, rndbit_128); tmp128 = fSHIFTR128(tmp128, uiV); RddV = fCAST16S_8S(tmp128); } else { rndbit_128 = fCAST8S_16S((1LL << (uiV - 1))); src_128 = fCAST8S_16S(RssV); tmp128 = fADD128(src_128, rndbit_128); tmp128 = fSHIFTR128(tmp128, uiV); RddV = fCAST16S_8S(tmp128); }; }
    return RddV;
}

int64_t HELPER(A7_croundd_rr)(CPUHexagonState *env, int64_t RssV, int32_t RtV)
{
    int64_t RddV = 0;
    { fHIDE(size16s_t rndbit_128;) fHIDE(size16s_t tmp128;) fHIDE(size16s_t src_128;) if (fZXTN(6,32,RtV) == 0) { RddV = RssV; } else if ((RssV & (size8s_t)((1LL << (fZXTN(6,32,RtV) - 1)) - 1LL)) == 0) { src_128 = fCAST8S_16S(RssV); rndbit_128 = fCAST8S_16S(1LL); rndbit_128 = fSHIFTL128(rndbit_128, fZXTN(6,32,RtV)); rndbit_128 = fAND128(rndbit_128, src_128); rndbit_128 = fSHIFTR128(rndbit_128, 1); tmp128 = fADD128(src_128, rndbit_128); tmp128 = fSHIFTR128(tmp128, fZXTN(6,32,RtV)); RddV = fCAST16S_8S(tmp128); } else { rndbit_128 = fCAST8S_16S((1LL << (fZXTN(6,32,RtV) - 1))); src_128 = fCAST8S_16S(RssV); tmp128 = fADD128(src_128, rndbit_128); tmp128 = fSHIFTR128(tmp128, fZXTN(6,32,RtV)); RddV = fCAST16S_8S(tmp128); }; }
    return RddV;
}

int32_t HELPER(S2_brev)(CPUHexagonState *env, int32_t RsV)
{
    int32_t RdV = 0;
    {RdV = fBREV_4(RsV);}
    return RdV;
}

int64_t HELPER(S2_brevp)(CPUHexagonState *env, int64_t RssV)
{
    int64_t RddV = 0;
    {RddV = fBREV_8(RssV);}
    return RddV;
}

int64_t HELPER(S2_interleave)(CPUHexagonState *env, int64_t RssV)
{
    int64_t RddV = 0;
    {RddV = fINTERLEAVE(fGETWORD(1,RssV),fGETWORD(0,RssV));}
    return RddV;
}

int64_t HELPER(S2_deinterleave)(CPUHexagonState *env, int64_t RssV)
{
    int64_t RddV = 0;
    {RddV = fDEINTERLEAVE(RssV);}
    return RddV;
}

void HELPER(V6_valignb)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { unsigned shift = RtV & (fVBYTES()-1); fHIDE(int i;) for(i = 0; i < fVBYTES(); i++) { VdV.ub[i] = (i+shift>=fVBYTES()) ? VuV.ub[i+shift-fVBYTES()] : VvV.ub[i+shift]; } }
}

void HELPER(V6_vlalignb)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { unsigned shift = fVBYTES() - (RtV & (fVBYTES()-1)); fHIDE(int i;) for(i = 0; i < fVBYTES(); i++) { VdV.ub[i] = (i+shift>=fVBYTES()) ? VuV.ub[i+shift-fVBYTES()] : VvV.ub[i+shift]; } }
}

void HELPER(V6_valignbi)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void, int32_t uiV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) for(i = 0; i < fVBYTES(); i++) { VdV.ub[i] = (i+uiV>=fVBYTES()) ? VuV.ub[i+uiV-fVBYTES()] : VvV.ub[i+uiV]; } }
}

void HELPER(V6_vlalignbi)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void, int32_t uiV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { unsigned shift = fVBYTES() - uiV; fHIDE(int i;) for(i = 0; i < fVBYTES(); i++) { VdV.ub[i] = (i+shift>=fVBYTES()) ? VuV.ub[i+shift-fVBYTES()] : VvV.ub[i+shift]; } }
}

void HELPER(V6_vror)(CPUHexagonState *env, void * VdV_void, void * VuV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int k;) for (k=0;k<fVBYTES();k++) { VdV.ub[k] = VuV.ub[(k+RtV)&(fVBYTES()-1)]; } }
}

void HELPER(V6_vunpackub)(CPUHexagonState *env, void * VddV_void, void * VuV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { fVARRAY_ELEMENT_ACCESS(VddV, uh, i) = fZE8_16( VuV.ub[i]) ; } }
}

void HELPER(V6_vunpackb)(CPUHexagonState *env, void * VddV_void, void * VuV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { fVARRAY_ELEMENT_ACCESS(VddV, h, i) = fSE8_16( VuV.b[i] ) ; } }
}

void HELPER(V6_vunpackuh)(CPUHexagonState *env, void * VddV_void, void * VuV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fVARRAY_ELEMENT_ACCESS(VddV, uw, i) = fZE16_32(VuV.uh[i]) ; } }
}

void HELPER(V6_vunpackh)(CPUHexagonState *env, void * VddV_void, void * VuV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fVARRAY_ELEMENT_ACCESS(VddV, w, i) = fSE16_32(VuV.h[i] ) ; } }
}

void HELPER(V6_vunpackob)(CPUHexagonState *env, void * VxxV_void, void * VuV_void)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { fVARRAY_ELEMENT_ACCESS(VxxV, uh, i) |= fZE8_16( VuV.ub[i])<<8 ; } }
}

void HELPER(V6_vunpackoh)(CPUHexagonState *env, void * VxxV_void, void * VuV_void)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fVARRAY_ELEMENT_ACCESS(VxxV, uw, i) |= fZE16_32(VuV.uh[i])<<16 ; } }
}

void HELPER(V6_vpackeb)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.ub[i] = fGETUBYTE(0, VvV.uh[i]); VdV.ub[i+fVELEM(16)] = fGETUBYTE(0, VuV.uh[i]) ; } }
}

void HELPER(V6_vpackeh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.uh[i] = fGETUHALF(0, VvV.uw[i]); VdV.uh[i+fVELEM(32)] = fGETUHALF(0, VuV.uw[i]) ; } }
}

void HELPER(V6_vpackob)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.ub[i] = fGETUBYTE(1, VvV.uh[i]); VdV.ub[i+fVELEM(16)] = fGETUBYTE(1, VuV.uh[i]) ; } }
}

void HELPER(V6_vpackoh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.uh[i] = fGETUHALF(1, VvV.uw[i]); VdV.uh[i+fVELEM(32)] = fGETUHALF(1, VuV.uw[i]) ; } }
}

void HELPER(V6_vpackhub_sat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.ub[i] = fVSATUB(VvV.h[i]); VdV.ub[i+fVELEM(16)] = fVSATUB(VuV.h[i]) ; } }
}

void HELPER(V6_vpackhb_sat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.b[i] = fVSATB(VvV.h[i]); VdV.b[i+fVELEM(16)] = fVSATB(VuV.h[i]) ; } }
}

void HELPER(V6_vpackwuh_sat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.uh[i] = fVSATUH(VvV.w[i]); VdV.uh[i+fVELEM(32)] = fVSATUH(VuV.w[i]) ; } }
}

void HELPER(V6_vpackwh_sat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.h[i] = fVSATH(VvV.w[i]); VdV.h[i+fVELEM(32)] = fVSATH(VuV.w[i]) ; } }
}

void HELPER(V6_vzb)(CPUHexagonState *env, void * VddV_void, void * VuV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VddV.v[0].uh[i] = fZE8_16(fGETUBYTE(0, VuV.uh[i])); VddV.v[1].uh[i] = fZE8_16(fGETUBYTE(1, VuV.uh[i])) ; } }
}

void HELPER(V6_vsb)(CPUHexagonState *env, void * VddV_void, void * VuV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VddV.v[0].h[i] = fSE8_16(fGETBYTE(0, VuV.h[i])); VddV.v[1].h[i] = fSE8_16(fGETBYTE(1, VuV.h[i])) ; } }
}

void HELPER(V6_vzh)(CPUHexagonState *env, void * VddV_void, void * VuV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].uw[i] = fZE16_32(fGETUHALF(0, VuV.uw[i])); VddV.v[1].uw[i] = fZE16_32(fGETUHALF(1, VuV.uw[i])) ; } }
}

void HELPER(V6_vsh)(CPUHexagonState *env, void * VddV_void, void * VuV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].w[i] = fSE16_32(fGETHALF(0, VuV.w[i])); VddV.v[1].w[i] = fSE16_32(fGETHALF(1, VuV.w[i])) ; } }
}

void HELPER(V6_vdmpybus)(CPUHexagonState *env, void * VdV_void, void * VuV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.h[i] = fMPY8US( fGETUBYTE(0, VuV.uh[i]), fGETBYTE((2*i) % 4, RtV)); VdV.h[i] += fMPY8US( fGETUBYTE(1, VuV.uh[i]), fGETBYTE((2*i+1)%4, RtV)) ; } }
}

void HELPER(V6_vdmpybus_acc)(CPUHexagonState *env, void * VxV_void, void * VuV_void, int32_t RtV)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VxV.h[i] += fMPY8US( fGETUBYTE(0, VuV.uh[i]), fGETBYTE((2*i) % 4, RtV)); VxV.h[i] += fMPY8US( fGETUBYTE(1, VuV.uh[i]), fGETBYTE((2*i+1)%4, RtV)) ; } }
}

void HELPER(V6_vdmpybus_dv)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, int32_t RtV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VddV.v[0].h[i] = fMPY8US(fGETUBYTE(0, VuuV.v[0].uh[i]),fGETBYTE((2*i) % 4, RtV)); VddV.v[0].h[i] += fMPY8US(fGETUBYTE(1, VuuV.v[0].uh[i]),fGETBYTE((2*i+1)%4, RtV)); VddV.v[1].h[i] = fMPY8US(fGETUBYTE(1, VuuV.v[0].uh[i]),fGETBYTE((2*i) % 4, RtV)); VddV.v[1].h[i] += fMPY8US(fGETUBYTE(0, VuuV.v[1].uh[i]),fGETBYTE((2*i+1)%4, RtV)) ; } }
}

void HELPER(V6_vdmpybus_dv_acc)(CPUHexagonState *env, void * VxxV_void, void * VuuV_void, int32_t RtV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VxxV.v[0].h[i] += fMPY8US(fGETUBYTE(0, VuuV.v[0].uh[i]),fGETBYTE((2*i) % 4, RtV)); VxxV.v[0].h[i] += fMPY8US(fGETUBYTE(1, VuuV.v[0].uh[i]),fGETBYTE((2*i+1)%4, RtV)); VxxV.v[1].h[i] += fMPY8US(fGETUBYTE(1, VuuV.v[0].uh[i]),fGETBYTE((2*i) % 4, RtV)); VxxV.v[1].h[i] += fMPY8US(fGETUBYTE(0, VuuV.v[1].uh[i]),fGETBYTE((2*i+1)%4, RtV)) ; } }
}

void HELPER(V6_vdmpyhb)(CPUHexagonState *env, void * VdV_void, void * VuV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = fMPY16SS(fGETHALF(0, VuV.w[i]),fGETBYTE((2*i+0)%4, RtV)); VdV.w[i] += fMPY16SS(fGETHALF(1, VuV.w[i]),fGETBYTE((2*i+1)%4, RtV)) ; } }
}

void HELPER(V6_vdmpyhb_acc)(CPUHexagonState *env, void * VxV_void, void * VuV_void, int32_t RtV)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxV.w[i] += fMPY16SS(fGETHALF(0, VuV.w[i]),fGETBYTE((2*i+0)%4, RtV)); VxV.w[i] += fMPY16SS(fGETHALF(1, VuV.w[i]),fGETBYTE((2*i+1)%4, RtV)) ; } }
}

void HELPER(V6_vdmpyhb_dv)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, int32_t RtV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].w[i] = fMPY16SS(fGETHALF(0, VuuV.v[0].w[i]),fGETBYTE((2*i+0)%4, RtV)); VddV.v[0].w[i] += fMPY16SS(fGETHALF(1, VuuV.v[0].w[i]),fGETBYTE((2*i+1)%4, RtV)); VddV.v[1].w[i] = fMPY16SS(fGETHALF(1, VuuV.v[0].w[i]),fGETBYTE((2*i+0)%4, RtV)); VddV.v[1].w[i] += fMPY16SS(fGETHALF(0, VuuV.v[1].w[i]),fGETBYTE((2*i+1)%4, RtV)) ; } }
}

void HELPER(V6_vdmpyhb_dv_acc)(CPUHexagonState *env, void * VxxV_void, void * VuuV_void, int32_t RtV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxxV.v[0].w[i] += fMPY16SS(fGETHALF(0, VuuV.v[0].w[i]),fGETBYTE((2*i+0)%4, RtV)); VxxV.v[0].w[i] += fMPY16SS(fGETHALF(1, VuuV.v[0].w[i]),fGETBYTE((2*i+1)%4, RtV)); VxxV.v[1].w[i] += fMPY16SS(fGETHALF(1, VuuV.v[0].w[i]),fGETBYTE((2*i+0)%4, RtV)); VxxV.v[1].w[i] += fMPY16SS(fGETHALF(0, VuuV.v[1].w[i]),fGETBYTE((2*i+1)%4, RtV)) ; } }
}

void HELPER(V6_vdmpyhvsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(size8s_t accum;) accum = fMPY16SS(fGETHALF(0,VuV.w[i]),fGETHALF(0, VvV.w[i])); accum += fMPY16SS(fGETHALF(1,VuV.w[i]),fGETHALF(1, VvV.w[i])); VdV.w[i] = fVSATW(accum) ; } }
}

void HELPER(V6_vdmpyhvsat_acc)(CPUHexagonState *env, void * VxV_void, void * VuV_void, void * VvV_void)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(size8s_t accum;) accum = fMPY16SS(fGETHALF(0,VuV.w[i]),fGETHALF(0, VvV.w[i])); accum += fMPY16SS(fGETHALF(1,VuV.w[i]),fGETHALF(1, VvV.w[i])); VxV.w[i] = fVSATW(VxV.w[i]+accum) ; } }
}

void HELPER(V6_vdmpyhsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(size8s_t accum;) accum = fMPY16SS(fGETHALF(0, VuV.w[i]),fGETHALF(0, RtV)); accum += fMPY16SS(fGETHALF(1, VuV.w[i]),fGETHALF(1, RtV)); VdV.w[i] = fVSATW(accum) ; } }
}

void HELPER(V6_vdmpyhsat_acc)(CPUHexagonState *env, void * VxV_void, void * VuV_void, int32_t RtV)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(size8s_t) accum = VxV.w[i]; accum += fMPY16SS(fGETHALF(0, VuV.w[i]),fGETHALF(0, RtV)); accum += fMPY16SS(fGETHALF(1, VuV.w[i]),fGETHALF(1, RtV)); VxV.w[i] = fVSATW(accum) ; } }
}

void HELPER(V6_vdmpyhisat)(CPUHexagonState *env, void * VdV_void, void * VuuV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(size8s_t accum;) accum = fMPY16SS(fGETHALF(1,VuuV.v[0].w[i]),fGETHALF(0,RtV)); accum += fMPY16SS(fGETHALF(0,VuuV.v[1].w[i]),fGETHALF(1,RtV)); VdV.w[i] = fVSATW(accum) ; } }
}

void HELPER(V6_vdmpyhisat_acc)(CPUHexagonState *env, void * VxV_void, void * VuuV_void, int32_t RtV)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(size8s_t) accum = VxV.w[i]; accum += fMPY16SS(fGETHALF(1,VuuV.v[0].w[i]),fGETHALF(0,RtV)); accum += fMPY16SS(fGETHALF(0,VuuV.v[1].w[i]),fGETHALF(1,RtV)); VxV.w[i] = fVSATW(accum) ; } }
}

void HELPER(V6_vdmpyhsusat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(size8s_t accum;) accum = fMPY16SU(fGETHALF(0, VuV.w[i]),fGETUHALF(0, RtV)); accum += fMPY16SU(fGETHALF(1, VuV.w[i]),fGETUHALF(1, RtV)); VdV.w[i] = fVSATW(accum) ; } }
}

void HELPER(V6_vdmpyhsusat_acc)(CPUHexagonState *env, void * VxV_void, void * VuV_void, int32_t RtV)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(size8s_t) accum=VxV.w[i]; accum += fMPY16SU(fGETHALF(0, VuV.w[i]),fGETUHALF(0, RtV)); accum += fMPY16SU(fGETHALF(1, VuV.w[i]),fGETUHALF(1, RtV)); VxV.w[i] = fVSATW(accum) ; } }
}

void HELPER(V6_vdmpyhsuisat)(CPUHexagonState *env, void * VdV_void, void * VuuV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(size8s_t accum;) accum = fMPY16SU(fGETHALF(1,VuuV.v[0].w[i]),fGETUHALF(0,RtV)); accum += fMPY16SU(fGETHALF(0,VuuV.v[1].w[i]),fGETUHALF(1,RtV)); VdV.w[i] = fVSATW(accum) ; } }
}

void HELPER(V6_vdmpyhsuisat_acc)(CPUHexagonState *env, void * VxV_void, void * VuuV_void, int32_t RtV)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(size8s_t) accum=VxV.w[i]; accum += fMPY16SU(fGETHALF(1, VuuV.v[0].w[i]),fGETUHALF(0,RtV)); accum += fMPY16SU(fGETHALF(0, VuuV.v[1].w[i]),fGETUHALF(1,RtV)); VxV.w[i] = fVSATW(accum) ; } }
}

void HELPER(V6_vtmpyb)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, int32_t RtV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VddV.v[0].h[i] = fMPY8SS(fGETBYTE(0,VuuV.v[0].h[i]), fGETBYTE((2*i )%4, RtV)); VddV.v[0].h[i] += fMPY8SS(fGETBYTE(1,VuuV.v[0].h[i]), fGETBYTE((2*i+1)%4, RtV)); VddV.v[0].h[i] += fGETBYTE(0,VuuV.v[1].h[i]); VddV.v[1].h[i] = fMPY8SS(fGETBYTE(1,VuuV.v[0].h[i]), fGETBYTE((2*i )%4, RtV)); VddV.v[1].h[i] += fMPY8SS(fGETBYTE(0,VuuV.v[1].h[i]), fGETBYTE((2*i+1)%4, RtV)); VddV.v[1].h[i] += fGETBYTE(1,VuuV.v[1].h[i]) ; } }
}

void HELPER(V6_vtmpyb_acc)(CPUHexagonState *env, void * VxxV_void, void * VuuV_void, int32_t RtV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VxxV.v[0].h[i] += fMPY8SS(fGETBYTE(0,VuuV.v[0].h[i]), fGETBYTE((2*i )%4, RtV)); VxxV.v[0].h[i] += fMPY8SS(fGETBYTE(1,VuuV.v[0].h[i]), fGETBYTE((2*i+1)%4, RtV)); VxxV.v[0].h[i] += fGETBYTE(0,VuuV.v[1].h[i]); VxxV.v[1].h[i] += fMPY8SS(fGETBYTE(1,VuuV.v[0].h[i]), fGETBYTE((2*i )%4, RtV)); VxxV.v[1].h[i] += fMPY8SS(fGETBYTE(0,VuuV.v[1].h[i]), fGETBYTE((2*i+1)%4, RtV)); VxxV.v[1].h[i] += fGETBYTE(1,VuuV.v[1].h[i]) ; } }
}

void HELPER(V6_vtmpybus)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, int32_t RtV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VddV.v[0].h[i] = fMPY8US(fGETUBYTE(0,VuuV.v[0].uh[i]), fGETBYTE((2*i )%4, RtV)); VddV.v[0].h[i] += fMPY8US(fGETUBYTE(1,VuuV.v[0].uh[i]), fGETBYTE((2*i+1)%4, RtV)); VddV.v[0].h[i] += fGETUBYTE(0,VuuV.v[1].uh[i]); VddV.v[1].h[i] = fMPY8US(fGETUBYTE(1,VuuV.v[0].uh[i]), fGETBYTE((2*i )%4, RtV)); VddV.v[1].h[i] += fMPY8US(fGETUBYTE(0,VuuV.v[1].uh[i]), fGETBYTE((2*i+1)%4, RtV)); VddV.v[1].h[i] += fGETUBYTE(1,VuuV.v[1].uh[i]) ; } }
}

void HELPER(V6_vtmpybus_acc)(CPUHexagonState *env, void * VxxV_void, void * VuuV_void, int32_t RtV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VxxV.v[0].h[i] += fMPY8US(fGETUBYTE(0,VuuV.v[0].uh[i]), fGETBYTE((2*i )%4, RtV)); VxxV.v[0].h[i] += fMPY8US(fGETUBYTE(1,VuuV.v[0].uh[i]), fGETBYTE((2*i+1)%4, RtV)); VxxV.v[0].h[i] += fGETUBYTE(0,VuuV.v[1].uh[i]); VxxV.v[1].h[i] += fMPY8US(fGETUBYTE(1,VuuV.v[0].uh[i]), fGETBYTE((2*i )%4, RtV)); VxxV.v[1].h[i] += fMPY8US(fGETUBYTE(0,VuuV.v[1].uh[i]), fGETBYTE((2*i+1)%4, RtV)); VxxV.v[1].h[i] += fGETUBYTE(1,VuuV.v[1].uh[i]) ; } }
}

void HELPER(V6_vtmpyhb)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, int32_t RtV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].w[i] = fMPY16SS(fGETHALF(0,VuuV.v[0].w[i]), fSE8_16(fGETBYTE((2*i+0)%4, RtV))); VddV.v[0].w[i]+= fMPY16SS(fGETHALF(1,VuuV.v[0].w[i]), fSE8_16(fGETBYTE((2*i+1)%4, RtV))); VddV.v[0].w[i]+= fGETHALF(0,VuuV.v[1].w[i]); VddV.v[1].w[i] = fMPY16SS(fGETHALF(1,VuuV.v[0].w[i]), fSE8_16(fGETBYTE((2*i+0)%4, RtV))); VddV.v[1].w[i]+= fMPY16SS(fGETHALF(0,VuuV.v[1].w[i]), fSE8_16(fGETBYTE((2*i+1)%4, RtV))); VddV.v[1].w[i]+= fGETHALF(1,VuuV.v[1].w[i]) ; } }
}

void HELPER(V6_vtmpyhb_acc)(CPUHexagonState *env, void * VxxV_void, void * VuuV_void, int32_t RtV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxxV.v[0].w[i]+= fMPY16SS(fGETHALF(0,VuuV.v[0].w[i]), fSE8_16(fGETBYTE((2*i+0)%4, RtV))); VxxV.v[0].w[i]+= fMPY16SS(fGETHALF(1,VuuV.v[0].w[i]), fSE8_16(fGETBYTE((2*i+1)%4, RtV))); VxxV.v[0].w[i]+= fGETHALF(0,VuuV.v[1].w[i]); VxxV.v[1].w[i]+= fMPY16SS(fGETHALF(1,VuuV.v[0].w[i]), fSE8_16(fGETBYTE((2*i+0)%4, RtV))); VxxV.v[1].w[i]+= fMPY16SS(fGETHALF(0,VuuV.v[1].w[i]), fSE8_16(fGETBYTE((2*i+1)%4, RtV))); VxxV.v[1].w[i]+= fGETHALF(1,VuuV.v[1].w[i]) ; } }
}

void HELPER(V6_vrmpyub)(CPUHexagonState *env, void * VdV_void, void * VuV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.uw[i] = fMPY8UU(fGETUBYTE(0,VuV.uw[i]), fGETUBYTE(0,RtV)); VdV.uw[i] += fMPY8UU(fGETUBYTE(1,VuV.uw[i]), fGETUBYTE(1,RtV)); VdV.uw[i] += fMPY8UU(fGETUBYTE(2,VuV.uw[i]), fGETUBYTE(2,RtV)); VdV.uw[i] += fMPY8UU(fGETUBYTE(3,VuV.uw[i]), fGETUBYTE(3,RtV)) ; } }
}

void HELPER(V6_vrmpyub_acc)(CPUHexagonState *env, void * VxV_void, void * VuV_void, int32_t RtV)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxV.uw[i] += fMPY8UU(fGETUBYTE(0,VuV.uw[i]), fGETUBYTE(0,RtV)); VxV.uw[i] += fMPY8UU(fGETUBYTE(1,VuV.uw[i]), fGETUBYTE(1,RtV)); VxV.uw[i] += fMPY8UU(fGETUBYTE(2,VuV.uw[i]), fGETUBYTE(2,RtV)); VxV.uw[i] += fMPY8UU(fGETUBYTE(3,VuV.uw[i]), fGETUBYTE(3,RtV)) ; } }
}

void HELPER(V6_vrmpyubv)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.uw[i] = fMPY8UU(fGETUBYTE(0,VuV.uw[i]), fGETUBYTE(0,VvV.uw[i])); VdV.uw[i] += fMPY8UU(fGETUBYTE(1,VuV.uw[i]), fGETUBYTE(1,VvV.uw[i])); VdV.uw[i] += fMPY8UU(fGETUBYTE(2,VuV.uw[i]), fGETUBYTE(2,VvV.uw[i])); VdV.uw[i] += fMPY8UU(fGETUBYTE(3,VuV.uw[i]), fGETUBYTE(3,VvV.uw[i])) ; } }
}

void HELPER(V6_vrmpyubv_acc)(CPUHexagonState *env, void * VxV_void, void * VuV_void, void * VvV_void)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxV.uw[i] += fMPY8UU(fGETUBYTE(0,VuV.uw[i]), fGETUBYTE(0,VvV.uw[i])); VxV.uw[i] += fMPY8UU(fGETUBYTE(1,VuV.uw[i]), fGETUBYTE(1,VvV.uw[i])); VxV.uw[i] += fMPY8UU(fGETUBYTE(2,VuV.uw[i]), fGETUBYTE(2,VvV.uw[i])); VxV.uw[i] += fMPY8UU(fGETUBYTE(3,VuV.uw[i]), fGETUBYTE(3,VvV.uw[i])) ; } }
}

void HELPER(V6_vrmpybv)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = fMPY8SS(fGETBYTE(0, VuV.w[i]), fGETBYTE(0, VvV.w[i])); VdV.w[i] += fMPY8SS(fGETBYTE(1, VuV.w[i]), fGETBYTE(1, VvV.w[i])); VdV.w[i] += fMPY8SS(fGETBYTE(2, VuV.w[i]), fGETBYTE(2, VvV.w[i])); VdV.w[i] += fMPY8SS(fGETBYTE(3, VuV.w[i]), fGETBYTE(3, VvV.w[i])) ; } }
}

void HELPER(V6_vrmpybv_acc)(CPUHexagonState *env, void * VxV_void, void * VuV_void, void * VvV_void)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxV.w[i] += fMPY8SS(fGETBYTE(0, VuV.w[i]), fGETBYTE(0, VvV.w[i])); VxV.w[i] += fMPY8SS(fGETBYTE(1, VuV.w[i]), fGETBYTE(1, VvV.w[i])); VxV.w[i] += fMPY8SS(fGETBYTE(2, VuV.w[i]), fGETBYTE(2, VvV.w[i])); VxV.w[i] += fMPY8SS(fGETBYTE(3, VuV.w[i]), fGETBYTE(3, VvV.w[i])) ; } }
}

void HELPER(V6_vrmpyubi)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, int32_t RtV, int32_t uiV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].uw[i] = fMPY8UU(fGETUBYTE(0, VuuV.v[uiV ? 1:0].uw[i]),fGETUBYTE((0-uiV) & 0x3,RtV)); VddV.v[0].uw[i] += fMPY8UU(fGETUBYTE(1, VuuV.v[0 ].uw[i]),fGETUBYTE((1-uiV) & 0x3,RtV)); VddV.v[0].uw[i] += fMPY8UU(fGETUBYTE(2, VuuV.v[0 ].uw[i]),fGETUBYTE((2-uiV) & 0x3,RtV)); VddV.v[0].uw[i] += fMPY8UU(fGETUBYTE(3, VuuV.v[0 ].uw[i]),fGETUBYTE((3-uiV) & 0x3,RtV)); VddV.v[1].uw[i] = fMPY8UU(fGETUBYTE(0, VuuV.v[1 ].uw[i]),fGETUBYTE((2-uiV) & 0x3,RtV)); VddV.v[1].uw[i] += fMPY8UU(fGETUBYTE(1, VuuV.v[1 ].uw[i]),fGETUBYTE((3-uiV) & 0x3,RtV)); VddV.v[1].uw[i] += fMPY8UU(fGETUBYTE(2, VuuV.v[uiV ? 1:0].uw[i]),fGETUBYTE((0-uiV) & 0x3,RtV)); VddV.v[1].uw[i] += fMPY8UU(fGETUBYTE(3, VuuV.v[0 ].uw[i]),fGETUBYTE((1-uiV) & 0x3,RtV)) ; } }
}

void HELPER(V6_vrmpyubi_acc)(CPUHexagonState *env, void * VxxV_void, void * VuuV_void, int32_t RtV, int32_t uiV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxxV.v[0].uw[i] += fMPY8UU(fGETUBYTE(0, VuuV.v[uiV ? 1:0].uw[i]),fGETUBYTE((0-uiV) & 0x3,RtV)); VxxV.v[0].uw[i] += fMPY8UU(fGETUBYTE(1, VuuV.v[0 ].uw[i]),fGETUBYTE((1-uiV) & 0x3,RtV)); VxxV.v[0].uw[i] += fMPY8UU(fGETUBYTE(2, VuuV.v[0 ].uw[i]),fGETUBYTE((2-uiV) & 0x3,RtV)); VxxV.v[0].uw[i] += fMPY8UU(fGETUBYTE(3, VuuV.v[0 ].uw[i]),fGETUBYTE((3-uiV) & 0x3,RtV)); VxxV.v[1].uw[i] += fMPY8UU(fGETUBYTE(0, VuuV.v[1 ].uw[i]),fGETUBYTE((2-uiV) & 0x3,RtV)); VxxV.v[1].uw[i] += fMPY8UU(fGETUBYTE(1, VuuV.v[1 ].uw[i]),fGETUBYTE((3-uiV) & 0x3,RtV)); VxxV.v[1].uw[i] += fMPY8UU(fGETUBYTE(2, VuuV.v[uiV ? 1:0].uw[i]),fGETUBYTE((0-uiV) & 0x3,RtV)); VxxV.v[1].uw[i] += fMPY8UU(fGETUBYTE(3, VuuV.v[0 ].uw[i]),fGETUBYTE((1-uiV) & 0x3,RtV)) ; } }
}

void HELPER(V6_vrmpybus)(CPUHexagonState *env, void * VdV_void, void * VuV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = fMPY8US(fGETUBYTE(0,VuV.uw[i]), fGETBYTE(0,RtV)); VdV.w[i] += fMPY8US(fGETUBYTE(1,VuV.uw[i]), fGETBYTE(1,RtV)); VdV.w[i] += fMPY8US(fGETUBYTE(2,VuV.uw[i]), fGETBYTE(2,RtV)); VdV.w[i] += fMPY8US(fGETUBYTE(3,VuV.uw[i]), fGETBYTE(3,RtV)) ; } }
}

void HELPER(V6_vrmpybus_acc)(CPUHexagonState *env, void * VxV_void, void * VuV_void, int32_t RtV)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxV.w[i] += fMPY8US(fGETUBYTE(0,VuV.uw[i]), fGETBYTE(0,RtV)); VxV.w[i] += fMPY8US(fGETUBYTE(1,VuV.uw[i]), fGETBYTE(1,RtV)); VxV.w[i] += fMPY8US(fGETUBYTE(2,VuV.uw[i]), fGETBYTE(2,RtV)); VxV.w[i] += fMPY8US(fGETUBYTE(3,VuV.uw[i]), fGETBYTE(3,RtV)) ; } }
}

void HELPER(V6_vrmpybusi)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, int32_t RtV, int32_t uiV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].w[i] = fMPY8US(fGETUBYTE(0, VuuV.v[uiV ? 1:0].uw[i]),fGETBYTE((0-uiV) & 0x3,RtV)); VddV.v[0].w[i] += fMPY8US(fGETUBYTE(1, VuuV.v[0 ].uw[i]),fGETBYTE((1-uiV) & 0x3,RtV)); VddV.v[0].w[i] += fMPY8US(fGETUBYTE(2, VuuV.v[0 ].uw[i]),fGETBYTE((2-uiV) & 0x3,RtV)); VddV.v[0].w[i] += fMPY8US(fGETUBYTE(3, VuuV.v[0 ].uw[i]),fGETBYTE((3-uiV) & 0x3,RtV)); VddV.v[1].w[i] = fMPY8US(fGETUBYTE(0, VuuV.v[1 ].uw[i]),fGETBYTE((2-uiV) & 0x3,RtV)); VddV.v[1].w[i] += fMPY8US(fGETUBYTE(1, VuuV.v[1 ].uw[i]),fGETBYTE((3-uiV) & 0x3,RtV)); VddV.v[1].w[i] += fMPY8US(fGETUBYTE(2, VuuV.v[uiV ? 1:0].uw[i]),fGETBYTE((0-uiV) & 0x3,RtV)); VddV.v[1].w[i] += fMPY8US(fGETUBYTE(3, VuuV.v[0 ].uw[i]),fGETBYTE((1-uiV) & 0x3,RtV)) ; } }
}

void HELPER(V6_vrmpybusi_acc)(CPUHexagonState *env, void * VxxV_void, void * VuuV_void, int32_t RtV, int32_t uiV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxxV.v[0].w[i] += fMPY8US(fGETUBYTE(0, VuuV.v[uiV ? 1:0].uw[i]),fGETBYTE((0-uiV) & 0x3,RtV)); VxxV.v[0].w[i] += fMPY8US(fGETUBYTE(1, VuuV.v[0 ].uw[i]),fGETBYTE((1-uiV) & 0x3,RtV)); VxxV.v[0].w[i] += fMPY8US(fGETUBYTE(2, VuuV.v[0 ].uw[i]),fGETBYTE((2-uiV) & 0x3,RtV)); VxxV.v[0].w[i] += fMPY8US(fGETUBYTE(3, VuuV.v[0 ].uw[i]),fGETBYTE((3-uiV) & 0x3,RtV)); VxxV.v[1].w[i] += fMPY8US(fGETUBYTE(0, VuuV.v[1 ].uw[i]),fGETBYTE((2-uiV) & 0x3,RtV)); VxxV.v[1].w[i] += fMPY8US(fGETUBYTE(1, VuuV.v[1 ].uw[i]),fGETBYTE((3-uiV) & 0x3,RtV)); VxxV.v[1].w[i] += fMPY8US(fGETUBYTE(2, VuuV.v[uiV ? 1:0].uw[i]),fGETBYTE((0-uiV) & 0x3,RtV)); VxxV.v[1].w[i] += fMPY8US(fGETUBYTE(3, VuuV.v[0 ].uw[i]),fGETBYTE((1-uiV) & 0x3,RtV)) ; } }
}

void HELPER(V6_vrmpybusv)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = fMPY8US(fGETUBYTE(0,VuV.uw[i]), fGETBYTE(0,VvV.w[i])); VdV.w[i] += fMPY8US(fGETUBYTE(1,VuV.uw[i]), fGETBYTE(1,VvV.w[i])); VdV.w[i] += fMPY8US(fGETUBYTE(2,VuV.uw[i]), fGETBYTE(2,VvV.w[i])); VdV.w[i] += fMPY8US(fGETUBYTE(3,VuV.uw[i]), fGETBYTE(3,VvV.w[i])) ; } }
}

void HELPER(V6_vrmpybusv_acc)(CPUHexagonState *env, void * VxV_void, void * VuV_void, void * VvV_void)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxV.w[i] += fMPY8US(fGETUBYTE(0,VuV.uw[i]), fGETBYTE(0,VvV.w[i])); VxV.w[i] += fMPY8US(fGETUBYTE(1,VuV.uw[i]), fGETBYTE(1,VvV.w[i])); VxV.w[i] += fMPY8US(fGETUBYTE(2,VuV.uw[i]), fGETBYTE(2,VvV.w[i])); VxV.w[i] += fMPY8US(fGETUBYTE(3,VuV.uw[i]), fGETBYTE(3,VvV.w[i])) ; } }
}

void HELPER(V6_vdsaduh)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, int32_t RtV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].uw[i] = fABS(fGETUHALF(0, VuuV.v[0].uw[i]) - fGETUHALF(0,RtV)); VddV.v[0].uw[i] += fABS(fGETUHALF(1, VuuV.v[0].uw[i]) - fGETUHALF(1,RtV)); VddV.v[1].uw[i] = fABS(fGETUHALF(1, VuuV.v[0].uw[i]) - fGETUHALF(0,RtV)); VddV.v[1].uw[i] += fABS(fGETUHALF(0, VuuV.v[1].uw[i]) - fGETUHALF(1,RtV)) ; } }
}

void HELPER(V6_vdsaduh_acc)(CPUHexagonState *env, void * VxxV_void, void * VuuV_void, int32_t RtV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxxV.v[0].uw[i] += fABS(fGETUHALF(0, VuuV.v[0].uw[i]) - fGETUHALF(0,RtV)); VxxV.v[0].uw[i] += fABS(fGETUHALF(1, VuuV.v[0].uw[i]) - fGETUHALF(1,RtV)); VxxV.v[1].uw[i] += fABS(fGETUHALF(1, VuuV.v[0].uw[i]) - fGETUHALF(0,RtV)); VxxV.v[1].uw[i] += fABS(fGETUHALF(0, VuuV.v[1].uw[i]) - fGETUHALF(1,RtV)) ; } }
}

void HELPER(V6_vrsadubi)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, int32_t RtV, int32_t uiV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].uw[i] = fABS(fZE8_16(fGETUBYTE(0, VuuV.v[uiV?1:0].uw[i])) - fZE8_16(fGETUBYTE((0-uiV)&3,RtV))); VddV.v[0].uw[i] += fABS(fZE8_16(fGETUBYTE(1, VuuV.v[0 ].uw[i])) - fZE8_16(fGETUBYTE((1-uiV)&3,RtV))); VddV.v[0].uw[i] += fABS(fZE8_16(fGETUBYTE(2, VuuV.v[0 ].uw[i])) - fZE8_16(fGETUBYTE((2-uiV)&3,RtV))); VddV.v[0].uw[i] += fABS(fZE8_16(fGETUBYTE(3, VuuV.v[0 ].uw[i])) - fZE8_16(fGETUBYTE((3-uiV)&3,RtV))); VddV.v[1].uw[i] = fABS(fZE8_16(fGETUBYTE(0, VuuV.v[1 ].uw[i])) - fZE8_16(fGETUBYTE((2-uiV)&3,RtV))); VddV.v[1].uw[i] += fABS(fZE8_16(fGETUBYTE(1, VuuV.v[1 ].uw[i])) - fZE8_16(fGETUBYTE((3-uiV)&3,RtV))); VddV.v[1].uw[i] += fABS(fZE8_16(fGETUBYTE(2, VuuV.v[uiV?1:0].uw[i])) - fZE8_16(fGETUBYTE((0-uiV)&3,RtV))); VddV.v[1].uw[i] += fABS(fZE8_16(fGETUBYTE(3, VuuV.v[0 ].uw[i])) - fZE8_16(fGETUBYTE((1-uiV)&3,RtV))) ; } }
}

void HELPER(V6_vrsadubi_acc)(CPUHexagonState *env, void * VxxV_void, void * VuuV_void, int32_t RtV, int32_t uiV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxxV.v[0].uw[i] += fABS(fZE8_16(fGETUBYTE(0, VuuV.v[uiV?1:0].uw[i])) - fZE8_16(fGETUBYTE((0-uiV)&3,RtV))); VxxV.v[0].uw[i] += fABS(fZE8_16(fGETUBYTE(1, VuuV.v[0 ].uw[i])) - fZE8_16(fGETUBYTE((1-uiV)&3,RtV))); VxxV.v[0].uw[i] += fABS(fZE8_16(fGETUBYTE(2, VuuV.v[0 ].uw[i])) - fZE8_16(fGETUBYTE((2-uiV)&3,RtV))); VxxV.v[0].uw[i] += fABS(fZE8_16(fGETUBYTE(3, VuuV.v[0 ].uw[i])) - fZE8_16(fGETUBYTE((3-uiV)&3,RtV))); VxxV.v[1].uw[i] += fABS(fZE8_16(fGETUBYTE(0, VuuV.v[1 ].uw[i])) - fZE8_16(fGETUBYTE((2-uiV)&3,RtV))); VxxV.v[1].uw[i] += fABS(fZE8_16(fGETUBYTE(1, VuuV.v[1 ].uw[i])) - fZE8_16(fGETUBYTE((3-uiV)&3,RtV))); VxxV.v[1].uw[i] += fABS(fZE8_16(fGETUBYTE(2, VuuV.v[uiV?1:0].uw[i])) - fZE8_16(fGETUBYTE((0-uiV)&3,RtV))); VxxV.v[1].uw[i] += fABS(fZE8_16(fGETUBYTE(3, VuuV.v[0 ].uw[i])) - fZE8_16(fGETUBYTE((1-uiV)&3,RtV))) ; } }
}

void HELPER(V6_vasrwv)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = fBIDIR_ASHIFTR(VuV.w[i], fSXTN((5+1),32,VvV.w[i]),4_4) ; } }
}

void HELPER(V6_vaslwv)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = fBIDIR_ASHIFTL(VuV.w[i], fSXTN((5+1),32,VvV.w[i]),4_4) ; } }
}

void HELPER(V6_vlsrwv)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.uw[i] = fBIDIR_LSHIFTR(VuV.uw[i], fSXTN((5+1),32,VvV.w[i]),4_4) ; } }
}

void HELPER(V6_vasrhv)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.h[i] = fBIDIR_ASHIFTR(VuV.h[i], fSXTN((4+1),16,VvV.h[i]),2_2) ; } }
}

void HELPER(V6_vaslhv)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.h[i] = fBIDIR_ASHIFTL(VuV.h[i], fSXTN((4+1),16,VvV.h[i]),2_2) ; } }
}

void HELPER(V6_vlsrhv)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.uh[i] = fBIDIR_LSHIFTR(VuV.uh[i], fSXTN((4+1),16,VvV.h[i]),2_2) ; } }
}

void HELPER(V6_vrotr)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.uw[i] = ((VuV.uw[i] >> (VvV.uw[i] & 0x1f)) | (VuV.uw[i] << (32 - (VvV.uw[i] & 0x1f)))) ; } }
}

void HELPER(V6_vasr_into)(CPUHexagonState *env, void * VxxV_void, void * VuV_void, void * VvV_void)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(int64_t ) shift = (fSE32_64(VuV.w[i]) << 32); fHIDE(int64_t ) mask = (((fSE32_64(VxxV.v[0].w[i])) << 32) | fZE32_64(VxxV.v[0].w[i])); fHIDE(int64_t) lomask = (((fSE32_64(1)) << 32) - 1); fHIDE(int ) count = -(0x40 & VvV.w[i]) + (VvV.w[i] & 0x3f); fHIDE(int64_t ) result = (count == -0x40) ? 0 : (((count < 0) ? ((shift << -(count)) | (mask & (lomask << -(count)))) : ((shift >> count) | (mask & (lomask >> count))))); VxxV.v[1].w[i] = ((result >> 32) & 0xffffffff); VxxV.v[0].w[i] = (result & 0xffffffff) ; } }
}

void HELPER(V6_vasrwh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(int )shamt = RtV & 0xF; fSETHALF(0,VdV.w[i],fECHO(fVNOROUND(VvV.w[i],shamt) >> shamt)); fSETHALF(1,VdV.w[i],fECHO(fVNOROUND(VuV.w[i],shamt) >> shamt)) ; } }
}

void HELPER(V6_vasrwhsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(int )shamt = RtV & 0xF; fSETHALF(0,VdV.w[i],fVSATH(fVNOROUND(VvV.w[i],shamt) >> shamt)); fSETHALF(1,VdV.w[i],fVSATH(fVNOROUND(VuV.w[i],shamt) >> shamt)) ; } }
}

void HELPER(V6_vasrwhrndsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(int )shamt = RtV & 0xF; fSETHALF(0,VdV.w[i],fVSATH(fVROUND(VvV.w[i],shamt) >> shamt)); fSETHALF(1,VdV.w[i],fVSATH(fVROUND(VuV.w[i],shamt) >> shamt)) ; } }
}

void HELPER(V6_vasrwuhrndsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(int )shamt = RtV & 0xF; fSETHALF(0,VdV.w[i],fVSATUH(fVROUND(VvV.w[i],shamt) >> shamt)); fSETHALF(1,VdV.w[i],fVSATUH(fVROUND(VuV.w[i],shamt) >> shamt)) ; } }
}

void HELPER(V6_vasrwuhsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(int )shamt = RtV & 0xF; fSETHALF(0,VdV.w[i],fVSATUH(fVNOROUND(VvV.w[i],shamt) >> shamt)); fSETHALF(1,VdV.w[i],fVSATUH(fVNOROUND(VuV.w[i],shamt) >> shamt)) ; } }
}

void HELPER(V6_vasruwuhrndsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(int )shamt = RtV & 0xF; fSETHALF(0,VdV.uw[i],fVSATUH(fVROUND(VvV.uw[i],shamt) >> shamt)); fSETHALF(1,VdV.uw[i],fVSATUH(fVROUND(VuV.uw[i],shamt) >> shamt)) ; } }
}

void HELPER(V6_vasruwuhsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(int )shamt = RtV & 0xF; fSETHALF(0,VdV.uw[i],fVSATUH(fVNOROUND(VvV.uw[i],shamt) >> shamt)); fSETHALF(1,VdV.uw[i],fVSATUH(fVNOROUND(VuV.uw[i],shamt) >> shamt)) ; } }
}

void HELPER(V6_vasrhubsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fHIDE(int )shamt = RtV & 0x7; fSETBYTE(0,VdV.h[i],fVSATUB(fVNOROUND(VvV.h[i],shamt) >> shamt)); fSETBYTE(1,VdV.h[i],fVSATUB(fVNOROUND(VuV.h[i],shamt) >> shamt)) ; } }
}

void HELPER(V6_vasrhubrndsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fHIDE(int )shamt = RtV & 0x7; fSETBYTE(0,VdV.h[i],fVSATUB(fVROUND(VvV.h[i],shamt) >> shamt)); fSETBYTE(1,VdV.h[i],fVSATUB(fVROUND(VuV.h[i],shamt) >> shamt)) ; } }
}

void HELPER(V6_vasrhbsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fHIDE(int )shamt = RtV & 0x7; fSETBYTE(0,VdV.h[i],fVSATB(fVNOROUND(VvV.h[i],shamt) >> shamt)); fSETBYTE(1,VdV.h[i],fVSATB(fVNOROUND(VuV.h[i],shamt) >> shamt)) ; } }
}

void HELPER(V6_vasrhbrndsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fHIDE(int )shamt = RtV & 0x7; fSETBYTE(0,VdV.h[i],fVSATB(fVROUND(VvV.h[i],shamt) >> shamt)); fSETBYTE(1,VdV.h[i],fVSATB(fVROUND(VuV.h[i],shamt) >> shamt)) ; } }
}

void HELPER(V6_vasrvwuhsat)(CPUHexagonState *env, void * VdV_void, void * VuuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(int )shamt = VvV.uh[2*i+0] & 0xF; fSETHALF(0,VdV.w[i],fVSATUH(fVNOROUND(VuuV.v[0].w[i],shamt) >> shamt)); shamt = VvV.uh[2*i+1] & 0xF; fSETHALF(1,VdV.w[i],fVSATUH(fVNOROUND(VuuV.v[1].w[i],shamt) >> shamt)) ; } }
}

void HELPER(V6_vasrvwuhrndsat)(CPUHexagonState *env, void * VdV_void, void * VuuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(int )shamt = VvV.uh[2*i+0] & 0xF; fSETHALF(0,VdV.w[i],fVSATUH(fVROUND(VuuV.v[0].w[i],shamt) >> shamt)); shamt = VvV.uh[2*i+1] & 0xF; fSETHALF(1,VdV.w[i],fVSATUH(fVROUND(VuuV.v[1].w[i],shamt) >> shamt)) ; } }
}

void HELPER(V6_vasrvuhubsat)(CPUHexagonState *env, void * VdV_void, void * VuuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fHIDE(int )shamt = VvV.ub[2*i+0] & 0x7; fSETBYTE(0,VdV.uh[i],fVSATUB(fVNOROUND(VuuV.v[0].uh[i],shamt) >> shamt)); shamt = VvV.ub[2*i+1] & 0x7; fSETBYTE(1,VdV.uh[i],fVSATUB(fVNOROUND(VuuV.v[1].uh[i],shamt) >> shamt)) ; } }
}

void HELPER(V6_vasrvuhubrndsat)(CPUHexagonState *env, void * VdV_void, void * VuuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fHIDE(int )shamt = VvV.ub[2*i+0] & 0x7; fSETBYTE(0,VdV.uh[i],fVSATUB(fVROUND(VuuV.v[0].uh[i],shamt) >> shamt)); shamt = VvV.ub[2*i+1] & 0x7; fSETBYTE(1,VdV.uh[i],fVSATUB(fVROUND(VuuV.v[1].uh[i],shamt) >> shamt)) ; } }
}

void HELPER(V6_vasruhubsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fHIDE(int )shamt = RtV & 0x7; fSETBYTE(0,VdV.uh[i],fVSATUB(fVNOROUND(VvV.uh[i],shamt) >> shamt)); fSETBYTE(1,VdV.uh[i],fVSATUB(fVNOROUND(VuV.uh[i],shamt) >> shamt)) ; } }
}

void HELPER(V6_vasruhubrndsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fHIDE(int )shamt = RtV & 0x7; fSETBYTE(0,VdV.uh[i],fVSATUB(fVROUND(VvV.uh[i],shamt) >> shamt)); fSETBYTE(1,VdV.uh[i],fVSATUB(fVROUND(VuV.uh[i],shamt) >> shamt)) ; } }
}

void HELPER(V6_vroundwh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fSETHALF(0, VdV.uw[i], fVSATH((VvV.w[i] + fCONSTLL(0x8000)) >> 16)); fSETHALF(1, VdV.uw[i], fVSATH((VuV.w[i] + fCONSTLL(0x8000)) >> 16)) ; } }
}

void HELPER(V6_vroundwuh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fSETHALF(0, VdV.uw[i], fVSATUH((VvV.w[i] + fCONSTLL(0x8000)) >> 16)); fSETHALF(1, VdV.uw[i], fVSATUH((VuV.w[i] + fCONSTLL(0x8000)) >> 16)) ; } }
}

void HELPER(V6_vrounduwuh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fSETHALF(0, VdV.uw[i], fVSATUH((VvV.uw[i] + fCONSTLL(0x8000)) >> 16)); fSETHALF(1, VdV.uw[i], fVSATUH((VuV.uw[i] + fCONSTLL(0x8000)) >> 16)) ; } }
}

void HELPER(V6_vroundhb)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fSETBYTE(0, VdV.uh[i], fVSATB((VvV.h[i] + 0x80) >> 8)); fSETBYTE(1, VdV.uh[i], fVSATB((VuV.h[i] + 0x80) >> 8)) ; } }
}

void HELPER(V6_vroundhub)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fSETBYTE(0, VdV.uh[i], fVSATUB((VvV.h[i] + 0x80) >> 8)); fSETBYTE(1, VdV.uh[i], fVSATUB((VuV.h[i] + 0x80) >> 8)) ; } }
}

void HELPER(V6_vrounduhub)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fSETBYTE(0, VdV.uh[i], fVSATUB((VvV.uh[i] + 0x80) >> 8)); fSETBYTE(1, VdV.uh[i], fVSATUB((VuV.uh[i] + 0x80) >> 8)) ; } }
}

void HELPER(V6_vaddubsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VdV.ub[i] = fVUADDSAT(8, VuV.ub[i], VvV.ub[i]) ; } }
}

void HELPER(V6_vaddubsat_dv)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, void * VvvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VddV.v[0].ub[i] = fVUADDSAT(8, VuuV.v[0].ub[i],VvvV.v[0].ub[i]); VddV.v[1].ub[i] = fVUADDSAT(8, VuuV.v[1].ub[i],VvvV.v[1].ub[i]) ; } }
}

void HELPER(V6_vsububsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VdV.ub[i] = fVUSUBSAT(8, VuV.ub[i], VvV.ub[i]) ; } }
}

void HELPER(V6_vsububsat_dv)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, void * VvvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VddV.v[0].ub[i] = fVUSUBSAT(8, VuuV.v[0].ub[i],VvvV.v[0].ub[i]); VddV.v[1].ub[i] = fVUSUBSAT(8, VuuV.v[1].ub[i],VvvV.v[1].ub[i]) ; } }
}

void HELPER(V6_vadduhsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.uh[i] = fVUADDSAT(16, VuV.uh[i], VvV.uh[i]) ; } }
}

void HELPER(V6_vadduhsat_dv)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, void * VvvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VddV.v[0].uh[i] = fVUADDSAT(16, VuuV.v[0].uh[i],VvvV.v[0].uh[i]); VddV.v[1].uh[i] = fVUADDSAT(16, VuuV.v[1].uh[i],VvvV.v[1].uh[i]) ; } }
}

void HELPER(V6_vsubuhsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.uh[i] = fVUSUBSAT(16, VuV.uh[i], VvV.uh[i]) ; } }
}

void HELPER(V6_vsubuhsat_dv)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, void * VvvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VddV.v[0].uh[i] = fVUSUBSAT(16, VuuV.v[0].uh[i],VvvV.v[0].uh[i]); VddV.v[1].uh[i] = fVUSUBSAT(16, VuuV.v[1].uh[i],VvvV.v[1].uh[i]) ; } }
}

void HELPER(V6_vadduwsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.uw[i] = fVUADDSAT(32, VuV.uw[i], VvV.uw[i]) ; } }
}

void HELPER(V6_vadduwsat_dv)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, void * VvvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].uw[i] = fVUADDSAT(32, VuuV.v[0].uw[i],VvvV.v[0].uw[i]); VddV.v[1].uw[i] = fVUADDSAT(32, VuuV.v[1].uw[i],VvvV.v[1].uw[i]) ; } }
}

void HELPER(V6_vsubuwsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.uw[i] = fVUSUBSAT(32, VuV.uw[i], VvV.uw[i]) ; } }
}

void HELPER(V6_vsubuwsat_dv)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, void * VvvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].uw[i] = fVUSUBSAT(32, VuuV.v[0].uw[i],VvvV.v[0].uw[i]); VddV.v[1].uw[i] = fVUSUBSAT(32, VuuV.v[1].uw[i],VvvV.v[1].uw[i]) ; } }
}

void HELPER(V6_vaddbsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VdV.b[i] = fVSADDSAT(8, VuV.b[i], VvV.b[i]) ; } }
}

void HELPER(V6_vaddbsat_dv)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, void * VvvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VddV.v[0].b[i] = fVSADDSAT(8, VuuV.v[0].b[i], VvvV.v[0].b[i]); VddV.v[1].b[i] = fVSADDSAT(8, VuuV.v[1].b[i], VvvV.v[1].b[i]) ; } }
}

void HELPER(V6_vsubbsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VdV.b[i] = fVSSUBSAT(8, VuV.b[i], VvV.b[i]) ; } }
}

void HELPER(V6_vsubbsat_dv)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, void * VvvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VddV.v[0].b[i] = fVSSUBSAT(8, VuuV.v[0].b[i], VvvV.v[0].b[i]); VddV.v[1].b[i] = fVSSUBSAT(8, VuuV.v[1].b[i], VvvV.v[1].b[i]) ; } }
}

void HELPER(V6_vaddhsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.h[i] = fVSADDSAT(16, VuV.h[i], VvV.h[i]) ; } }
}

void HELPER(V6_vaddhsat_dv)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, void * VvvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VddV.v[0].h[i] = fVSADDSAT(16, VuuV.v[0].h[i], VvvV.v[0].h[i]); VddV.v[1].h[i] = fVSADDSAT(16, VuuV.v[1].h[i], VvvV.v[1].h[i]) ; } }
}

void HELPER(V6_vsubhsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.h[i] = fVSSUBSAT(16, VuV.h[i], VvV.h[i]) ; } }
}

void HELPER(V6_vsubhsat_dv)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, void * VvvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VddV.v[0].h[i] = fVSSUBSAT(16, VuuV.v[0].h[i], VvvV.v[0].h[i]); VddV.v[1].h[i] = fVSSUBSAT(16, VuuV.v[1].h[i], VvvV.v[1].h[i]) ; } }
}

void HELPER(V6_vaddwsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = fVSADDSAT(32, VuV.w[i], VvV.w[i]) ; } }
}

void HELPER(V6_vaddwsat_dv)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, void * VvvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].w[i] = fVSADDSAT(32, VuuV.v[0].w[i], VvvV.v[0].w[i]); VddV.v[1].w[i] = fVSADDSAT(32, VuuV.v[1].w[i], VvvV.v[1].w[i]) ; } }
}

void HELPER(V6_vsubwsat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = fVSSUBSAT(32, VuV.w[i], VvV.w[i]) ; } }
}

void HELPER(V6_vsubwsat_dv)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, void * VvvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].w[i] = fVSSUBSAT(32, VuuV.v[0].w[i], VvvV.v[0].w[i]); VddV.v[1].w[i] = fVSSUBSAT(32, VuuV.v[1].w[i], VvvV.v[1].w[i]) ; } }
}

void HELPER(V6_vavgub)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VdV.ub[i] = fVAVGU( 8, VuV.ub[i], VvV.ub[i]) ; } }
}

void HELPER(V6_vavgubrnd)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VdV.ub[i] = fVAVGURND(8, VuV.ub[i], VvV.ub[i]) ; } }
}

void HELPER(V6_vavguh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.uh[i] = fVAVGU( 16, VuV.uh[i], VvV.uh[i]) ; } }
}

void HELPER(V6_vavguhrnd)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.uh[i] = fVAVGURND(16, VuV.uh[i], VvV.uh[i]) ; } }
}

void HELPER(V6_vavguw)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.uw[i] = fVAVGU( 32, VuV.uw[i], VvV.uw[i]) ; } }
}

void HELPER(V6_vavguwrnd)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.uw[i] = fVAVGURND(32, VuV.uw[i], VvV.uw[i]) ; } }
}

void HELPER(V6_vavgb)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VdV.b[i] = fVAVGS( 8, VuV.b[i], VvV.b[i]) ; } }
}

void HELPER(V6_vavgbrnd)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VdV.b[i] = fVAVGSRND( 8, VuV.b[i], VvV.b[i]) ; } }
}

void HELPER(V6_vnavgb)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VdV.b[i] = fVNAVGS( 8, VuV.b[i], VvV.b[i]) ; } }
}

void HELPER(V6_vavgh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.h[i] = fVAVGS( 16, VuV.h[i], VvV.h[i]) ; } }
}

void HELPER(V6_vavghrnd)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.h[i] = fVAVGSRND( 16, VuV.h[i], VvV.h[i]) ; } }
}

void HELPER(V6_vnavgh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.h[i] = fVNAVGS( 16, VuV.h[i], VvV.h[i]) ; } }
}

void HELPER(V6_vavgw)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = fVAVGS( 32, VuV.w[i], VvV.w[i]) ; } }
}

void HELPER(V6_vavgwrnd)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = fVAVGSRND( 32, VuV.w[i], VvV.w[i]) ; } }
}

void HELPER(V6_vnavgw)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = fVNAVGS( 32, VuV.w[i], VvV.w[i]) ; } }
}

void HELPER(V6_vabsdiffub)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VdV.ub[i] = (VuV.ub[i] > VvV.ub[i]) ? (VuV.ub[i] - VvV.ub[i]) : (VvV.ub[i] - VuV.ub[i]) ; } }
}

void HELPER(V6_vabsdiffuh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.uh[i] = (VuV.uh[i] > VvV.uh[i]) ? (VuV.uh[i] - VvV.uh[i]) : (VvV.uh[i] - VuV.uh[i]) ; } }
}

void HELPER(V6_vabsdiffh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.uh[i] = (VuV.h[i] > VvV.h[i]) ? (VuV.h[i] - VvV.h[i]) : (VvV.h[i] - VuV.h[i]) ; } }
}

void HELPER(V6_vabsdiffw)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.uw[i] = (VuV.w[i] > VvV.w[i]) ? (VuV.w[i] - VvV.w[i]) : (VvV.w[i] - VuV.w[i]) ; } }
}

void HELPER(V6_vnavgub)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VdV.b[i] = fVNAVGU(8, VuV.ub[i], VvV.ub[i]) ; } }
}

void HELPER(V6_vaddcarrysat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void, void * QsV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    /* QsV is *(MMQReg *)(QsV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = fVSATW(VuV.w[i]+VvV.w[i]+fGETQBIT(QsV,i*4)) ; } }
}

void HELPER(V6_vaddcarry)(CPUHexagonState *env, void * VdV_void, void * QxV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    /* QxV is *(MMQReg *)(QxV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = VuV.w[i]+VvV.w[i]+fGETQBIT(QxV,i*4); fSETQBITS(QxV,4,0xF,4*i,-fCARRY_FROM_ADD32(VuV.w[i],VvV.w[i],fGETQBIT(QxV,i*4))) ; } }
}

void HELPER(V6_vsubcarry)(CPUHexagonState *env, void * VdV_void, void * QxV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    /* QxV is *(MMQReg *)(QxV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = VuV.w[i]+~VvV.w[i]+fGETQBIT(QxV,i*4); fSETQBITS(QxV,4,0xF,4*i,-fCARRY_FROM_ADD32(VuV.w[i],~VvV.w[i],fGETQBIT(QxV,i*4))) ; } }
}

void HELPER(V6_vaddcarryo)(CPUHexagonState *env, void * VdV_void, void * QeV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* QeV is *(MMQReg *)(QeV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = VuV.w[i]+VvV.w[i]; fSETQBITS(QeV,4,0xF,4*i,-fCARRY_FROM_ADD32(VuV.w[i],VvV.w[i],0)) ; } }
}

void HELPER(V6_vsubcarryo)(CPUHexagonState *env, void * VdV_void, void * QeV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* QeV is *(MMQReg *)(QeV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = VuV.w[i]+~VvV.w[i]+1; fSETQBITS(QeV,4,0xF,4*i,-fCARRY_FROM_ADD32(VuV.w[i],~VvV.w[i],1)) ; } }
}

void HELPER(V6_vsatdw)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = fVSATDW(VuV.w[i],VvV.w[i]) ; } }
}

void HELPER(V6_vaddububb_sat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VdV.ub[i] = fVSATUB(VuV.ub[i] + VvV.b[i]) ; } }
}

void HELPER(V6_vsubububb_sat)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VdV.ub[i] = fVSATUB(VuV.ub[i] - VvV.b[i]) ; } }
}

void HELPER(V6_vaddubh)(CPUHexagonState *env, void * VddV_void, void * VuV_void, void * VvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VddV.v[0].h[i] = fZE8_16(fGETUBYTE(0, VuV.uh[i])) + fZE8_16(fGETUBYTE(0, VvV.uh[i])); VddV.v[1].h[i] = fZE8_16(fGETUBYTE(1, VuV.uh[i])) + fZE8_16(fGETUBYTE(1, VvV.uh[i])) ; } }
}

void HELPER(V6_vsububh)(CPUHexagonState *env, void * VddV_void, void * VuV_void, void * VvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VddV.v[0].h[i] = fZE8_16(fGETUBYTE(0, VuV.uh[i])) - fZE8_16(fGETUBYTE(0, VvV.uh[i])); VddV.v[1].h[i] = fZE8_16(fGETUBYTE(1, VuV.uh[i])) - fZE8_16(fGETUBYTE(1, VvV.uh[i])) ; } }
}

void HELPER(V6_vaddhw)(CPUHexagonState *env, void * VddV_void, void * VuV_void, void * VvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].w[i] = fGETHALF(0, VuV.w[i]) + fGETHALF(0, VvV.w[i]); VddV.v[1].w[i] = fGETHALF(1, VuV.w[i]) + fGETHALF(1, VvV.w[i]) ; } }
}

void HELPER(V6_vsubhw)(CPUHexagonState *env, void * VddV_void, void * VuV_void, void * VvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].w[i] = fGETHALF(0, VuV.w[i]) - fGETHALF(0, VvV.w[i]); VddV.v[1].w[i] = fGETHALF(1, VuV.w[i]) - fGETHALF(1, VvV.w[i]) ; } }
}

void HELPER(V6_vadduhw)(CPUHexagonState *env, void * VddV_void, void * VuV_void, void * VvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].w[i] = fZE16_32(fGETUHALF(0, VuV.uw[i])) + fZE16_32(fGETUHALF(0, VvV.uw[i])); VddV.v[1].w[i] = fZE16_32(fGETUHALF(1, VuV.uw[i])) + fZE16_32(fGETUHALF(1, VvV.uw[i])) ; } }
}

void HELPER(V6_vsubuhw)(CPUHexagonState *env, void * VddV_void, void * VuV_void, void * VvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].w[i] = fZE16_32(fGETUHALF(0, VuV.uw[i])) - fZE16_32(fGETUHALF(0, VvV.uw[i])); VddV.v[1].w[i] = fZE16_32(fGETUHALF(1, VuV.uw[i])) - fZE16_32(fGETUHALF(1, VvV.uw[i])) ; } }
}

void HELPER(V6_vaddhw_acc)(CPUHexagonState *env, void * VxxV_void, void * VuV_void, void * VvV_void)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxxV.v[0].w[i] += fGETHALF(0, VuV.w[i]) + fGETHALF(0, VvV.w[i]); VxxV.v[1].w[i] += fGETHALF(1, VuV.w[i]) + fGETHALF(1, VvV.w[i]) ; } }
}

void HELPER(V6_vadduhw_acc)(CPUHexagonState *env, void * VxxV_void, void * VuV_void, void * VvV_void)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxxV.v[0].w[i] += fGETUHALF(0, VuV.w[i]) + fGETUHALF(0, VvV.w[i]); VxxV.v[1].w[i] += fGETUHALF(1, VuV.w[i]) + fGETUHALF(1, VvV.w[i]) ; } }
}

void HELPER(V6_vaddubh_acc)(CPUHexagonState *env, void * VxxV_void, void * VuV_void, void * VvV_void)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VxxV.v[0].h[i] += fGETUBYTE(0, VuV.h[i]) + fGETUBYTE(0, VvV.h[i]); VxxV.v[1].h[i] += fGETUBYTE(1, VuV.h[i]) + fGETUBYTE(1, VvV.h[i]) ; } }
}

void HELPER(V6_vaddbq)(CPUHexagonState *env, void * VxV_void, void * QvV_void, void * VuV_void)
{
    /* QvV is *(MMQReg *)(QvV_void) */
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VxV.ub[i]=fCONDMASK8(QvV,i,VxV.ub[i]+VuV.ub[i],VxV.ub[i]) ; } }
}

void HELPER(V6_vsubbq)(CPUHexagonState *env, void * VxV_void, void * QvV_void, void * VuV_void)
{
    /* QvV is *(MMQReg *)(QvV_void) */
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VxV.ub[i]=fCONDMASK8(QvV,i,VxV.ub[i]-VuV.ub[i],VxV.ub[i]) ; } }
}

void HELPER(V6_vaddbnq)(CPUHexagonState *env, void * VxV_void, void * QvV_void, void * VuV_void)
{
    /* QvV is *(MMQReg *)(QvV_void) */
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VxV.ub[i]=fCONDMASK8(QvV,i,VxV.ub[i],VxV.ub[i]+VuV.ub[i]) ; } }
}

void HELPER(V6_vsubbnq)(CPUHexagonState *env, void * VxV_void, void * QvV_void, void * VuV_void)
{
    /* QvV is *(MMQReg *)(QvV_void) */
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VxV.ub[i]=fCONDMASK8(QvV,i,VxV.ub[i],VxV.ub[i]-VuV.ub[i]) ; } }
}

void HELPER(V6_vaddhq)(CPUHexagonState *env, void * VxV_void, void * QvV_void, void * VuV_void)
{
    /* QvV is *(MMQReg *)(QvV_void) */
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VxV.h[i]=fCONDMASK16(QvV,i,VxV.h[i]+VuV.h[i],VxV.h[i]) ; } }
}

void HELPER(V6_vsubhq)(CPUHexagonState *env, void * VxV_void, void * QvV_void, void * VuV_void)
{
    /* QvV is *(MMQReg *)(QvV_void) */
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VxV.h[i]=fCONDMASK16(QvV,i,VxV.h[i]-VuV.h[i],VxV.h[i]) ; } }
}

void HELPER(V6_vaddhnq)(CPUHexagonState *env, void * VxV_void, void * QvV_void, void * VuV_void)
{
    /* QvV is *(MMQReg *)(QvV_void) */
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VxV.h[i]=fCONDMASK16(QvV,i,VxV.h[i],VxV.h[i]+VuV.h[i]) ; } }
}

void HELPER(V6_vsubhnq)(CPUHexagonState *env, void * VxV_void, void * QvV_void, void * VuV_void)
{
    /* QvV is *(MMQReg *)(QvV_void) */
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VxV.h[i]=fCONDMASK16(QvV,i,VxV.h[i],VxV.h[i]-VuV.h[i]) ; } }
}

void HELPER(V6_vaddwq)(CPUHexagonState *env, void * VxV_void, void * QvV_void, void * VuV_void)
{
    /* QvV is *(MMQReg *)(QvV_void) */
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxV.w[i]=fCONDMASK32(QvV,i,VxV.w[i]+VuV.w[i],VxV.w[i]) ; } }
}

void HELPER(V6_vsubwq)(CPUHexagonState *env, void * VxV_void, void * QvV_void, void * VuV_void)
{
    /* QvV is *(MMQReg *)(QvV_void) */
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxV.w[i]=fCONDMASK32(QvV,i,VxV.w[i]-VuV.w[i],VxV.w[i]) ; } }
}

void HELPER(V6_vaddwnq)(CPUHexagonState *env, void * VxV_void, void * QvV_void, void * VuV_void)
{
    /* QvV is *(MMQReg *)(QvV_void) */
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxV.w[i]=fCONDMASK32(QvV,i,VxV.w[i],VxV.w[i]+VuV.w[i]) ; } }
}

void HELPER(V6_vsubwnq)(CPUHexagonState *env, void * VxV_void, void * QvV_void, void * VuV_void)
{
    /* QvV is *(MMQReg *)(QvV_void) */
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxV.w[i]=fCONDMASK32(QvV,i,VxV.w[i],VxV.w[i]-VuV.w[i]) ; } }
}

void HELPER(V6_vabsb_sat)(CPUHexagonState *env, void * VdV_void, void * VuV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VdV.b[i] = fVSATB(fABS(fSE8_16(VuV.b[i]))) ; } }
}

void HELPER(V6_vabsh_sat)(CPUHexagonState *env, void * VdV_void, void * VuV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.h[i] = fVSATH(fABS(fSE16_32(VuV.h[i]))) ; } }
}

void HELPER(V6_vabsw_sat)(CPUHexagonState *env, void * VdV_void, void * VuV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = fVSATW(fABS(fSE32_64(VuV.w[i]))) ; } }
}

void HELPER(V6_vmpybv)(CPUHexagonState *env, void * VddV_void, void * VuV_void, void * VvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VddV.v[0].h[i] = fMPY8SS(fGETBYTE(0, VuV.h[i]), fGETBYTE(0, VvV.h[i])); VddV.v[1].h[i] = fMPY8SS(fGETBYTE(1, VuV.h[i]), fGETBYTE(1, VvV.h[i])) ; } }
}

void HELPER(V6_vmpybv_acc)(CPUHexagonState *env, void * VxxV_void, void * VuV_void, void * VvV_void)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VxxV.v[0].h[i] += fMPY8SS(fGETBYTE(0, VuV.h[i]), fGETBYTE(0, VvV.h[i])); VxxV.v[1].h[i] += fMPY8SS(fGETBYTE(1, VuV.h[i]), fGETBYTE(1, VvV.h[i])) ; } }
}

void HELPER(V6_vmpyubv)(CPUHexagonState *env, void * VddV_void, void * VuV_void, void * VvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VddV.v[0].uh[i] = fMPY8UU(fGETUBYTE(0, VuV.uh[i]), fGETUBYTE(0, VvV.uh[i]) ); VddV.v[1].uh[i] = fMPY8UU(fGETUBYTE(1, VuV.uh[i]), fGETUBYTE(1, VvV.uh[i]) ) ; } }
}

void HELPER(V6_vmpyubv_acc)(CPUHexagonState *env, void * VxxV_void, void * VuV_void, void * VvV_void)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VxxV.v[0].uh[i] += fMPY8UU(fGETUBYTE(0, VuV.uh[i]), fGETUBYTE(0, VvV.uh[i]) ); VxxV.v[1].uh[i] += fMPY8UU(fGETUBYTE(1, VuV.uh[i]), fGETUBYTE(1, VvV.uh[i]) ) ; } }
}

void HELPER(V6_vmpybusv)(CPUHexagonState *env, void * VddV_void, void * VuV_void, void * VvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VddV.v[0].h[i] = fMPY8US(fGETUBYTE(0, VuV.uh[i]), fGETBYTE(0, VvV.h[i])); VddV.v[1].h[i] = fMPY8US(fGETUBYTE(1, VuV.uh[i]), fGETBYTE(1, VvV.h[i])) ; } }
}

void HELPER(V6_vmpybusv_acc)(CPUHexagonState *env, void * VxxV_void, void * VuV_void, void * VvV_void)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VxxV.v[0].h[i] += fMPY8US(fGETUBYTE(0, VuV.uh[i]), fGETBYTE(0, VvV.h[i])); VxxV.v[1].h[i] += fMPY8US(fGETUBYTE(1, VuV.uh[i]), fGETBYTE(1, VvV.h[i])) ; } }
}

void HELPER(V6_vmpabusv)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, void * VvvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VddV.v[0].h[i] = fMPY8US(fGETUBYTE(0, VuuV.v[0].uh[i]), fGETBYTE(0, VvvV.v[0].uh[i])) + fMPY8US(fGETUBYTE(0, VuuV.v[1].uh[i]), fGETBYTE(0, VvvV.v[1].uh[i])); VddV.v[1].h[i] = fMPY8US(fGETUBYTE(1, VuuV.v[0].uh[i]), fGETBYTE(1, VvvV.v[0].uh[i])) + fMPY8US(fGETUBYTE(1, VuuV.v[1].uh[i]), fGETBYTE(1, VvvV.v[1].uh[i])) ; } }
}

void HELPER(V6_vmpabuuv)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, void * VvvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VddV.v[0].h[i] = fMPY8UU(fGETUBYTE(0, VuuV.v[0].uh[i]), fGETUBYTE(0, VvvV.v[0].uh[i])) + fMPY8UU(fGETUBYTE(0, VuuV.v[1].uh[i]), fGETUBYTE(0, VvvV.v[1].uh[i])); VddV.v[1].h[i] = fMPY8UU(fGETUBYTE(1, VuuV.v[0].uh[i]), fGETUBYTE(1, VvvV.v[0].uh[i])) + fMPY8UU(fGETUBYTE(1, VuuV.v[1].uh[i]), fGETUBYTE(1, VvvV.v[1].uh[i])) ; } }
}

void HELPER(V6_vmpyhv)(CPUHexagonState *env, void * VddV_void, void * VuV_void, void * VvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].w[i] = fMPY16SS(fGETHALF(0, VuV.w[i]), fGETHALF(0, VvV.w[i])); VddV.v[1].w[i] = fMPY16SS(fGETHALF(1, VuV.w[i]), fGETHALF(1, VvV.w[i])) ; } }
}

void HELPER(V6_vmpyhv_acc)(CPUHexagonState *env, void * VxxV_void, void * VuV_void, void * VvV_void)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxxV.v[0].w[i] += fMPY16SS(fGETHALF(0, VuV.w[i]), fGETHALF(0, VvV.w[i])); VxxV.v[1].w[i] += fMPY16SS(fGETHALF(1, VuV.w[i]), fGETHALF(1, VvV.w[i])) ; } }
}

void HELPER(V6_vmpyuhv)(CPUHexagonState *env, void * VddV_void, void * VuV_void, void * VvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].uw[i] = fMPY16UU(fGETUHALF(0, VuV.uw[i]), fGETUHALF(0, VvV.uw[i])); VddV.v[1].uw[i] = fMPY16UU(fGETUHALF(1, VuV.uw[i]), fGETUHALF(1, VvV.uw[i])) ; } }
}

void HELPER(V6_vmpyuhv_acc)(CPUHexagonState *env, void * VxxV_void, void * VuV_void, void * VvV_void)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxxV.v[0].uw[i] += fMPY16UU(fGETUHALF(0, VuV.uw[i]), fGETUHALF(0, VvV.uw[i])); VxxV.v[1].uw[i] += fMPY16UU(fGETUHALF(1, VuV.uw[i]), fGETUHALF(1, VvV.uw[i])) ; } }
}

void HELPER(V6_vmpyhvsrs)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.h[i] = fVSATH(fGETHALF(1,fVSAT(fROUND((fMPY16SS(VuV.h[i],VvV.h[i] )<<1))))) ; } }
}

void HELPER(V6_vmpyuhvs)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.uh[i] = fGETUHALF(1,fMPY16UU(VuV.uh[i],VvV.uh[i])) ; } }
}

void HELPER(V6_vmpyhus)(CPUHexagonState *env, void * VddV_void, void * VuV_void, void * VvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].w[i] = fMPY16SU(fGETHALF(0, VuV.w[i]), fGETUHALF(0, VvV.uw[i])); VddV.v[1].w[i] = fMPY16SU(fGETHALF(1, VuV.w[i]), fGETUHALF(1, VvV.uw[i])) ; } }
}

void HELPER(V6_vmpyhus_acc)(CPUHexagonState *env, void * VxxV_void, void * VuV_void, void * VvV_void)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxxV.v[0].w[i] += fMPY16SU(fGETHALF(0, VuV.w[i]), fGETUHALF(0, VvV.uw[i])); VxxV.v[1].w[i] += fMPY16SU(fGETHALF(1, VuV.w[i]), fGETUHALF(1, VvV.uw[i])) ; } }
}

void HELPER(V6_vmpyih)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.h[i] = fMPY16SS(VuV.h[i], VvV.h[i]) ; } }
}

void HELPER(V6_vmpyih_acc)(CPUHexagonState *env, void * VxV_void, void * VuV_void, void * VvV_void)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VxV.h[i] += fMPY16SS(VuV.h[i], VvV.h[i]) ; } }
}

void HELPER(V6_vmpyewuh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = fMPY3216SU(VuV.w[i], fGETUHALF(0, VvV.w[i])) >> 16 ; } }
}

void HELPER(V6_vmpyowh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = fVSATW((((fMPY3216SS(VuV.w[i], fGETHALF(1, VvV.w[i])) >> 14) + 0) >> 1)) ; } }
}

void HELPER(V6_vmpyowh_rnd)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = fVSATW((((fMPY3216SS(VuV.w[i], fGETHALF(1, VvV.w[i])) >> 14) + 1) >> 1)) ; } }
}

void HELPER(V6_vmpyewuh_64)(CPUHexagonState *env, void * VddV_void, void * VuV_void, void * VvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(size8s_t prod;) prod = fMPY32SU(VuV.w[i],fGETUHALF(0,VvV.w[i])); VddV.v[1].w[i] = prod >> 16; VddV.v[0].w[i] = prod << 16 ; } }
}

void HELPER(V6_vmpyowh_64_acc)(CPUHexagonState *env, void * VxxV_void, void * VuV_void, void * VvV_void)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(size8s_t prod;) prod = fMPY32SS(VuV.w[i],fGETHALF(1,VvV.w[i])) + fSE32_64(VxxV.v[1].w[i]); VxxV.v[1].w[i] = prod >> 16; fSETHALF(0, VxxV.v[0].w[i], VxxV.v[0].w[i] >> 16); fSETHALF(1, VxxV.v[0].w[i], prod & 0x0000ffff) ; } }
}

void HELPER(V6_vmpyowh_sacc)(CPUHexagonState *env, void * VxV_void, void * VuV_void, void * VvV_void)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { IV1DEAD() VxV.w[i] = fVSATW(((((VxV.w[i] + fMPY3216SS(VuV.w[i], fGETHALF(1, VvV.w[i]))) >> 14) + 0) >> 1)) ; } }
}

void HELPER(V6_vmpyowh_rnd_sacc)(CPUHexagonState *env, void * VxV_void, void * VuV_void, void * VvV_void)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { IV1DEAD() VxV.w[i] = fVSATW(((((VxV.w[i] + fMPY3216SS(VuV.w[i], fGETHALF(1, VvV.w[i]))) >> 14) + 1) >> 1)) ; } }
}

void HELPER(V6_vmpyieoh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = (fGETHALF(0,VuV.w[i])*fGETHALF(1,VvV.w[i])) << 16 ; } }
}

void HELPER(V6_vmpyiewuh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { IV1DEAD() VdV.w[i] = fMPY3216SU(VuV.w[i], fGETUHALF(0, VvV.w[i])) ; } }
}

void HELPER(V6_vmpyiowh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { IV1DEAD() VdV.w[i] = fMPY3216SS(VuV.w[i], fGETHALF(1, VvV.w[i])) ; } }
}

void HELPER(V6_vmpyiewh_acc)(CPUHexagonState *env, void * VxV_void, void * VuV_void, void * VvV_void)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxV.w[i] = VxV.w[i] + fMPY3216SS(VuV.w[i], fGETHALF(0, VvV.w[i])) ; } }
}

void HELPER(V6_vmpyiewuh_acc)(CPUHexagonState *env, void * VxV_void, void * VuV_void, void * VvV_void)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxV.w[i] = VxV.w[i] + fMPY3216SU(VuV.w[i], fGETUHALF(0, VvV.w[i])) ; } }
}

void HELPER(V6_vmpyub)(CPUHexagonState *env, void * VddV_void, void * VuV_void, int32_t RtV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VddV.v[0].uh[i] = fMPY8UU(fGETUBYTE(0, VuV.uh[i]), fGETUBYTE((2*i+0)%4, RtV)); VddV.v[1].uh[i] = fMPY8UU(fGETUBYTE(1, VuV.uh[i]), fGETUBYTE((2*i+1)%4, RtV)) ; } }
}

void HELPER(V6_vmpyub_acc)(CPUHexagonState *env, void * VxxV_void, void * VuV_void, int32_t RtV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VxxV.v[0].uh[i] += fMPY8UU(fGETUBYTE(0, VuV.uh[i]), fGETUBYTE((2*i+0)%4, RtV)); VxxV.v[1].uh[i] += fMPY8UU(fGETUBYTE(1, VuV.uh[i]), fGETUBYTE((2*i+1)%4, RtV)) ; } }
}

void HELPER(V6_vmpybus)(CPUHexagonState *env, void * VddV_void, void * VuV_void, int32_t RtV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VddV.v[0].h[i] = fMPY8US(fGETUBYTE(0, VuV.uh[i]), fGETBYTE((2*i+0)%4, RtV)); VddV.v[1].h[i] = fMPY8US(fGETUBYTE(1, VuV.uh[i]), fGETBYTE((2*i+1)%4, RtV)) ; } }
}

void HELPER(V6_vmpybus_acc)(CPUHexagonState *env, void * VxxV_void, void * VuV_void, int32_t RtV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VxxV.v[0].h[i] += fMPY8US(fGETUBYTE(0, VuV.uh[i]), fGETBYTE((2*i+0)%4, RtV)); VxxV.v[1].h[i] += fMPY8US(fGETUBYTE(1, VuV.uh[i]), fGETBYTE((2*i+1)%4, RtV)) ; } }
}

void HELPER(V6_vmpabus)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, int32_t RtV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VddV.v[0].h[i] = fMPY8US(fGETUBYTE(0, VuuV.v[0].uh[i]), fGETBYTE(0, RtV)) + fMPY16SS(fGETUBYTE(0, VuuV.v[1].uh[i]), fGETBYTE(1, RtV)); VddV.v[1].h[i] = fMPY8US(fGETUBYTE(1, VuuV.v[0].uh[i]), fGETBYTE(2, RtV)) + fMPY16SS(fGETUBYTE(1, VuuV.v[1].uh[i]), fGETBYTE(3, RtV)) ; } }
}

void HELPER(V6_vmpabus_acc)(CPUHexagonState *env, void * VxxV_void, void * VuuV_void, int32_t RtV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VxxV.v[0].h[i] += fMPY8US(fGETUBYTE(0, VuuV.v[0].uh[i]), fGETBYTE(0, RtV)) + fMPY16SS(fGETUBYTE(0, VuuV.v[1].uh[i]), fGETBYTE(1, RtV)); VxxV.v[1].h[i] += fMPY8US(fGETUBYTE(1, VuuV.v[0].uh[i]), fGETBYTE(2, RtV)) + fMPY16SS(fGETUBYTE(1, VuuV.v[1].uh[i]), fGETBYTE(3, RtV)) ; } }
}

void HELPER(V6_vmpabuu)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, int32_t RtV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VddV.v[0].uh[i] = fMPY8UU(fGETUBYTE(0, VuuV.v[0].uh[i]), fGETUBYTE(0, RtV)) + fMPY8UU(fGETUBYTE(0, VuuV.v[1].uh[i]), fGETUBYTE(1, RtV)); VddV.v[1].uh[i] = fMPY8UU(fGETUBYTE(1, VuuV.v[0].uh[i]), fGETUBYTE(2, RtV)) + fMPY8UU(fGETUBYTE(1, VuuV.v[1].uh[i]), fGETUBYTE(3, RtV)) ; } }
}

void HELPER(V6_vmpabuu_acc)(CPUHexagonState *env, void * VxxV_void, void * VuuV_void, int32_t RtV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VxxV.v[0].uh[i] += fMPY8UU(fGETUBYTE(0, VuuV.v[0].uh[i]), fGETUBYTE(0, RtV)) + fMPY8UU(fGETUBYTE(0, VuuV.v[1].uh[i]), fGETUBYTE(1, RtV)); VxxV.v[1].uh[i] += fMPY8UU(fGETUBYTE(1, VuuV.v[0].uh[i]), fGETUBYTE(2, RtV)) + fMPY8UU(fGETUBYTE(1, VuuV.v[1].uh[i]), fGETUBYTE(3, RtV)) ; } }
}

void HELPER(V6_vmpahb)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, int32_t RtV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].w[i] = fMPY16SS(fGETHALF(0, VuuV.v[0].w[i]), fSE8_16(fGETBYTE(0, RtV))) + fMPY16SS(fGETHALF(0, VuuV.v[1].w[i]), fSE8_16(fGETBYTE(1, RtV))); VddV.v[1].w[i] = fMPY16SS(fGETHALF(1, VuuV.v[0].w[i]), fSE8_16(fGETBYTE(2, RtV))) + fMPY16SS(fGETHALF(1, VuuV.v[1].w[i]), fSE8_16(fGETBYTE(3, RtV))) ; } }
}

void HELPER(V6_vmpahb_acc)(CPUHexagonState *env, void * VxxV_void, void * VuuV_void, int32_t RtV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxxV.v[0].w[i] += fMPY16SS(fGETHALF(0, VuuV.v[0].w[i]), fSE8_16(fGETBYTE(0, RtV))) + fMPY16SS(fGETHALF(0, VuuV.v[1].w[i]), fSE8_16(fGETBYTE(1, RtV))); VxxV.v[1].w[i] += fMPY16SS(fGETHALF(1, VuuV.v[0].w[i]), fSE8_16(fGETBYTE(2, RtV))) + fMPY16SS(fGETHALF(1, VuuV.v[1].w[i]), fSE8_16(fGETBYTE(3, RtV))) ; } }
}

void HELPER(V6_vmpauhb)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, int32_t RtV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].w[i] = fMPY16US(fGETUHALF(0, VuuV.v[0].w[i]), fSE8_16(fGETBYTE(0, RtV))) + fMPY16US(fGETUHALF(0, VuuV.v[1].w[i]), fSE8_16(fGETBYTE(1, RtV))); VddV.v[1].w[i] = fMPY16US(fGETUHALF(1, VuuV.v[0].w[i]), fSE8_16(fGETBYTE(2, RtV))) + fMPY16US(fGETUHALF(1, VuuV.v[1].w[i]), fSE8_16(fGETBYTE(3, RtV))) ; } }
}

void HELPER(V6_vmpauhb_acc)(CPUHexagonState *env, void * VxxV_void, void * VuuV_void, int32_t RtV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxxV.v[0].w[i] += fMPY16US(fGETUHALF(0, VuuV.v[0].w[i]), fSE8_16(fGETBYTE(0, RtV))) + fMPY16US(fGETUHALF(0, VuuV.v[1].w[i]), fSE8_16(fGETBYTE(1, RtV))); VxxV.v[1].w[i] += fMPY16US(fGETUHALF(1, VuuV.v[0].w[i]), fSE8_16(fGETBYTE(2, RtV))) + fMPY16US(fGETUHALF(1, VuuV.v[1].w[i]), fSE8_16(fGETBYTE(3, RtV))) ; } }
}

void HELPER(V6_vmpyh)(CPUHexagonState *env, void * VddV_void, void * VuV_void, int32_t RtV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].w[i] = fMPY16SS(fGETHALF(0, VuV.w[i]), fGETHALF(0, RtV)); VddV.v[1].w[i] = fMPY16SS(fGETHALF(1, VuV.w[i]), fGETHALF(1, RtV)) ; } }
}

void HELPER(V6_vmpyh_acc)(CPUHexagonState *env, void * VxxV_void, void * VuV_void, int32_t RtV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxxV.v[0].w[i] = fCAST8s(VxxV.v[0].w[i]) + fMPY16SS(fGETHALF(0, VuV.w[i]), fGETHALF(0, RtV)); VxxV.v[1].w[i] = fCAST8s(VxxV.v[1].w[i]) + fMPY16SS(fGETHALF(1, VuV.w[i]), fGETHALF(1, RtV)) ; } }
}

void HELPER(V6_vmpyhsat_acc)(CPUHexagonState *env, void * VxxV_void, void * VuV_void, int32_t RtV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxxV.v[0].w[i] = fVSATW(fCAST8s(VxxV.v[0].w[i]) + fMPY16SS(fGETHALF(0, VuV.w[i]), fGETHALF(0, RtV))); VxxV.v[1].w[i] = fVSATW(fCAST8s(VxxV.v[1].w[i]) + fMPY16SS(fGETHALF(1, VuV.w[i]), fGETHALF(1, RtV))) ; } }
}

void HELPER(V6_vmpyhss)(CPUHexagonState *env, void * VdV_void, void * VuV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fSETHALF(0,VdV.w[i],fVSATH(fGETHALF(1,fVSAT((fMPY16SS(fGETHALF(0,VuV.w[i]),fGETHALF(0,RtV))<<1))))); fSETHALF(1,VdV.w[i],fVSATH(fGETHALF(1,fVSAT((fMPY16SS(fGETHALF(1,VuV.w[i]),fGETHALF(1,RtV))<<1))))); ; } }
}

void HELPER(V6_vmpyhsrs)(CPUHexagonState *env, void * VdV_void, void * VuV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fSETHALF(0,VdV.w[i],fVSATH(fGETHALF(1,fVSAT(fROUND((fMPY16SS(fGETHALF(0,VuV.w[i]),fGETHALF(0,RtV))<<1)))))); fSETHALF(1,VdV.w[i],fVSATH(fGETHALF(1,fVSAT(fROUND((fMPY16SS(fGETHALF(1,VuV.w[i]),fGETHALF(1,RtV))<<1)))))); ; } }
}

void HELPER(V6_vmpyuh)(CPUHexagonState *env, void * VddV_void, void * VuV_void, int32_t RtV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VddV.v[0].uw[i] = fMPY16UU(fGETUHALF(0, VuV.uw[i]),fGETUHALF(0,RtV)); VddV.v[1].uw[i] = fMPY16UU(fGETUHALF(1, VuV.uw[i]),fGETUHALF(1,RtV)) ; } }
}

void HELPER(V6_vmpyuh_acc)(CPUHexagonState *env, void * VxxV_void, void * VuV_void, int32_t RtV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxxV.v[0].uw[i] += fMPY16UU(fGETUHALF(0, VuV.uw[i]),fGETUHALF(0,RtV)); VxxV.v[1].uw[i] += fMPY16UU(fGETUHALF(1, VuV.uw[i]),fGETUHALF(1,RtV)) ; } }
}

void HELPER(V6_vmpyihb)(CPUHexagonState *env, void * VdV_void, void * VuV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.h[i] = fMPY16SS(VuV.h[i], fGETBYTE(i % 4, RtV) ) ; } }
}

void HELPER(V6_vmpyihb_acc)(CPUHexagonState *env, void * VxV_void, void * VuV_void, int32_t RtV)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VxV.h[i] += fMPY16SS(VuV.h[i], fGETBYTE(i % 4, RtV) ) ; } }
}

void HELPER(V6_vmpyiwb)(CPUHexagonState *env, void * VdV_void, void * VuV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = fMPY32SS(VuV.w[i], fGETBYTE(i % 4, RtV) ) ; } }
}

void HELPER(V6_vmpyiwb_acc)(CPUHexagonState *env, void * VxV_void, void * VuV_void, int32_t RtV)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxV.w[i] += fMPY32SS(VuV.w[i], fGETBYTE(i % 4, RtV) ) ; } }
}

void HELPER(V6_vmpyiwub)(CPUHexagonState *env, void * VdV_void, void * VuV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = fMPY32SS(VuV.w[i], fGETUBYTE(i % 4, RtV) ) ; } }
}

void HELPER(V6_vmpyiwub_acc)(CPUHexagonState *env, void * VxV_void, void * VuV_void, int32_t RtV)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxV.w[i] += fMPY32SS(VuV.w[i], fGETUBYTE(i % 4, RtV) ) ; } }
}

void HELPER(V6_vmpyiwh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = fMPY32SS(VuV.w[i], fGETHALF(i % 2, RtV)) ; } }
}

void HELPER(V6_vmpyiwh_acc)(CPUHexagonState *env, void * VxV_void, void * VuV_void, int32_t RtV)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxV.w[i] += fMPY32SS(VuV.w[i], fGETHALF(i % 2, RtV)) ; } }
}

void HELPER(V6_vandqrt)(CPUHexagonState *env, void * VdV_void, void * QuV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* QuV is *(MMQReg *)(QuV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VdV.ub[i] = fGETQBIT(QuV,i) ? fGETUBYTE(i % 4, RtV) : 0 ; } }
}

void HELPER(V6_vandqrt_acc)(CPUHexagonState *env, void * VxV_void, void * QuV_void, int32_t RtV)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* QuV is *(MMQReg *)(QuV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VxV.ub[i] |= (fGETQBIT(QuV,i)) ? fGETUBYTE(i % 4, RtV) : 0 ; } }
}

void HELPER(V6_vandnqrt)(CPUHexagonState *env, void * VdV_void, void * QuV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* QuV is *(MMQReg *)(QuV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VdV.ub[i] = !fGETQBIT(QuV,i) ? fGETUBYTE(i % 4, RtV) : 0 ; } }
}

void HELPER(V6_vandnqrt_acc)(CPUHexagonState *env, void * VxV_void, void * QuV_void, int32_t RtV)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* QuV is *(MMQReg *)(QuV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VxV.ub[i] |= !(fGETQBIT(QuV,i)) ? fGETUBYTE(i % 4, RtV) : 0 ; } }
}

void HELPER(V6_vandvrt)(CPUHexagonState *env, void * QdV_void, void * VuV_void, int32_t RtV)
{
    /* QdV is *(MMQReg *)(QdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { fSETQBIT(QdV,i,((VuV.ub[i] & fGETUBYTE(i % 4, RtV)) != 0) ? 1 : 0) ; } }
}

void HELPER(V6_vandvrt_acc)(CPUHexagonState *env, void * QxV_void, void * VuV_void, int32_t RtV)
{
    /* QxV is *(MMQReg *)(QxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { fSETQBIT(QxV,i,fGETQBIT(QxV,i)|(((VuV.ub[i] & fGETUBYTE(i % 4, RtV)) != 0) ? 1 : 0)) ; } }
}

void HELPER(V6_vandvqv)(CPUHexagonState *env, void * VdV_void, void * QvV_void, void * VuV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* QvV is *(MMQReg *)(QvV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VdV.b[i] = fGETQBIT(QvV,i) ? VuV.b[i] : 0 ; } }
}

void HELPER(V6_vandvnqv)(CPUHexagonState *env, void * VdV_void, void * QvV_void, void * VuV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* QvV is *(MMQReg *)(QvV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VdV.b[i] = !fGETQBIT(QvV,i) ? VuV.b[i] : 0 ; } }
}

void HELPER(V6_pred_scalar2)(CPUHexagonState *env, void * QdV_void, int32_t RtV)
{
    /* QdV is *(MMQReg *)(QdV_void) */
    { fHIDE(int i;) for(i = 0; i < fVBYTES(); i++) fSETQBIT(QdV,i,(i < (RtV & (fVBYTES()-1))) ? 1 : 0); }
}

void HELPER(V6_pred_scalar2v2)(CPUHexagonState *env, void * QdV_void, int32_t RtV)
{
    /* QdV is *(MMQReg *)(QdV_void) */
    { fHIDE(int i;) for(i = 0; i < fVBYTES(); i++) fSETQBIT(QdV,i,(i <= ((RtV-1) & (fVBYTES()-1))) ? 1 : 0); }
}

void HELPER(V6_shuffeqw)(CPUHexagonState *env, void * QdV_void, void * QsV_void, void * QtV_void)
{
    /* QdV is *(MMQReg *)(QdV_void) */
    /* QsV is *(MMQReg *)(QsV_void) */
    /* QtV is *(MMQReg *)(QtV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { fSETQBIT(QdV,i, (i & 2) ? fGETQBIT(QsV,i-2) : fGETQBIT(QtV,i) ) ; } }
}

void HELPER(V6_shuffeqh)(CPUHexagonState *env, void * QdV_void, void * QsV_void, void * QtV_void)
{
    /* QdV is *(MMQReg *)(QdV_void) */
    /* QsV is *(MMQReg *)(QsV_void) */
    /* QtV is *(MMQReg *)(QtV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { fSETQBIT(QdV,i, (i & 1) ? fGETQBIT(QsV,i-1) : fGETQBIT(QtV,i) ) ; } }
}

void HELPER(V6_vccombine)(CPUHexagonState *env, void * VddV_void, int32_t PsV, void * VuV_void, void * VvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { if (fLSBOLD(PsV)) { fHIDE(int i;) fVFOREACH(8, i) { VddV.v[0].ub[i] = VvV.ub[i]; VddV.v[1].ub[i] = VuV.ub[i]; } } else {CANCEL;} }
}

void HELPER(V6_vnccombine)(CPUHexagonState *env, void * VddV_void, int32_t PsV, void * VuV_void, void * VvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { if (fLSBOLDNOT(PsV)) { fHIDE(int i;) fVFOREACH(8, i) { VddV.v[0].ub[i] = VvV.ub[i]; VddV.v[1].ub[i] = VuV.ub[i]; } } else {CANCEL;} }
}

void HELPER(V6_vmux)(CPUHexagonState *env, void * VdV_void, void * QtV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* QtV is *(MMQReg *)(QtV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VdV.ub[i] = fGETQBIT(QtV,i) ? VuV.ub[i] : VvV.ub[i] ; } }
}

void HELPER(V6_vswap)(CPUHexagonState *env, void * VddV_void, void * QtV_void, void * VuV_void, void * VvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* QtV is *(MMQReg *)(QtV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { VddV.v[0].ub[i] = fGETQBIT(QtV,i) ? VuV.ub[i] : VvV.ub[i]; VddV.v[1].ub[i] = !fGETQBIT(QtV,i) ? VuV.ub[i] : VvV.ub[i] ; } }
}

void HELPER(V6_vsathub)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fSETBYTE(0, VdV.uh[i], fVSATUB(VvV.h[i])); fSETBYTE(1, VdV.uh[i], fVSATUB(VuV.h[i])) ; } }
}

void HELPER(V6_vsatwh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fSETHALF(0, VdV.w[i], fVSATH(VvV.w[i])); fSETHALF(1, VdV.w[i], fVSATH(VuV.w[i])) ; } }
}

void HELPER(V6_vsatuwuh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fSETHALF(0, VdV.w[i], fVSATUH(VvV.uw[i])); fSETHALF(1, VdV.w[i], fVSATUH(VuV.uw[i])) ; } }
}

void HELPER(V6_vshuffeb)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fSETBYTE(0, VdV.uh[i], fGETUBYTE(0, VvV.uh[i])); fSETBYTE(1, VdV.uh[i], fGETUBYTE(0, VuV.uh[i])) ; } }
}

void HELPER(V6_vshuffob)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fSETBYTE(0, VdV.uh[i], fGETUBYTE(1, VvV.uh[i])); fSETBYTE(1, VdV.uh[i], fGETUBYTE(1, VuV.uh[i])) ; } }
}

void HELPER(V6_vshufeh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fSETHALF(0, VdV.uw[i], fGETUHALF(0, VvV.uw[i])); fSETHALF(1, VdV.uw[i], fGETUHALF(0, VuV.uw[i])) ; } }
}

void HELPER(V6_vshufoh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fSETHALF(0, VdV.uw[i], fGETUHALF(1, VvV.uw[i])); fSETHALF(1, VdV.uw[i], fGETUHALF(1, VuV.uw[i])) ; } }
}

void HELPER(V6_vshuff)(CPUHexagonState *env, void * VyV_void, void * VxV_void, int32_t RtV)
{
    /* VyV is *(MMVector *)(VyV_void) */
    /* VxV is *(MMVector *)(VxV_void) */
    { fHIDE(int offset;) for (offset=1; offset<fVBYTES(); offset<<=1) { if ( RtV & offset) { fHIDE(int k;) fVFOREACH(8, k) { if (!( k & offset)) { fSWAPB(VyV.ub[k], VxV.ub[k+offset]); } } } } }
}

void HELPER(V6_vshuffvdd)(CPUHexagonState *env, void * VddV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int offset;) VddV.v[0] = VvV; VddV.v[1] = VuV; for (offset=1; offset<fVBYTES(); offset<<=1) { if ( RtV & offset) { fHIDE(int k;) fVFOREACH(8, k) { if (!( k & offset)) { fSWAPB(VddV.v[1].ub[k], VddV.v[0].ub[k+offset]); } } } } }
}

void HELPER(V6_vdeal)(CPUHexagonState *env, void * VyV_void, void * VxV_void, int32_t RtV)
{
    /* VyV is *(MMVector *)(VyV_void) */
    /* VxV is *(MMVector *)(VxV_void) */
    { fHIDE(int offset;) for (offset=fVBYTES()>>1; offset>0; offset>>=1) { if ( RtV & offset) { fHIDE(int k;) fVFOREACH(8, k) { if (!( k & offset)) { fSWAPB(VyV.ub[k], VxV.ub[k+offset]); } } } } }
}

void HELPER(V6_vdealvdd)(CPUHexagonState *env, void * VddV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int offset;) VddV.v[0] = VvV; VddV.v[1] = VuV; for (offset=fVBYTES()>>1; offset>0; offset>>=1) { if ( RtV & offset) { fHIDE(int k;) fVFOREACH(8, k) { if (!( k & offset)) { fSWAPB(VddV.v[1].ub[k], VddV.v[0].ub[k+offset]); } } } } }
}

void HELPER(V6_vshufoeh)(CPUHexagonState *env, void * VddV_void, void * VuV_void, void * VvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fSETHALF(0, VddV.v[0].uw[i], fGETUHALF(0, VvV.uw[i])); fSETHALF(1, VddV.v[0].uw[i], fGETUHALF(0, VuV.uw[i])); fSETHALF(0, VddV.v[1].uw[i], fGETUHALF(1, VvV.uw[i])); fSETHALF(1, VddV.v[1].uw[i], fGETUHALF(1, VuV.uw[i])) ; } }
}

void HELPER(V6_vshufoeb)(CPUHexagonState *env, void * VddV_void, void * VuV_void, void * VvV_void)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fSETBYTE(0, VddV.v[0].uh[i], fGETUBYTE(0, VvV.uh[i])); fSETBYTE(1, VddV.v[0].uh[i], fGETUBYTE(0, VuV.uh[i])); fSETBYTE(0, VddV.v[1].uh[i], fGETUBYTE(1, VvV.uh[i])); fSETBYTE(1, VddV.v[1].uh[i], fGETUBYTE(1, VuV.uh[i])) ; } }
}

void HELPER(V6_vdealh)(CPUHexagonState *env, void * VdV_void, void * VuV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.uh[i ] = fGETUHALF(0, VuV.uw[i]); VdV.uh[i+fVELEM(32)] = fGETUHALF(1, VuV.uw[i]) ; } }
}

void HELPER(V6_vdealb)(CPUHexagonState *env, void * VdV_void, void * VuV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.ub[i ] = fGETUBYTE(0, VuV.uh[i]); VdV.ub[i+fVELEM(16)] = fGETUBYTE(1, VuV.uh[i]) ; } }
}

void HELPER(V6_vdealb4w)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.ub[0+i ] = fGETUBYTE(0, VvV.uw[i]); VdV.ub[fVELEM(32)+i ] = fGETUBYTE(2, VvV.uw[i]); VdV.ub[2*fVELEM(32)+i] = fGETUBYTE(0, VuV.uw[i]); VdV.ub[3*fVELEM(32)+i] = fGETUBYTE(2, VuV.uw[i]) ; } }
}

void HELPER(V6_vshuffh)(CPUHexagonState *env, void * VdV_void, void * VuV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fSETHALF(0, VdV.uw[i], VuV.uh[i]); fSETHALF(1, VdV.uw[i], VuV.uh[i+fVELEM(32)]) ; } }
}

void HELPER(V6_vshuffb)(CPUHexagonState *env, void * VdV_void, void * VuV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fSETBYTE(0, VdV.uh[i], VuV.ub[i]); fSETBYTE(1, VdV.uh[i], VuV.ub[i+fVELEM(16)]) ; } }
}

int32_t HELPER(V6_extractw)(CPUHexagonState *env, void * VuV_void, int32_t RsV)
{
    int32_t RdV = 0;
    /* VuV is *(MMVector *)(VuV_void) */
    fHIDE(warn("RdN=%d VuN=%d RsN=%d RsV=0x%08x widx=%d",RdN,VuN,RsN,RsV,((RsV & (fVBYTES()-1)) >> 2));) RdV = VuV.uw[ (RsV & (fVBYTES()-1)) >> 2]; fHIDE(warn("RdV=0x%08x",RdV);)
    return RdV;
}

void HELPER(V6_vinsertwr)(CPUHexagonState *env, void * VxV_void, int32_t RtV)
{
    /* VxV is *(MMVector *)(VxV_void) */
    VxV.uw[0] = RtV;
}

void HELPER(V6_vdelta)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int offset;) fHIDE(int k;) fHIDE(mmvector_t tmp;) tmp = VuV; for (offset=fVBYTES(); (offset>>=1)>0; ) { for (k = 0; k<fVBYTES(); k++) { VdV.ub[k] = (VvV.ub[k]&offset) ? tmp.ub[k^offset] : tmp.ub[k]; } for (k = 0; k<fVBYTES(); k++) { tmp.ub[k] = VdV.ub[k]; } } }
}

void HELPER(V6_vrdelta)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int offset;) fHIDE(int k;) fHIDE(mmvector_t tmp;) tmp = VuV; for (offset=1; offset<fVBYTES(); offset<<=1){ for (k = 0; k<fVBYTES(); k++) { VdV.ub[k] = (VvV.ub[k]&offset) ? tmp.ub[k^offset] : tmp.ub[k]; } for (k = 0; k<fVBYTES(); k++) { tmp.ub[k] = VdV.ub[k]; } } }
}

void HELPER(V6_vcl0w)(CPUHexagonState *env, void * VdV_void, void * VuV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.uw[i]=fCL1_4(~VuV.uw[i]) ; } }
}

void HELPER(V6_vcl0h)(CPUHexagonState *env, void * VdV_void, void * VuV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.uh[i]=fCL1_2(~VuV.uh[i]) ; } }
}

void HELPER(V6_vnormamtw)(CPUHexagonState *env, void * VdV_void, void * VuV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i]=fMAX(fCL1_4(~VuV.w[i]),fCL1_4(VuV.w[i]))-1; fHIDE(IV1DEAD();) ; } }
}

void HELPER(V6_vnormamth)(CPUHexagonState *env, void * VdV_void, void * VuV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.h[i]=fMAX(fCL1_2(~VuV.h[i]),fCL1_2(VuV.h[i]))-1; fHIDE(IV1DEAD();) ; } }
}

void HELPER(V6_vaddclbw)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.w[i] = fMAX(fCL1_4(~VuV.w[i]),fCL1_4(VuV.w[i])) + VvV.w[i] ; } }
}

void HELPER(V6_vaddclbh)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.h[i] = fMAX(fCL1_2(~VuV.h[i]),fCL1_2(VuV.h[i])) + VvV.h[i] ; } }
}

void HELPER(V6_vpopcounth)(CPUHexagonState *env, void * VdV_void, void * VuV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.uh[i]=fCOUNTONES_2(VuV.uh[i]) ; } }
}

void HELPER(V6_vlutvvb)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { fHIDE(unsigned int idx;) fHIDE(int matchval;) fHIDE(int oddhalf;) matchval = RtV & 0x7; oddhalf = (RtV >> (fVECLOGSIZE()-6)) & 0x1; idx = VuV.ub[i]; VdV.b[i] = ((idx & 0xE0) == (matchval << 5)) ? fGETBYTE(oddhalf,VvV.h[idx % fVELEM(16)]) : 0 ; } }
}

void HELPER(V6_vlutvvb_oracc)(CPUHexagonState *env, void * VxV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { fHIDE(unsigned int idx;) fHIDE(int matchval;) fHIDE(int oddhalf;) matchval = RtV & 0x7; oddhalf = (RtV >> (fVECLOGSIZE()-6)) & 0x1; idx = VuV.ub[i]; VxV.b[i] |= ((idx & 0xE0) == (matchval << 5)) ? fGETBYTE(oddhalf,VvV.h[idx % fVELEM(16)]) : 0 ; } }
}

void HELPER(V6_vlutvwh)(CPUHexagonState *env, void * VddV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fHIDE(unsigned int idx;) fHIDE(int matchval;) fHIDE(int oddhalf;) matchval = RtV & 0xF; oddhalf = (RtV >> (fVECLOGSIZE()-6)) & 0x1; idx = fGETUBYTE(0,VuV.uh[i]); VddV.v[0].h[i] = ((idx & 0xF0) == (matchval << 4)) ? fGETHALF(oddhalf,VvV.w[idx % fVELEM(32)]) : 0; idx = fGETUBYTE(1,VuV.uh[i]); VddV.v[1].h[i] = ((idx & 0xF0) == (matchval << 4)) ? fGETHALF(oddhalf,VvV.w[idx % fVELEM(32)]) : 0 ; } }
}

void HELPER(V6_vlutvwh_oracc)(CPUHexagonState *env, void * VxxV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fHIDE(unsigned int idx;) fHIDE(int matchval;) fHIDE(int oddhalf;) matchval = fGETUBYTE(0,RtV) & 0xF; oddhalf = (RtV >> (fVECLOGSIZE()-6)) & 0x1; idx = fGETUBYTE(0,VuV.uh[i]); VxxV.v[0].h[i] |= ((idx & 0xF0) == (matchval << 4)) ? fGETHALF(oddhalf,VvV.w[idx % fVELEM(32)]) : 0; idx = fGETUBYTE(1,VuV.uh[i]); VxxV.v[1].h[i] |= ((idx & 0xF0) == (matchval << 4)) ? fGETHALF(oddhalf,VvV.w[idx % fVELEM(32)]) : 0 ; } }
}

void HELPER(V6_vlutvvbi)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void, int32_t uiV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { fHIDE(unsigned int idx;) fHIDE(int matchval;) fHIDE(int oddhalf;) matchval = uiV & 0x7; oddhalf = (uiV >> (fVECLOGSIZE()-6)) & 0x1; idx = VuV.ub[i]; VdV.b[i] = ((idx & 0xE0) == (matchval << 5)) ? fGETBYTE(oddhalf,VvV.h[idx % fVELEM(16)]) : 0 ; } }
}

void HELPER(V6_vlutvvb_oracci)(CPUHexagonState *env, void * VxV_void, void * VuV_void, void * VvV_void, int32_t uiV)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { fHIDE(unsigned int idx;) fHIDE(int matchval;) fHIDE(int oddhalf;) matchval = uiV & 0x7; oddhalf = (uiV >> (fVECLOGSIZE()-6)) & 0x1; idx = VuV.ub[i]; VxV.b[i] |= ((idx & 0xE0) == (matchval << 5)) ? fGETBYTE(oddhalf,VvV.h[idx % fVELEM(16)]) : 0 ; } }
}

void HELPER(V6_vlutvwhi)(CPUHexagonState *env, void * VddV_void, void * VuV_void, void * VvV_void, int32_t uiV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fHIDE(unsigned int idx;) fHIDE(int matchval;) fHIDE(int oddhalf;) matchval = uiV & 0xF; oddhalf = (uiV >> (fVECLOGSIZE()-6)) & 0x1; idx = fGETUBYTE(0,VuV.uh[i]); VddV.v[0].h[i] = ((idx & 0xF0) == (matchval << 4)) ? fGETHALF(oddhalf,VvV.w[idx % fVELEM(32)]) : 0; idx = fGETUBYTE(1,VuV.uh[i]); VddV.v[1].h[i] = ((idx & 0xF0) == (matchval << 4)) ? fGETHALF(oddhalf,VvV.w[idx % fVELEM(32)]) : 0 ; } }
}

void HELPER(V6_vlutvwh_oracci)(CPUHexagonState *env, void * VxxV_void, void * VuV_void, void * VvV_void, int32_t uiV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fHIDE(unsigned int idx;) fHIDE(int matchval;) fHIDE(int oddhalf;) matchval = uiV & 0xF; oddhalf = (uiV >> (fVECLOGSIZE()-6)) & 0x1; idx = fGETUBYTE(0,VuV.uh[i]); VxxV.v[0].h[i] |= ((idx & 0xF0) == (matchval << 4)) ? fGETHALF(oddhalf,VvV.w[idx % fVELEM(32)]) : 0; idx = fGETUBYTE(1,VuV.uh[i]); VxxV.v[1].h[i] |= ((idx & 0xF0) == (matchval << 4)) ? fGETHALF(oddhalf,VvV.w[idx % fVELEM(32)]) : 0 ; } }
}

void HELPER(V6_vlutvvb_nm)(CPUHexagonState *env, void * VdV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(8, i) { fHIDE(unsigned int idx;) fHIDE(int oddhalf;) fHIDE(int matchval;) matchval = RtV & 0x7; oddhalf = (RtV >> (fVECLOGSIZE()-6)) & 0x1; idx = VuV.ub[i]; idx = (idx&0x1F) | (matchval<<5); VdV.b[i] = fGETBYTE(oddhalf,VvV.h[idx % fVELEM(16)]) ; } }
}

void HELPER(V6_vlutvwh_nm)(CPUHexagonState *env, void * VddV_void, void * VuV_void, void * VvV_void, int32_t RtV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { fHIDE(unsigned int idx;) fHIDE(int oddhalf;) fHIDE(int matchval;) matchval = RtV & 0xF; oddhalf = (RtV >> (fVECLOGSIZE()-6)) & 0x1; idx = fGETUBYTE(0,VuV.uh[i]); idx = (idx&0x0F) | (matchval<<4); VddV.v[0].h[i] = fGETHALF(oddhalf,VvV.w[idx % fVELEM(32)]); idx = fGETUBYTE(1,VuV.uh[i]); idx = (idx&0x0F) | (matchval<<4); VddV.v[1].h[i] = fGETHALF(oddhalf,VvV.w[idx % fVELEM(32)]) ; } }
}

void HELPER(V6_vmpahhsat)(CPUHexagonState *env, void * VxV_void, void * VuV_void, int64_t RttV)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VxV.h[i]= fVSATH( ( ( fMPY16SS(VxV.h[i],VuV.h[i])<<1) + (fGETHALF(( (VuV.h[i]>>14)&0x3), RttV )<<15))>>16) ; } }
}

void HELPER(V6_vmpauhuhsat)(CPUHexagonState *env, void * VxV_void, void * VuV_void, int64_t RttV)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VxV.h[i]= fVSATH( ( fMPY16SU(VxV.h[i],VuV.uh[i]) + (fGETUHALF(((VuV.uh[i]>>14)&0x3), RttV )<<15))>>16) ; } }
}

void HELPER(V6_vmpsuhuhsat)(CPUHexagonState *env, void * VxV_void, void * VuV_void, int64_t RttV)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VxV.h[i]= fVSATH( ( fMPY16SU(VxV.h[i],VuV.uh[i]) - (fGETUHALF(((VuV.uh[i]>>14)&0x3), RttV )<<15))>>16) ; } }
}

void HELPER(V6_vlut4)(CPUHexagonState *env, void * VdV_void, void * VuV_void, int64_t RttV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(16, i) { VdV.h[i]= fGETHALF( ((VuV.h[i]>>14)&0x3), RttV ) ; } }
}

void HELPER(V6_vmpyuhe)(CPUHexagonState *env, void * VdV_void, void * VuV_void, int32_t RtV)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VdV.uw[i] = fMPY16UU(fGETUHALF(0, VuV.uw[i]),fGETUHALF(0,RtV)) ; } }
}

void HELPER(V6_vmpyuhe_acc)(CPUHexagonState *env, void * VxV_void, void * VuV_void, int32_t RtV)
{
    /* VxV is *(MMVector *)(VxV_void) */
    /* VuV is *(MMVector *)(VuV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { VxV.uw[i] += fMPY16UU(fGETUHALF(0, VuV.uw[i]),fGETUHALF(0,RtV)) ; } }
}

void HELPER(V6_vgathermw)(CPUHexagonState *env, int32_t RtV, int32_t MuV, void * VvV_void)
{
    uint32_t EA;
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fHIDE(int element_size = 4;) fHIDE(fGATHER_INIT( RtV, MuV, element_size);) fVLASTBYTE(MuV, element_size); fVALIGN(RtV, element_size); fVFOREACH(32, i) { EA = RtV+VvV.uw[i]; fVLOG_VTCM_GATHER_WORD(EA, VvV.uw[i], i,MuV); } fGATHER_FINISH() }
}

void HELPER(V6_vgathermh)(CPUHexagonState *env, int32_t RtV, int32_t MuV, void * VvV_void)
{
    uint32_t EA;
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fHIDE(int element_size = 2;) fHIDE(fGATHER_INIT( RtV, MuV, element_size);) fVLASTBYTE(MuV, element_size); fVALIGN(RtV, element_size); fVFOREACH(16, i) { EA = RtV+VvV.uh[i]; fVLOG_VTCM_GATHER_HALFWORD(EA, VvV.uh[i], i,MuV); } fGATHER_FINISH() }
}

void HELPER(V6_vgathermhw)(CPUHexagonState *env, int32_t RtV, int32_t MuV, void * VvvV_void)
{
    uint32_t EA;
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    { fHIDE(int i;) fHIDE(int j;) fHIDE(int element_size = 2;) fHIDE(fGATHER_INIT( RtV, MuV, element_size);) fVLASTBYTE(MuV, element_size); fVALIGN(RtV, element_size); fVFOREACH(32, i) { for(j = 0; j < 2; j++) { EA = RtV+VvvV.v[j].uw[i]; fVLOG_VTCM_GATHER_HALFWORD_DV(EA, VvvV.v[j].uw[i], (2*i+j),i,j,MuV); } } fGATHER_FINISH() }
}

void HELPER(V6_vgathermwq)(CPUHexagonState *env, void * QsV_void, int32_t RtV, int32_t MuV, void * VvV_void)
{
    uint32_t EA;
    /* QsV is *(MMQReg *)(QsV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fHIDE(int element_size = 4;) fHIDE(fGATHER_INIT( RtV, MuV, element_size);) fVLASTBYTE(MuV, element_size); fVALIGN(RtV, element_size); fVFOREACH(32, i) { EA = RtV+VvV.uw[i]; fVLOG_VTCM_GATHER_WORDQ(EA, VvV.uw[i], i,QsV,MuV); } fGATHER_FINISH() }
}

void HELPER(V6_vgathermhq)(CPUHexagonState *env, void * QsV_void, int32_t RtV, int32_t MuV, void * VvV_void)
{
    uint32_t EA;
    /* QsV is *(MMQReg *)(QsV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    { fHIDE(int i;) fHIDE(int element_size = 2;) fHIDE(fGATHER_INIT( RtV, MuV, element_size);) fVLASTBYTE(MuV, element_size); fVALIGN(RtV, element_size); fVFOREACH(16, i) { EA = RtV+VvV.uh[i]; fVLOG_VTCM_GATHER_HALFWORDQ(EA, VvV.uh[i], i,QsV,MuV); } fGATHER_FINISH() }
}

void HELPER(V6_vgathermhwq)(CPUHexagonState *env, void * QsV_void, int32_t RtV, int32_t MuV, void * VvvV_void)
{
    uint32_t EA;
    /* QsV is *(MMQReg *)(QsV_void) */
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    { fHIDE(int i;) fHIDE(int j;) fHIDE(int element_size = 2;) fHIDE(fGATHER_INIT( RtV, MuV, element_size);) fVLASTBYTE(MuV, element_size); fVALIGN(RtV, element_size); fVFOREACH(32, i) { for(j = 0; j < 2; j++) { EA = RtV+VvvV.v[j].uw[i]; fVLOG_VTCM_GATHER_HALFWORDQ_DV(EA, VvvV.v[j].uw[i], (2*i+j),i,j,QsV,MuV); } } fGATHER_FINISH() }
}

void HELPER(V6_vscattermw)(CPUHexagonState *env, int32_t RtV, int32_t MuV, void * VvV_void, void * VwV_void)
{
    uint32_t EA;
    /* VvV is *(MMVector *)(VvV_void) */
    /* VwV is *(MMVector *)(VwV_void) */
    { fHIDE(int i;) fHIDE(int element_size = 4;) fHIDE(fSCATTER_INIT( RtV, MuV, element_size);) fVLASTBYTE(MuV, element_size); fVALIGN(RtV, element_size); fVFOREACH(32, i) { EA = RtV+VvV.uw[i]; fVLOG_VTCM_WORD(EA, VvV.uw[i], VwV,i,MuV); } fSCATTER_FINISH(0) }
}

void HELPER(V6_vscattermh)(CPUHexagonState *env, int32_t RtV, int32_t MuV, void * VvV_void, void * VwV_void)
{
    uint32_t EA;
    /* VvV is *(MMVector *)(VvV_void) */
    /* VwV is *(MMVector *)(VwV_void) */
    { fHIDE(int i;) fHIDE(int element_size = 2;) fHIDE(fSCATTER_INIT( RtV, MuV, element_size);) fVLASTBYTE(MuV, element_size); fVALIGN(RtV, element_size); fVFOREACH(16, i) { EA = RtV+VvV.uh[i]; fVLOG_VTCM_HALFWORD(EA,VvV.uh[i],VwV,i,MuV); } fSCATTER_FINISH(0) }
}

void HELPER(V6_vscattermw_add)(CPUHexagonState *env, int32_t RtV, int32_t MuV, void * VvV_void, void * VwV_void)
{
    uint32_t EA;
    /* VvV is *(MMVector *)(VvV_void) */
    /* VwV is *(MMVector *)(VwV_void) */
    { fHIDE(int i;) fHIDE(int ALIGNMENT=4;) fHIDE(int element_size = 4;) fHIDE(fSCATTER_INIT( RtV, MuV, element_size);) fVLASTBYTE(MuV, element_size); fVALIGN(RtV, element_size); fVFOREACH(32, i) { EA = (RtV+fVALIGN(VvV.uw[i],ALIGNMENT)); fVLOG_VTCM_WORD_INCREMENT(EA,VvV.uw[i],VwV,i,ALIGNMENT,MuV); } fHIDE(fLOG_SCATTER_OP(4);) fSCATTER_FINISH(1) }
}

void HELPER(V6_vscattermh_add)(CPUHexagonState *env, int32_t RtV, int32_t MuV, void * VvV_void, void * VwV_void)
{
    uint32_t EA;
    /* VvV is *(MMVector *)(VvV_void) */
    /* VwV is *(MMVector *)(VwV_void) */
    { fHIDE(int i;) fHIDE(int ALIGNMENT=2;) fHIDE(int element_size = 2;) fHIDE(fSCATTER_INIT( RtV, MuV, element_size);) fVLASTBYTE(MuV, element_size); fVALIGN(RtV, element_size); fVFOREACH(16, i) { EA = (RtV+fVALIGN(VvV.uh[i],ALIGNMENT)); fVLOG_VTCM_HALFWORD_INCREMENT(EA,VvV.uh[i],VwV,i,ALIGNMENT,MuV); } fHIDE(fLOG_SCATTER_OP(2);) fSCATTER_FINISH(1) }
}

void HELPER(V6_vscattermwq)(CPUHexagonState *env, void * QsV_void, int32_t RtV, int32_t MuV, void * VvV_void, void * VwV_void)
{
    uint32_t EA;
    /* QsV is *(MMQReg *)(QsV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    /* VwV is *(MMVector *)(VwV_void) */
    { fHIDE(int i;) fHIDE(int element_size = 4;) fHIDE(fSCATTER_INIT( RtV, MuV, element_size);) fVLASTBYTE(MuV, element_size); fVALIGN(RtV, element_size); fVFOREACH(32, i) { EA = RtV+VvV.uw[i]; fVLOG_VTCM_WORDQ(EA,VvV.uw[i], VwV,i,QsV,MuV); } fSCATTER_FINISH(0) }
}

void HELPER(V6_vscattermhq)(CPUHexagonState *env, void * QsV_void, int32_t RtV, int32_t MuV, void * VvV_void, void * VwV_void)
{
    uint32_t EA;
    /* QsV is *(MMQReg *)(QsV_void) */
    /* VvV is *(MMVector *)(VvV_void) */
    /* VwV is *(MMVector *)(VwV_void) */
    { fHIDE(int i;) fHIDE(int element_size = 2;) fHIDE(fSCATTER_INIT( RtV, MuV, element_size);) fVLASTBYTE(MuV, element_size); fVALIGN(RtV, element_size); fVFOREACH(16, i) { EA = RtV+VvV.uh[i]; fVLOG_VTCM_HALFWORDQ(EA,VvV.uh[i],VwV,i,QsV,MuV); } fSCATTER_FINISH(0) }
}

void HELPER(V6_vscattermhw)(CPUHexagonState *env, int32_t RtV, int32_t MuV, void * VvvV_void, void * VwV_void)
{
    uint32_t EA;
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    /* VwV is *(MMVector *)(VwV_void) */
    { fHIDE(int i;) fHIDE(int j;) fHIDE(int element_size = 2;) fHIDE(fSCATTER_INIT( RtV, MuV, element_size);) fVLASTBYTE(MuV, element_size); fVALIGN(RtV, element_size); fVFOREACH(32, i) { for(j = 0; j < 2; j++) { EA = RtV+VvvV.v[j].uw[i]; fVLOG_VTCM_HALFWORD_DV(EA,VvvV.v[j].uw[i],VwV,(2*i+j),i,j,MuV); } } fSCATTER_FINISH(0) }
}

void HELPER(V6_v6mpyvubs10_vxx)(CPUHexagonState *env, void * VxxV_void, void * VuuV_void, void * VvvV_void, int32_t uiV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(size2s_t c00;) fGET10BIT(c00, VvvV.v[0].uw[i], 0) fHIDE(size2s_t c01;) fGET10BIT(c01, VvvV.v[0].uw[i], 1) fHIDE(size2s_t c02;) fGET10BIT(c02, VvvV.v[0].uw[i], 2) fHIDE(size2s_t c10;) fGET10BIT(c10, VvvV.v[1].uw[i], 0) fHIDE(size2s_t c11;) fGET10BIT(c11, VvvV.v[1].uw[i], 1) fHIDE(size2s_t c12;) fGET10BIT(c12, VvvV.v[1].uw[i], 2) if (uiV == 0) { VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c10); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[1].uw[i]), c11); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[1].uw[i]), c12); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[0].uw[i]), c00); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c01); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[1].uw[i]), c02); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[0].uw[i]), c10); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c11); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[1].uw[i]), c12); } else if (uiV == 1) { VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c00); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[1].uw[i]), c01); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[1].uw[i]), c02); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c10); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[1].uw[i]), c11); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[1].uw[i]), c12); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[0].uw[i]), c00); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c01); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[1].uw[i]), c02); } else if (uiV == 2) { VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[0].uw[i]), c10); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c11); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[1].uw[i]), c12); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[0].uw[i]), c00); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[0].uw[i]), c01); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c02); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[0].uw[i]), c10); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[0].uw[i]), c11); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c12); } else if (uiV == 3) { VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[0].uw[i]), c00); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c01); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[1].uw[i]), c02); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[0].uw[i]), c10); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c11); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[1].uw[i]), c12); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[0].uw[i]), c00); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[0].uw[i]), c01); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c02); } ; } }
}

void HELPER(V6_v6mpyhubs10_vxx)(CPUHexagonState *env, void * VxxV_void, void * VuuV_void, void * VvvV_void, int32_t uiV)
{
    /* VxxV is *(MMVectorPair *)(VxxV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(size2s_t c00;) fGET10BIT(c00, VvvV.v[0].uw[i], 0) fHIDE(size2s_t c01;) fGET10BIT(c01, VvvV.v[0].uw[i], 1) fHIDE(size2s_t c02;) fGET10BIT(c02, VvvV.v[0].uw[i], 2) fHIDE(size2s_t c10;) fGET10BIT(c10, VvvV.v[1].uw[i], 0) fHIDE(size2s_t c11;) fGET10BIT(c11, VvvV.v[1].uw[i], 1) fHIDE(size2s_t c12;) fGET10BIT(c12, VvvV.v[1].uw[i], 2) if (uiV == 0) { VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[1].uw[i]), c10); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[1].uw[i]), c11); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c12); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[1].uw[i]), c00); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c01); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[0].uw[i]), c02); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[1].uw[i]), c10); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c11); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[0].uw[i]), c12); } else if (uiV == 1) { VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[1].uw[i]), c00); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[1].uw[i]), c01); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c02); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[1].uw[i]), c10); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[1].uw[i]), c11); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c12); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[1].uw[i]), c00); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c01); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[0].uw[i]), c02); } else if (uiV == 2) { VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[1].uw[i]), c10); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c11); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[0].uw[i]), c12); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c00); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[0].uw[i]), c01); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[0].uw[i]), c02); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c10); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[0].uw[i]), c11); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[0].uw[i]), c12); } else if (uiV == 3) { VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[1].uw[i]), c00); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c01); VxxV.v[1].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[0].uw[i]), c02); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[1].uw[i]), c10); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c11); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[0].uw[i]), c12); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c00); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[0].uw[i]), c01); VxxV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[0].uw[i]), c02); } ; } }
}

void HELPER(V6_v6mpyvubs10)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, void * VvvV_void, int32_t uiV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(short c00;) fGET10BIT(c00, VvvV.v[0].uw[i], 0) fHIDE(short c01;) fGET10BIT(c01, VvvV.v[0].uw[i], 1) fHIDE(short c02;) fGET10BIT(c02, VvvV.v[0].uw[i], 2) fHIDE(short c10;) fGET10BIT(c10, VvvV.v[1].uw[i], 0) fHIDE(short c11;) fGET10BIT(c11, VvvV.v[1].uw[i], 1) fHIDE(short c12;) fGET10BIT(c12, VvvV.v[1].uw[i], 2) if (uiV == 0) { VddV.v[1].w[i] = fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c10); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[1].uw[i]), c11); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[1].uw[i]), c12); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[0].uw[i]), c00); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c01); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[1].uw[i]), c02); VddV.v[0].w[i] = fMPY16US(fGETUBYTE(1,VuuV.v[0].uw[i]), c10); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c11); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[1].uw[i]), c12); } else if (uiV == 1) { VddV.v[1].w[i] = fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c00); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[1].uw[i]), c01); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[1].uw[i]), c02); VddV.v[0].w[i] = fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c10); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[1].uw[i]), c11); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[1].uw[i]), c12); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[0].uw[i]), c00); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c01); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[1].uw[i]), c02); } else if (uiV == 2) { VddV.v[1].w[i] = fMPY16US(fGETUBYTE(2,VuuV.v[0].uw[i]), c10); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c11); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[1].uw[i]), c12); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[0].uw[i]), c00); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[0].uw[i]), c01); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c02); VddV.v[0].w[i] = fMPY16US(fGETUBYTE(0,VuuV.v[0].uw[i]), c10); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[0].uw[i]), c11); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c12); } else if (uiV == 3) { VddV.v[1].w[i] = fMPY16US(fGETUBYTE(2,VuuV.v[0].uw[i]), c00); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c01); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[1].uw[i]), c02); VddV.v[0].w[i] = fMPY16US(fGETUBYTE(2,VuuV.v[0].uw[i]), c10); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c11); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[1].uw[i]), c12); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[0].uw[i]), c00); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[0].uw[i]), c01); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c02); } ; } }
}

void HELPER(V6_v6mpyhubs10)(CPUHexagonState *env, void * VddV_void, void * VuuV_void, void * VvvV_void, int32_t uiV)
{
    /* VddV is *(MMVectorPair *)(VddV_void) */
    /* VuuV is *(MMVectorPair *)(VuuV_void) */
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    { fHIDE(int i;) fVFOREACH(32, i) { fHIDE(short c00;) fGET10BIT(c00, VvvV.v[0].uw[i], 0) fHIDE(short c01;) fGET10BIT(c01, VvvV.v[0].uw[i], 1) fHIDE(short c02;) fGET10BIT(c02, VvvV.v[0].uw[i], 2) fHIDE(short c10;) fGET10BIT(c10, VvvV.v[1].uw[i], 0) fHIDE(short c11;) fGET10BIT(c11, VvvV.v[1].uw[i], 1) fHIDE(short c12;) fGET10BIT(c12, VvvV.v[1].uw[i], 2) if (uiV == 0) { VddV.v[1].w[i] = fMPY16US(fGETUBYTE(3,VuuV.v[1].uw[i]), c10); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[1].uw[i]), c11); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c12); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[1].uw[i]), c00); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c01); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[0].uw[i]), c02); VddV.v[0].w[i] = fMPY16US(fGETUBYTE(2,VuuV.v[1].uw[i]), c10); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c11); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[0].uw[i]), c12); } else if (uiV == 1) { VddV.v[1].w[i] = fMPY16US(fGETUBYTE(3,VuuV.v[1].uw[i]), c00); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[1].uw[i]), c01); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c02); VddV.v[0].w[i] = fMPY16US(fGETUBYTE(3,VuuV.v[1].uw[i]), c10); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[1].uw[i]), c11); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c12); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[1].uw[i]), c00); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c01); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[0].uw[i]), c02); } else if (uiV == 2) { VddV.v[1].w[i] = fMPY16US(fGETUBYTE(1,VuuV.v[1].uw[i]), c10); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c11); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[0].uw[i]), c12); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c00); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[0].uw[i]), c01); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[0].uw[i]), c02); VddV.v[0].w[i] = fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c10); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[0].uw[i]), c11); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[0].uw[i]), c12); } else if (uiV == 3) { VddV.v[1].w[i] = fMPY16US(fGETUBYTE(1,VuuV.v[1].uw[i]), c00); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c01); VddV.v[1].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[0].uw[i]), c02); VddV.v[0].w[i] = fMPY16US(fGETUBYTE(1,VuuV.v[1].uw[i]), c10); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(3,VuuV.v[0].uw[i]), c11); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(1,VuuV.v[0].uw[i]), c12); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[1].uw[i]), c00); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(2,VuuV.v[0].uw[i]), c01); VddV.v[0].w[i] += fMPY16US(fGETUBYTE(0,VuuV.v[0].uw[i]), c02); } ; } }
}

void HELPER(V6_vscattermhwq)(CPUHexagonState *env, void * QsV_void, int32_t RtV, int32_t MuV, void * VvvV_void, void * VwV_void)
{
    uint32_t EA;
    /* QsV is *(MMQReg *)(QsV_void) */
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    /* VwV is *(MMVector *)(VwV_void) */
    { fHIDE(int i;) fHIDE(int j;) fHIDE(int element_size = 2;) fHIDE(fSCATTER_INIT( RtV, MuV, element_size);) fVLASTBYTE(MuV, element_size); fVALIGN(RtV, element_size); fVFOREACH(32, i) { for(j = 0; j < 2; j++) { EA = RtV+VvvV.v[j].uw[i]; fVLOG_VTCM_HALFWORDQ_DV(EA,VvvV.v[j].uw[i],VwV,(2*i+j),QsV,i,j,MuV); } } fSCATTER_FINISH(0) }
}

void HELPER(V6_vscattermhw_add)(CPUHexagonState *env, int32_t RtV, int32_t MuV, void * VvvV_void, void * VwV_void)
{
    uint32_t EA;
    /* VvvV is *(MMVectorPair *)(VvvV_void) */
    /* VwV is *(MMVector *)(VwV_void) */
    { fHIDE(int i;) fHIDE(int j;) fHIDE(int ALIGNMENT=2;) fHIDE(int element_size = 2;) fHIDE(fSCATTER_INIT( RtV, MuV, element_size);) fVLASTBYTE(MuV, element_size); fVALIGN(RtV, element_size); fVFOREACH(32, i) { for(j = 0; j < 2; j++) { EA = RtV + fVALIGN(VvvV.v[j].uw[i],ALIGNMENT);; fVLOG_VTCM_HALFWORD_INCREMENT_DV(EA,VvvV.v[j].uw[i],VwV,(2*i+j),i,j,ALIGNMENT,MuV); } } fHIDE(fLOG_SCATTER_OP(2);) fSCATTER_FINISH(1) }
}

void HELPER(V6_vprefixqb)(CPUHexagonState *env, void * VdV_void, void * QvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* QvV is *(MMQReg *)(QvV_void) */
    { fHIDE(int i;) fHIDE(size1u_t acc = 0;) fVFOREACH(8, i) { acc += fGETQBIT(QvV,i); VdV.ub[i] = acc; } }
}

void HELPER(V6_vprefixqh)(CPUHexagonState *env, void * VdV_void, void * QvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* QvV is *(MMQReg *)(QvV_void) */
    { fHIDE(int i;) fHIDE(size2u_t acc = 0;) fVFOREACH(16, i) { acc += fGETQBIT(QvV,i*2+0); acc += fGETQBIT(QvV,i*2+1); VdV.uh[i] = acc; } }
}

void HELPER(V6_vprefixqw)(CPUHexagonState *env, void * VdV_void, void * QvV_void)
{
    /* VdV is *(MMVector *)(VdV_void) */
    /* QvV is *(MMQReg *)(QvV_void) */
    { fHIDE(int i;) fHIDE(size4u_t acc = 0;) fVFOREACH(32, i) { acc += fGETQBIT(QvV,i*4+0); acc += fGETQBIT(QvV,i*4+1); acc += fGETQBIT(QvV,i*4+2); acc += fGETQBIT(QvV,i*4+3); VdV.uw[i] = acc; } }
}

