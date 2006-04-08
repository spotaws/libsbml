/**
 * \file    InitialAssignment.cpp
 * \brief   SBML InitialAssignment
 * \author  Ben Bornstein
 *
 * $Id$
 * $Source$
 */
/* Copyright 2006 California Institute of Technology and Japan Science and
 * Technology Corporation.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is
 * provided in the file named "LICENSE.txt" included with this software
 * distribution.  It is also available online at
 * http://sbml.org/software/libsbml/license.html
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 */


#include <sbml/xml/XMLAttributes.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/xml/XMLOutputStream.h>

#include <sbml/math/MathML.h>
#include <sbml/math/ASTNode.h>

#include "SBML.h"
#include "SBMLVisitor.h"
#include "InitialAssignment.h"


using namespace std;


/**
 * Creates a new InitialAssignment, optionally with its symbol attributes
 * set.
 */
InitialAssignment::InitialAssignment (const string& symbol) :
   SBase   ( symbol )
 , mMath   ( 0      )
 , mSBOTerm( -1     )
{
}


/**
 * Copies this InitialAssignment.
 */
InitialAssignment::InitialAssignment (const InitialAssignment& rhs) :
   SBase   ( rhs )
 , mMath   ( 0   )
 , mSBOTerm( rhs.mSBOTerm )
{
  if (rhs.mMath) mMath = rhs.mMath->deepCopy();
}


/**
 * Destroys this InitialAssignment.
 */
InitialAssignment::~InitialAssignment ()
{
}


/**
 * Accepts the given SBMLVisitor.
 *
 * @return the result of calling <code>v.visit()</code>, which indicates
 * whether or not the Visitor would like to visit the Model's next
 * InitialAssignment (if available).
 */
bool
InitialAssignment::accept (SBMLVisitor& v) const
{
  return v.visit(*this);
}


/**
 * @return a (deep) copy of this InitialAssignment.
 */
SBase*
InitialAssignment::clone () const
{
  return new InitialAssignment(*this);
}


/**
 * @return the symbol for this InitialAssignment.
 */
const string&
InitialAssignment::getSymbol () const
{
  return getId();
}


/**
 * @return the math for this InitialAssignment.
 */
const ASTNode*
InitialAssignment::getMath () const
{
  return mMath;
}


/**
 * @return the sboTerm of this InitialAssignment as an integer.  If not
 * set, sboTerm will be -1.  Use SBML::sboTermToString() to convert the
 * sboTerm to a zero-padded, seven digit string.
 */
int
InitialAssignment::getSBOTerm () const
{
  return mSBOTerm;
}


/**
 * @return tru if the symbol of this InitialAssignment has been set,
 * false otherwise.
 */
bool
InitialAssignment::isSetSymbol () const
{
  return isSetId();
}


/**
 * @return true if the math for this InitialAssignment has been set,
 * false otherwise.
 */
bool
InitialAssignment::isSetMath () const
{
  return (mMath != 0);
}


/**
 * @return true if the sboTerm of this InitialAssignment has been set,
 * false otherwise.
 */
bool
InitialAssignment::isSetSBOTerm () const
{
  return (mSBOTerm != -1);
}


/**
 * Sets the symbol of this InitialAssignment to a copy of sid.
 */
void
InitialAssignment::setSymbol (const string& sid)
{
  setId(sid);
}


/**
 * Sets the math of this InitialAssignment to a copy of the given
 * ASTNode.
 */
void
InitialAssignment::setMath (const ASTNode* math)
{
  if (mMath == math) return;


  delete mMath;
  mMath = (math != 0) ? math->deepCopy() : 0;
}


/**
 * Sets the sboTerm field of this InitialAssignment to value.
 */
void
InitialAssignment::setSBOTerm (int sboTerm)
{
  mSBOTerm = sboTerm;
}


/**
 * Unsets the sboTerm of this InitialAssignment.
 */
void
InitialAssignment::unsetSBOTerm ()
{
  mSBOTerm = -1;
}


/**
 * @return the SBMLTypeCode_t of this SBML object or SBML_UNKNOWN
 * (default).
 *
 * @see getElementName()
 */
SBMLTypeCode_t
InitialAssignment::getTypeCode () const
{
  return SBML_INITIAL_ASSIGNMENT;
}


/**
 * Subclasses should override this method to return XML element name of
 * this SBML object.
 */
const string&
InitialAssignment::getElementName () const
{
  static const string name = "initialAssignment";
  return name;
}


/**
 * Subclasses should override this method to read (and store) XHTML,
 * MathML, etc. directly from the XMLInputStream.
 *
 * @return true if the subclass read from the stream, false otherwise.
 */
bool
InitialAssignment::readOtherXML (XMLInputStream& stream)
{
  bool          read = false;
  const string& name = stream.peek().getName();


  if (name == "math")
  {
    delete mMath;
    mMath = readMathML(stream);
    read  = true;
  }

  return read;
}


/**
 * Subclasses should override this method to read values from the given
 * XMLAttributes set into their specific fields.  Be sure to call your
 * parents implementation of this method as well.
 */
void
InitialAssignment::readAttributes (const XMLAttributes& attributes)
{
  SBase::readAttributes(attributes);

  //
  // symbol: SId  { use="required" }  (L2v2)
  //
  attributes.readInto("symbol", mId);

  //
  // sboTerm: SBOTerm { use="optional" }  (L2v2)
  //
  mSBOTerm = SBML::readSBOTerm(attributes);
}


/**
 * Subclasses should override this method to write their XML attributes
 * to the XMLOutputStream.  Be sure to call your parents implementation
 * of this method as well.
 */
void
InitialAssignment::writeAttributes (XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  //
  // symbol: SId  { use="required" }  (L2v2)
  //
  stream.writeAttribute("symbol", mId);

  //
  // sboTerm: SBOTerm { use="optional" }  (L2v2)
  //
  SBML::writeSBOTerm(stream, mSBOTerm);
}


/**
 * Subclasses should override this method to write out their contained
 * SBML objects as XML elements.  Be sure to call your parents
 * implementation of this method as well.
 */
void
InitialAssignment::writeElements (XMLOutputStream& stream) const
{
  if (mMath) writeMathML(mMath, stream);
}



/**
 * @return a (deep) copy of this ListOfInitialAssignments.
 */
SBase*
ListOfInitialAssignments::clone () const
{
  return new ListOfInitialAssignments(*this);
}


/**
 * @return the SBMLTypeCode_t of SBML objects contained in this ListOf or
 * SBML_UNKNOWN (default).
 */
SBMLTypeCode_t
ListOfInitialAssignments::getItemTypeCode () const
{
  return SBML_INITIAL_ASSIGNMENT;
}


/**
 * Subclasses should override this method to return XML element name of
 * this SBML object.
 */
const string&
ListOfInitialAssignments::getElementName () const
{
  static const string name = "listOfInitialAssignments";
  return name;
}


/**
 * @return the SBML object corresponding to next XMLToken in the
 * XMLInputStream or NULL if the token was not recognized.
 */
SBase*
ListOfInitialAssignments::createObject (XMLInputStream& stream)
{
  const string& name   = stream.peek().getName();
  SBase*        object = 0;


  if (name == "initialAssignment")
  {
    object = new InitialAssignment();
    mItems.push_back(object);
  }

  return object;
}




/**
 * Creates a new InitialAssignment and returns a pointer to it.
 */
LIBSBML_EXTERN
InitialAssignment_t *
InitialAssignment_create ()
{
  return new(nothrow) InitialAssignment;
}


/**
 * Creates a new InitialAssignment, optionally with its symbol attributes
 * set.
 */
LIBSBML_EXTERN
InitialAssignment_t *
InitialAssignment_createWith (const char *symbol)
{
  return new(nothrow) InitialAssignment(symbol ? symbol : "");
}


/**
 * Frees the given InitialAssignment.
 */
LIBSBML_EXTERN
void
InitialAssignment_free (InitialAssignment_t *ia)
{
  delete ia;
}


/**
 * @return a (deep) copy of the given InitialAssignment.
 */
LIBSBML_EXTERN
InitialAssignment_t *
InitialAssignment_clone (const InitialAssignment_t *ia)
{
  return static_cast<InitialAssignment*>( ia->clone() );
}


/**
 * @return the symbol for this InitialAssignment
 */
LIBSBML_EXTERN
const char *
InitialAssignment_getSymbol (const InitialAssignment_t *ia)
{
  return ia->isSetSymbol() ? ia->getSymbol().c_str() : NULL;
}


/**
 * @return the math for this InitialAssignment.
 */
LIBSBML_EXTERN
const ASTNode_t *
InitialAssignment_getMath (const InitialAssignment_t *ia)
{
  return ia->getMath();
}


/**
 * @return the sboTerm of this InitialAssignment as an integer.  If not
 * set, sboTerm will be -1.  Use SBML_sboTermToString() to convert the
 * sboTerm to a zero-padded, seven digit string.
 */
LIBSBML_EXTERN
int
InitialAssignment_getSBOTerm (const InitialAssignment_t *ia)
{
  return ia->getSBOTerm();
}


/**
 * @return true (non-zero) if the symbol of this InitialAssignment has been
 * set, false (0) otherwise.
 */
LIBSBML_EXTERN
int
InitialAssignment_isSetSymbol (const InitialAssignment_t *ia)
{
  return static_cast<int>( ia->isSetSymbol() );
}


/**
 * @return true (non-zero) if the math of this InitialAssignment has been
 * set, false (0) otherwise.
 */
LIBSBML_EXTERN
int
InitialAssignment_isSetMath (const InitialAssignment_t *ia)
{
  return static_cast<int>( ia->isSetMath() );
}


/**
 * @return true (non-zero) if the sboTerm of this InitialAssignment has
 * been set, false (0) otherwise.
 */
LIBSBML_EXTERN
int
InitialAssignment_isSetSBOTerm (const InitialAssignment_t *ia)
{
  return static_cast<int>( ia->isSetSBOTerm() );
}


/**
 * Sets the symbol of this InitialAssignment to a copy of sid.
 */
LIBSBML_EXTERN
void
InitialAssignment_setSymbol (InitialAssignment_t *ia, const char *sid)
{
  ia->setSymbol(sid ? sid : "");
}


/**
 * Sets the math of this InitialAssignment to a copy of the given
 * ASTNode.
 */
LIBSBML_EXTERN
void
InitialAssignment_setMath (InitialAssignment_t *ia, const ASTNode_t *math)
{
  ia->setMath(math);
}


/**
 * Sets the sboTerm field of this InitialAssignment to value.
 */
LIBSBML_EXTERN
void
InitialAssignment_setSBOTerm (InitialAssignment_t *ia, int sboTerm)
{
  ia->setSBOTerm(sboTerm);
}


/**
 * Unsets the sboTerm of this InitialAssignment.
 */
LIBSBML_EXTERN
void
InitialAssignment_unsetSBOTerm (InitialAssignment_t *ia)
{
  ia->unsetSBOTerm();
}
