
////////////////////////////////////////////////////////////////////////////////

// The Following are only examples and places where this code could be implemented.
//  It is not final or guaranteed working.
//  This should only serve as a reference for implementing.

////////////////////////////////////////////////////////////////////////////////

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

#include "transactions/ux/display_ux.h"

// #include <stdbool.h>
// #include <string.h>

// #include "transactions/transaction.h"

// #include "transactions/types/types.h"

// #include "transactions/ux/transfer_ux.h"
// #include "transactions/ux/second_signature_ux.h"
#include "transactions/ux/delegate_registration_ux.h"
// #include "transactions/ux/vote_ux.h"
// #include "transactions/ux/ipfs_ux.h"
// #include "transactions/ux/htlc_lock_ux.h"
// #include "transactions/ux/htlc_claim_ux.h"
// #include "transactions/ux/htlc_refund_ux.h"

// #include "display/context.h"
// #include "display/display.h"

// ////////////////////////////////////////////////////////////////////////////////
// extern void SetUxDisplay(size_t steps, bool isExtended);

// ////////////////////////////////////////////////////////////////////////////////
// void SetUx(const Transaction *transaction) {
//     explicit_bzero(&displayCtx, sizeof(displayCtx));

//     const bool hasVendorField = transaction->vendorFieldLength > 0;

//     switch (transaction->type) {
//         case TRANSFER_TYPE:
//             SetUxTransfer(transaction);
//             SetUxDisplay(UX_TRANSFER_STEPS + hasVendorField, hasVendorField);
//             break;

//         case SECOND_SIGNATURE_TYPE:
//             SetUxSecondSignature(transaction);
//             SetUxDisplay(UX_SECOND_SIGNATURE_STEPS, false);
//             break;

        case DELEGATE_REGISTRATION_TYPE:
            displayDelegateRegistration(transaction);
            SetUxDisplay(UX_DELEGATE_REGISTRATION_STEPS, false);
            break;

//         case VOTE_TYPE:
//             SetUxVote(transaction);
//             SetUxDisplay(UX_VOTE_STEPS, false);
//             break;

//         case IPFS_TYPE:
//             SetUxIpfs(transaction);
//             SetUxDisplay(UX_IPFS_STEPS, true);
//             break;

//         case HTLC_LOCK_TYPE:
//             SetUxHtlcLock(transaction);
//             SetUxDisplay(UX_HTLC_LOCK_STEPS + hasVendorField, hasVendorField);
//             break;

//         case HTLC_CLAIM_TYPE:
//             SetUxHtlcClaim(transaction);
//             SetUxDisplay(UX_HTLC_CLAIM_STEPS, false);
//             break;

//         case HTLC_REFUND_TYPE:
//             SetUxHtlcRefund(transaction);
//             SetUxDisplay(UX_HTLC_REFUND_STEPS, false);
//             break;

//         default: break;
//     };
// }
