#pragma once
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
#include "logentry.h"

//--------------------------------------------------------------------------
class QOwnerAddedEvent;
typedef SFArrayBase<QOwnerAddedEvent>         QOwnerAddedEventArray;
typedef SFList<QOwnerAddedEvent*>             QOwnerAddedEventList;
typedef SFUniqueList<QOwnerAddedEvent*>       QOwnerAddedEventListU;

// EXISTING_CODE
// EXISTING_CODE

//--------------------------------------------------------------------------
class QOwnerAddedEvent : public CLogEntry {
public:
    SFAddress newOwner;

public:
    QOwnerAddedEvent(void);
    QOwnerAddedEvent(const QOwnerAddedEvent& ow);
    ~QOwnerAddedEvent(void);
    QOwnerAddedEvent& operator=(const QOwnerAddedEvent& ow);

    DECLARE_NODE(QOwnerAddedEvent);

    // EXISTING_CODE
    // EXISTING_CODE

protected:
    void Clear(void);
    void Init(void);
    void Copy(const QOwnerAddedEvent& ow);
    bool readBackLevel(SFArchive& archive);

    // EXISTING_CODE
    // EXISTING_CODE
};

//--------------------------------------------------------------------------
inline QOwnerAddedEvent::QOwnerAddedEvent(void) {
    Init();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline QOwnerAddedEvent::QOwnerAddedEvent(const QOwnerAddedEvent& ow) {
    // EXISTING_CODE
    // EXISTING_CODE
    Copy(ow);
}

// EXISTING_CODE
// EXISTING_CODE

//--------------------------------------------------------------------------
inline QOwnerAddedEvent::~QOwnerAddedEvent(void) {
    Clear();
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void QOwnerAddedEvent::Clear(void) {
    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void QOwnerAddedEvent::Init(void) {
    CLogEntry::Init();

//    newOwner = EMPTY;

    // EXISTING_CODE
    // EXISTING_CODE
}

//--------------------------------------------------------------------------
inline void QOwnerAddedEvent::Copy(const QOwnerAddedEvent& ow) {
    Clear();
    CLogEntry::Copy(ow);

    newOwner = ow.newOwner;

    // EXISTING_CODE
    // EXISTING_CODE
    finishParse();
}

//--------------------------------------------------------------------------
inline QOwnerAddedEvent& QOwnerAddedEvent::operator=(const QOwnerAddedEvent& ow) {
    Copy(ow);
    // EXISTING_CODE
    // EXISTING_CODE
    return *this;
}

//---------------------------------------------------------------------------
inline SFString QOwnerAddedEvent::getValueByName(const SFString& fieldName) const {
    // EXISTING_CODE
    // EXISTING_CODE
    return Format("[{"+toUpper(fieldName)+"}]");
}

//---------------------------------------------------------------------------
IMPLEMENT_ARCHIVE_ARRAY(QOwnerAddedEventArray);
IMPLEMENT_ARCHIVE_ARRAY_C(QOwnerAddedEventArray);
IMPLEMENT_ARCHIVE_LIST(QOwnerAddedEventList);

//---------------------------------------------------------------------------
// EXISTING_CODE
// EXISTING_CODE

