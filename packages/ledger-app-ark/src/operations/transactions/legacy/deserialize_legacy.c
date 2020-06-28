/*******************************************************************************
 * This file is part of the ARK Ledger App.
 *
 * Copyright (c) ARK Ecosystem <info@ark.io>
 *
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

#include "transactions/legacy/deserialize_legacy.h"

#include <stddef.h>
#include <stdint.h>

#include "constants.h"

#include "transactions/transaction.h"
#include "transactions/offsets.h"

#include "utils/unpack.h"
#include "utils/utils.h"

////////////////////////////////////////////////////////////////////////////////
void deserializeCommonLegacy(Transaction *transaction,
                             const uint8_t *buffer,
                             size_t size) {
    // Deserialize Common
    transaction->version        = TRANSACTION_VERSION_LEGACY;
    transaction->type           = buffer[TYPE_OFFSET_LEGACY];

    bytecpy(transaction->recipientId,
            &buffer[RECIPIENT_OFFSET_LEGACY],
            ADDRESS_HASH_LEN);

    transaction->vendorField = (uint8_t *)&buffer[VF_OFFSET];
    if (buffer[VF_OFFSET] != 0) {
        uint8_t *ptr = transaction->vendorField;
        while (*ptr++) {
            ++transaction->vendorFieldLength;
        }
    }
    else {
        transaction->vendorFieldLength = 0U;
    }

    transaction->amount         = U8LE(buffer, AMOUNT_OFFSET_LEGACY);
    transaction->fee            = U8LE(buffer, FEE_OFFSET_LEGACY);

    transaction->assetOffset    = ASSET_OFFSET_LEGACY;
    transaction->assetSize      = size - transaction->assetOffset;
}
