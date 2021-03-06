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
#include "branch.h"
#include "accounttree.h"

namespace qblocks {

//---------------------------------------------------------------------------
IMPLEMENT_NODE(CBranch, CTreeNode, curVersion);

//---------------------------------------------------------------------------
static SFString nextBranchChunk(const SFString& fieldIn, bool& force, const void *data);
static SFString nextBranchChunk_custom(const SFString& fieldIn, bool& force, const void *data);

//---------------------------------------------------------------------------
void CBranch::Format(CExportContext& ctx, const SFString& fmtIn, void *data) const {
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
        ctx << getNextChunk(fmt, nextBranchChunk, this);
}

//---------------------------------------------------------------------------
SFString nextBranchChunk(const SFString& fieldIn, bool& force, const void *data) {
    const CBranch *bra = (const CBranch *)data;
    if (bra) {
        // Give customized code a chance to override first
        SFString ret = nextBranchChunk_custom(fieldIn, force, data);
        if (!ret.empty())
            return ret;

        switch (tolower(fieldIn[0])) {
            case 'm':
            return EMPTY;
//                if ( fieldIn % "m_nodes[16]" ) { expContext().noFrst=true; return bra->m_nodes[16].Format(); }
                if ( fieldIn % "m_branchValue" ) return bra->m_branchValue;
                break;
        }

        // EXISTING_CODE
        // EXISTING_CODE

        // Finally, give the parent class a chance
        ret = nextTreenodeChunk(fieldIn, force, bra);
        if (!ret.empty())
            return ret;
    }

    return "Field not found: [{" + fieldIn + "}]\n";
}

//---------------------------------------------------------------------------------------------------
bool CBranch::setValueByName(const SFString& fieldName, const SFString& fieldValue) {
    // EXISTING_CODE
    // EXISTING_CODE

    if (CTreeNode::setValueByName(fieldName, fieldValue))
        return true;

    switch (tolower(fieldName[0])) {
        case 'm':
            return true;
//            if ( fieldName % "m_nodes[16]" ) { /* m_nodes[16] = fieldValue; */ return false; }
            if ( fieldName % "m_branchValue" ) { m_branchValue = fieldValue; return true; }
            break;
        default:
            break;
    }
    return false;
}

//---------------------------------------------------------------------------------------------------
void CBranch::finishParse() {
    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------------------------------
bool CBranch::Serialize(SFArchive& archive) {
    if (!archive.isReading())
        return ((const CBranch*)this)->SerializeC(archive);

    CTreeNode::Serialize(archive);

//    archive >> m_nodes[16];
    archive >> m_branchValue;
    finishParse();
    return true;
}

//---------------------------------------------------------------------------------------------------
bool CBranch::SerializeC(SFArchive& archive) const {
    CTreeNode::SerializeC(archive);

//    archive << m_nodes[16];
    archive << m_branchValue;

    return true;
}

//---------------------------------------------------------------------------
void CBranch::registerClass(void) {
    static bool been_here = false;
    if (been_here) return;
    been_here = true;

    CTreeNode::registerClass();

    uint32_t fieldNum = 1000;
    ADD_FIELD(CBranch, "schema",  T_NUMBER|TS_LABEL, ++fieldNum);
    ADD_FIELD(CBranch, "deleted", T_BOOL|TS_LABEL,  ++fieldNum);
    ADD_FIELD(CBranch, "m_nodes[16]", T_POINTER, ++fieldNum);
    ADD_FIELD(CBranch, "m_branchValue", T_TEXT, ++fieldNum);

    // Hide our internal fields, user can turn them on if they like
    HIDE_FIELD(CBranch, "schema");
    HIDE_FIELD(CBranch, "deleted");

    // EXISTING_CODE
    // EXISTING_CODE
}

//---------------------------------------------------------------------------
SFString nextBranchChunk_custom(const SFString& fieldIn, bool& force, const void *data) {
    const CBranch *bra = (const CBranch *)data;
    if (bra) {
        switch (tolower(fieldIn[0])) {
            // EXISTING_CODE
            // EXISTING_CODE
            case 'p':
                // Display only the fields of this node, not it's parent type
                if ( fieldIn % "parsed" )
                    return nextBasenodeChunk(fieldIn, force, bra);
                break;

            default:
                break;
        }
    }

    return EMPTY;
}

//---------------------------------------------------------------------------
bool CBranch::handleCustomFormat(CExportContext& ctx, const SFString& fmtIn, void *data) const {
    // EXISTING_CODE
    // EXISTING_CODE
    return false;
}

//---------------------------------------------------------------------------
bool CBranch::readBackLevel(SFArchive& archive) {
    bool done = false;
    // EXISTING_CODE
    // EXISTING_CODE
    return done;
}

//---------------------------------------------------------------------------
// EXISTING_CODE
    //-----------------------------------------------------------------------------
    CBranch::CBranch(const SFString& _value) : m_branchValue(_value) {
        memset(m_nodes, 0, sizeof(CTreeNode*) * 16);
    }

    //-----------------------------------------------------------------------------
    CBranch::CBranch(char _i1, CTreeNode* _n1, const SFString& _value) : m_branchValue(_value) {
        memset(m_nodes, 0, sizeof(CTreeNode*) * 16);
        m_nodes[nodeIndex(_i1)] = _n1;
    }

    //-----------------------------------------------------------------------------
    CBranch::CBranch(char _i1, CTreeNode* _n1, char _i2, CTreeNode* _n2) {
        memset(m_nodes, 0, sizeof(CTreeNode*) * 16);
        m_nodes[nodeIndex(_i1)] = _n1;
        m_nodes[nodeIndex(_i2)] = _n2;
    }

    //-----------------------------------------------------------------------------
    SFString CBranch::at(const SFString& _key) const {
        if (_key.empty())
            return m_branchValue;

        int idx = nodeIndex(_key[0]);
        if (m_nodes[idx])
            return m_nodes[idx]->at(_key.substr(1));

        return "";
    }

    //-----------------------------------------------------------------------------
    CTreeNode* CBranch::insert(const SFString& _key, const SFString& _value) {
        if (verbose == 2) cerr << "\tInserting branch " << _key << "\n";
        if (_key.empty()) {
            // We've reached the end of the key, so store the value here
            if (m_branchValue.empty()) {
                // store the first encountered block
                m_branchValue = _value;

            } else {
                // preserve the most recent block encountered
                m_branchValue = nextTokenClear(m_branchValue, '|');
                m_branchValue += "|" + _value;
            }

        } else {
            // Figure out which bucket to store the value in by the next character in the key
            int idx = nodeIndex(_key[0]);
            if (m_nodes[nodeIndex(_key[0])]) {
                // There is already something stored here, so we need to find room for it
                m_nodes[idx] = m_nodes[idx]->insert(_key.substr(1), _value);

            } else {
                // we've reached a leaf
                m_nodes[idx] = new CLeaf(_key.substr(1), _value);
            }
        }
        return this;
    }

    //-----------------------------------------------------------------------------
    CTreeNode* CBranch::remove(const SFString& _key) {
        if (verbose) {
            cerr << endl<< endl<< endl
            << idnt << SFString('-', 80) << endl
            << idnt << SFString('-', 80) << endl
            << idnt << "remove branch at [" << _key << "]: ";
            idnt+="\t";
        }

        if (_key.empty()) {
            if (m_branchValue.length()) {
                if (verbose)
                    cerr << "and non-empty value " << endl;
                m_branchValue = "";
                return rejig();
            }
            if (verbose)
                cerr << "and empty value" << endl;
            idnt.Replace("\t", "");
            return this;
        }

        int idx = nodeIndex(_key[0]);
        if (m_nodes[idx]) {
            const char *k = (const char*)_key;
            CTreeNode *ret = m_nodes[idx]->remove(&k[1]);
            m_nodes[idx] = ret;
            CTreeNode *n = rejig();
            if (verbose)
                idnt.Replace("\t", "");
            return n;
        }

        if (verbose) {
            cerr << endl;
            idnt.Replace("\t", "");
        }
        return this;
    }

    //-----------------------------------------------------------------------------
#define NO_BRANCHS   ((char)-1)
#define MULTI_BRANCH ((char)16)
    CTreeNode *CBranch::rejig() {
        char n = activeBranch();
        if (n == NO_BRANCHS && m_branchValue.length()) {
            if (verbose)
                cerr << "No branches, but we have a value, so we save it as a leaf" << endl;
            // revert back down to a leaf
            CTreeNode *r = new CLeaf("", m_branchValue);
            delete this;
            return r;

        } else if (n != MULTI_BRANCH && m_branchValue.empty()) {
            if (verbose == 2)
                cerr << idnt << "This single (empty) branch has a single child at [" << idex(n) << "]" << endl;
            // only branching to n...
            int nn = static_cast<int>(n);
            if (auto b = dynamic_cast<CBranch*>(m_nodes[nn])) {
                // switch to infix
                m_nodes[nn] = NULL;
                delete this;
                SFString x = idex(n);
                return new CInfix(x, b);

            } else {
                auto x = m_nodes[nn];
                ASSERT(x);
                // include in child
                x->m_prefix = idex(n) + x->m_prefix;
                m_nodes[nn] = NULL;
                delete this;
                return x;
            }
        }

        return this;
    }

    //-----------------------------------------------------------------------------
    /// @returns (byte)-1 when no active branches, 16 when multiple active and the index of the active branch otherwise.
    char CBranch::activeBranch() const {
        char n = NO_BRANCHS;
        for (int i = 0 ; i < 16 ; i++) {
            if (m_nodes[i]) {
                if (n == NO_BRANCHS)
                    n = static_cast<char>(i);
                else
                    return MULTI_BRANCH;
            }
        }
        return n;
    }

    //------------------------------------------------------------------
    bool CBranch::visitItems(ACCTVISITOR func, void *data) const {
        ASSERT(func);
        CVisitData *vd = reinterpret_cast<CVisitData*>(data);
        uint32_t save = vd->type;
        vd->type = T_BRANCH;
        vd->strs = vd->strs + "+" + m_branchValue;
        (*func)(this, data);
        for (uint32_t i = 0; i < 16; ++i) {
            if (m_nodes[i]) {
                vd->strs = vd->strs + "-" + idex(i);
                m_nodes[i]->visitItems(func, data);
                nextTokenClearReverse(vd->strs, '-');
            }
        }
        nextTokenClearReverse(vd->strs, '+');
        vd->type = save;
        return true;
    }
// EXISTING_CODE
}  // namespace qblocks

