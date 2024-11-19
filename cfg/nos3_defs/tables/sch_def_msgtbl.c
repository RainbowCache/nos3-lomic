/*
** $Id: sch_def_msgtbl.c 1.3 2017/06/21 15:28:56EDT mdeschu Exp  $
**
**  Copyright (c) 2007-2014 United States Government as represented by the 
**  Administrator of the National Aeronautics and Space Administration. 
**  All Other Rights Reserved.  
**
**  This software was created at NASA's Goddard Space Flight Center.
**  This software is governed by the NASA Open Source Agreement and may be 
**  used, distributed and modified only pursuant to the terms of that 
**  agreement.
**
** Purpose: Scheduler (SCH) default message definition table data
**
** Author: 
**
** Notes:
**
*/

/*************************************************************************
**
** Include section
**
**************************************************************************/

#include "cfe.h"
#include "cfe_endian.h"
#include "cfe_tbl_filedef.h"
#include "sch_platform_cfg.h"
#include "sch_tbldefs.h"

#include "cfe_msgids.h"
#include "cf_msgids.h"
#include "ci_msgids.h"
#include "ds_msgids.h"
#include "fm_msgids.h"
//#include "hk_msgids.h"
//#include "hs_msgids.h"
#include "lc_msgids.h"
#include "lc_msgdefs.h"
#include "sc_msgids.h"
#include "sch_msgids.h"
#include "to_msgids.h"

/*
** Component Include Files
*/
#include "cam_msgids.h"
#include "generic_adcs_msgids.h"
#include "generic_css_msgids.h"
#include "generic_eps_msgids.h"
#include "generic_fss_msgids.h"
#include "generic_imu_msgids.h"
#include "generic_mag_msgids.h"
#include "generic_radio_msgids.h"
#include "generic_reaction_wheel_msgids.h"
#include "generic_star_tracker_msgids.h"
#include "lomic_thruster_msgids.h"
#include "generic_torquer_msgids.h"
#include "novatel_oem615_msgids.h"
#include "sample_msgids.h"
#include "syn_msgids.h"
#include "cannon_msgids.h"

/*
** Message Table entry map...
**
**  Entry 0 -- reserved (DO NOT USE)
**  
**  Several Entries in this default table provide example messages for a default
**  system. These messages can be uncommented, and the CFE_MAKE_BIG16(SCH_UNUSED_MID) entry just
**  below them can be deleted to enable them.
*/

/*
** Default command definition table data
*/
SCH_MessageEntry_t SCH_DefaultMessageTable[SCH_MAX_MESSAGES] =
{
  /*
  **  DO NOT USE -- entry #0 reserved for "unused" command ID - DO NOT USE
  */
    /* command ID #0 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },

  /*
  **  cFE housekeeping request messages
  */
    /* command ID #1 - Executive Services HK Request   */
  { { CFE_MAKE_BIG16(CFE_ES_SEND_HK_MID),   CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0000 } },
    /* command ID #2 - Event Services HK Request     */
  { { CFE_MAKE_BIG16(CFE_EVS_SEND_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0000 } },
    /* command ID #3 - Software Bus HK Request       */
  { { CFE_MAKE_BIG16(CFE_SB_SEND_HK_MID),   CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0000 } },
    /* command ID #4 - Time Services HK Request      */
  { { CFE_MAKE_BIG16(CFE_TIME_SEND_HK_MID), CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0000 } },
    /* command ID #5 - Table Services HK Request     */
  { { CFE_MAKE_BIG16(CFE_TBL_SEND_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0000 } },

  /*
  **  CFS housekeeping request messages
  */
    /* command ID #6 - Checksum HK Request           */
/*{ { CFE_MAKE_BIG16(CS_SEND_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0000 } }, */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #7 - Data Store HK Request         */
  { { CFE_MAKE_BIG16(DS_SEND_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0000 } },
    /* command ID #8 - File Manager HK Request       */
  { { CFE_MAKE_BIG16(FM_SEND_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0000 } },
    /* command ID #9 - Housekeeping HK Request       */
/*{ { CFE_MAKE_BIG16(HK_SEND_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0000 } }, */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },

    /* command ID #10 - Health & Safety HK Request   */
/*{ { CFE_MAKE_BIG16(HS_SEND_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0000 } }, */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #11 - Limit Checker HK Request     */
  { { CFE_MAKE_BIG16(LC_SEND_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0000 } },
    /* command ID #12 - Memory Dwell HK Request      */
/*{ { CFE_MAKE_BIG16(MD_SEND_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0000 } }, */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #13 - Memory Manager HK Request    */
/*{ { CFE_MAKE_BIG16(MM_SEND_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0000 } }, */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #14 - Stored Command HK Request    */
  { { CFE_MAKE_BIG16(SC_SEND_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0000 } },
    /* command ID #15 - Scheduler HK Request         */
  { { CFE_MAKE_BIG16(SCH_SEND_HK_MID), CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0000 } },

  /*
  **  CFS routine messages
  */
    /* command ID #16 - HK Send Combined Housekeeping Msg #1 */
/*{ { CFE_MAKE_BIG16(HK_SEND_COMBINED_PKT_MID), CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0003), 0x0000, HK_COMBINED_PKT1_MID } }, */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #17 - HK Send Combined Housekeeping Msg #2 */
/*{ { CFE_MAKE_BIG16(HK_SEND_COMBINED_PKT_MID), CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0003), 0x0000, HK_COMBINED_PKT2_MID } }, */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #18 - HK Send Combined Housekeeping Msg #3 */
/*{ { CFE_MAKE_BIG16(HK_SEND_COMBINED_PKT_MID), CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0003), 0x0000, HK_COMBINED_PKT3_MID } }, */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #19 - HK Send Combined Housekeeping Msg #4 */
/*{ { CFE_MAKE_BIG16(HK_SEND_COMBINED_PKT_MID), CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0003), 0x0000, HK_COMBINED_PKT4_MID } }, */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #20 - CS Background Cycle               */
/*{ { CFE_MAKE_BIG16(CS_BACKGROUND_CYCLE_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0000 } }, */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #21 - SC 1 Hz Wakeup                    */
  { { CFE_MAKE_BIG16(SC_1HZ_WAKEUP_MID),        CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0000 } },
    /* command ID #22 - LC Sample Action Points           */
  { { CFE_MAKE_BIG16(LC_SAMPLE_AP_MID),         CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0005), 0x0000, LC_ALL_ACTIONPOINTS, 0x0000 } },
    /* command ID #23 - DS 1 HZ Wakeup                    */
/*{ { CFE_MAKE_BIG16(DS_1HZ_WAKEUP_MID),        CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0000 } }, */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #24 - MD Wakeup                         */
/*{ { CFE_MAKE_BIG16(MD_WAKEUP_MID),            CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0000 } }, */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #25 */
  { { CFE_MAKE_BIG16(CF_WAKE_UP_MID), CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0000 } },
    /* command ID #26 - CF HK Request */
  { { CFE_MAKE_BIG16(CF_SEND_HK_MID),           CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0000) } },
    /* command ID #27 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #28 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #29 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },

  /*
  **  Mission Defined Messages
  */
    /* command ID #30 - Command Ingest HK Request Example */
  { { CFE_MAKE_BIG16(CI_SEND_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0000) } },
    /* command ID #31 - Telemetry Output HK Request Example */
  { { CFE_MAKE_BIG16(TO_SEND_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0000) } },
    /* command ID #32 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #33 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #34 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },  
    /* command ID #35 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #36 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #37 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #38 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #39 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
  
    /* command ID #40 - CAM HK */
  { { CFE_MAKE_BIG16(CAM_SEND_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0000) } },
    /* command ID #41 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #42 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #43 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #44 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },  
    /* command ID #45 - RW HK */
  { { CFE_MAKE_BIG16(GENERIC_RW_APP_CMD_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0200) } },
    /* command ID #46 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #47 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #48 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #49 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },

    /* command ID #50 - GPS HK */
  { { CFE_MAKE_BIG16(NOVATEL_OEM615_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0000 } },
    /* command ID #51 - GPS Data */
  { { CFE_MAKE_BIG16(NOVATEL_OEM615_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), 0x0100 } },
    /* command ID #52 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #53 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #54 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },  
    /* command ID #55 - Sample HK */
  { { CFE_MAKE_BIG16(SAMPLE_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0000) } },
    /* command ID #56 - Sample Data */
  { { CFE_MAKE_BIG16(SAMPLE_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0100) } },
    /* command ID #57 */
  { { CFE_MAKE_BIG16(SYN_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0000) } },
    /* command ID #58 */
  { { CFE_MAKE_BIG16(CANNON_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0000) } },
    /* command ID #59 */
  { { CFE_MAKE_BIG16(CANNON_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0100) } },

    /* command ID #60 - FSS HK */
  { { CFE_MAKE_BIG16(GENERIC_FSS_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0000) } },
    /* command ID #61 - FSS Data */
  { { CFE_MAKE_BIG16(GENERIC_FSS_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0100) } },
    /* command ID #62 */
  { { CFE_MAKE_BIG16(GENERIC_TORQUER_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0000) } },
    /* command ID #63 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #64 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },  
    /* command ID #65 - EPS HK */
  { { CFE_MAKE_BIG16(GENERIC_EPS_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0000) } },
    /* command ID #66 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #67 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #68 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #69 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },

    /* command ID #70 - CSS HK */
  { { CFE_MAKE_BIG16(GENERIC_CSS_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0000) } },
    /* command ID #71 - CSS Data */
  { { CFE_MAKE_BIG16(GENERIC_CSS_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0100) } },
    /* command ID #72 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #73 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #74 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #75 - IMU HK */
  { { CFE_MAKE_BIG16(GENERIC_IMU_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0000) } },
    /* command ID #76 - IMU Data */
  { { CFE_MAKE_BIG16(GENERIC_IMU_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0100) } },
    /* command ID #77 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #78 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #79 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
  
    /* command ID #80 - MAG HK */
  { { CFE_MAKE_BIG16(GENERIC_MAG_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0000) } },
    /* command ID #81 - MAG Data */
  { { CFE_MAKE_BIG16(GENERIC_MAG_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0100) } },
    /* command ID #82 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #83 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #84 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #85 - Radio HK */
  { { CFE_MAKE_BIG16(GENERIC_RADIO_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0000) } },
    /* command ID #86 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #87 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #88 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #89 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
  
    /* command ID #90 - ADCS ADAC */
  { { CFE_MAKE_BIG16(GENERIC_ADCS_ADAC_UPDATE_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0000) } },
    /* command ID #91 - ADCS DI */
  { { CFE_MAKE_BIG16(GENERIC_ADCS_CMD_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0300) } },
    /* command ID #92 - ADCS AD */
  { { CFE_MAKE_BIG16(GENERIC_ADCS_CMD_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0400) } },
    /* command ID #93 - ADCS GNC */
  { { CFE_MAKE_BIG16(GENERIC_ADCS_CMD_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0500) } },
    /* command ID #94 - ADCS AC */
  { { CFE_MAKE_BIG16(GENERIC_ADCS_CMD_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0600) } },
    /* command ID #94 - ADCS AC */
  { { CFE_MAKE_BIG16(GENERIC_ADCS_CMD_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0700) } },
    /* command ID #96 - ADCS HK */
  { { CFE_MAKE_BIG16(GENERIC_ADCS_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0000) } },
    /* command ID #97 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #98 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #99 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
  
    /* command ID #100 - Star Tracker HK */
  { { CFE_MAKE_BIG16(GENERIC_STAR_TRACKER_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0000) } },
    /* command ID #101 - Star Tracker Data */
  { { CFE_MAKE_BIG16(GENERIC_STAR_TRACKER_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0100) } },
    /* command ID #102 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #103 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #104 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #105 - Thruster HK */
  { { CFE_MAKE_BIG16(LOMIC_THRUSTER_REQ_HK_MID),  CFE_MAKE_BIG16(0xC000), CFE_MAKE_BIG16(0x0001), CFE_MAKE_BIG16(0x0000) } },
    /* command ID #106 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #107 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #108 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #109 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
  
    /* command ID #110 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #111 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #112 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #113 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #114 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #115 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #116 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #117 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #118 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #119 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
  
    /* command ID #120 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #121 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #122 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #123 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #124 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #125 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #126 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } },
    /* command ID #127 */
  { { CFE_MAKE_BIG16(SCH_UNUSED_MID) } }

};

/*
** Table file header
*/
CFE_TBL_FILEDEF(SCH_DefaultMessageTable, SCH.MSG_DEFS, SCH message definitions table, sch_def_msgtbl.tbl)

/*************************************************************************
**
** File data
**
**************************************************************************/

/*
** (none)
*/

/*************************************************************************
**
** Local function prototypes
**
**************************************************************************/

/*
** (none)
*/

/************************/
/*  End of File Comment */
/************************/

