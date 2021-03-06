/*-------------------------------------------------------------------------
 * This source code is confidential proprietary information which is
 * Copyright (c) 2017 by Great Hill Corporation.
 * All Rights Reserved
 *
 * The LICENSE at the root of this repo details your rights (if any)
 *------------------------------------------------------------------------*/
/*
 * This file was generated with makeClass. Edit only those parts of the code inside
 * of 'EXISTING_CODE' tags.
 */
#include "kill.h"
#include "etherlib.h"

//---------------------------------------------------------------------------
IMPLEMENT_NODE(QKill, CTransaction, curVersion);

//---------------------------------------------------------------------------
static SFString nextKillChunk(const SFString& fieldIn, bool& force, const void *data);
static SFString nextKillChunk_custom(const SFString& fieldIn, bool& force, const void *data);

//---------------------------------------------------------------------------
void QKill::Format(CExportContext& ctx, const SFString& fmtIn, void *data) const {
    if (!m_showing)
        return;

    if (fmtIn.empty()) {
        ctx << toJson();
        return;
    }

    SFString fmt = fmtIn;
    if (handleCustomFormat(ctx, fmt, data))
        return;

    while (!fmt.empty())
        ctx << getNextChunk(fmt, nextKillChunk, this);
}

//---------------------------------------------------------------------------
SFString nextKillChunk(const SFString& fieldIn, bool& force, const void *data) {
    const QKill *kil = (const QKill *)data;
    if (kil) {
        // Give customized code a chance to override first
        SFString ret = nextKillChunk_custom(fieldIn, force, data);
        if (!ret.empty())
            return ret;

        switch (tolower(fieldIn[0])) {
            case '_':
                if ( fieldIn % "_to" ) return fromAddress(kil->_to);
                break;
        }

        // EXISTING_CODE
        // EXISTING_CODE

        // Finally, give the parent class a chance
        ret = nextTransactionChunk(fieldIn, force, kil);
        if (!ret.empty())
            return ret;
    }

    return "Field not found: [{" + fieldIn + "}]\n";
}

//---------------------------------------------------------------------------------------------------
bool QKill::setValueByName(const SFString& fieldName, const SFString& fieldValue) {
    // EXISTING_CODE
    // EXISTING_CODE

    if (CTransaction::setValueByName(fieldName, fieldValue))
        return true;

    switch (tolower(fieldName[0])) {
        case '_':
            if ( fieldName % "_to" ) { _to = toAddress(fieldValue); return true; }
            break;
        default:
            break;
    }
    return false;
}

//---------------------------------------------------------------------------------------------------
void QKill::finishParse() {
    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------------------------------
bool QKill::Serialize(SFArchive& archive) {
    if (!archive.isReading())
        return ((const QKill*)this)->SerializeC(archive);

    CTransaction::Serialize(archive);

    archive >> _to;
    finishParse();
    return true;
}

//---------------------------------------------------------------------------------------------------
bool QKill::SerializeC(SFArchive& archive) const {
    CTransaction::SerializeC(archive);

    archive << _to;

    return true;
}

//---------------------------------------------------------------------------
void QKill::registerClass(void) {
    static bool been_here = false;
    if (been_here) return;
    been_here = true;

    CTransaction::registerClass();

    uint32_t fieldNum = 1000;
    ADD_FIELD(QKill, "schema",  T_NUMBER|TS_LABEL, ++fieldNum);
    ADD_FIELD(QKill, "deleted", T_BOOL|TS_LABEL,  ++fieldNum);
    ADD_FIELD(QKill, "_to", T_TEXT, ++fieldNum);

    // Hide our internal fields, user can turn them on if they like
    HIDE_FIELD(QKill, "schema");
    HIDE_FIELD(QKill, "deleted");

    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------
SFString nextKillChunk_custom(const SFString& fieldIn, bool& force, const void *data) {
    const QKill *kil = (const QKill *)data;
    if (kil) {
        switch (tolower(fieldIn[0])) {
            // EXISTING_CODE
            // EXISTING_CODE
            case 'p':
                // Display only the fields of this node, not it's parent type
                if ( fieldIn % "parsed" )
                    return nextBasenodeChunk(fieldIn, force, kil);
                break;

            default:
                break;
        }
    }

    return EMPTY;
}

//---------------------------------------------------------------------------
bool QKill::handleCustomFormat(CExportContext& ctx, const SFString& fmtIn, void *data) const {
    // EXISTING_CODE
    // EXISTING_CODE
    return false;
}

//---------------------------------------------------------------------------
bool QKill::readBackLevel(SFArchive& archive) {
    bool done = false;
    // EXISTING_CODE
    // EXISTING_CODE
    return done;
}

//---------------------------------------------------------------------------
// EXISTING_CODE
// EXISTING_CODE

