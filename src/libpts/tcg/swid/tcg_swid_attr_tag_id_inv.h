/*
 * Copyright (C) 2013 Andreas Steffen
 * HSR Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

/**
 * @defgroup tcg_swid_attr_tag_id_inv tcg_swid_attr_tag_id_inv
 * @{ @ingroup tcg_attr
 */

#ifndef TCG_SWID_ATTR_TAG_ID_INV_H_
#define TCG_SWID_ATTR_TAG_ID_INV_H_

typedef struct tcg_swid_attr_tag_id_inv_t tcg_swid_attr_tag_id_inv_t;

#include "tcg/tcg_attr.h"
#include "swid/swid_tag_id.h"

#include <pa_tnc/pa_tnc_attr.h>

/**
 * Class implementing the TCG SWID Tag Identifier Inventory attribute
 *
 */
struct tcg_swid_attr_tag_id_inv_t {

	/**
	 * Public PA-TNC attribute interface
	 */
	pa_tnc_attr_t pa_tnc_attribute;

	/**
	 * Get Request ID
	 *
	 * @return					Request ID
	 */
	u_int32_t (*get_request_id)(tcg_swid_attr_tag_id_inv_t *this);

	/**
	 * Get Last Event ID
	 *
	 * @param eid_epoch			Event ID Epoch
	 * @return					Last Event ID
	 */
	u_int32_t (*get_last_eid)(tcg_swid_attr_tag_id_inv_t *this,
							  u_int32_t *eid_epoch);

	/**
	 * Add Tag ID
	 *
	 * @param tag_id			SWID Tag ID (is not cloned by constructor!)
	 */
	void (*add_tag_id)(tcg_swid_attr_tag_id_inv_t *this, swid_tag_id_t *tag_id);

	/**
	 * Create Tag ID enumerator
	 *
	 * @return					Tag ID enumerator
	 */
	enumerator_t* (*create_tag_id_enumerator)(tcg_swid_attr_tag_id_inv_t *this);

};

/**
 * Creates an tcg_swid_attr_tag_id_inv_t object
 *
 * @param request_id			Copy of the Request ID
 * @param eid_epoch				Event ID Epoch
 * @param eid					Last Event ID
 */
pa_tnc_attr_t* tcg_swid_attr_tag_id_inv_create(u_int32_t request_id,
											   u_int32_t eid_epoch,
											   u_int32_t eid);

/**
 * Creates an tcg_swid_attr_tag_id_inv_t object from received data
 *
 * @param value					unparsed attribute value
 */
pa_tnc_attr_t* tcg_swid_attr_tag_id_inv_create_from_data(chunk_t value);

#endif /** TCG_SWID_ATTR_TAG_ID_INV_H_ @}*/
