#ifndef __ASN_IOMANIP_H__
#define __ASN_IOMANIP_H__

_BEGIN_SNACC_NAMESPACE

inline int SNACCDLL_API
getSNACCEncoderIOSType()
{
    static int iDelimIdx = std::ios_base::xalloc();
    return iDelimIdx;
}

static inline std::ios_base& SNACCDLL_API
SNACC_setiosencodetype(std::ios_base &s, SNACCEncodeDecodeRules t)
{
    s.iword(getSNACCEncoderIOSType()) = (int)t;
    return s;
}

static inline SNACCEncodeDecodeRules SNACCDLL_API
SNACC_getiosencodetype(std::ios_base &s)
{
    return (SNACCEncodeDecodeRules)s.iword(getSNACCEncoderIOSType());
}

static inline
std::ios_base & SNACCDLL_API EncodeBER(std::ios_base &s)
{
    return SNACC_setiosencodetype(s, BER);
}

static inline
std::ios_base & SNACCDLL_API EncodeNORMAL(std::ios_base &s)
{
    return SNACC_setiosencodetype(s, SNACC_ASCII);
}

static inline
std::ios_base & SNACCDLL_API EncodePER(std::ios_base &s)
{
    return SNACC_setiosencodetype(s, PER);
}

_END_SNACC_NAMESPACE

// Overload of operator<< to stream out an AsnType
std::ostream& SNACCDLL_API operator<<(std::ostream& os,
                                      const SNACC::AsnType& a);

// Overload of operator>> to stream into an AsnType
std::istream& SNACCDLL_API operator>>(std::istream& is, SNACC::AsnType& a);

#endif
