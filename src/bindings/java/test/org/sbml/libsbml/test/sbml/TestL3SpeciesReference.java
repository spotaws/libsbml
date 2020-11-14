/*
 * @file    TestL3SpeciesReference.java
 * @brief   L3 SpeciesReference unit tests
 *
 * @author  Akiya Jouraku (Java conversion)
 * @author  Sarah Keating 
 * 
 * ====== WARNING ===== WARNING ===== WARNING ===== WARNING ===== WARNING ======
 *
 * DO NOT EDIT THIS FILE.
 *
 * This file was generated automatically by converting the file located at
 * src/sbml/test/TestL3SpeciesReference.c
 * using the conversion program dev/utilities/translateTests/translateTests.pl.
 * Any changes made here will be lost the next time the file is regenerated.
 *
 * -----------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2020 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. University of Heidelberg, Heidelberg, Germany
 *     3. University College London, London, UK
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
 * -----------------------------------------------------------------------------
 */

package org.sbml.libsbml.test.sbml;

import org.sbml.libsbml.*;

import java.io.File;
import java.lang.AssertionError;

public class TestL3SpeciesReference {

  static void assertTrue(boolean condition) throws AssertionError
  {
    if (condition == true)
    {
      return;
    }
    throw new AssertionError();
  }

  static void assertEquals(Object a, Object b) throws AssertionError
  {
    if ( (a == null) && (b == null) )
    {
      return;
    }
    else if ( (a == null) || (b == null) )
    {
      throw new AssertionError();
    }
    else if (a.equals(b))
    {
      return;
    }

    throw new AssertionError();
  }

  static void assertNotEquals(Object a, Object b) throws AssertionError
  {
    if ( (a == null) && (b == null) )
    {
      throw new AssertionError();
    }
    else if ( (a == null) || (b == null) )
    {
      return;
    }
    else if (a.equals(b))
    {
      throw new AssertionError();
    }
  }

  static void assertEquals(boolean a, boolean b) throws AssertionError
  {
    if ( a == b )
    {
      return;
    }
    throw new AssertionError();
  }

  static void assertNotEquals(boolean a, boolean b) throws AssertionError
  {
    if ( a != b )
    {
      return;
    }
    throw new AssertionError();
  }

  static void assertEquals(int a, int b) throws AssertionError
  {
    if ( a == b )
    {
      return;
    }
    throw new AssertionError();
  }

  static void assertNotEquals(int a, int b) throws AssertionError
  {
    if ( a != b )
    {
      return;
    }
    throw new AssertionError();
  }
  private SpeciesReference SR;

  public boolean isnan(double x)
  {
    return (x != x);
  }

  protected void setUp() throws Exception
  {
    SR = new  SpeciesReference(3,1);
    if (SR == null);
    {
    }
  }

  protected void tearDown() throws Exception
  {
    SR = null;
  }

  public void test_L3_SpeciesReference_NS()
  {
    assertTrue( SR.getNamespaces() != null );
    assertTrue( SR.getNamespaces().getLength() == 1 );
    assertTrue(SR.getNamespaces().getURI(0).equals(    "http://www.sbml.org/sbml/level3/version1/core"));
  }

  public void test_L3_SpeciesReference_constant()
  {
    assertTrue( SR.isSetConstant() == false );
    SR.setConstant(true);
    assertTrue( SR.getConstant() == true );
    assertTrue( SR.isSetConstant() == true );
    SR.setConstant(false);
    assertTrue( SR.getConstant() == false );
    assertTrue( SR.isSetConstant() == true );
  }

  public void test_L3_SpeciesReference_create()
  {
    assertTrue( SR.getTypeCode() == libsbml.SBML_SPECIES_REFERENCE );
    assertTrue( SR.getMetaId().equals("") == true );
    assertTrue( SR.getNotes() == null );
    assertTrue( SR.getAnnotation() == null );
    assertTrue( SR.getId().equals("") == true );
    assertTrue( SR.getName().equals("") == true );
    assertTrue( SR.getSpecies().equals("") == true );
    assertEquals( true, isnan(SR.getStoichiometry()) );
    assertTrue( SR.getConstant() == false );
    assertEquals( false, SR.isSetId() );
    assertEquals( false, SR.isSetName() );
    assertEquals( false, SR.isSetSpecies() );
    assertEquals( false, SR.isSetStoichiometry() );
    assertEquals( false, SR.isSetConstant() );
  }

  public void test_L3_SpeciesReference_createWithNS()
  {
    XMLNamespaces xmlns = new  XMLNamespaces();
    xmlns.add( "http://www.sbml.org", "testsbml");
    SBMLNamespaces sbmlns = new  SBMLNamespaces(3,1);
    sbmlns.addNamespaces(xmlns);
    SpeciesReference sr = new  SpeciesReference(sbmlns);
    assertTrue( sr.getTypeCode() == libsbml.SBML_SPECIES_REFERENCE );
    assertTrue( sr.getMetaId().equals("") == true );
    assertTrue( sr.getNotes() == null );
    assertTrue( sr.getAnnotation() == null );
    assertTrue( sr.getLevel() == 3 );
    assertTrue( sr.getVersion() == 1 );
    assertTrue( sr.getNamespaces() != null );
    assertTrue( sr.getNamespaces().getLength() == 2 );
    assertTrue( sr.getId().equals("") == true );
    assertTrue( sr.getName().equals("") == true );
    assertTrue( sr.getSpecies().equals("") == true );
    assertEquals( true, isnan(sr.getStoichiometry()) );
    assertTrue( sr.getConstant() == false );
    assertEquals( false, sr.isSetId() );
    assertEquals( false, sr.isSetName() );
    assertEquals( false, sr.isSetSpecies() );
    assertEquals( false, sr.isSetStoichiometry() );
    assertEquals( false, sr.isSetConstant() );
    sr = null;
  }

  public void test_L3_SpeciesReference_free_NULL()
  {
  }

  public void test_L3_SpeciesReference_hasRequiredAttributes()
  {
    SpeciesReference sr = new  SpeciesReference(3,1);
    assertEquals( false, sr.hasRequiredAttributes() );
    sr.setSpecies( "id");
    assertEquals( false, sr.hasRequiredAttributes() );
    sr.setConstant(false);
    assertEquals( true, sr.hasRequiredAttributes() );
    sr = null;
  }

  public void test_L3_SpeciesReference_id()
  {
    String id =  "mitochondria";
    assertEquals( false, SR.isSetId() );
    SR.setId(id);
    assertTrue(SR.getId().equals(id));
    assertEquals( true, SR.isSetId() );
    if (SR.getId() == id);
    {
    }
  }

  public void test_L3_SpeciesReference_name()
  {
    String name =  "My_Favorite_Factory";
    assertEquals( false, SR.isSetName() );
    SR.setName(name);
    assertTrue(SR.getName().equals(name));
    assertEquals( true, SR.isSetName() );
    if (SR.getName() == name);
    {
    }
    SR.unsetName();
    assertEquals( false, SR.isSetName() );
    if (SR.getName() != null);
    {
    }
  }

  public void test_L3_SpeciesReference_species()
  {
    String species =  "cell";
    assertEquals( false, SR.isSetSpecies() );
    SR.setSpecies(species);
    assertTrue(SR.getSpecies().equals(species));
    assertEquals( true, SR.isSetSpecies() );
    if (SR.getSpecies() == species);
    {
    }
  }

  public void test_L3_SpeciesReference_stoichiometry()
  {
    double stoichiometry = 0.2;
    assertEquals( false, SR.isSetStoichiometry() );
    assertEquals( true, isnan(SR.getStoichiometry()) );
    SR.setStoichiometry(stoichiometry);
    assertTrue( SR.getStoichiometry() == stoichiometry );
    assertEquals( true, SR.isSetStoichiometry() );
    SR.unsetStoichiometry();
    assertEquals( false, SR.isSetStoichiometry() );
    assertEquals( true, isnan(SR.getStoichiometry()) );
  }

  /**
   * Loads the SWIG-generated libSBML Java module when this class is
   * loaded, or reports a sensible diagnostic message about why it failed.
   */
  static
  {
    String varname;
    String shlibname;

    if (System.getProperty("mrj.version") != null)
    {
      varname = "DYLD_LIBRARY_PATH";    // We're on a Mac.
      shlibname = "libsbmlj.jnilib and/or libsbml.dylib";
    }
    else
    {
      varname = "LD_LIBRARY_PATH";      // We're not on a Mac.
      shlibname = "libsbmlj.so and/or libsbml.so";
    }

    try
    {
      System.loadLibrary("sbmlj");
      // For extra safety, check that the jar file is in the classpath.
      Class.forName("org.sbml.libsbml.libsbml");
    }
    catch (SecurityException e)
    {
      e.printStackTrace();
      System.err.println("Could not load the libSBML library files due to a"+
                         " security exception.\n");
      System.exit(1);
    }
    catch (UnsatisfiedLinkError e)
    {
      e.printStackTrace();
      System.err.println("Error: could not link with the libSBML library files."+
                         " It is likely\nyour " + varname +
                         " environment variable does not include the directories\n"+
                         "containing the " + shlibname + " library files.\n");
      System.exit(1);
    }
    catch (ClassNotFoundException e)
    {
      e.printStackTrace();
      System.err.println("Error: unable to load the file libsbmlj.jar."+
                         " It is likely\nyour -classpath option and CLASSPATH" +
                         " environment variable\n"+
                         "do not include the path to libsbmlj.jar.\n");
      System.exit(1);
    }
  }
}
