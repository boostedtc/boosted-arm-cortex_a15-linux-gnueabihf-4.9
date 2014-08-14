/* { dg-do compile } */
/* { dg-options "-mavx512f -O2" } */
/* { dg-final { scan-assembler-times "vinserti32x4\[^\n\]*xmm\[^\n\]*zmm\[^\n\]*zmm\[0-9\]\[^\{\]" 1 } } */
/* { dg-final { scan-assembler-times "vinserti32x4\[^\n\]*\{z\}" 1 } } */
/* { dg-final { scan-assembler-times "vinserti32x4\[^\n\]*\{%k\[1-7\]\}\[^\{\]" 1 } } */

#include <immintrin.h>

volatile __m512i x,a;
volatile __m128i y;

void extern
avx512f_test (void)
{
  x = _mm512_maskz_inserti32x4 (6, x, y, 1);
  x = _mm512_mask_inserti32x4 (a, 6, x, y, 1);
  x = _mm512_inserti32x4 (x, y, 1);
}
