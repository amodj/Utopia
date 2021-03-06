/*
 * arch/x86/mm/hap/private.h
 *
 * Copyright (c) 2007, AMD Corporation (Wei Huang)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place - Suite 330, Boston, MA 02111-1307 USA.
 *
 */
#ifndef __HAP_PRIVATE_H__
#define __HAP_PRIVATE_H__

/********************************************/
/*          GUEST TRANSLATION FUNCS         */
/********************************************/
unsigned long hap_gva_to_gfn_2level(struct vcpu *v, unsigned long gva, 
                                    uint32_t *pfec);
unsigned long hap_gva_to_gfn_3level(struct vcpu *v, unsigned long gva,
                                    uint32_t *pfec);
unsigned long hap_gva_to_gfn_4level(struct vcpu *v, unsigned long gva,
                                    uint32_t *pfec);


#endif /* __SVM_NPT_H__ */
