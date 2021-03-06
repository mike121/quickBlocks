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
#include "execute.h"
#include "etherlib.h"

//---------------------------------------------------------------------------
IMPLEMENT_NODE(QExecute, CTransaction, curVersion);

//---------------------------------------------------------------------------
static SFString nextExecuteChunk(const SFString& fieldIn, bool& force, const void *data);
static SFString nextExecuteChunk_custom(const SFString& fieldIn, bool& force, const void *data);

//---------------------------------------------------------------------------
void QExecute::Format(CExportContext& ctx, const SFString& fmtIn, void *data) const {
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
        ctx << getNextChunk(fmt, nextExecuteChunk, this);
}

//---------------------------------------------------------------------------
SFString nextExecuteChunk(const SFString& fieldIn, bool& force, const void *data) {
    const QExecute *exe = (const QExecute *)data;
    if (exe) {
        // Give customized code a chance to override first
        SFString ret = nextExecuteChunk_custom(fieldIn, force, data);
        if (!ret.empty())
            return ret;

        switch (tolower(fieldIn[0])) {
            case '_':
                if ( fieldIn % "_to" ) return fromAddress(exe->_to);
                if ( fieldIn % "_value" ) return asStringBN(exe->_value);
                if ( fieldIn % "_data" ) return exe->_data;
                break;
        }

        // EXISTING_CODE
        // EXISTING_CODE

        // Finally, give the parent class a chance
        ret = nextTransactionChunk(fieldIn, force, exe);
        if (!ret.empty())
            return ret;
    }

    return "Field not found: [{" + fieldIn + "}]\n";
}

//---------------------------------------------------------------------------------------------------
bool QExecute::setValueByName(const SFString& fieldName, const SFString& fieldValue) {
    // EXISTING_CODE
    // EXISTING_CODE

    if (CTransaction::setValueByName(fieldName, fieldValue))
        return true;

    switch (tolower(fieldName[0])) {
        case '_':
            if ( fieldName % "_to" ) { _to = toAddress(fieldValue); return true; }
            if ( fieldName % "_value" ) { _value = toUnsigned(fieldValue); return true; }
            if ( fieldName % "_data" ) { _data = toLower(fieldValue); return true; }
            break;
        default:
            break;
    }
    return false;
}

//---------------------------------------------------------------------------------------------------
void QExecute::finishParse() {
    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------------------------------
bool QExecute::Serialize(SFArchive& archive) {
    if (!archive.isReading())
        return ((const QExecute*)this)->SerializeC(archive);

    CTransaction::Serialize(archive);

    archive >> _to;
    archive >> _value;
    archive >> _data;
    finishParse();
    return true;
}

//---------------------------------------------------------------------------------------------------
bool QExecute::SerializeC(SFArchive& archive) const {
    CTransaction::SerializeC(archive);

    archive << _to;
    archive << _value;
    archive << _data;

    return true;
}

//---------------------------------------------------------------------------
void QExecute::registerClass(void) {
    static bool been_here = false;
    if (been_here) return;
    been_here = true;

    CTransaction::registerClass();

    uint32_t fieldNum = 1000;
    ADD_FIELD(QExecute, "schema",  T_NUMBER|TS_LABEL, ++fieldNum);
    ADD_FIELD(QExecute, "deleted", T_BOOL|TS_LABEL,  ++fieldNum);
    ADD_FIELD(QExecute, "_to", T_TEXT, ++fieldNum);
    ADD_FIELD(QExecute, "_value", T_NUMBER, ++fieldNum);
    ADD_FIELD(QExecute, "_data", T_TEXT, ++fieldNum);

    // Hide our internal fields, user can turn them on if they like
    HIDE_FIELD(QExecute, "schema");
    HIDE_FIELD(QExecute, "deleted");

    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------
SFString nextExecuteChunk_custom(const SFString& fieldIn, bool& force, const void *data) {
    const QExecute *exe = (const QExecute *)data;
    if (exe) {
        switch (tolower(fieldIn[0])) {
            // EXISTING_CODE
            // EXISTING_CODE
            case 'p':
                // Display only the fields of this node, not it's parent type
                if ( fieldIn % "parsed" )
                    return nextBasenodeChunk(fieldIn, force, exe);
                break;

            default:
                break;
        }
    }

    return EMPTY;
}

//---------------------------------------------------------------------------
bool QExecute::handleCustomFormat(CExportContext& ctx, const SFString& fmtIn, void *data) const {
    // EXISTING_CODE
    // EXISTING_CODE
    return false;
}

//---------------------------------------------------------------------------
bool QExecute::readBackLevel(SFArchive& archive) {
    bool done = false;
    // EXISTING_CODE
    // EXISTING_CODE
    return done;
}

//---------------------------------------------------------------------------
// EXISTING_CODE
// EXISTING_CODE

