/**
 * @file:   QualitativeSpecies.cpp
 * @brief:  Implementation of the QualitativeSpecies class
 * @author: Generated by autocreate code
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2009-2013 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
 *
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *
 * Copyright (C) 2002-2005 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */


#include <sbml/packages/qual/sbml/QualitativeSpecies.h>
#include <sbml/packages/qual/validator/QualSBMLError.h>


using namespace std;


LIBSBML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new QualitativeSpecies with the given level, version, and package version.
 */
QualitativeSpecies::QualitativeSpecies (unsigned int level, unsigned int version, unsigned int pkgVersion)
  : SBase(level, version)
   ,mId ("")
   ,mCompartment ("")
   ,mConstant (false)
   ,mIsSetConstant (false)
   ,mName ("")
   ,mInitialLevel (SBML_INT_MAX)
   ,mIsSetInitialLevel (false)
   ,mMaxLevel (SBML_INT_MAX)
   ,mIsSetMaxLevel (false)
{
  // set an SBMLNamespaces derived object of this package
  setSBMLNamespacesAndOwn(new QualPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new QualitativeSpecies with the given QualPkgNamespaces object.
 */
QualitativeSpecies::QualitativeSpecies (QualPkgNamespaces* qualns)
  : SBase(qualns)
   ,mId ("")
   ,mCompartment ("")
   ,mConstant (false)
   ,mIsSetConstant (false)
   ,mName ("")
   ,mInitialLevel (SBML_INT_MAX)
   ,mIsSetInitialLevel (false)
   ,mMaxLevel (SBML_INT_MAX)
   ,mIsSetMaxLevel (false)
{
  // set the element namespace of this object
  setElementNamespace(qualns->getURI());

  // load package extensions bound with this object (if any) 
  loadPlugins(qualns);
}


/*
 * Copy constructor for QualitativeSpecies.
 */
QualitativeSpecies::QualitativeSpecies (const QualitativeSpecies& orig)
  : SBase(orig)
{
  if (&orig == NULL)
  {
    throw SBMLConstructorException("Null argument to copy constructor");
  }
  else
  {
    mId  = orig.mId;
    mCompartment  = orig.mCompartment;
    mConstant  = orig.mConstant;
    mIsSetConstant  = orig.mIsSetConstant;
    mName  = orig.mName;
    mInitialLevel  = orig.mInitialLevel;
    mIsSetInitialLevel  = orig.mIsSetInitialLevel;
    mMaxLevel  = orig.mMaxLevel;
    mIsSetMaxLevel  = orig.mIsSetMaxLevel;
  }
}


/*
 * Assignment for QualitativeSpecies.
 */
QualitativeSpecies&
QualitativeSpecies::operator=(const QualitativeSpecies& rhs)
{
  if (&rhs == NULL)
  {
    throw SBMLConstructorException("Null argument to assignment");
  }
  else if (&rhs != this)
  {
    SBase::operator=(rhs);
    mId  = rhs.mId;
    mCompartment  = rhs.mCompartment;
    mConstant  = rhs.mConstant;
    mIsSetConstant  = rhs.mIsSetConstant;
    mName  = rhs.mName;
    mInitialLevel  = rhs.mInitialLevel;
    mIsSetInitialLevel  = rhs.mIsSetInitialLevel;
    mMaxLevel  = rhs.mMaxLevel;
    mIsSetMaxLevel  = rhs.mIsSetMaxLevel;
  }
  return *this;
}


/*
 * Clone for QualitativeSpecies.
 */
QualitativeSpecies*
QualitativeSpecies::clone () const
{
  return new QualitativeSpecies(*this);
}


/*
 * Destructor for QualitativeSpecies.
 */
QualitativeSpecies::~QualitativeSpecies ()
{
}


/*
 * Returns the value of the "id" attribute of this QualitativeSpecies.
 */
const std::string&
QualitativeSpecies::getId() const
{
  return mId;
}


/*
 * Returns the value of the "compartment" attribute of this QualitativeSpecies.
 */
const std::string&
QualitativeSpecies::getCompartment() const
{
  return mCompartment;
}


/*
 * Returns the value of the "constant" attribute of this QualitativeSpecies.
 */
const bool
QualitativeSpecies::getConstant() const
{
  return mConstant;
}


/*
 * Returns the value of the "name" attribute of this QualitativeSpecies.
 */
const std::string&
QualitativeSpecies::getName() const
{
  return mName;
}


/*
 * Returns the value of the "initialLevel" attribute of this QualitativeSpecies.
 */
const int
QualitativeSpecies::getInitialLevel() const
{
  return mInitialLevel;
}


/*
 * Returns the value of the "maxLevel" attribute of this QualitativeSpecies.
 */
const int
QualitativeSpecies::getMaxLevel() const
{
  return mMaxLevel;
}


/*
 * Returns true/false if id is set.
 */
bool
QualitativeSpecies::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Returns true/false if compartment is set.
 */
bool
QualitativeSpecies::isSetCompartment() const
{
  return (mCompartment.empty() == false);
}


/*
 * Returns true/false if constant is set.
 */
bool
QualitativeSpecies::isSetConstant() const
{
  return mIsSetConstant;
}


/*
 * Returns true/false if name is set.
 */
bool
QualitativeSpecies::isSetName() const
{
  return (mName.empty() == false);
}


/*
 * Returns true/false if initialLevel is set.
 */
bool
QualitativeSpecies::isSetInitialLevel() const
{
  return mIsSetInitialLevel;
}


/*
 * Returns true/false if maxLevel is set.
 */
bool
QualitativeSpecies::isSetMaxLevel() const
{
  return mIsSetMaxLevel;
}


/*
 * Sets id and returns value indicating success.
 */
int
QualitativeSpecies::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets compartment and returns value indicating success.
 */
int
QualitativeSpecies::setCompartment(const std::string& compartment)
{
  if (&(compartment) == NULL)
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else if (!(SyntaxChecker::isValidInternalSId(compartment)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mCompartment = compartment;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets constant and returns value indicating success.
 */
int
QualitativeSpecies::setConstant(bool constant)
{
  mConstant = constant;
  mIsSetConstant = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets name and returns value indicating success.
 */
int
QualitativeSpecies::setName(const std::string& name)
{
  if (&(name) == NULL)
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mName = name;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets initialLevel and returns value indicating success.
 */
int
QualitativeSpecies::setInitialLevel(int initialLevel)
{
  mInitialLevel = initialLevel;
  mIsSetInitialLevel = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets maxLevel and returns value indicating success.
 */
int
QualitativeSpecies::setMaxLevel(int maxLevel)
{
  mMaxLevel = maxLevel;
  mIsSetMaxLevel = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets id and returns value indicating success.
 */
int
QualitativeSpecies::unsetId()
{
  mId.erase();

  if (mId.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets compartment and returns value indicating success.
 */
int
QualitativeSpecies::unsetCompartment()
{
  mCompartment.erase();

  if (mCompartment.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets constant and returns value indicating success.
 */
int
QualitativeSpecies::unsetConstant()
{
  mConstant = false;
  mIsSetConstant = false;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets name and returns value indicating success.
 */
int
QualitativeSpecies::unsetName()
{
  mName.erase();

  if (mName.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets initialLevel and returns value indicating success.
 */
int
QualitativeSpecies::unsetInitialLevel()
{
  mInitialLevel = SBML_INT_MAX;
  mIsSetInitialLevel = false;

  if (isSetInitialLevel() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets maxLevel and returns value indicating success.
 */
int
QualitativeSpecies::unsetMaxLevel()
{
  mMaxLevel = SBML_INT_MAX;
  mIsSetMaxLevel = false;

  if (isSetMaxLevel() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * rename attributes that are SIdRefs or instances in math
 */
void
QualitativeSpecies::renameSIdRefs(const std::string& oldid, const std::string& newid)
{
  if (isSetCompartment() == true && mCompartment == oldid)
  {
    setCompartment(newid);
  }

}


/*
 * Returns the XML element name of this object
 */
const std::string&
QualitativeSpecies::getElementName () const
{
  static const string name = "qualitativeSpecies";
  return name;
}


/*
 * Returns the libSBML type code for this SBML object.
 */
int
QualitativeSpecies::getTypeCode () const
{
  return SBML_QUAL_QUALITATIVE_SPECIES;
}


/*
 * check if all the required attributes are set
 */
bool
QualitativeSpecies::hasRequiredAttributes () const
{
  bool allPresent = true;

  if (isSetId() == false)
    allPresent = false;

  if (isSetCompartment() == false)
    allPresent = false;

  if (isSetConstant() == false)
    allPresent = false;

  return allPresent;
}


  /** @cond doxygenLibsbmlInternal */

/*
 * write contained elements
 */
void
QualitativeSpecies::writeElements (XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  SBase::writeExtensionElements(stream);
}


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor.
 */
bool
QualitativeSpecies::accept (SBMLVisitor& v) const
{
  return v.visit(*this);
}


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument.
 */
void
QualitativeSpecies::setSBMLDocument (SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * Enables/Disables the given package with this element.
 */
void
QualitativeSpecies::enablePackageInternal(const std::string& pkgURI,
             const std::string& pkgPrefix, bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * Get the list of expected attributes for this element.
 */
void
QualitativeSpecies::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("id");
  attributes.add("compartment");
  attributes.add("constant");
  attributes.add("name");
  attributes.add("initialLevel");
  attributes.add("maxLevel");
}


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
QualitativeSpecies::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
  const unsigned int sbmlLevel   = getLevel  ();
  const unsigned int sbmlVersion = getVersion();

  unsigned int numErrs;

  /* look to see whether an unknown attribute error was logged
   * during the read of the listOfQualitativeSpeciess - which will have
   * happened immediately prior to this read
   */

  if (getErrorLog() != NULL && 
    static_cast<ListOfQualitativeSpecies*>(getParentSBMLObject())->size() < 2)
  {
    numErrs = getErrorLog()->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)      
    {
      if (getErrorLog()->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = 
          getErrorLog()->getError(n)->getMessage();
        getErrorLog()->remove(UnknownPackageAttribute);
        getErrorLog()->logPackageError("qual", QualLOQualSpeciesAllowedAttributes,
          getPackageVersion(), sbmlLevel, sbmlVersion, details);
      } 
      else if (getErrorLog()->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = 
          getErrorLog()->getError(n)->getMessage();
        getErrorLog()->remove(UnknownCoreAttribute);
        getErrorLog()->logPackageError("qual", QualLOQualSpeciesAllowedAttributes,
          getPackageVersion(), sbmlLevel, sbmlVersion, details);
      } 
    }
  }
  SBase::readAttributes(attributes, expectedAttributes);

  // look to see whether an unknown attribute error was logged
  if (getErrorLog() != NULL)
  {
    numErrs = getErrorLog()->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (getErrorLog()->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details =
                          getErrorLog()->getError(n)->getMessage();
        getErrorLog()->remove(UnknownPackageAttribute);
        getErrorLog()->logPackageError("qual", QualQualSpeciesAllowedAttributes,
                       getPackageVersion(), sbmlLevel, sbmlVersion, details);
      }
      else if (getErrorLog()->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details =
                          getErrorLog()->getError(n)->getMessage();
        getErrorLog()->remove(UnknownCoreAttribute);
        getErrorLog()->logPackageError("qual", QualQualSpeciesAllowedCoreAttributes,
                       getPackageVersion(), sbmlLevel, sbmlVersion, details);
      }
    }
  }

  bool assigned = false;

  //
  // id SId  ( use = "required" )
  //
  assigned = attributes.readInto("id", mId);

   if (assigned == true)
  {
    // check string is not empty and correct syntax

    if (mId.empty() == true)
    {
      logEmptyString(mId, getLevel(), getVersion(), "<QualitativeSpecies>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      logError(InvalidIdSyntax);
    }
  }
  else
  {
    std::string message = "Qual attribute 'id' is missing.";
    getErrorLog()->logPackageError("qual", QualQualSpeciesAllowedAttributes,
                   getPackageVersion(), sbmlLevel, sbmlVersion, message);
  }

  //
  // compartment SIdRef   ( use = "required" )
  //
  assigned = attributes.readInto("compartment", mCompartment);

  if (assigned == true)
  {
    // check string is not empty and correct syntax

    if (mCompartment.empty() == true)
    {
      logEmptyString(mCompartment, getLevel(), getVersion(), "<QualitativeSpecies>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mCompartment) == false)
    {
      logError(InvalidIdSyntax, getLevel(), getVersion(), 
        "The syntax of the attribute compartment='" + mCompartment + "' does not conform.");
    }
  }
  else
  {
    std::string message = "Qual attribute 'compartment' is missing.";
    getErrorLog()->logPackageError("qual", QualQualSpeciesAllowedAttributes,
                   getPackageVersion(), sbmlLevel, sbmlVersion, message);
  }

  //
  // constant bool   ( use = "required" )
  //
  numErrs = getErrorLog()->getNumErrors();
  mIsSetConstant = attributes.readInto("constant", mConstant);

  if (mIsSetConstant == false)
  {
    if (getErrorLog() != NULL)
    {
      if (getErrorLog()->getNumErrors() == numErrs + 1 &&
              getErrorLog()->contains(XMLAttributeTypeMismatch))
      {
        getErrorLog()->remove(XMLAttributeTypeMismatch);
        getErrorLog()->logPackageError("qual", QualConstantMustBeBool,
                     getPackageVersion(), sbmlLevel, sbmlVersion);
      }
      else
      {
      std::string message = "Qual attribute 'constant' is missing.";
      getErrorLog()->logPackageError("qual", QualQualSpeciesAllowedAttributes,
                     getPackageVersion(), sbmlLevel, sbmlVersion, message);
      }
    }
  }
  

  //
  // name string   ( use = "optional" )
  //
  assigned = attributes.readInto("name", mName);

  if (assigned == true)
  {
    // check string is not empty

    if (mName.empty() == true)
    {
      logEmptyString(mName, getLevel(), getVersion(), "<QualitativeSpecies>");
    }
  }

  //
  // initialLevel int   ( use = "optional" )
  //
  numErrs = getErrorLog()->getNumErrors();
  mIsSetInitialLevel = attributes.readInto("initialLevel", mInitialLevel);

  if (mIsSetInitialLevel == false)
  {
    if (getErrorLog() != NULL)
    {
      if (getErrorLog()->getNumErrors() == numErrs + 1 &&
              getErrorLog()->contains(XMLAttributeTypeMismatch))
      {
        getErrorLog()->remove(XMLAttributeTypeMismatch);
        getErrorLog()->logPackageError("qual", QualInitialLevelMustBeInt,
                     getPackageVersion(), sbmlLevel, sbmlVersion);
      }
    }
  }
  else
  {
    if (mInitialLevel < 0)
    {
      getErrorLog()->logPackageError("qual", QualInitalLevelNotNegative,
                   getPackageVersion(), sbmlLevel, sbmlVersion);
    }
  }

  //
  // maxLevel int   ( use = "optional" )
  //
  numErrs = getErrorLog()->getNumErrors();
  mIsSetMaxLevel = attributes.readInto("maxLevel", mMaxLevel);

  if (mIsSetMaxLevel == false)
  {
    if (getErrorLog() != NULL)
    {
      if (getErrorLog()->getNumErrors() == numErrs + 1 &&
              getErrorLog()->contains(XMLAttributeTypeMismatch))
      {
        getErrorLog()->remove(XMLAttributeTypeMismatch);
        getErrorLog()->logPackageError("qual", QualMaxLevelMustBeInt,
                     getPackageVersion(), sbmlLevel, sbmlVersion);
      }
    }
  }
  else
  {
    if (mMaxLevel < 0)
    {
      getErrorLog()->logPackageError("qual", QualMaxLevelNotNegative,
                   getPackageVersion(), sbmlLevel, sbmlVersion);
    }
  }
}


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * Write values of XMLAttributes to the output stream.
 */
  void
QualitativeSpecies::writeAttributes (XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  if (isSetId() == true)
    stream.writeAttribute("id", getPrefix(), mId);

  if (isSetCompartment() == true)
    stream.writeAttribute("compartment", getPrefix(), mCompartment);

  if (isSetConstant() == true)
    stream.writeAttribute("constant", getPrefix(), mConstant);

  if (isSetName() == true)
    stream.writeAttribute("name", getPrefix(), mName);

  if (isSetInitialLevel() == true)
    stream.writeAttribute("initialLevel", getPrefix(), mInitialLevel);

  if (isSetMaxLevel() == true)
    stream.writeAttribute("maxLevel", getPrefix(), mMaxLevel);

  SBase::writeExtensionAttributes(stream);

}


  /** @endcond */


/*
 * Constructor 
 */
ListOfQualitativeSpecies::ListOfQualitativeSpecies(unsigned int level, 
                                                   unsigned int version, 
                                                   unsigned int pkgVersion)
 : ListOf(level, version)
{
  setSBMLNamespacesAndOwn(new QualPkgNamespaces(level, version, pkgVersion)); 
}


/*
 * Constructor 
 */
ListOfQualitativeSpecies::ListOfQualitativeSpecies(QualPkgNamespaces* qualns)
  : ListOf(qualns)
{
  setElementNamespace(qualns->getURI());
}


/*
 * Returns a deep copy of this ListOfQualitativeSpecies 
 */
ListOfQualitativeSpecies* 
ListOfQualitativeSpecies::clone () const
 {
  return new ListOfQualitativeSpecies(*this);
}


/*
 * Get a QualitativeSpecies from the ListOfQualitativeSpecies by index.
*/
QualitativeSpecies*
ListOfQualitativeSpecies::get(unsigned int n)
{
  return static_cast<QualitativeSpecies*>(ListOf::get(n));
}


/*
 * Get a QualitativeSpecies from the ListOfQualitativeSpecies by index.
 */
const QualitativeSpecies*
ListOfQualitativeSpecies::get(unsigned int n) const
{
  return static_cast<const QualitativeSpecies*>(ListOf::get(n));
}


/*
 * Get a QualitativeSpecies from the ListOfQualitativeSpecies by id.
 */
QualitativeSpecies*
ListOfQualitativeSpecies::get(const std::string& sid)
{
  return const_cast<QualitativeSpecies*>(
    static_cast<const ListOfQualitativeSpecies&>(*this).get(sid));
}


/*
 * Get a QualitativeSpecies from the ListOfQualitativeSpecies by id.
 */
const QualitativeSpecies*
ListOfQualitativeSpecies::get(const std::string& sid) const
{
  vector<SBase*>::const_iterator result;

  result = find_if( mItems.begin(), mItems.end(), IdEq<QualitativeSpecies>(sid) );
  return (result == mItems.end()) ? 0 : static_cast <QualitativeSpecies*> (*result);
}


/*
 * Removes the nth QualitativeSpecies from this ListOfQualitativeSpecies
 */
QualitativeSpecies*
ListOfQualitativeSpecies::remove(unsigned int n)
{
  return static_cast<QualitativeSpecies*>(ListOf::remove(n));
}


/*
 * Removes the QualitativeSpecies from this ListOfQualitativeSpecies with the given identifier
 */
QualitativeSpecies*
ListOfQualitativeSpecies::remove(const std::string& sid)
{
  SBase* item = NULL;
  vector<SBase*>::iterator result;

  result = find_if( mItems.begin(), mItems.end(), IdEq<QualitativeSpecies>(sid) );

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <QualitativeSpecies*> (item);
}


/*
 * Returns the XML element name of this object
 */
const std::string&
ListOfQualitativeSpecies::getElementName () const
{
  static const string name = "listOfQualitativeSpecies";
  return name;
}


/*
 * Returns the libSBML type code for the objects in this LIST_OF.
 */
int
ListOfQualitativeSpecies::getItemTypeCode () const
{
  return SBML_QUAL_QUALITATIVE_SPECIES;
}


  /** @cond doxygenLibsbmlInternal */

/*
 * Creates a new QualitativeSpecies in this ListOfQualitativeSpecies
 */
SBase*
ListOfQualitativeSpecies::createObject(XMLInputStream& stream)
{
  const std::string& name   = stream.peek().getName();
  SBase* object = NULL;

  if (name == "qualitativeSpecies")
  {
    QUAL_CREATE_NS(qualns, getSBMLNamespaces());
    object = new QualitativeSpecies(qualns);
    appendAndOwn(object);
  }

  return object;
}


  /** @endcond */


  /** @cond doxygenLibsbmlInternal */

/*
 * Write the namespace for the Qual package.
 */
void
ListOfQualitativeSpecies::writeXMLNS(XMLOutputStream& stream) const
{
  XMLNamespaces xmlns;

  std::string prefix = getPrefix();

  if (prefix.empty())
  {
    if (getNamespaces()->hasURI(QualExtension::getXmlnsL3V1V1()))
    {
      xmlns.add(QualExtension::getXmlnsL3V1V1(),prefix);
    }
  }

  stream << xmlns;
}


  /** @endcond */


/**
 *
 */
LIBSBML_EXTERN
QualitativeSpecies_t *
QualitativeSpecies_create(unsigned int level, unsigned int version,
                          unsigned int pkgVersion)
{
  return new QualitativeSpecies(level, version, pkgVersion);
}


/**
 *
 */
LIBSBML_EXTERN
void
QualitativeSpecies_free(QualitativeSpecies_t * qs)
{
  if (qs != NULL)
    delete qs;
}


/**
 *
 */
LIBSBML_EXTERN
QualitativeSpecies_t *
QualitativeSpecies_clone(QualitativeSpecies_t * qs)
{
  if (qs != NULL)
  {
    return static_cast<QualitativeSpecies_t*>(qs->clone());
  }
  else
  {
    return NULL;
  }
}


/**
 *
 */
LIBSBML_EXTERN
char *
QualitativeSpecies_getId(QualitativeSpecies_t * qs)
{
  if (qs == NULL)
    return NULL;

  return qs->getId().empty() ? NULL : safe_strdup(qs->getId().c_str());
}


/**
 *
 */
LIBSBML_EXTERN
char *
QualitativeSpecies_getCompartment(QualitativeSpecies_t * qs)
{
  if (qs == NULL)
    return NULL;

  return qs->getCompartment().empty() ? NULL : safe_strdup(qs->getCompartment().c_str());
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_getConstant(QualitativeSpecies_t * qs)
{
  return (qs != NULL) ? static_cast<int>(qs->getConstant()) : 0;
}


/**
 *
 */
LIBSBML_EXTERN
char *
QualitativeSpecies_getName(QualitativeSpecies_t * qs)
{
  if (qs == NULL)
    return NULL;

  return qs->getName().empty() ? NULL : safe_strdup(qs->getName().c_str());
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_getInitialLevel(QualitativeSpecies_t * qs)
{
  return (qs != NULL) ? qs->getInitialLevel() : SBML_INT_MAX;
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_getMaxLevel(QualitativeSpecies_t * qs)
{
  return (qs != NULL) ? qs->getMaxLevel() : SBML_INT_MAX;
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_isSetId(QualitativeSpecies_t * qs)
{
  return (qs != NULL) ? static_cast<int>(qs->isSetId()) : 0;
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_isSetCompartment(QualitativeSpecies_t * qs)
{
  return (qs != NULL) ? static_cast<int>(qs->isSetCompartment()) : 0;
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_isSetConstant(QualitativeSpecies_t * qs)
{
  return (qs != NULL) ? static_cast<int>(qs->isSetConstant()) : 0;
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_isSetName(QualitativeSpecies_t * qs)
{
  return (qs != NULL) ? static_cast<int>(qs->isSetName()) : 0;
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_isSetInitialLevel(QualitativeSpecies_t * qs)
{
  return (qs != NULL) ? static_cast<int>(qs->isSetInitialLevel()) : 0;
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_isSetMaxLevel(QualitativeSpecies_t * qs)
{
  return (qs != NULL) ? static_cast<int>(qs->isSetMaxLevel()) : 0;
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_setId(QualitativeSpecies_t * qs, const char * id)
{
  return (qs != NULL) ? qs->setId(id) : LIBSBML_INVALID_OBJECT;
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_setCompartment(QualitativeSpecies_t * qs, const char * compartment)
{
  return (qs != NULL) ? qs->setCompartment(compartment) : LIBSBML_INVALID_OBJECT;
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_setConstant(QualitativeSpecies_t * qs, int constant)
{
  return (qs != NULL) ? qs->setConstant(constant) : LIBSBML_INVALID_OBJECT;
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_setName(QualitativeSpecies_t * qs, const char * name)
{
  return (qs != NULL) ? qs->setName(name) : LIBSBML_INVALID_OBJECT;
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_setInitialLevel(QualitativeSpecies_t * qs, int initialLevel)
{
  return (qs != NULL) ? qs->setInitialLevel(initialLevel) : LIBSBML_INVALID_OBJECT;
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_setMaxLevel(QualitativeSpecies_t * qs, int maxLevel)
{
  return (qs != NULL) ? qs->setMaxLevel(maxLevel) : LIBSBML_INVALID_OBJECT;
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_unsetId(QualitativeSpecies_t * qs)
{
  return (qs != NULL) ? qs->unsetId() : LIBSBML_INVALID_OBJECT;
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_unsetCompartment(QualitativeSpecies_t * qs)
{
  return (qs != NULL) ? qs->unsetCompartment() : LIBSBML_INVALID_OBJECT;
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_unsetConstant(QualitativeSpecies_t * qs)
{
  return (qs != NULL) ? qs->unsetConstant() : LIBSBML_INVALID_OBJECT;
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_unsetName(QualitativeSpecies_t * qs)
{
  return (qs != NULL) ? qs->unsetName() : LIBSBML_INVALID_OBJECT;
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_unsetInitialLevel(QualitativeSpecies_t * qs)
{
  return (qs != NULL) ? qs->unsetInitialLevel() : LIBSBML_INVALID_OBJECT;
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_unsetMaxLevel(QualitativeSpecies_t * qs)
{
  return (qs != NULL) ? qs->unsetMaxLevel() : LIBSBML_INVALID_OBJECT;
}


/**
 *
 */
LIBSBML_EXTERN
int
QualitativeSpecies_hasRequiredAttributes(QualitativeSpecies_t * qs)
{
  return (qs != NULL) ? static_cast<int>(qs->hasRequiredAttributes()) : 0;
}


/**
 *
 */
LIBSBML_EXTERN
QualitativeSpecies_t *
ListOfQualitativeSpecies_getById(ListOf_t * lo, const char * sid)
{
  if (lo == NULL)
    return NULL;

  return (sid != NULL) ? static_cast <ListOfQualitativeSpecies *>(lo)->get(sid) : NULL;
}


/**
 *
 */
LIBSBML_EXTERN
QualitativeSpecies_t *
ListOfQualitativeSpecies_removeById(ListOf_t * lo, const char * sid)
{
  if (lo == NULL)
    return NULL;

  return (sid != NULL) ? static_cast <ListOfQualitativeSpecies *>(lo)->remove(sid) : NULL;
}




LIBSBML_CPP_NAMESPACE_END


