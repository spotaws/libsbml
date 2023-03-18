/**
 * \file    TestUnusualRDFAnnotation.cpp
 * \brief   fomula units data unit tests
 * \author  Sarah Keating
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2020 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. University of Heidelberg, Heidelberg, Germany
 *     3. University College London, London, UK
 *
 * Copyright (C) 2019 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2013-2018 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *     3. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2009-2013 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
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
 * ---------------------------------------------------------------------- -->*/

#include <sbml/common/common.h>
#include <sbml/common/extern.h>

#include <sbml/SBMLReader.h>
#include <sbml/SBMLTypes.h>

#include <sbml/SBMLDocument.h>
#include <sbml/Model.h>
#include <sbml/SBMLTypeCodes.h>

#include <sbml/annotation/RDFAnnotation.h>
#include <sbml/annotation/ModelHistory.h>

#include <check.h>

LIBSBML_CPP_NAMESPACE_USE

CK_CPPSTART


static Model *m;
static SBMLDocument* d;

extern char *TestDataDirectory;

/* 
 * tests the results from rdf annotations
 */



void
UnusualRDFAnnotation_setup (void)
{
  char *filename = safe_strcat(TestDataDirectory, "set_annot_test.xml");

  // The following will return a pointer to a new SBMLDocument.
  d = readSBML(filename);
  m = d->getModel();

  free(filename);
}


void
UnusualRDFAnnotation_teardown (void)
{
  delete d;
}

static bool
equals (const char* expected, const char* actual)
{
  if ( !strcmp(expected, actual) ) return true;

  printf( "\nStrings are not equal:\n"  );
  printf( "Expected:\n[%s]\n", expected );
  printf( "Actual:\n[%s]\n"  , actual   );

  return false;
}


START_TEST(test_roundtrip)
{
  const char * expected = "<annotation>\n"
    "</annotation>";

  Species *s = m->getSpecies(0);
  XMLNode* node = s->getAnnotation();

  fail_unless(equals(expected, node->toXMLString().c_str()));
}
END_TEST


START_TEST(test_hasCVTerms)
{
  Species *s = m->getSpecies(0);
  fail_unless(s->getNumCVTerms() == 2);

}
END_TEST


START_TEST(test_read_XMLNode_from_file)
{
  char *filename = safe_strcat(TestDataDirectory, "just_annotation.xml");
  XMLNode *node = XMLNode::readXMLNodeFromFile(filename);
  fail_unless(node != NULL);

  fail_unless(node->getNumChildren() == 1);

  const XMLNode_t* rdf = XMLNode_getChild(node, 0);

  fail_unless(!strcmp(XMLNode_getName(rdf), "RDF"));
  fail_unless(!strcmp(XMLNode_getPrefix(rdf), "rdf"));
  fail_unless(!strcmp(XMLNode_getURI(rdf), "http://www.w3.org/1999/02/22-rdf-syntax-ns#"));
  fail_unless(XMLNode_getNumChildren(rdf) == 1);

  const XMLNode_t* desc = XMLNode_getChild(rdf, 0);

  fail_unless(!strcmp(XMLNode_getName(desc), "Description"));
  fail_unless(!strcmp(XMLNode_getPrefix(desc), "rdf"));
  fail_unless(!strcmp(XMLNode_getURI(desc), "http://www.w3.org/1999/02/22-rdf-syntax-ns#"));
  fail_unless(XMLNode_getNumChildren(desc) == 1);

  const XMLNode_t * is1 = XMLNode_getChild(desc, 0);
  fail_unless(!strcmp(XMLNode_getName(is1), "is"));
  fail_unless(!strcmp(XMLNode_getPrefix(is1), "bqbiol"));
  fail_unless(XMLNode_getNumChildren(is1) == 1);

  const XMLNode_t * Bag = XMLNode_getChild(is1, 0);
  fail_unless(!strcmp(XMLNode_getName(Bag), "Bag"));
  fail_unless(!strcmp(XMLNode_getPrefix(Bag), "rdf"));
  fail_unless(!strcmp(XMLNode_getURI(Bag), "http://www.w3.org/1999/02/22-rdf-syntax-ns#"));
  fail_unless(XMLNode_getNumChildren(Bag) == 4);

  const XMLNode_t * li = XMLNode_getChild(Bag, 0);
  fail_unless(!strcmp(XMLNode_getName(li), "li"));
  fail_unless(!strcmp(XMLNode_getPrefix(li), "rdf"));
  fail_unless(!strcmp(XMLNode_getURI(li), "http://www.w3.org/1999/02/22-rdf-syntax-ns#"));
  fail_unless(li->getAttrValue(0) == "http://identifiers.org/chebi/CHEBI:59789");
  fail_unless(XMLNode_getNumChildren(li) == 0);

  const XMLNode_t * hasProp1 = XMLNode_getChild(Bag, 1);
  fail_unless(!strcmp(XMLNode_getName(hasProp1), "hasProperty"));
  fail_unless(!strcmp(XMLNode_getPrefix(hasProp1), "bqbiol"));
  fail_unless(XMLNode_getNumChildren(hasProp1) == 1);

  const XMLNode_t * Bag1 = XMLNode_getChild(hasProp1, 0);
  fail_unless(!strcmp(XMLNode_getName(Bag1), "Bag"));
  fail_unless(!strcmp(XMLNode_getPrefix(Bag1), "rdf"));
  fail_unless(!strcmp(XMLNode_getURI(Bag1), "http://www.w3.org/1999/02/22-rdf-syntax-ns#"));
  fail_unless(XMLNode_getNumChildren(Bag1) == 1);

  const XMLNode_t * li_Bag1 = XMLNode_getChild(Bag1, 0);
  fail_unless(!strcmp(XMLNode_getName(li_Bag1), "li"));
  fail_unless(!strcmp(XMLNode_getPrefix(li_Bag1), "rdf"));
  fail_unless(!strcmp(XMLNode_getURI(li_Bag1), "http://www.w3.org/1999/02/22-rdf-syntax-ns#"));
  fail_unless(XMLNode_getNumChildren(li_Bag1) == 0);


  const XMLNode_t * li2 = XMLNode_getChild(Bag, 2);
  fail_unless(!strcmp(XMLNode_getName(li2), "li"));
  fail_unless(!strcmp(XMLNode_getPrefix(li2), "rdf"));
  fail_unless(!strcmp(XMLNode_getURI(li2), "http://www.w3.org/1999/02/22-rdf-syntax-ns#"));
  fail_unless(XMLNode_getNumChildren(li2) == 0);

  //const XMLNode_t * li3 = XMLNode_getChild(Bag, 3);
  //fail_unless(!strcmp(XMLNode_getName(li3), "li"));
  //fail_unless(!strcmp(XMLNode_getPrefix(li3), "rdf"));
  //fail_unless(!strcmp(XMLNode_getURI(li3), "http://www.w3.org/1999/02/22-rdf-syntax-ns#"));
  //fail_unless(XMLNode_getNumChildren(li3) == 0);

  delete node;
}
END_TEST


Suite *
create_suite_UnusualRDFAnnotation (void)
{
  Suite *suite = suite_create("UnusualRDFAnnotation");
  TCase *tcase = tcase_create("UnusualRDFAnnotation");

  tcase_add_checked_fixture(tcase,
    UnusualRDFAnnotation_setup,
    UnusualRDFAnnotation_teardown);

//  tcase_add_test(tcase, test_roundtrip );
//  tcase_add_test(tcase, test_hasCVTerms);
  tcase_add_test(tcase, test_read_XMLNode_from_file);


  suite_add_tcase(suite, tcase);

  return suite;
}


CK_CPPEND

