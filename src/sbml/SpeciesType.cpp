/**
 * @file    SpeciesType.cpp
 * @brief   Implementation of SpeciesType and ListOfSpeciesTypes.
 * @author  Ben Bornstein
 *
 * $Id$
 * $HeadURL$
 *
 *<!---------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright 2005-2010 California Institute of Technology.
 * Copyright 2002-2005 California Institute of Technology and
 *                     Japan Science and Technology Corporation.
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 *----------------------------------------------------------------------- -->*/

#include <sbml/xml/XMLNode.h>
#include <sbml/xml/XMLAttributes.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/xml/XMLOutputStream.h>

#include <sbml/SBO.h>
#include <sbml/SBMLVisitor.h>
#include <sbml/SBMLError.h>
#include <sbml/SBMLDocument.h>
#include <sbml/Model.h>
#include <sbml/SpeciesType.h>

/** @cond doxygen-ignored */

using namespace std;

/** @endcond */

LIBSBML_CPP_NAMESPACE_BEGIN

SpeciesType::SpeciesType (unsigned int level, unsigned int version) :
   SBase ( level, version )
 , mId   ( "" )
 , mName ( "" )
{
  if (!hasValidLevelVersionNamespaceCombination())
    throw SBMLConstructorException();
}


SpeciesType::SpeciesType (SBMLNamespaces * sbmlns) :
   SBase ( sbmlns )
 , mId   ( "" )
 , mName ( "" )
{
  if (!hasValidLevelVersionNamespaceCombination())
    throw SBMLConstructorException();
}


/** @cond doxygen-libsbml-internal */

/* constructor for validators */
SpeciesType::SpeciesType() :
  SBase()
{
}

/** @endcond */
                          

/*
 * Destroys this SpeciesType.
 */
SpeciesType::~SpeciesType ()
{
}


/*
 * Copy constructor. Creates a copy of this SpeciesType.
 */
SpeciesType::SpeciesType(const SpeciesType& orig) :
   SBase             ( orig                    )
{
  if (&orig == NULL)
  {
    throw SBMLConstructorException("Null argument to copy constructor");
  }
  else
  {
    mId               = orig.mId;
    mName             = orig.mName;
  }
}


/*
 * Assignment operator
 */
SpeciesType& SpeciesType::operator=(const SpeciesType& rhs)
{
  if (&rhs == NULL)
  {
    throw SBMLConstructorException("Null argument to assignment operator");
  }
  else if(&rhs!=this)
  {
    this->SBase::operator =(rhs);
    mId = rhs.mId;
    mName = rhs.mName;
  }

  return *this;
}


/*
 * Accepts the given SBMLVisitor.
 *
 * @return the result of calling <code>v.visit()</code>, which indicates
 * whether or not the Visitor would like to visit the Model's next
 * SpeciesType (if available).
 */
bool
SpeciesType::accept (SBMLVisitor& v) const
{
  return v.visit(*this);
}


/*
 * @return a (deep) copy of this SpeciesType.
 */
SpeciesType*
SpeciesType::clone () const
{
  return new SpeciesType(*this);
}


/*
 * @return the id of this SBML object.
 */
const string&
SpeciesType::getId () const
{
  return mId;
}


/*
 * @return the name of this SBML object.
 */
const string&
SpeciesType::getName () const
{
  return (getLevel() == 1) ? mId : mName;
}


/*
 * @return true if the id of this SBML object has been set, false
 * otherwise.
 */
bool
SpeciesType::isSetId () const
{
  return (mId.empty() == false);
}


/*
 * @return true if the name of this SBML object has been set, false
 * otherwise.
 */
bool
SpeciesType::isSetName () const
{
  return (getLevel() == 1) ? (mId.empty() == false) : 
                            (mName.empty() == false);
}


/*
 * Sets the id of this SBML object to a copy of sid.
 */
int
SpeciesType::setId (const std::string& sid)
{
  /* since the setId function has been used as an
   * alias for setName we cant require it to only
   * be used on a L2 model
   */
/*  if (getLevel() == 1)
  {
    return LIBSBML_UNEXPECTED_ATTRIBUTE;
  }
*/
  if (&(sid) == NULL)
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else if (!(SyntaxChecker::isValidSBMLSId(sid)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mId = sid;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the name of this SBML object to a copy of name.
 */
int
SpeciesType::setName (const std::string& name)
{
  /* if this is setting an L2 name the type is string
   * whereas if it is setting an L1 name its type is SId
   */
  if (&(name) == NULL)
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else if (getLevel() == 1)
  {
    if (!(SyntaxChecker::isValidSBMLSId(name)))
    {
      return LIBSBML_INVALID_ATTRIBUTE_VALUE;
    }
    else
    {
      mId = name;
      return LIBSBML_OPERATION_SUCCESS;
    }
  }
  else
  {
    mName = name;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the name of this SBML object.
 */
int
SpeciesType::unsetName ()
{
  if (getLevel() == 1) 
  {
    mId.erase();
  }
  else 
  {
    mName.erase();
  }

  if (getLevel() == 1 && mId.empty())
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (mName.empty())
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * @return the SBMLTypeCode_t of this SBML object or SBML_UNKNOWN
 * (default).
 *
 * @see getElementName()
 */
SBMLTypeCode_t
SpeciesType::getTypeCode () const
{
  return SBML_SPECIES_TYPE;
}


/*
 * @return the name of this element ie "speciesType".
 */
const string&
SpeciesType::getElementName () const
{
  static const string name = "speciesType";
  return name;
}


bool 
SpeciesType::hasRequiredAttributes() const
{
  bool allPresent = true;

  /* required attributes for speciesType: id */

  if (!isSetId())
    allPresent = false;

  return allPresent;
}


/** @cond doxygen-libsbml-internal */
/*
 * Subclasses should override this method to read values from the given
 * XMLAttributes set into their specific fields.  Be sure to call your
 * parents implementation of this method as well.
 */
void
SpeciesType::readAttributes (const XMLAttributes& attributes)
{
  SBase::readAttributes(attributes);

  const unsigned int level = getLevel();
  const unsigned int version = getVersion();

  if (level < 2 || (level == 2 && version == 1))
  {
    logError(NotSchemaConformant, getLevel(), getVersion(),
	      "SpeciesType is not a valid component for this level/version.");
    return;
  }

  std::vector<std::string> expectedAttributes;
  expectedAttributes.clear();

  expectedAttributes.push_back("name");
  expectedAttributes.push_back("id");
  expectedAttributes.push_back("metaid");

  if (!(level == 2 && version < 3))
  {
    expectedAttributes.push_back("sboTerm");
  }

  // check that all attributes are expected
  for (int i = 0; i < attributes.getLength(); i++)
  {
    std::vector<std::string>::const_iterator end = expectedAttributes.end();
    std::vector<std::string>::const_iterator begin = expectedAttributes.begin();
    std::string name = attributes.getName(i);
    std::string prefix = attributes.getPrefix(i);
    // only check attributes in the sbml namespace   
    if (prefix.empty() || prefix == "sbml")
    {
      if (std::find(begin, end, name) == end)
      {
        logUnknownAttribute(name, level, version, "<speciesType>");
      }
    }
  }

  //
  // id: SId  { use="required" }  (L2v2->)
  //
  bool assigned = attributes.readInto("id", mId, getErrorLog(), true);
  if (assigned && mId.size() == 0)
  {
    logEmptyString("id", level, version, "<speciesType>");
  }
  if (!SyntaxChecker::isValidSBMLSId(mId)) logError(InvalidIdSyntax);

  //
  // name: string  { use="optional" }  (L2v2->)
  //
  attributes.readInto("name", mName);

  //
  // sboTerm: SBOTerm { use="optional" }  (L2v3->)
  //
  if (!(level == 2 && version < 3))
  {
    mSBOTerm = SBO::readTerm(attributes, this->getErrorLog(), level, version);
  }
}
/** @endcond */


/** @cond doxygen-libsbml-internal */
/*
 * Subclasses should override this method to write their XML attributes
 * to the XMLOutputStream.  Be sure to call your parents implementation
 * of this method as well.
 */
void
SpeciesType::writeAttributes (XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  const unsigned int level = getLevel();
  const unsigned int version = getVersion();

  /* invalid level/version */
  if (level < 2 || (level == 2 && version == 1))
  {
    return;
  }

  //
  // id: SId  { use="required" }  (L2v2 ->)
  //
  stream.writeAttribute("id", mId);

  //
  // name: string  { use="optional" }  (L2v2 ->)
  //
  stream.writeAttribute("name", mName);
  //
  // sboTerm: SBOTerm { use="optional" }  (L2v3 ->)
  //
  if (!(level == 2 && version < 3)) 
  {
    SBO::writeTerm(stream, mSBOTerm);
  }
}
/** @endcond */


/*
 * @return a (deep) copy of this ListOfSpeciesTypes.
 */
ListOfSpeciesTypes*
ListOfSpeciesTypes::clone () const
{
  return new ListOfSpeciesTypes(*this);
}


/*
 * @return the SBMLTypeCode_t of SBML objects contained in this ListOf or
 * SBML_UNKNOWN (default).
 */
SBMLTypeCode_t
ListOfSpeciesTypes::getItemTypeCode () const
{
  return SBML_SPECIES_TYPE;
}


/*
 * @return the name of this element ie "listOfSpeciesTypes".
 */
const string&
ListOfSpeciesTypes::getElementName () const
{
  static const string name = "listOfSpeciesTypes";
  return name;
}


/* return nth item in list */
SpeciesType *
ListOfSpeciesTypes::get(unsigned int n)
{
  return static_cast<SpeciesType*>(ListOf::get(n));
}


/* return nth item in list */
const SpeciesType *
ListOfSpeciesTypes::get(unsigned int n) const
{
  return static_cast<const SpeciesType*>(ListOf::get(n));
}


/**
 * Used by ListOf::get() to lookup an SBase based by its id.
 */
struct IdEqST : public unary_function<SBase*, bool>
{
  const string& id;

  IdEqST (const string& id) : id(id) { }
  bool operator() (SBase* sb) 
       { return static_cast <SpeciesType *> (sb)->getId() == id; }
};


/* return item by id */
SpeciesType*
ListOfSpeciesTypes::get (const std::string& sid)
{
  return const_cast<SpeciesType*>( 
    static_cast<const ListOfSpeciesTypes&>(*this).get(sid) );
}


/* return item by id */
const SpeciesType*
ListOfSpeciesTypes::get (const std::string& sid) const
{
  vector<SBase*>::const_iterator result;

  if (&(sid) == NULL)
  {
    return NULL;
  }
  else
  {
    result = find_if( mItems.begin(), mItems.end(), IdEqST(sid) );
    return (result == mItems.end()) ? NULL : 
                               static_cast <SpeciesType*> (*result);
  }
}


/* Removes the nth item from this list */
SpeciesType*
ListOfSpeciesTypes::remove (unsigned int n)
{
   return static_cast<SpeciesType*>(ListOf::remove(n));
}


/* Removes item in this list by id */
SpeciesType*
ListOfSpeciesTypes::remove (const std::string& sid)
{
  SBase* item = NULL;
  vector<SBase*>::iterator result;

  if (&(sid) != NULL)
  {
    result = find_if( mItems.begin(), mItems.end(), IdEqST(sid) );

    if (result != mItems.end())
    {
      item = *result;
      mItems.erase(result);
    }
  }

  return static_cast <SpeciesType*> (item);
}


/** @cond doxygen-libsbml-internal */
/*
 * @return the ordinal position of the element with respect to its siblings
 * or -1 (default) to indicate the position is not significant.
 */
int
ListOfSpeciesTypes::getElementPosition () const
{
  return 4;
}
/** @endcond */


/** @cond doxygen-libsbml-internal */
/*
 * @return the SBML object corresponding to next XMLToken in the
 * XMLInputStream or NULL if the token was not recognized.
 */
SBase*
ListOfSpeciesTypes::createObject (XMLInputStream& stream)
{
  const string& name   = stream.peek().getName();
  SBase*        object = NULL;


  if (name == "speciesType")
  {
    try
    {
      object = new SpeciesType(getSBMLNamespaces());
    }
    catch (SBMLConstructorException*)
    {
      object = new SpeciesType(SBMLDocument::getDefaultLevel(),
        SBMLDocument::getDefaultVersion());
    }
    catch ( ... )
    {
      object = new SpeciesType(SBMLDocument::getDefaultLevel(),
        SBMLDocument::getDefaultVersion());
    }
    
    if (object != NULL) mItems.push_back(object);
  }

  return object;
}
/** @endcond */



/** @cond doxygen-c-only */

/**
 * Creates a new SpeciesType_t structure using the given SBML @p level
 * and @p version values.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * SpeciesType
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * SpeciesType
 *
 * @return a pointer to the newly created SpeciesType_t structure.
 *
 * @note Once a SpeciesType has been added to an SBMLDocument, the @p
 * level and @p version for the document @em override those used to create
 * the SpeciesType.  Despite this, the ability to supply the values at
 * creation time is an important aid to creating valid SBML.  Knowledge of
 * the intended SBML Level and Version  determine whether it is valid to
 * assign a particular value to an attribute, or whether it is valid to add
 * an object to an existing SBMLDocument.
 */
LIBSBML_EXTERN
SpeciesType_t *
SpeciesType_create (unsigned int level, unsigned int version)
{
  try
  {
    SpeciesType* obj = new SpeciesType(level,version);
    return obj;
  }
  catch (SBMLConstructorException)
  {
    return NULL;
  }
}


/**
 * Creates a new SpeciesType_t structure using the given
 * SBMLNamespaces_t structure.
 *
 * @param sbmlns SBMLNamespaces, a pointer to an SBMLNamespaces structure
 * to assign to this SpeciesType
 *
 * @return a pointer to the newly created SpeciesType_t structure.
 *
 * @note Once a SpeciesType has been added to an SBMLDocument, the
 * @p sbmlns namespaces for the document @em override those used to create
 * the SpeciesType. Despite this, the ability to supply the values at creation 
 * time is an important aid to creating valid SBML.  Knowledge of the intended 
 * SBML Level and Version determine whether it is valid to assign a particular 
 * value to an attribute, or whether it is valid to add an object to an existing
 * SBMLDocument.
 */
LIBSBML_EXTERN
SpeciesType_t *
SpeciesType_createWithNS (SBMLNamespaces_t* sbmlns)
{
  try
  {
    SpeciesType* obj = new SpeciesType(sbmlns);
    return obj;
  }
  catch (SBMLConstructorException)
  {
    return NULL;
  }
}


/**
 * Frees the given SpeciesType_t structure.
 *
 * @param ct the SpeciesType_t structure to be freed.
 */
LIBSBML_EXTERN
void
SpeciesType_free (SpeciesType_t *st)
{
  delete st;
}


/**
 * Creates a deep copy of the given SpeciesType_t structure
 * 
 * @param ct the SpeciesType_t structure to be copied
 * 
 * @return a (deep) copy of this SpeciesType_t structure.
 */
LIBSBML_EXTERN
SpeciesType_t *
SpeciesType_clone (const SpeciesType_t *st)
{
  return (st != NULL) ? static_cast<SpeciesType*>( st->clone() ) : NULL;
}


/**
 * Returns a list of XMLNamespaces_t associated with this SpeciesType_t
 * structure.
 *
 * @param st the SpeciesType_t structure
 * 
 * @return pointer to the XMLNamespaces_t structure associated with 
 * this SBML object
 */
LIBSBML_EXTERN
const XMLNamespaces_t *
SpeciesType_getNamespaces(SpeciesType_t *st)
{
  return (st != NULL) ? st->getNamespaces() : NULL;
}


/**
 * Takes a SpeciesType_t structure and returns its identifier.
 *
 * @param ct the SpeciesType_t structure whose identifier is sought
 * 
 * @return the identifier of this SpeciesType_t, as a pointer to a string.
 */
LIBSBML_EXTERN
const char *
SpeciesType_getId (const SpeciesType_t *st)
{
  return (st != NULL && st->isSetId()) ? st->getId().c_str() : NULL;
}


/**
 * Takes a SpeciesType_t structure and returns its name.
 *
 * @param ct the SpeciesType_t whose name is sought.
 *
 * @return the name of this SpeciesType_t, as a pointer to a string.
 */
LIBSBML_EXTERN
const char *
SpeciesType_getName (const SpeciesType_t *st)
{
  return (st != NULL && st->isSetName()) ? st->getName().c_str() : NULL;
}


/**
 * Predicate returning @c true or @c false depending on whether the given
 * SpeciesType_t structure's identifier has been set.
 *
 * @param ct the SpeciesType_t structure to query
 * 
 * @return @c non-zero (true) if the "id" field of the given
 * SpeciesType has been set, zero (false) otherwise.
 */
LIBSBML_EXTERN
int
SpeciesType_isSetId (const SpeciesType_t *st)
{
  return (st != NULL) ? static_cast<int>( st->isSetId() ) : 0;
}


/**
 * Predicate returning @c true or @c false depending on whether the given
 * SpeciesType_t structure's name has been set.
 *
 * @param ct the SpeciesType_t structure to query
 * 
 * @return @c non-zero (true) if the "name" field of the given
 * SpeciesType has been set, zero (false) otherwise.
 */
LIBSBML_EXTERN
int
SpeciesType_isSetName (const SpeciesType_t *st)
{
  return (st != NULL) ? static_cast<int>( st->isSetName() ) : 0;
}


/**
 * Assigns the identifier of a SpeciesType_t structure.
 *
 * This makes a copy of the string passed as the argument @p sid.
 *
 * @param ct the SpeciesType_t structure to set.
 * @param sid the string to use as the identifier.
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSBML_OPERATION_SUCCESS
 * @li LIBSBML_INVALID_ATTRIBUTE_VALUE
 *
 * @note Using this function with an id of NULL is equivalent to
 * unsetting the "id" attribute.
 */
LIBSBML_EXTERN
int
SpeciesType_setId (SpeciesType_t *st, const char *sid)
{
  if (st != NULL)
    return (sid == NULL) ? st->setId("") : st->setId(sid);
  else
    return LIBSBML_INVALID_OBJECT;
}


/**
 * Assign the name of a SpeciesType_t structure.
 *
 * This makes a copy of the string passed as the argument @p name.
 *
 * @param ct the SpeciesType_t structure to set.
 * @param name the string to use as the name.
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSBML_OPERATION_SUCCESS
 * @li LIBSBML_INVALID_ATTRIBUTE_VALUE
 *
 * @note Using this function with the name set to NULL is equivalent to
 * unsetting the "name" attribute.
 */
LIBSBML_EXTERN
int
SpeciesType_setName (SpeciesType_t *st, const char *name)
{
  if (st != NULL)
    return (name == NULL) ? st->unsetName() : st->setName(name);
  else
    return LIBSBML_INVALID_OBJECT;
}


/**
 * Unsets the name of a SpeciesType.
 * 
 * @param ct the SpeciesType_t structure whose name is to be unset.
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSBML_OPERATION_SUCCESS
 * @li LIBSBML_OPERATION_FAILED
 */
LIBSBML_EXTERN
int
SpeciesType_unsetName (SpeciesType_t *st)
{
  return (st != NULL) ? st->unsetName() : LIBSBML_INVALID_OBJECT;
}



/**
 * @return item in this ListOfSpeciesType with the given id or NULL if no such
 * item exists.
 */
LIBSBML_EXTERN
SpeciesType_t *
ListOfSpeciesTypes_getById (ListOf_t *lo, const char *sid)
{
  if (lo != NULL)
    return (sid != NULL) ? 
      static_cast <ListOfSpeciesTypes *> (lo)->get(sid) : NULL;
  else
    return NULL;
}


/**
 * Removes item in this ListOf items with the given id or NULL if no such
 * item exists.  The caller owns the returned item and is responsible for
 * deleting it.
 */
LIBSBML_EXTERN
SpeciesType_t *
ListOfSpeciesTypes_removeById (ListOf_t *lo, const char *sid)
{
  if (lo != NULL)
    return (sid != NULL) ? 
      static_cast <ListOfSpeciesTypes *> (lo)->remove(sid) : NULL;
  else
    return NULL;
}


/** @endcond */

LIBSBML_CPP_NAMESPACE_END
