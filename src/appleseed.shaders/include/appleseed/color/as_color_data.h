
//
// This source file is part of appleseed.
// Visit http://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2016-2017 Luis Barrancos, The appleseedhq Organization
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef AS_COLOR_DATA_H
#define AS_COLOR_DATA_H

// Ref.: SMPTE RP-177:1993
// http://car.france3.mars.free.fr/HD/INA-%2026%20jan%2006/SMPTE%20normes%20et%20confs/rp177.pdf

// Illuminants xyz chromaticity coordinates

#define D60_WHITEPOINT_CIE1931_2DEG_xyz     0.32168, 0.33767, 0.34065
#define D65_WHITEPOINT_CIE1931_2DEG_xyz     0.31270, 0.32900, 0.35830
#define DCIP3_WHITEPOINT_CIE1931_2DEG_xyz   0.31400, 0.35100, 0.33500

// The xyz chromaticity coordinates for the system RGB primaries, white point.
// OSL does not support 3x3 matrices, use vector[3] instead.

// ITU-R/BT.601 Ref: https://www.itu.int/rec/R-REC-BT.601-7-201103-I/en
#define REC601_CHROMATICITIES_Rxyz          0.640, 0.330, 0.030
#define REC601_CHROMATICITIES_Gxyz          0.290, 0.600, 0.110
#define REC601_CHROMATICITIES_Bxyz          0.150, 0.060, 0.790
#define REC601_CHROMATICITIES_Wxyz          D65_WHITEPOINT_CIE1931_2DEG_xyz

// ITU-R/BT.709 Ref: https://www.itu.int/rec/R-REC-BT.709/en
#define REC709_CHROMATICITIES_Rxyz          0.640, 0.330, 0.030
#define REC709_CHROMATICITIES_Gxyz          0.300, 0.600, 0.100
#define REC709_CHROMATICITIES_Bxyz          0.150, 0.060, 0.790
#define REC709_CHROMATICITIES_Wxyz          D65_WHITEPOINT_CIE1931_2DEG_xyz

// AdobeRGB Ref: http://www.adobe.com/digitalimag/pdfs/AdobeRGB1998.pdf
#define ADOBERGB98_CHROMATICITIES_Rxyz      0.640, 0.330, 0.030
#define ADOBERGB98_CHROMATICITIES_Gxyz      0.210, 0.710, 0.080
#define ADOBERGB98_CHROMATICITIES_Bxyz      0.150, 0.060, 0.790
#define ADOBERGB98_CHROMATICITIES_Wxyz      D65_WHITEPOINT_CIE1931_2DEG_xyz

// ITU-R/BT.2020 Ref: https://www.itu.int/rec/R-REC-BT.2020/en
#define REC2020_CHROMATICITIES_Rxyz         0.708, 0.292, 0.000
#define REC2020_CHROMATICITIES_Gxyz         0.170, 0.797, 0.033
#define REC2020_CHROMATICITIES_Bxyz         0.131, 0.046, 0.823
#define REC2020_CHROMATICITIES_Wxyz         D65_WHITEPOINT_CIE1931_2DEG_xyz

// ACES 2065-1 AP0 Ref: TB-2014-004: http://j.mp/TB-2014-004
#define ACES_AP0_CHROMATICITIES_Rxyz        0.7347, 0.2653, 0.0000
#define ACES_AP0_CHROMATICITIES_Gxyz        0.0000, 1.0000, 0.0000
#define ACES_AP0_CHROMATICITIES_Bxyz        0.0001, -0.077, 1.0769
#define ACES_AP0_CHROMATICITIES_Wxyz        D60_WHITEPOINT_CIE1931_2DEG_xyz

// ACEScg AP1 Ref: S-2014-004: http://j.mp/S-2014-004
#define ACESCG_AP1_CHROMATICITIES_Rxyz      0.7130, 0.2930, -0.006
#define ACESCG_AP1_CHROMATICITIES_Gxyz      0.1650, 0.8300, 0.0050
#define ACESCG_AP1_CHROMATICITIES_Bxyz      0.1280, 0.0440, 0.8280
#define ACESCG_AP1_CHROMATICITIES_Wxyz      D60_WHITEPOINT_CIE1931_2DEG_xyz

// DCI-P3 Ref: https://en.wikipedia.org/wiki/DCI-P3#cite_note-SMPTE_RP_431-2-3
#define DCIP3_CHROMATICITIES_Rxyz           0.6800, 0.3200, 0.0000
#define DCIP3_CHROMATICITIES_Gxyz           0.2650, 0.6900, 0.0450
#define DCIP3_CHROMATICITIES_Bxyz           0.1500, 0.0600, 0.7900
#define DCIP3_CHROMATICITIES_Wxyz           DCIP3_WHITEPOINT_CIE1931_2DEG_xyz

// Some useful quantities
#define DCIP3_GAMMA         2.6
#define ADOBERGB98_GAMMA    2.19921875

// RGB to XYZ and XYZ to RGB matrixes, chromatically adapted using the 
// Bradford CAT (where the white points differ), and respective Y coefficients.

// Rec.601 D65
#define RGB_TO_XYZ_REC601_D65_R0        0.43055381, 0.34154980, 0.17835231
#define RGB_TO_XYZ_REC601_D65_R1        0.22200431, 0.70665477, 0.07134092
#define RGB_TO_XYZ_REC601_D65_R2        0.02018221, 0.12955337, 0.93932217

#define XYZ_TO_RGB_REC601_D65_R0        3.06336109,-1.39339017,-0.47582374
#define XYZ_TO_RGB_REC601_D65_R1       -0.96924364, 1.87596750, 0.04155506
#define XYZ_TO_RGB_REC601_D65_R2        0.06786105,-0.22879927, 1.06908962

#define REC601_D65_LUMINANCE_COEFFS     RGB_TO_XYZ_REC601_D65_R1

// Rec.601 D65 to D60
#define RGB_TO_XYZ_REC601_D65_D60_R0    0.43721929, 0.34837665, 0.16705013
#define RGB_TO_XYZ_REC601_D65_D60_R1    0.22480951, 0.70733430, 0.06785619
#define RGB_TO_XYZ_REC601_D65_D60_R2    0.01847536, 0.12211323, 0.86823660

#define XYZ_TO_RGB_REC601_D60_D65_R0    3.03334911,-1.41228620,-0.47324544
#define XYZ_TO_RGB_REC601_D60_D65_R1   -0.97098721, 1.88517303, 0.03948565
#define XYZ_TO_RGB_REC601_D60_D65_R2    0.07201742,-0.23508807, 1.15627660

#define REC601_D60_LUMINANCE_COEFFS     RGB_TO_XYZ_REC601_D65_D60_R1

// Rec.601 D65 to DCI
#define RGB_TO_XYZ_REC601_D65_DCI_R0    0.41670609, 0.32048049, 0.15740031
#define RGB_TO_XYZ_REC601_D65_DCI_R1    0.21720295, 0.71755742, 0.06523963
#define RGB_TO_XYZ_REC601_D65_DCI_R2    0.01758496, 0.11874324, 0.81808775

#define XYZ_TO_RGB_REC601_DCI_D65_R0    3.09967787,-1.30290336,-0.49247693
#define XYZ_TO_RGB_REC601_DCI_D65_R1   -0.94467399, 1.80933334, 0.03746756
#define XYZ_TO_RGB_REC601_DCI_D65_R2    0.07048868,-0.23461370, 1.22751034

#define REC601_DCI_LUMINANCE_COEFFS     RGB_TO_XYZ_REC601_D65_DCI_R1

// Rec.709 D65 whitepoint
#define RGB_TO_XYZ_REC709_D65_R0        0.41239080, 0.35758434, 0.18048079
#define RGB_TO_XYZ_REC709_D65_R1        0.21263901, 0.71516868, 0.07219232
#define RGB_TO_XYZ_REC709_D65_R2        0.01933082, 0.11919478, 0.95053215

#define XYZ_TO_RGB_REC709_D65_R0        3.24096994,-1.53738318,-0.49861076
#define XYZ_TO_RGB_REC709_D65_R1       -0.96924364, 1.87596750, 0.04155506
#define XYZ_TO_RGB_REC709_D65_R2        0.05563008,-0.20397696, 1.05697151

#define REC709_D65_LUMINANCE_COEFFS     RGB_TO_XYZ_REC709_D65_R1 

// Rec.709 D65 to D60
#define RGB_TO_XYZ_REC709_D65_D60_R0    0.41877509, 0.36482725, 0.16904373
#define RGB_TO_XYZ_REC709_D65_D60_R1    0.21532587, 0.71600814, 0.06866599
#define RGB_TO_XYZ_REC709_D65_D60_R2    0.01769597, 0.11253097, 0.87859824

#define XYZ_TO_RGB_REC709_D60_D65_R0    3.20971293,-1.55751688,-0.49582777
#define XYZ_TO_RGB_REC709_D60_D65_R1   -0.97098721, 1.88517303, 0.03948565
#define XYZ_TO_RGB_REC709_D60_D65_R2    0.05971687,-0.21008302, 1.14310586

#define REC709_D60_LUMINANCE_COEFFS     RGB_TO_XYZ_REC709_D65_D60_R1

// Rec.709 D65 to DCI
#define RGB_TO_XYZ_REC709_D65_DCI_R0    0.39912725, 0.33618090, 0.15927875
#define RGB_TO_XYZ_REC709_D65_DCI_R1    0.20804019, 0.72594160, 0.06601820
#define RGB_TO_XYZ_REC709_D65_DCI_R2    0.01684314, 0.10972191, 0.82785091

#define XYZ_TO_RGB_REC709_DCI_D65_R0    3.27780410,-1.43997625,-0.51581739
#define XYZ_TO_RGB_REC709_DCI_D65_R1   -0.94467399, 1.80933334, 0.03746756
#define XYZ_TO_RGB_REC709_DCI_D65_R2    0.05851649,-0.21050866, 1.21347571

#define REC709_DCI_LUMINANCE_COEFFS     RGB_TO_XYZ_REC709_D65_DCI_R1

// AdobeRGB D65 
#define RGB_TO_XYZ_ADOBERGB_D65_R0      0.57667, 0.18556, 0.18823
#define RGB_TO_XYZ_ADOBERGB_D65_R1      0.29734, 0.62736, 0.07529
#define RGB_TO_XYZ_ADOBERGB_D65_R2      0.02703, 0.07069, 0.99134

#define XYZ_TO_RGB_ADOBERGB_D65_R0      2.04159,-0.56501,-0.34473
#define XYZ_TO_RGB_ADOBERGB_D65_R1     -0.96924, 1.87597, 0.04156
#define XYZ_TO_RGB_ADOBERGB_D65_R2      0.01344,-0.11836, 1.01517

#define ADOBERGB_D65_LUMINANCE_COEFFS   RGB_TO_XYZ_ADOBERGB_D65_R1

// AdobeRGB D65 to D60
#define RGB_TO_XYZ_ADOBERGB_D65_D60_R0  0.58559752, 0.19075066, 0.17630193
#define RGB_TO_XYZ_ADOBERGB_D65_D60_R1  0.30109721, 0.62728053, 0.0716123
#define RGB_TO_XYZ_ADOBERGB_D65_D60_R2  0.02474398, 0.06776538, 0.91631784

#define XYZ_TO_RGB_ADOBERGB_D60_D65_R0  2.01873297,-0.57678916,-0.3433321
#define XYZ_TO_RGB_ADOBERGB_D60_D65_R1 -0.97097442, 1.88518233, 0.03948677
#define XYZ_TO_RGB_ADOBERGB_D60_D65_R2  0.01729417,-0.12384136, 1.09767542

#define ADOBERGB_D60_LUMINANCE_COEFFS   RGB_TO_XYZ_ADOBERGB_D65_D60_R1

// AdobeRGB D65 to DCI
#define RGB_TO_XYZ_ADOBERGB_D65_DCI_R0  0.55812291, 0.17035035, 0.16611773
#define RGB_TO_XYZ_ADOBERGB_D65_DCI_R1  0.29090906, 0.64022978, 0.06885075
#define RGB_TO_XYZ_ADOBERGB_D65_DCI_R2  0.02355145, 0.06747449, 0.86339183

#define XYZ_TO_RGB_ADOBERGB_DCI_D60_R0  2.07492223,-0.51433755,-0.35820218
#define XYZ_TO_RGB_ADOBERGB_DCI_D60_R1 -0.94466041, 1.80934263, 0.03746878
#define XYZ_TO_RGB_ADOBERGB_DCI_D60_R2  0.01722631,-0.12737100, 1.16506545

#define ADOBERGB_DCI_LUMINANCE_COEFFS   RGB_TO_XYZ_ADOBERGB_D65_DCI_R1

// Rec.2020 D65
#define RGB_TO_XYZ_REC2020_D65_R0       0.63695805, 0.14461690, 0.16888098
#define RGB_TO_XYZ_REC2020_D65_R1       0.26270021, 0.67799807, 0.05930172
#define RGB_TO_XYZ_REC2020_D65_R2       0.00000000, 0.02807269, 1.06098506

#define XYZ_TO_RGB_REC2020_D65_R0       1.71665119,-0.35567078,-0.25336628
#define XYZ_TO_RGB_REC2020_D65_R1      -0.66668435, 1.61648124, 0.01576855
#define XYZ_TO_RGB_REC2020_D65_R2       0.01763986,-0.04277061, 0.94210312

#define REC2020_D65_LUMINANCE_COEFFS    RGB_TO_XYZ_REC2020_D65_R1

// Rec.2020 D65 to D60
#define RGB_TO_XYZ_REC2020_D65_D60_R0   0.64686459, 0.15022105, 0.15556043
#define RGB_TO_XYZ_REC2020_D65_D60_R1   0.26712117, 0.67772486, 0.05515397
#define RGB_TO_XYZ_REC2020_D65_D60_R2  -0.00057901, 0.02871900, 0.98068519

#define XYZ_TO_RGB_REC2020_D60_D65_R0   1.69664330,-0.36553600,-0.24857090
#define XYZ_TO_RGB_REC2020_D60_D65_R1  -0.67040097, 1.62348553, 0.01503663
#define XYZ_TO_RGB_REC2020_D60_D65_R2   0.02063416,-0.04775899, 1.01910812

#define REC2020_D60_LUMINANCE_COEFFS    RGB_TO_XYZ_REC2020_D65_D60_R1

// Rec.2020 D65 to DCI
#define RGB_TO_XYZ_REC2020_D65_DCI_R0   0.61798468, 0.13029564, 0.14630658
#define RGB_TO_XYZ_REC2020_D65_DCI_R1   0.25383422, 0.69352615, 0.05263963
#define RGB_TO_XYZ_REC2020_D65_DCI_R2  -0.00072416, 0.03114189, 0.92399823

#define XYZ_TO_RGB_REC2020_DCI_D65_R0   1.74797647,-0.31678170,-0.25872905
#define XYZ_TO_RGB_REC2020_DCI_D65_R1  -0.64151364, 1.56186477, 0.01259925
#define XYZ_TO_RGB_REC2020_DCI_D65_R2   0.02299113,-0.05288843, 1.08162574

#define REC2020_DCI_LUMINANCE_COEFFS    RGB_TO_XYZ_REC2020_D65_DCI_R1

// ACES 2065-1 AP0 D60 to D65
#define RGB_TO_XYZ_ACES_D60_D65_R0      0.93827985,-0.00445145, 0.01662752
#define RGB_TO_XYZ_ACES_D60_D65_R1      0.33736889, 0.72952157,-0.06689046
#define RGB_TO_XYZ_ACES_D60_D65_R2      0.00117395,-0.00371071, 1.09159451

#define XYZ_TO_RGB_ACES_D65_D60_R0      1.06349549, 0.00640891,-0.01580679
#define XYZ_TO_RGB_ACES_D65_D60_R1     -0.49207413, 1.36822341, 0.09133709
#define XYZ_TO_RGB_ACES_D65_D60_R2     -0.00281646, 0.00464417, 0.91641857

#define ACES_D65_LUMINANCE_COEFFS       RGB_TO_XYZ_ACES_D60_D65_R1

// ACES 2065-1 AP0 D60
#define RGB_TO_XYZ_ACES_D60_R0          0.95255240, 0.00000000, 0.00009368
#define RGB_TO_XYZ_ACES_D60_R1          0.34396645, 0.72816610,-0.07213255
#define RGB_TO_XYZ_ACES_D60_R2          0.00000000, 0.00000000, 1.00882518

#define XYZ_TO_RGB_ACES_D60_R0          1.04981102, 0.00000000,-0.00009748
#define XYZ_TO_RGB_ACES_D60_R1         -0.49590302, 1.37331305, 0.09824004
#define XYZ_TO_RGB_ACES_D60_R2          0.00000000, 0.00000000, 0.99125202

#define ACES_D60_LUMINANCE_COEFFS       RGB_TO_XYZ_ACES_D60_R1

// ACES 2065-1 AP0 D60 to DCI
#define RGB_TO_XYZ_ACES_D60_DCI_R0      0.91107700,-0.01554636,-0.00094374
#define RGB_TO_XYZ_ACES_D60_DCI_R1      0.32288858, 0.75046991,-0.07335849
#define RGB_TO_XYZ_ACES_D60_DCI_R2     -0.00059354, 0.00487426, 0.95013523

#define XYZ_TO_RGB_ACES_DCI_D60_R0      1.08961088, 0.02255349, 0.00282360
#define XYZ_TO_RGB_ACES_DCI_D60_R1     -0.46850201, 1.32213323, 0.10161453
#define XYZ_TO_RGB_ACES_DCI_D60_R2      0.00308412,-0.00676855, 1.05196223

#define ACES_DCI_LUMINANCE_COEFFS       RGB_TO_XYZ_ACES_D60_DCI_R1

// ACEScg AP1 D60 to D65
#define RGB_TO_XYZ_ACESCG_D60_D65_R0    0.65223754, 0.12823614, 0.16998225
#define RGB_TO_XYZ_ACESCG_D60_D65_R1    0.26767218, 0.67433999, 0.05798783
#define RGB_TO_XYZ_ACESCG_D60_D65_R2   -0.00538182, 0.00136906, 1.09307051

#define XYZ_TO_RGB_ACESCG_D65_D60_R0    1.66058533,-0.31529556,-0.24150933
#define XYZ_TO_RGB_ACESCG_D65_D60_R1   -0.65992606, 1.60839147, 0.01729859
#define XYZ_TO_RGB_ACESCG_D65_D60_R2    0.00900257,-0.00356688, 0.91364331

#define ACESCG_D65_LUMINANCE_COEFFS     RGB_TO_XYZ_ACES_D60_D65_R1

// ACEScg AP1 D60
#define RGB_TO_XYZ_ACESCG_D60_R0        0.66245418, 0.13400421, 0.15618769
#define RGB_TO_XYZ_ACESCG_D60_R1        0.27222872, 0.67408177, 0.05368952
#define RGB_TO_XYZ_ACESCG_D60_R2       -0.00557465, 0.00406073, 1.01033910

#define XYZ_TO_RGB_ACESCG_D60_R0        1.64102338,-0.32480329,-0.23642470
#define XYZ_TO_RGB_ACESCG_D60_R1       -0.66366286, 1.61533159, 0.01675635
#define XYZ_TO_RGB_ACESCG_D60_R2        0.01172189,-0.00828444, 0.98839486

#define ACESCG_D60_LUMINANCE_COEFFS     RGB_TO_XYZ_ACES_D60_R1

// ACEScg AP1 D60 to DCI
#define RGB_TO_XYZ_ACESCG_D60_DCI_R0    0.63291936, 0.11480057, 0.14686696
#define RGB_TO_XYZ_ACESCG_D60_DCI_R1    0.25857593, 0.69028557, 0.05113851
#define RGB_TO_XYZ_ACESCG_D60_DCI_R2   -0.00544477, 0.00793126, 0.95192947

#define XYZ_TO_RGB_ACESCG_DCI_D60_R0    1.69164697,-0.27850893,-0.24603138
#define XYZ_TO_RGB_ACESCG_DCI_D60_R1   -0.63478722, 1.55408048, 0.01445056
#define XYZ_TO_RGB_ACESCG_DCI_D60_R2    0.01496466,-0.01454124, 1.04897036

#define ACESCG_DCI_LUMINANCE_COEFFS     RGB_TO_XYZ_ACES_D60_DCI_R1

// DCI-P3 DCI to D65
#define RGB_TO_XYZ_DCIP3_DCI_D65_R0     0.45925165, 0.29579179, 0.19541248
#define RGB_TO_XYZ_DCIP3_DCI_D65_R1     0.21515051, 0.70913364, 0.07571585
#define RGB_TO_XYZ_DCIP3_DCI_D65_R2     0.00027201, 0.04693951, 1.04184623

#define XYZ_TO_RGB_DCIP3_D65_DCI_R0     2.69022591,-1.09400194,-0.42508235
#define XYZ_TO_RGB_DCIP3_D65_DCI_R1    -0.82008218, 1.75048091, 0.02660195
#define XYZ_TO_RGB_DCIP3_D65_DCI_R2     0.03624575,-0.07858084, 0.95874699

#define DCIP3_D65_LUMINANCE_COEFFS      RGB_TO_XYZ_DCIP3_DCI_D65_R1

// DCI-P3 DCI to D60
#define RGB_TO_XYZ_DCIP3_DCI_D60_R0     0.46654744, 0.30327412, 0.18282451
#define RGB_TO_XYZ_DCIP3_DCI_D60_R1     0.21828941, 0.70987208, 0.07183851
#define RGB_TO_XYZ_DCIP3_DCI_D60_R2    -0.00004540, 0.04587783, 0.96299275

#define XYZ_TO_RGB_DCIP3_D60_DCI_R0     2.66286214,-1.11031817,-0.42271645
#define XYZ_TO_RGB_DCIP3_D60_DCI_R1    -0.82282389, 1.75861719, 0.02502194
#define XYZ_TO_RGB_DCIP3_D60_DCI_R2     0.03932559,-0.08383443, 1.03721743

#define DCIP3_D60_LUMINANCE_COEFFS      RGB_TO_XYZ_DCIP3_DCI_D60_R1

// DCI-P3 DCI
#define RGB_TO_XYZ_DCIP3_DCI_R0         0.44516982, 0.27713441, 0.17228267
#define RGB_TO_XYZ_DCIP3_DCI_R1         0.20949168, 0.72159525, 0.06891307
#define RGB_TO_XYZ_DCIP3_DCI_R2        -0.00000000, 0.04706056, 0.90735539

#define XYZ_TO_RGB_DCIP3_DCI_R0         2.72539403,-1.01800301,-0.44016320
#define XYZ_TO_RGB_DCIP3_DCI_R1        -0.79516803, 1.68973205, 0.02264719
#define XYZ_TO_RGB_DCIP3_DCI_R2         0.04124189,-0.08763902, 1.10092938

#define DCIP3_DCI_LUMINANCE_COEFFS      RGB_TO_XYZ_DCIP3_DCI_R1

#endif /// AS_COLOR_DATA_H