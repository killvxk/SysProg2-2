/*
 * Copyright (c) 2002-2009 Sam Leffler, Errno Consulting
 * Copyright (c) 2005-2006 Atheros Communications, Inc.
 * All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * $FreeBSD: releng/10.3/sys/dev/ath/ath_hal/ah_regdomain/ah_rd_domains.h 248677 2013-03-24 04:42:56Z adrian $
 */

#ifndef	__AH_REGDOMAIN_DOMAINS_H__
#define	__AH_REGDOMAIN_DOMAINS_H__

/* 
 * BMLEN defines the size of the bitmask used to hold frequency
 * band specifications.  Note this must agree with the BM macro
 * definition that's used to setup initializers.  See also further
 * comments below.
 */
/* BMLEN is now defined in ah_regdomain.h */
#define	W0(_a) \
	(((_a) >= 0 && (_a) < 64 ? (((uint64_t) 1)<<(_a)) : (uint64_t) 0))
#define	W1(_a) \
	(((_a) > 63 && (_a) < 128 ? (((uint64_t) 1)<<((_a)-64)) : (uint64_t) 0))
#define BM1(_fa)	{ W0(_fa), W1(_fa) }
#define BM2(_fa, _fb)	{ W0(_fa) | W0(_fb), W1(_fa) | W1(_fb) }
#define BM3(_fa, _fb, _fc) \
	{ W0(_fa) | W0(_fb) | W0(_fc), W1(_fa) | W1(_fb) | W1(_fc) }
#define BM4(_fa, _fb, _fc, _fd)						\
	{ W0(_fa) | W0(_fb) | W0(_fc) | W0(_fd),			\
	  W1(_fa) | W1(_fb) | W1(_fc) | W1(_fd) }
#define BM5(_fa, _fb, _fc, _fd, _fe)					\
	{ W0(_fa) | W0(_fb) | W0(_fc) | W0(_fd) | W0(_fe),		\
	  W1(_fa) | W1(_fb) | W1(_fc) | W1(_fd) | W1(_fe) }
#define BM6(_fa, _fb, _fc, _fd, _fe, _ff)				\
	{ W0(_fa) | W0(_fb) | W0(_fc) | W0(_fd) | W0(_fe) | W0(_ff),	\
	  W1(_fa) | W1(_fb) | W1(_fc) | W1(_fd) | W1(_fe) | W1(_ff) }
#define BM7(_fa, _fb, _fc, _fd, _fe, _ff, _fg)	\
	{ W0(_fa) | W0(_fb) | W0(_fc) | W0(_fd) | W0(_fe) | W0(_ff) |	\
	  W0(_fg),\
	  W1(_fa) | W1(_fb) | W1(_fc) | W1(_fd) | W1(_fe) | W1(_ff) |	\
	  W1(_fg) }
#define BM8(_fa, _fb, _fc, _fd, _fe, _ff, _fg, _fh)	\
	{ W0(_fa) | W0(_fb) | W0(_fc) | W0(_fd) | W0(_fe) | W0(_ff) |	\
	  W0(_fg) | W0(_fh) ,	\
	  W1(_fa) | W1(_fb) | W1(_fc) | W1(_fd) | W1(_fe) | W1(_ff) |	\
	  W1(_fg) | W1(_fh) }
#define BM9(_fa, _fb, _fc, _fd, _fe, _ff, _fg, _fh, _fi)	\
	{ W0(_fa) | W0(_fb) | W0(_fc) | W0(_fd) | W0(_fe) | W0(_ff) |	\
	  W0(_fg) | W0(_fh) | W0(_fi) ,	\
	  W1(_fa) | W1(_fb) | W1(_fc) | W1(_fd) | W1(_fe) | W1(_ff) |	\
	  W1(_fg) | W1(_fh) | W1(_fi) }

static REG_DOMAIN regDomains[] = {

	{.regDmnEnum		= DEBUG_REG_DMN,
	 .conformanceTestLimit	= FCC,
	 .dfsMask		= DFS_FCC3,
	 .chan11a		= BM4(F1_4950_4980,
				      F1_5120_5240,
				      F1_5260_5700,
				      F1_5745_5825),
	 .chan11a_half		= BM4(F1_4945_4985,
				      F2_5120_5240,
				      F2_5260_5700,
				      F7_5745_5825),
	 .chan11a_quarter	= BM4(F1_4942_4987,
				      F3_5120_5240,
				      F3_5260_5700,
				      F8_5745_5825),
	 .chan11a_turbo		= BM8(T1_5130_5210,
				      T1_5250_5330,
				      T1_5370_5490,
				      T1_5530_5650,
				      T1_5150_5190,
				      T1_5230_5310,
				      T1_5350_5470,
				      T1_5510_5670),
	 .chan11a_dyn_turbo	= BM4(T1_5200_5240,
				      T1_5280_5280,
				      T1_5540_5660,
				      T1_5765_5805),
	 .chan11b		= BM4(F1_2312_2372,
				      F1_2412_2472,
				      F1_2484_2484,
				      F1_2512_2732),
	 .chan11g		= BM3(G1_2312_2372, G1_2412_2472, G1_2512_2732),
	 .chan11g_turbo		= BM3(T1_2312_2372, T1_2437_2437, T1_2512_2732),
	 .chan11g_half		= BM3(G2_2312_2372, G4_2412_2472, G2_2512_2732),
	 .chan11g_quarter	= BM3(G3_2312_2372, G5_2412_2472, G3_2512_2732),
	},

	{.regDmnEnum		= APL1,
	 .conformanceTestLimit	= FCC,
	 .chan11a		= BM1(F4_5745_5825),
	},

	{.regDmnEnum		= APL2,
	 .conformanceTestLimit	= FCC,
	 .chan11a		= BM1(F1_5745_5805),
	},

	{.regDmnEnum		= APL3,
	 .conformanceTestLimit	= FCC,
	 .chan11a		= BM2(F1_5280_5320, F2_5745_5805),
	},

	{.regDmnEnum		= APL4,
	 .conformanceTestLimit	= FCC,
	 .chan11a		= BM2(F4_5180_5240, F3_5745_5825),
	},

	{.regDmnEnum		= APL5,
	 .conformanceTestLimit	= FCC,
	 .chan11a		= BM1(F2_5745_5825),
	},

	{.regDmnEnum		= APL6,
	 .conformanceTestLimit	= ETSI,
	 .dfsMask		= DFS_ETSI,
	 .pscan			= PSCAN_FCC_T | PSCAN_FCC,
	 .chan11a		= BM3(F4_5180_5240, F2_5260_5320, F3_5745_5825),
	 .chan11a_turbo		= BM3(T2_5210_5210, T1_5250_5290, T1_5760_5800),
	},

	{.regDmnEnum		= APL8,
	 .conformanceTestLimit	= ETSI,
	 .flags			= DISALLOW_ADHOC_11A|DISALLOW_ADHOC_11A_TURB,
	 .chan11a		= BM2(F6_5260_5320, F4_5745_5825),
	},

	{.regDmnEnum		= APL9,
	 .conformanceTestLimit	= ETSI,
	 .dfsMask		= DFS_ETSI,
	 .pscan			= PSCAN_ETSI,
	 .flags			= DISALLOW_ADHOC_11A|DISALLOW_ADHOC_11A_TURB,
	 .chan11a		= BM3(F1_5180_5320, F1_5500_5620, F3_5745_5805),
	},

	{.regDmnEnum		= ETSI1,
	 .conformanceTestLimit	= ETSI,
	 .dfsMask		= DFS_ETSI,
	 .pscan			= PSCAN_ETSI,
	 .flags			= DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 .chan11a		= BM3(W2_5180_5240, F2_5260_5320, F2_5500_5700),
	},

	{.regDmnEnum		= ETSI2,
	 .conformanceTestLimit	= ETSI,
	 .dfsMask		= DFS_ETSI,
	 .pscan			= PSCAN_ETSI,
	 .flags			= DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 .chan11a		= BM1(F3_5180_5240),
	},

	{.regDmnEnum		= ETSI3,
	 .conformanceTestLimit	= ETSI,
	 .dfsMask		= DFS_ETSI,
	 .pscan			= PSCAN_ETSI,
	 .flags			= DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 .chan11a		= BM2(W2_5180_5240, F2_5260_5320),
	},

	{.regDmnEnum		= ETSI4,
	 .conformanceTestLimit	= ETSI,
	 .dfsMask		= DFS_ETSI,
	 .pscan			= PSCAN_ETSI,
	 .flags			= DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 .chan11a		= BM2(F3_5180_5240, F1_5260_5320),
	},

	{.regDmnEnum		= ETSI5,
	 .conformanceTestLimit	= ETSI,
	 .dfsMask		= DFS_ETSI,
	 .pscan			= PSCAN_ETSI,
	 .flags			= DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 .chan11a		= BM1(F1_5180_5240),
	},

	{.regDmnEnum		= ETSI6,
	 .conformanceTestLimit	= ETSI,
	 .dfsMask		= DFS_ETSI,
	 .pscan			= PSCAN_ETSI,
	 .flags			= DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 .chan11a		= BM3(F5_5180_5240, F1_5260_5280, F3_5500_5700),
	},

	{.regDmnEnum		= FCC1,
	 .conformanceTestLimit	= FCC,
	 .chan11a		= BM3(F2_5180_5240, F4_5260_5320, F5_5745_5825),
	 .chan11a_turbo		= BM3(T1_5210_5210, T2_5250_5290, T2_5760_5800),
	 .chan11a_dyn_turbo	= BM3(T1_5200_5240, T1_5280_5280, T1_5765_5805),
	},

	{.regDmnEnum		= FCC2,
	 .conformanceTestLimit	= FCC,
	 .chan11a		= BM3(F6_5180_5240, F5_5260_5320, F6_5745_5825),
	 .chan11a_dyn_turbo	= BM3(T2_5200_5240, T1_5280_5280, T1_5765_5805),
	},

	{.regDmnEnum		= FCC3,
	 .conformanceTestLimit	= FCC,
	 .dfsMask		= DFS_FCC3,
	 .pscan			= PSCAN_FCC | PSCAN_FCC_T,
	 .chan11a		= BM4(F2_5180_5240,
				      F3_5260_5320,
				      F1_5500_5700,
				      F5_5745_5825),
	 .chan11a_turbo		= BM4(T1_5210_5210,
				      T1_5250_5250,
				      T1_5290_5290,
				      T2_5760_5800),
	 .chan11a_dyn_turbo	= BM3(T1_5200_5240, T2_5280_5280, T1_5540_5660),
	},

	{.regDmnEnum		= FCC4,
	 .conformanceTestLimit	= FCC,
	 .dfsMask		= DFS_FCC3,
	 .pscan			= PSCAN_FCC | PSCAN_FCC_T,
	 .chan11a		= BM1(F1_4950_4980),
	 .chan11a_half		= BM1(F1_4945_4985),
	 .chan11a_quarter	= BM1(F1_4942_4987),
	},

	/* FCC1 w/ 1/2 and 1/4 width channels */
	{.regDmnEnum		= FCC5,
	 .conformanceTestLimit	= FCC,
	 .chan11a		= BM3(F2_5180_5240, F4_5260_5320, F5_5745_5825),
	 .chan11a_turbo		= BM3(T1_5210_5210, T2_5250_5290, T2_5760_5800),
	 .chan11a_dyn_turbo	= BM3(T1_5200_5240, T1_5280_5280, T1_5765_5805),
	 .chan11a_half		= BM3(F7_5180_5240, F7_5260_5320, F9_5745_5825),
	 .chan11a_quarter	= BM3(F8_5180_5240, F8_5260_5320,F10_5745_5825),
	},

	{.regDmnEnum		= MKK1,
	 .conformanceTestLimit	= MKK,
	 .pscan			= PSCAN_MKK1,
	 .flags			= DISALLOW_ADHOC_11A_TURB,
	 .chan11a		= BM1(F1_5170_5230),
	},

	{.regDmnEnum		= MKK2,
	 .conformanceTestLimit	= MKK,
	 .pscan			= PSCAN_MKK2,
	 .flags			= DISALLOW_ADHOC_11A_TURB,
	 .chan11a		= BM3(F1_4920_4980, F1_5040_5080, F1_5170_5230),
	 .chan11a_half		= BM4(F1_4915_4925,
				      F1_4935_4945,
				      F1_5035_5040,
				      F1_5055_5055),
	},

	/* UNI-1 even */
	{.regDmnEnum		= MKK3,
	 .conformanceTestLimit	= MKK,
	 .pscan			= PSCAN_MKK3,
	 .flags			= DISALLOW_ADHOC_11A_TURB,
	 .chan11a		= BM1(F4_5180_5240),
	},

	/* UNI-1 even + UNI-2 */
	{.regDmnEnum		= MKK4,
	 .conformanceTestLimit	= MKK,
	 .dfsMask		= DFS_MKK4,
	 .pscan			= PSCAN_MKK3,
	 .flags			= DISALLOW_ADHOC_11A_TURB,
	 .chan11a		= BM2(F4_5180_5240, F2_5260_5320),
	},

	/* UNI-1 even + UNI-2 + mid-band */
	{.regDmnEnum		= MKK5,
	 .conformanceTestLimit	= MKK,
	 .dfsMask		= DFS_MKK4,
	 .pscan			= PSCAN_MKK3,
	 .flags			= DISALLOW_ADHOC_11A_TURB,
	 .chan11a		= BM3(F4_5180_5240, F2_5260_5320, F4_5500_5700),
	},

	/* UNI-1 odd + even */
	{.regDmnEnum		= MKK6,
	 .conformanceTestLimit	= MKK,
	 .pscan			= PSCAN_MKK1,
	 .flags			= DISALLOW_ADHOC_11A_TURB,
	 .chan11a		= BM2(F2_5170_5230, F4_5180_5240),
	},

	/* UNI-1 odd + UNI-1 even + UNI-2 */
	{.regDmnEnum		= MKK7,
	 .conformanceTestLimit	= MKK,
	 .dfsMask		= DFS_MKK4,
	 .pscan			= PSCAN_MKK1 | PSCAN_MKK3,
	 .flags			= DISALLOW_ADHOC_11A_TURB,
	 .chan11a		= BM3(F1_5170_5230, F4_5180_5240, F2_5260_5320),
	},

	/* UNI-1 odd + UNI-1 even + UNI-2 + mid-band */
	{.regDmnEnum		= MKK8,
	 .conformanceTestLimit	= MKK,
	 .dfsMask		= DFS_MKK4,
	 .pscan			= PSCAN_MKK1 | PSCAN_MKK3,
	 .flags			= DISALLOW_ADHOC_11A_TURB,
	 .chan11a		= BM4(F1_5170_5230,
				      F4_5180_5240,
				      F2_5260_5320,
				      F4_5500_5700),
	},

        /* UNI-1 even + 4.9 GHZ */
        {.regDmnEnum		= MKK9,
	 .conformanceTestLimit	= MKK,
	 .pscan			= PSCAN_MKK3,
	 .flags			= DISALLOW_ADHOC_11A_TURB,
         .chan11a		= BM7(F1_4915_4925,
				      F1_4935_4945,
				      F1_4920_4980,
				      F1_5035_5040,
				      F1_5055_5055,
				      F1_5040_5080,
				      F4_5180_5240),
        },

        /* UNI-1 even + UNI-2 + 4.9 GHZ */
        {.regDmnEnum		= MKK10,
	 .conformanceTestLimit	= MKK,
	 .dfsMask		= DFS_MKK4,
	 .pscan			= PSCAN_MKK3,
	 .flags			= DISALLOW_ADHOC_11A_TURB,
         .chan11a		= BM8(F1_4915_4925,
				      F1_4935_4945,
				      F1_4920_4980,
				      F1_5035_5040,
				      F1_5055_5055,
				      F1_5040_5080,
				      F4_5180_5240,
				      F2_5260_5320),
        },

	/* Defined here to use when 2G channels are authorised for country K2 */
	{.regDmnEnum		= APLD,
	 .conformanceTestLimit	= NO_CTL,
	 .chan11b		= BM2(F2_2312_2372,F2_2412_2472),
	 .chan11g		= BM2(G2_2312_2372,G2_2412_2472),
	},

	{.regDmnEnum		= ETSIA,
	 .conformanceTestLimit	= NO_CTL,
	 .pscan			= PSCAN_ETSIA,
	 .flags			= DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 .chan11b		= BM1(F1_2457_2472),
	 .chan11g		= BM1(G1_2457_2472),
	 .chan11g_turbo		= BM1(T2_2437_2437)
	},

	{.regDmnEnum		= ETSIB,
	 .conformanceTestLimit	= ETSI,
	 .pscan			= PSCAN_ETSIB,
	 .flags			= DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 .chan11b		= BM1(F1_2432_2442),
	 .chan11g		= BM1(G1_2432_2442),
	 .chan11g_turbo		= BM1(T2_2437_2437)
	},

	{.regDmnEnum		= ETSIC,
	 .conformanceTestLimit	= ETSI,
	 .pscan			= PSCAN_ETSIC,
	 .flags			= DISALLOW_ADHOC_11A | DISALLOW_ADHOC_11A_TURB,
	 .chan11b		= BM1(F3_2412_2472),
	 .chan11g		= BM1(G3_2412_2472),
	 .chan11g_turbo		= BM1(T2_2437_2437)
	},

	{.regDmnEnum		= FCCA,
	 .conformanceTestLimit	= FCC,
	 .chan11b		= BM1(F1_2412_2462),
	 .chan11g		= BM1(G1_2412_2462),
	 .chan11g_turbo		= BM1(T2_2437_2437),
	},

	/* FCCA w/ 1/2 and 1/4 width channels */
	{.regDmnEnum		= FCCB,
	 .conformanceTestLimit	= FCC,
	 .chan11b		= BM1(F1_2412_2462),
	 .chan11g		= BM1(G1_2412_2462),
	 .chan11g_turbo		= BM1(T2_2437_2437),
	 .chan11g_half		= BM1(G3_2412_2462),
	 .chan11g_quarter	= BM1(G4_2412_2462),
	},

	{.regDmnEnum		= MKKA,
	 .conformanceTestLimit	= MKK,
	 .pscan			= PSCAN_MKKA | PSCAN_MKKA_G
				| PSCAN_MKKA1 | PSCAN_MKKA1_G
				| PSCAN_MKKA2 | PSCAN_MKKA2_G,
	 .flags			= DISALLOW_ADHOC_11A_TURB,
	 .chan11b		= BM3(F2_2412_2462, F1_2467_2472, F2_2484_2484),
	 .chan11g		= BM2(G2_2412_2462, G1_2467_2472),
	 .chan11g_turbo		= BM1(T2_2437_2437)
	},

	{.regDmnEnum		= MKKC,
	 .conformanceTestLimit	= MKK,
	 .chan11b		= BM1(F2_2412_2472),
	 .chan11g		= BM1(G2_2412_2472),
	 .chan11g_turbo		= BM1(T2_2437_2437)
	},

	{.regDmnEnum		= WORLD,
	 .conformanceTestLimit	= ETSI,
	 .chan11b		= BM1(F2_2412_2472),
	 .chan11g		= BM1(G2_2412_2472),
	 .chan11g_turbo		= BM1(T2_2437_2437)
	},

	{.regDmnEnum		= WOR0_WORLD,
	 .conformanceTestLimit	= NO_CTL,
	 .dfsMask		= DFS_FCC3 | DFS_ETSI,
	 .pscan			= PSCAN_WWR,
	 .flags			= ADHOC_PER_11D,
	 .chan11a		= BM5(W1_5260_5320,
				      W1_5180_5240,
				      W1_5170_5230,
				      W1_5745_5825,
				      W1_5500_5700),
	 .chan11a_turbo		= BM3(WT1_5210_5250,
				      WT1_5290_5290,
				      WT1_5760_5800),
	 .chan11b		= BM8(W1_2412_2412,
				      W1_2437_2442,
				      W1_2462_2462,
				      W1_2472_2472,
				      W1_2417_2432,
				      W1_2447_2457,
				      W1_2467_2467,
				      W1_2484_2484),
	 .chan11g		= BM7(WG1_2412_2412,
				      WG1_2437_2442,
				      WG1_2462_2462,
				      WG1_2472_2472,
				      WG1_2417_2432,
				      WG1_2447_2457,
				      WG1_2467_2467),
	 .chan11g_turbo		= BM1(T3_2437_2437)
	},

	{.regDmnEnum		= WOR01_WORLD,
	 .conformanceTestLimit	= NO_CTL,
	 .dfsMask		= DFS_FCC3 | DFS_ETSI,
	 .pscan			= PSCAN_WWR,
	 .flags			= ADHOC_PER_11D,
	 .chan11a		= BM5(W1_5260_5320,
				      W1_5180_5240,
				      W1_5170_5230,
				      W1_5745_5825,
				      W1_5500_5700),
	 .chan11a_turbo		= BM3(WT1_5210_5250,
				      WT1_5290_5290,
				      WT1_5760_5800),
	 .chan11b		= BM5(W1_2412_2412,
				      W1_2437_2442,
				      W1_2462_2462,
				      W1_2417_2432,
				      W1_2447_2457),
	 .chan11g		= BM5(WG1_2412_2412,
				      WG1_2437_2442,
				      WG1_2462_2462,
				      WG1_2417_2432,
				      WG1_2447_2457),
	 .chan11g_turbo		= BM1(T3_2437_2437)},

	{.regDmnEnum		= WOR02_WORLD,
	 .conformanceTestLimit	= NO_CTL,
	 .dfsMask		= DFS_FCC3 | DFS_ETSI,
	 .pscan			= PSCAN_WWR,
	 .flags			= ADHOC_PER_11D,
	 .chan11a		= BM5(W1_5260_5320,
				      W1_5180_5240,
				      W1_5170_5230,
				      W1_5745_5825,
				      W1_5500_5700),
	 .chan11a_turbo		= BM3(WT1_5210_5250,
				      WT1_5290_5290,
				      WT1_5760_5800),
	 .chan11b		= BM7(W1_2412_2412,
				      W1_2437_2442,
				      W1_2462_2462,
				      W1_2472_2472,
				      W1_2417_2432,
				      W1_2447_2457,
				      W1_2467_2467),
	 .chan11g		= BM7(WG1_2412_2412,
				      WG1_2437_2442,
				      WG1_2462_2462,
				      WG1_2472_2472,
				      WG1_2417_2432,
				      WG1_2447_2457,
				      WG1_2467_2467),
	 .chan11g_turbo		= BM1(T3_2437_2437)},

	{.regDmnEnum		= EU1_WORLD,
	 .conformanceTestLimit	= NO_CTL,
	 .dfsMask		= DFS_FCC3 | DFS_ETSI,
	 .pscan			= PSCAN_WWR,
	 .flags			= ADHOC_PER_11D,
	 .chan11a		= BM5(W1_5260_5320,
				      W1_5180_5240,
				      W1_5170_5230,
				      W1_5745_5825,
				      W1_5500_5700),
	 .chan11a_turbo		= BM3(WT1_5210_5250,
				      WT1_5290_5290,
				      WT1_5760_5800),
	 .chan11b		= BM7(W1_2412_2412,
				      W1_2437_2442,
				      W1_2462_2462,
				      W2_2472_2472,
				      W1_2417_2432,
				      W1_2447_2457,
				      W2_2467_2467),
	 .chan11g		= BM7(WG1_2412_2412,
				      WG1_2437_2442,
				      WG1_2462_2462,
				      WG2_2472_2472,
				      WG1_2417_2432,
				      WG1_2447_2457,
				      WG2_2467_2467),
	 .chan11g_turbo		= BM1(T3_2437_2437)},

	{.regDmnEnum		= WOR1_WORLD,
	 .conformanceTestLimit	= NO_CTL,
	 .dfsMask		= DFS_FCC3 | DFS_ETSI,
	 .pscan			= PSCAN_WWR,
	 .flags			= DISALLOW_ADHOC_11A,
	 .chan11a		= BM5(W1_5260_5320,
				      W1_5180_5240,
				      W1_5170_5230,
				      W1_5745_5825,
				      W1_5500_5700),
	 .chan11b		= BM8(W1_2412_2412,
				      W1_2437_2442,
				      W1_2462_2462,
				      W1_2472_2472,
				      W1_2417_2432,
				      W1_2447_2457,
				      W1_2467_2467,
				      W1_2484_2484),
	 .chan11g		= BM7(WG1_2412_2412,
				      WG1_2437_2442,
				      WG1_2462_2462,
				      WG1_2472_2472,
				      WG1_2417_2432,
				      WG1_2447_2457,
				      WG1_2467_2467),
	 .chan11g_turbo		= BM1(T3_2437_2437)
	},

	{.regDmnEnum		= WOR2_WORLD,
	 .conformanceTestLimit	= NO_CTL,
	 .dfsMask		= DFS_FCC3 | DFS_ETSI,
	 .pscan			= PSCAN_WWR,
	 .flags			= DISALLOW_ADHOC_11A,
	 .chan11a		= BM5(W1_5260_5320,
				      W1_5180_5240,
				      W1_5170_5230,
				      W1_5745_5825,
				      W1_5500_5700),
	 .chan11a_turbo		= BM3(WT1_5210_5250,
				      WT1_5290_5290,
				      WT1_5760_5800),
	 .chan11b		= BM8(W1_2412_2412,
				      W1_2437_2442,
				      W1_2462_2462,
				      W1_2472_2472,
				      W1_2417_2432,
				      W1_2447_2457,
				      W1_2467_2467,
				      W1_2484_2484),
	 .chan11g		= BM7(WG1_2412_2412,
				      WG1_2437_2442,
				      WG1_2462_2462,
				      WG1_2472_2472,
				      WG1_2417_2432,
				      WG1_2447_2457,
				      WG1_2467_2467),
	 .chan11g_turbo		= BM1(T3_2437_2437)},

	{.regDmnEnum		= WOR3_WORLD,
	 .conformanceTestLimit	= NO_CTL,
	 .dfsMask		= DFS_FCC3 | DFS_ETSI,
	 .pscan			= PSCAN_WWR,
	 .flags			= ADHOC_PER_11D,
	 .chan11a		= BM4(W1_5260_5320,
				      W1_5180_5240,
				      W1_5170_5230,
				      W1_5745_5825),
	 .chan11a_turbo		= BM3(WT1_5210_5250,
				      WT1_5290_5290,
				      WT1_5760_5800),
	 .chan11b		= BM7(W1_2412_2412,
				      W1_2437_2442,
				      W1_2462_2462,
				      W1_2472_2472,
				      W1_2417_2432,
				      W1_2447_2457,
				      W1_2467_2467),
	 .chan11g		= BM7(WG1_2412_2412,
				      WG1_2437_2442,
				      WG1_2462_2462,
				      WG1_2472_2472,
				      WG1_2417_2432,
				      WG1_2447_2457,
				      WG1_2467_2467),
	 .chan11g_turbo		= BM1(T3_2437_2437)},

	{.regDmnEnum		= WOR4_WORLD,
	 .conformanceTestLimit	= NO_CTL,
	 .dfsMask		= DFS_FCC3 | DFS_ETSI,
	 .pscan			= PSCAN_WWR,
	 .flags			= DISALLOW_ADHOC_11A,
	 .chan11a		= BM4(W2_5260_5320,
				      W2_5180_5240,
				      F2_5745_5805,
				      W2_5825_5825),
	 .chan11a_turbo		= BM3(WT1_5210_5250,
				      WT1_5290_5290,
				      WT1_5760_5800),
	 .chan11b		= BM5(W1_2412_2412,
				      W1_2437_2442,
				      W1_2462_2462,
				      W1_2417_2432,
				      W1_2447_2457),
	 .chan11g		= BM5(WG1_2412_2412,
				      WG1_2437_2442,
				      WG1_2462_2462,
				      WG1_2417_2432,
				      WG1_2447_2457),
	 .chan11g_turbo		= BM1(T3_2437_2437)},

	{.regDmnEnum		= WOR5_ETSIC,
	 .conformanceTestLimit	= NO_CTL,
	 .dfsMask		= DFS_FCC3 | DFS_ETSI,
	 .pscan			= PSCAN_WWR,
	 .flags			= DISALLOW_ADHOC_11A,
	 .chan11a		= BM3(W1_5260_5320, W2_5180_5240, F6_5745_5825),
	 .chan11b		= BM7(W1_2412_2412,
				      W1_2437_2442,
				      W1_2462_2462,
				      W2_2472_2472,
				      W1_2417_2432,
				      W1_2447_2457,
				      W2_2467_2467),
	 .chan11g		= BM7(WG1_2412_2412,
				      WG1_2437_2442,
				      WG1_2462_2462,
				      WG2_2472_2472,
				      WG1_2417_2432,
				      WG1_2447_2457,
				      WG2_2467_2467),
	 .chan11g_turbo		= BM1(T3_2437_2437)},

	{.regDmnEnum		= WOR9_WORLD,
	 .conformanceTestLimit	= NO_CTL,
	 .dfsMask		= DFS_FCC3 | DFS_ETSI,
	 .pscan			= PSCAN_WWR,
	 .flags			= DISALLOW_ADHOC_11A,
	 .chan11a		= BM4(W1_5260_5320,
				      W1_5180_5240,
				      W1_5745_5825,
				      W1_5500_5700),
	 .chan11a_turbo		= BM3(WT1_5210_5250,
				      WT1_5290_5290,
				      WT1_5760_5800),
	 .chan11b		= BM5(W1_2412_2412,
				      W1_2437_2442,
				      W1_2462_2462,
				      W1_2417_2432,
				      W1_2447_2457),
	 .chan11g		= BM5(WG1_2412_2412,
				      WG1_2437_2442,
				      WG1_2462_2462,
				      WG1_2417_2432,
				      WG1_2447_2457),
	 .chan11g_turbo		= BM1(T3_2437_2437)},

	{.regDmnEnum		= WORA_WORLD,
	 .conformanceTestLimit	= NO_CTL,
	 .dfsMask		= DFS_FCC3 | DFS_ETSI,
	 .pscan			= PSCAN_WWR,
	 .flags			= DISALLOW_ADHOC_11A,
	 .chan11a		= BM4(W1_5260_5320,
				      W1_5180_5240,
				      W1_5745_5825,
				      W1_5500_5700),
	 .chan11b		= BM7(W1_2412_2412,
				      W1_2437_2442,
				      W1_2462_2462,
				      W1_2472_2472,
				      W1_2417_2432,
				      W1_2447_2457,
				      W1_2467_2467),
	 .chan11g		= BM7(WG1_2412_2412,
				      WG1_2437_2442,
				      WG1_2462_2462,
				      WG1_2472_2472,
				      WG1_2417_2432,
				      WG1_2447_2457,
				      WG1_2467_2467),
	 .chan11g_turbo		= BM1(T3_2437_2437)},

	{.regDmnEnum		= WORB_WORLD,
	 .conformanceTestLimit	= NO_CTL,
	 .dfsMask		= DFS_FCC3 | DFS_ETSI,
	 .pscan			= PSCAN_WWR,
	 .flags			= DISALLOW_ADHOC_11A,
	 .chan11a		= BM4(W1_5260_5320,
				      W1_5180_5240,
				      W1_5745_5825,
				      W1_5500_5700),
	 .chan11b		= BM7(W1_2412_2412,
				      W1_2437_2442,
				      W1_2462_2462,
				      W1_2472_2472,
				      W1_2417_2432,
				      W1_2447_2457,
				      W1_2467_2467),
	 .chan11g		= BM7(WG1_2412_2412,
				      WG1_2437_2442,
				      WG1_2462_2462,
				      WG1_2472_2472,
				      WG1_2417_2432,
				      WG1_2447_2457,
				      WG1_2467_2467),
	 .chan11g_turbo		= BM1(T3_2437_2437)},

	{.regDmnEnum		= WORC_WORLD,
	 .conformanceTestLimit	= NO_CTL,
	 .dfsMask		= DFS_FCC3 | DFS_ETSI,
	 .pscan			= PSCAN_WWR,
	 .flags			= ADHOC_PER_11D,
	 .chan11a		= BM4(W1_5260_5320,
				      W1_5180_5240,
				      W1_5745_5825,
				      W1_5500_5700),
	 .chan11b		= BM7(W1_2412_2412,
				      W1_2437_2442,
				      W1_2462_2462,
				      W1_2472_2472,
				      W1_2417_2432,
				      W1_2447_2457,
				      W1_2467_2467),
	 .chan11g		= BM7(WG1_2412_2412,
				      WG1_2437_2442,
				      WG1_2462_2462,
				      WG1_2472_2472,
				      WG1_2417_2432,
				      WG1_2447_2457,
				      WG1_2467_2467),
	 .chan11g_turbo		= BM1(T3_2437_2437)},

	{.regDmnEnum		= NULL1,
	 .conformanceTestLimit	= NO_CTL,
	}
};

#endif
