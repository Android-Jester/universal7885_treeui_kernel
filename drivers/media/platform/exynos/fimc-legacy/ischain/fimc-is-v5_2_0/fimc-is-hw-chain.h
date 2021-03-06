/*
 * Samsung Exynos SoC series FIMC-IS2 driver
 *
 * Copyright (c) 2015 Samsung Electronics Co., Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef FIMC_IS_HW_CHAIN_V5_2_H
#define FIMC_IS_HW_CHAIN_V5_2_H

#include "fimc-is-hw-api-common.h"
#include "fimc-is-groupmgr.h"
#include "fimc-is-config.h"

enum sysreg_cam_reg_name {
	SYSREG_CAM_R_USER_CON1,
	SYSREG_CAM_REG_CNT
};

enum sysreg_isplp_reg_name {
	SYSREG_ISPLP_R_USER_CON,
	SYSREG_ISPLP_REG_CNT
};

enum sysreg_isphq_reg_name {
	SYSREG_ISPHQ_R_USER_CON,
	SYSREG_ISPHQ_REG_CNT
};

enum qe_3aaw_reg_name {
	QE_3AAW_R_QOS_CON,
	QE_3AAW_R_READ_CH_CON,
	QE_3AAW_R_WRITE_CH_CON,
	QE_3AAW_REG_CNT
};

enum qe_isplp_reg_name {
	QE_ISPLP_R_QOS_CON,
	QE_ISPLP_R_READ_CH_CON,
	QE_ISPLP_R_WRITE_CH_CON,
	QE_ISPLP_REG_CNT
};

enum qe_3aa_reg_name {
	QE_3AA_R_QOS_CON,
	QE_3AA_R_READ_CH_CON,
	QE_3AA_R_WRITE_CH_CON,
	QE_3AA_REG_CNT
};

enum qe_isphq_reg_name {
	QE_ISPHQ_R_QOS_CON,
	QE_ISPHQ_R_READ_CH_CON,
	QE_ISPHQ_R_WRITE_CH_CON,
	QE_ISPHQ_REG_CNT
};

enum sysreg_cam_reg_field {
	SYSREG_CAM_F_GLUEMUX_SRDZ_VAL,
	SYSREG_CAM_F_GLUEMUX_MC_SCALER_SC1_VAL,
	SYSREG_CAM_F_GLUEMUX_MC_SCALER_SC0_VAL,
	SYSREG_CAM_F_GLUEMUX_ISPLP_VAL,
	SYSREG_CAM_F_GLUEMUX_ISPHQ_VAL,
	SYSREG_CAM_F_GLUEMUX_WOBNS_VAL,
	SYSREG_CAM_F_GLUEMUX_BNS_VAL,
	SYSREG_CAM_F_RT_INFO_TPU1_VAL,
	SYSREG_CAM_F_RT_INFO_VRA_VAL,
	SYSREG_CAM_F_RT_INFO_TPU0_VAL,
	SYSREG_CAM_F_RT_INFO_MC_SCALER_VAL,
	SYSREG_CAM_F_RT_INFO_CSISX4_VAL,
	SYSREG_CAM_REG_FIELD_CNT
};

enum sysreg_isplp_reg_field {
	SYSREG_ISPLP_F_RT_INFO_ISPLP,
	SYSREG_ISPLP_F_RT_INFO_3AAW,
	SYSREG_ISPLP_F_GLUEMUX_ISPLP_SEL,
	SYSREG_ISPLP_F_MCUCTL_ISPLP_AWCACHE_H,
	SYSREG_ISPLP_F_MCUCTL_ISPLP_ARCACHE_L,
	SYSREG_ISPLP_REG_FIELD_CNT
};

enum sysreg_isphq_reg_field {
	SYSREG_ISPHQ_F_RT_INFO_ISPHQ,
	SYSREG_ISPHQ_F_RT_INFO_3AA,
	SYSREG_ISPHQ_F_GLUEMUX_ISPHQ_SEL,
	SYSREG_ISPHQ_F_MCUCTL_ISPHQ_AWCACHE_H,
	SYSREG_ISPHQ_F_MCUCTL_ISPHQ_ARCACHE_L,
	SYSREG_ISPHQ_REG_FIELD_CNT
};

#define GROUP_HW_MAX	(GROUP_SLOT_MAX)

#define IORESOURCE_CSIS_DMA	0
#define IORESOURCE_3AAW		1
#define IORESOURCE_3AA		2
#define IORESOURCE_ISPLP	3
#define IORESOURCE_ISPHQ	4
#define IORESOURCE_TPU0		5
#define IORESOURCE_TPU1		6
#define IORESOURCE_MCSC		7
#define IORESOURCE_VRA_CH0	8
#define IORESOURCE_VRA_CH1	9
#define IORESOURCE_DCP		10
#define IORESOURCE_SRDZ		11

#define FIMC_IS_RESERVE_LIB_SIZE	(0x01000000)	/* 16MB */
#define FIMC_IS_TAAISP_SIZE		(0x00500000)	/* 5MB */
#define FIMC_IS_VRA_SIZE		(0x00800000)	/* 8MB */

#define SYSREG_CAM_BASE_ADDR		0x12C20000
#define SYSREG_ISPLP_BASE_ADDR		0x13020000
#define SYSREG_ISPHQ_BASE_ADDR		0x13120000
#define SYSREG_DCP_BASE_ADDR		0x12E20000
#define SYSREG_SRDZ_BASE_ADDR		0x14220000

#define HWFC_RESET_ADDR			0x12C50850
#define QE_3AAW_BASE_ADDR		0x13080000
#define QE_ISPLP_BASE_ADDR		0x13090000
#define QE_3AA_BASE_ADDR		0x13180000
#define QE_ISPHQ_BASE_ADDR		0x13190000

enum taaisp_chain_id {
	ID_3AA_0 = 0,
	ID_3AA_1 = 1,
	ID_ISP_0 = 2,
	ID_ISP_1 = 3,
	ID_TPU_0 = 4,
	ID_TPU_1 = 5,
	ID_DCP   = 6,
	ID_3AAISP_MAX
};

/* the number of interrupt source at each IP */
enum hwip_interrupt_map {
	INTR_HWIP1 = 0,
	INTR_HWIP2 = 1,
	INTR_HWIP_MAX
};

/* Specific interrupt map belonged to each IP */

/* MC-Scaler */
#define MCSC_INTR_MASK		(0x00000034)
#define USE_DMA_BUFFER_INDEX	(0) /* 0 ~ 7 */
#define MCSC_PRECISION		(20)
#define MCSC_POLY_RATIO_UP	(8)
#define MCSC_POLY_RATIO_DOWN	(4)
#define MCSC_POST_RATIO_DOWN	(8)
#define MCSC_POST_WA
#define MCSC_POST_WA_SHIFT	(8)	/* 256 = 2^8 */

#define MCSC_OUTPUT_SSB		(0xF)	/* This number has no special meaning. */

enum mc_scaler_interrupt_map {
	INTR_MC_SCALER_FRAME_END		= 0,
	INTR_MC_SCALER_FRAME_START		= 1,
	INTR_MC_SCALER_WDMA_FINISH		= 2,
	INTR_MC_SCALER_CORE_FINISH		= 3,
	INTR_MC_SCALER_SHADOW_HW_TRIGGER	= 4,
	INTR_MC_SCALER_SHADOW_TRIGGER		= 5,
	INTR_MC_SCALER_INPUT_HORIZONTAL_OVF	= 7,
	INTR_MC_SCALER_INPUT_HORIZONTAL_UNF	= 8,
	INTR_MC_SCALER_INPUT_VERTICAL_OVF	= 9,
	INTR_MC_SCALER_INPUT_VERTICAL_UNF	= 10,
	INTR_MC_SCALER_OUTSTALL			= 11,
	INTR_MC_SCALER_OVERFLOW			= 12
};

#define SRDZ_INTR_MASK		(0x00000003)

enum srdz_interrupt_map {
	INTR_SRDZ_FRAME_END			= 0,
	INTR_SRDZ_FRAME_START			= 1,
	INTR_SRDZ_SFR_QUEUE_ERROR		= 2,
	INTR_SRDZ_COLUMN_SIZE_ERROR		= 3,
	INTR_SRDZ_ROW_SIZE_ERROR		= 5,
	INTR_SRDZ_TIME_OUT			= 7,
	INTR_SRDZ_RDMA_FRAEM_END		= 9,
	INTR_SRDZ_INFIFO_FRAME_END		= 10,
	INTR_SRDZ_EZPRE_FRAME_END		= 11,
	INTR_SRDZ_BCLPF_FRAME_END		= 12,
	INTR_SRDZ_SAD_FRAME_END			= 13,
	INTR_SRDZ_PATCH_FRAME_END		= 14,
	INTR_SRDZ_RECON_FRAME_END		= 15,
	INTR_SRDZ_EZPOST_FRAME_END		= 16,
	INTR_SRDZ_OUTFIFO_FRAME_END		= 17,
	INTR_SRDZ_WDMA_FRAME_END		= 18,
	INTR_SRDZ_FRAME_END_SUBFRAME		= 19,
	INTR_SRDZ_FRAME_START_SUBFRAME		= 20,
};

enum vra_chain0_interrupt_map {
	CH0INT_CIN_FR_ST			= 0,	/* VSYNC rise - verified when CIN is active */
	CH0INT_CIN_FR_END			= 1,	/* VSYNC fall - verified when CIN is active */
	CH0INT_CIN_LINE_ST			= 2,	/* Not used - per line */
	CH0INT_CIN_LINE_END			= 3,	/* Not used - per line */
	CH0INT_CIN_SP_LINE			= 4,	/* On start of line defined by reg_cin2isp_int_row
							- Currently not used */
	CH0INT_CIN_ERR_SIZES			= 5,	/* Interrupt occurs as the error occurs
							- not used - CH0INT_FRAME_SIZE_ERROR is used instead */
	CH0INT_CIN_ERR_YUV_FORMAT		= 6,	/* For YUV444 - not all channels are valid,
							for 422 - Even & Odd data not match (e.g. YU match YV) */
	CH0INT_CIN_FR_ST_NO_ACTIVE		= 7,	/* VSYNC received when CH0 not enabled */
	CH0INT_DMA_IN_ERROR			= 8,	/* An error that is "read" by DMA controller.
							Not a control error. Should be reported to HOST. */
	CH0INT_DMA_IN_FLUSH_DONE		= 9,	/* When TRANS_STOP_REQ is set this interrupt should be set */
	CH0INT_DMA_IN_FR_END			= 10,	/* Finished operation */
	CH0INT_DMA_IN_INFO			= 11,	/* Stall / Frame Start while active / Track
							- see RW_reg_dma_info_int_vector_ofs. Not used. */
	CH0INT_OUT_DMA_ERROR			= 12,	/* An error that is "read" by DMA controller.
							Not a control error. Should be reported to HOST. */
	CH0INT_OUT_DMA_FLUSH_DONE		= 13,	/* When TRANS_STOP_REQ is set this interrupt should be set */
	CH0INT_OUT_DMA_FR_END			= 14,	/* Finished operation */
	CH0INT_OUT_DMA_INFO			= 15,	/* Stall / Frame Start while active / Track
							- see RW_reg_dma_info_int_vector_ofs. Not used. */
	CH0INT_RWS_TRIGGER			= 16,	/* Not used (In our code Trigger == Frame Start) */
	CH0INT_END_FRAME			= 17,	/* CIN + DMAs + ISP chain were finished */
	CH0INT_END_ISP_DMA_OUT			= 18,	/* ISP chain + DMA out were finished (doesn't include CIN) */
	CH0INT_END_ISP_INPUT			= 19,	/* ISP chain + CIN / Input DMAs were finished
							(doesn't include output) */
	CH0INT_FRAME_SIZE_ERROR			= 20,	/* Like CH0INT_CIN_ERR_SIZES
							but interrupt occurs when VSYNC falls */
	CH0INT_ERR_FR_ST_BEF_FR_END		= 21,	/* VSYNC received while previous frame is being processed.
							Might be a trigger for "no end isp" */
	CH0INT_ERR_FR_ST_WHILE_FLUSH		= 22,	/* Should be tested on end of TRANS_STOP */
	CH0INT_ERR_VRHR_INTERVAL_VIOLATION	= 23,	/* Violation of minimal delta Frame start to first data */
	CH0INT_ERR_HFHR_INTERVAL_VIOLATION	= 24,	/* Violation of minimal delta End line -> Next line */
	CH0INT_ERR_PYRAMID_OVERFLOW		= 25
};

enum vra_chain1_interrupt_map {
	CH1INT_IN_CONT_SP_LINE			= 0,	/* Reach RW_reg_ch1_interrupted_insruction +
							RW_reg_ch1_interrupted_line */
	CH1INT_IN_STOP_IMMED_DONE		= 1,	/* Stop immediate command is done. */
	CH1INT_IN_END_OF_CONTEXT		= 2,	/* The reason might be found in RW_reg_ch1_stop_cause */
	CH1INT_IN_START_OF_CONTEXT		= 3,	/* Not used. */
	CH1INT_END_LOAD_FEATURES		= 4,	/* Not used. */
	CH1INT_SHADOW_TRIGGER			= 5,	/* Not used. */
	CH1INT_OUT_DMA_OVERFLOW			= 6,	/* Some output results not written to memory */
	CH1INT_MAX_NUM_RESULTS			= 7,	/* RCCs found more than maximal number of results
							- some results not sent to DMA */
	CH1INT_IN_DMA_ERROR			= 8,
	CH1INT_IN_DMA_FLUSH_DONE		= 9,	/* Not used. HW responsibility to check */
	CH1INT_IN_DMA_FR_END			= 10,	/* Finished operation */
	CH1INT_IN_DMA_INFO			= 11,	/* Stall / Frame Start while active / Track
							- see RW_reg_dma_info_int_vector_ofs */
	CH1INT_RES_DMA_ERROR			= 12,
	CH1INT_RES_DMA_FLUSH_DONE		= 13,	/* Not used. HW responsibility to check */
	CH1INT_RES_DMA_FR_END			= 14,	/* Finished operation */
	CH1INT_RES_DMA_INFO			= 15,	/* Stall / Frame Start while active / Track
							- see RW_reg_dma_info_int_vector_ofs */
	CH1INT_WATCHDOG				= 16	/* Watchdog timer expired => RCC is assumed to be stack */
};
#endif
