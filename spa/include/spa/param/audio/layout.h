/* Simple Plugin API
 *
 * Copyright © 2018 Wim Taymans
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef SPA_AUDIO_LAYOUT_H
#define SPA_AUDIO_LAYOUT_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __FreeBSD__
#include <endian.h>
#endif

/**
 * \addtogroup spa_param
 * \{
 */
#include <spa/param/audio/raw.h>

struct spa_audio_layout_info {
	uint32_t n_channels;
	uint32_t position[SPA_AUDIO_MAX_CHANNELS];
};

#define SPA_AUDIO_LAYOUT_Mono		1, { SPA_AUDIO_CHANNEL_MONO, }
#define SPA_AUDIO_LAYOUT_Stereo		2, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, }
#define SPA_AUDIO_LAYOUT_Quad		4, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_RL, SPA_AUDIO_CHANNEL_RR, }
#define SPA_AUDIO_LAYOUT_Pentagonal	5, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_RL, SPA_AUDIO_CHANNEL_RR, \
					     SPA_AUDIO_CHANNEL_FC, }
#define SPA_AUDIO_LAYOUT_Hexagonal	6, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_RL, SPA_AUDIO_CHANNEL_RR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_RC, }
#define SPA_AUDIO_LAYOUT_Octagonal	8, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_RL, SPA_AUDIO_CHANNEL_RR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_RC, \
					     SPA_AUDIO_CHANNEL_SL, SPA_AUDIO_CHANNEL_SR, }
#define SPA_AUDIO_LAYOUT_Cube		8, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR }, \
					     SPA_AUDIO_CHANNEL_RL, SPA_AUDIO_CHANNEL_RR, \
					     SPA_AUDIO_CHANNEL_TFL, SPA_AUDIO_CHANNEL_TFR, \
					     SPA_AUDIO_CHANNEL_TRL, SPA_AUDIO_CHANNEL_TRR, }


#define SPA_AUDIO_LAYOUT_MPEG_1_0	SPA_AUDIO_LAYOUT_Mono
#define SPA_AUDIO_LAYOUT_MPEG_2_0	SPA_AUDIO_LAYOUT_Stereo
#define SPA_AUDIO_LAYOUT_MPEG_3_0A	3, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, }
#define SPA_AUDIO_LAYOUT_MPEG_3_0B	3, { SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_FL, \
					     SPA_AUDIO_CHANNEL_FR, }
#define SPA_AUDIO_LAYOUT_MPEG_4_0A	4, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_RC, }
#define SPA_AUDIO_LAYOUT_MPEG_4_0B	4, { SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_FL, \
					     SPA_AUDIO_CHANNEL_FR, SPA_AUDIO_CHANNEL_RC, }
#define SPA_AUDIO_LAYOUT_MPEG_5_0A	5, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_SL, \
					     SPA_AUDIO_CHANNEL_SR, }
#define SPA_AUDIO_LAYOUT_MPEG_5_0B	5, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_SL, SPA_AUDIO_CHANNEL_SR, \
					     SPA_AUDIO_CHANNEL_FC, }
#define SPA_AUDIO_LAYOUT_MPEG_5_0C	5, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FC, \
					     SPA_AUDIO_CHANNEL_FR, SPA_AUDIO_CHANNEL_SL, \
					     SPA_AUDIO_CHANNEL_SR, }
#define SPA_AUDIO_LAYOUT_MPEG_5_0D	5, { SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_FL, \
					     SPA_AUDIO_CHANNEL_FR, SPA_AUDIO_CHANNEL_SL, \
					     SPA_AUDIO_CHANNEL_SR, }
#define SPA_AUDIO_LAYOUT_MPEG_5_1A	6, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_LFE, \
					     SPA_AUDIO_CHANNEL_SL, SPA_AUDIO_CHANNEL_SR, }
#define SPA_AUDIO_LAYOUT_MPEG_5_1B	6, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_SL, SPA_AUDIO_CHANNEL_SR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_LFE, }
#define SPA_AUDIO_LAYOUT_MPEG_5_1C	6, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FC, \
					     SPA_AUDIO_CHANNEL_FR, SPA_AUDIO_CHANNEL_SL, \
					     SPA_AUDIO_CHANNEL_SR, SPA_AUDIO_CHANNEL_LFE, }
#define SPA_AUDIO_LAYOUT_MPEG_5_1D	6, { SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_FL, \
					     SPA_AUDIO_CHANNEL_FR, SPA_AUDIO_CHANNEL_SL, \
					     SPA_AUDIO_CHANNEL_SR, SPA_AUDIO_CHANNEL_LFE, }
#define SPA_AUDIO_LAYOUT_MPEG_6_1A	7, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_LFE, \
					     SPA_AUDIO_CHANNEL_SL, SPA_AUDIO_CHANNEL_SR, \
					     SPA_AUDIO_CHANNEL_RC, }
#define SPA_AUDIO_LAYOUT_MPEG_7_1A	8, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_LFE, \
					     SPA_AUDIO_CHANNEL_RL, SPA_AUDIO_CHANNEL_RR, \
					     SPA_AUDIO_CHANNEL_SL, SPA_AUDIO_CHANNEL_SR, }
#define SPA_AUDIO_LAYOUT_MPEG_7_1B	8, { SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_SL, \
					     SPA_AUDIO_CHANNEL_SR, SPA_AUDIO_CHANNEL_FL, \
					     SPA_AUDIO_CHANNEL_FR, SPA_AUDIO_CHANNEL_RL, \
					     SPA_AUDIO_CHANNEL_RR, SPA_AUDIO_CHANNEL_LFE, }
#define SPA_AUDIO_LAYOUT_MPEG_7_1C	8, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_LFE, \
					     SPA_AUDIO_CHANNEL_SL, SPA_AUDIO_CHANNEL_SR, \
					     SPA_AUDIO_CHANNEL_RL, SPA_AUDIO_CHANNEL_RR, }


#define SPA_AUDIO_LAYOUT_2_1		3, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_LFE, }

#define SPA_AUDIO_LAYOUT_2RC		3, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_RC, }
#define SPA_AUDIO_LAYOUT_2FC		3, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, }

#define SPA_AUDIO_LAYOUT_3_1		4, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_LFE, }
#define SPA_AUDIO_LAYOUT_4_0		4, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_RC, }
#define SPA_AUDIO_LAYOUT_2_2		4, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_SL, SPA_AUDIO_CHANNEL_SR, }

#define SPA_AUDIO_LAYOUT_4_1		5, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_LFE, \
					     SPA_AUDIO_CHANNEL_RC, }
#define SPA_AUDIO_LAYOUT_5_0		5, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_SL, \
					     SPA_AUDIO_CHANNEL_SR, }
#define SPA_AUDIO_LAYOUT_5_0R		5, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_RL, \
					     SPA_AUDIO_CHANNEL_RR, }
#define SPA_AUDIO_LAYOUT_5_1		6, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_LFE, \
					     SPA_AUDIO_CHANNEL_SL, SPA_AUDIO_CHANNEL_SR, }
#define SPA_AUDIO_LAYOUT_5_1R		6, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_LFE, \
					     SPA_AUDIO_CHANNEL_RL, SPA_AUDIO_CHANNEL_RR, }
#define SPA_AUDIO_LAYOUT_6_0		6, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_RC, \
					     SPA_AUDIO_CHANNEL_SL, SPA_AUDIO_CHANNEL_SR, }
#define SPA_AUDIO_LAYOUT_6_0F		6, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FLC, SPA_AUDIO_CHANNEL_FRC, \
					     SPA_AUDIO_CHANNEL_SL, SPA_AUDIO_CHANNEL_SR, }
#define SPA_AUDIO_LAYOUT_6_1		7, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_LFE, \
					     SPA_AUDIO_CHANNEL_RC, SPA_AUDIO_CHANNEL_SL, \
					     SPA_AUDIO_CHANNEL_SR, }
#define SPA_AUDIO_LAYOUT_6_1F		7, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_LFE, \
					     SPA_AUDIO_CHANNEL_RL, SPA_AUDIO_CHANNEL_RR, \
					     SPA_AUDIO_CHANNEL_RC, }
#define SPA_AUDIO_LAYOUT_7_0		7, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_RL, \
					     SPA_AUDIO_CHANNEL_RR, SPA_AUDIO_CHANNEL_SL, \
					     SPA_AUDIO_CHANNEL_SR, }
#define SPA_AUDIO_LAYOUT_7_0F		7, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_FLC, \
					     SPA_AUDIO_CHANNEL_FRC, SPA_AUDIO_CHANNEL_SL, \
					     SPA_AUDIO_CHANNEL_SR, }
#define SPA_AUDIO_LAYOUT_7_1		8, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_LFE, \
					     SPA_AUDIO_CHANNEL_RL, SPA_AUDIO_CHANNEL_RR, \
					     SPA_AUDIO_CHANNEL_SL, SPA_AUDIO_CHANNEL_SR, }
#define SPA_AUDIO_LAYOUT_7_1W		8, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_LFE, \
					     SPA_AUDIO_CHANNEL_FLC, SPA_AUDIO_CHANNEL_FRC, \
					     SPA_AUDIO_CHANNEL_SL, SPA_AUDIO_CHANNEL_SR, }
#define SPA_AUDIO_LAYOUT_7_1WR		8, { SPA_AUDIO_CHANNEL_FL, SPA_AUDIO_CHANNEL_FR, \
					     SPA_AUDIO_CHANNEL_FC, SPA_AUDIO_CHANNEL_LFE, \
					     SPA_AUDIO_CHANNEL_RL, SPA_AUDIO_CHANNEL_RR, \
					     SPA_AUDIO_CHANNEL_FLC, SPA_AUDIO_CHANNEL_FRC, }

/**
 * \}
 */

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif /* SPA_AUDIO_LAYOUT_H */
