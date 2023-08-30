/****************************************************************************
 *
 * Copyright (c) 2022 STMicroelectronics - All Rights Reserved
 *
 * License terms: STMicroelectronics Proprietary in accordance with licensing
 * terms SLA0098 at www.st.com.
 *
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *****************************************************************************/

/* SR5E1 memory map */

MEMORY
{
    /* flash memory */
    cflash1        (rx) : org = 0x08000000, len = 960k  /* Code Flash 1 */
    cflash2        (rx) : org = 0x080F0000, len = 960k  /* Code Flash 2 */
    dflash         (rx) : org = 0x08F00000, len = 64k   /* Data Flash */

    /* system memory */
    sram1          (wx) : org = 0x24000000, len = 128k  /* SRAM1 */
    sram2          (wx) : org = 0x24020000, len = 128k  /* SRAM2 */

    /* TCM */
    itcm1          (wx) : org = 0x5A000000, len = 32k   /* ITCM1 */
    itcm2          (wx) : org = 0x5A040000, len = 32k   /* ITCM2 */
    dtcm1          (wx) : org = 0x5C000000, len = 64k   /* DTCM1 */
    dtcm2          (wx) : org = 0x5C040000, len = 64k   /* DTCM2 */

    /* flash  memory (alias for cores) */
    core1_nvm      (rx) : org = 0x08000000, len = 960k  /* cflash1 */
    core2_nvm      (rx) : org = 0x080F0000, len = 960k  /* cflash2 */

    /* system memory (alias for cores) */
    core1_ram      (wx) : org = 0x24000000, len = 128k  /* sram1 */
    core2_ram      (wx) : org = 0x24020000, len = 128k  /* sram2 */

    /* TCM (alias for cores) */
    core1_itcm_dir (wx) : org = 0x00000000, len = 32k   /* itcm1 direct access */
    core1_itcm_ind (wx) : org = 0x5A000000, len = 32k   /* itcm1 indirect access */
    core1_dtcm_dir (wx) : org = 0x20000000, len = 64k   /* dtcm1 direct access */
    core1_dtcm_ind (wx) : org = 0x5C000000, len = 64k   /* dtcm1 indirect access */
    core2_itcm_dir (wx) : org = 0x00000000, len = 32k   /* itcm2 direct access */
    core2_itcm_ind (wx) : org = 0x5A040000, len = 32k   /* itcm2 indirect access */
    core2_dtcm_dir (wx) : org = 0x20000000, len = 64k   /* dtcm2 direct access */
    core2_dtcm_ind (wx) : org = 0x5C040000, len = 64k   /* dtcm2 indirect access */
}
