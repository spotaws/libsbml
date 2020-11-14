/*
 * @file    TestL3Event.java
 * @brief   L3 Event unit tests
 *
 * @author  Akiya Jouraku (Java conversion)
 * @author  Sarah Keating 
 * 
 * ====== WARNING ===== WARNING ===== WARNING ===== WARNING ===== WARNING ======
 *
 * DO NOT EDIT THIS FILE.
 *
 * This file was generated automatically by converting the file located at
 * src/sbml/test/TestL3Event.c
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

public class TestL3Event {

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
  private Event E;

  protected void setUp() throws Exception
  {
    E = new  Event(3,1);
    if (E == null);
    {
    }
  }

  protected void tearDown() throws Exception
  {
    E = null;
  }

  public void test_L3_Event_NS()
  {
    assertTrue( E.getNamespaces() != null );
    assertTrue( E.getNamespaces().getLength() == 1 );
    assertTrue(E.getNamespaces().getURI(0).equals(    "http://www.sbml.org/sbml/level3/version1/core"));
  }

  public void test_L3_Event_create()
  {
    assertTrue( E.getTypeCode() == libsbml.SBML_EVENT );
    assertTrue( E.getMetaId().equals("") == true );
    assertTrue( E.getNotes() == null );
    assertTrue( E.getAnnotation() == null );
    assertTrue( E.getId().equals("") == true );
    assertTrue( E.getName().equals("") == true );
    assertTrue( E.getUseValuesFromTriggerTime() == true );
    assertEquals( false, E.isSetId() );
    assertEquals( false, E.isSetName() );
    assertEquals( false, E.isSetUseValuesFromTriggerTime() );
  }

  public void test_L3_Event_createWithNS()
  {
    XMLNamespaces xmlns = new  XMLNamespaces();
    xmlns.add( "http://www.sbml.org", "testsbml");
    SBMLNamespaces sbmlns = new  SBMLNamespaces(3,1);
    sbmlns.addNamespaces(xmlns);
    Event e = new  Event(sbmlns);
    assertTrue( e.getTypeCode() == libsbml.SBML_EVENT );
    assertTrue( e.getMetaId().equals("") == true );
    assertTrue( e.getNotes() == null );
    assertTrue( e.getAnnotation() == null );
    assertTrue( e.getLevel() == 3 );
    assertTrue( e.getVersion() == 1 );
    assertTrue( e.getNamespaces() != null );
    assertTrue( e.getNamespaces().getLength() == 2 );
    assertTrue( e.getId().equals("") == true );
    assertTrue( e.getName().equals("") == true );
    assertTrue( e.getUseValuesFromTriggerTime() == true );
    assertEquals( false, e.isSetId() );
    assertEquals( false, e.isSetName() );
    assertEquals( false, e.isSetUseValuesFromTriggerTime() );
    e = null;
  }

  public void test_L3_Event_free_NULL()
  {
  }

  public void test_L3_Event_hasRequiredAttributes()
  {
    Event e = new  Event(3,1);
    assertEquals( false, e.hasRequiredAttributes() );
    e.setUseValuesFromTriggerTime(true);
    assertEquals( true, e.hasRequiredAttributes() );
    e = null;
  }

  public void test_L3_Event_hasRequiredElements()
  {
    Event e = new  Event(3,1);
    assertEquals( false, e.hasRequiredElements() );
    Trigger t = new  Trigger(3,1);
    t.setMath(libsbml.parseFormula("true"));
    t.setInitialValue(false);
    t.setPersistent(false);
    e.setTrigger(t);
    assertEquals( true, e.hasRequiredElements() );
    e = null;
  }

  public void test_L3_Event_id()
  {
    String id =  "mitochondria";
    assertEquals( false, E.isSetId() );
    E.setId(id);
    assertTrue(E.getId().equals(id));
    assertEquals( true, E.isSetId() );
    if (E.getId() == id);
    {
    }
    E.unsetId();
    assertEquals( false, E.isSetId() );
    if (E.getId() != null);
    {
    }
  }

  public void test_L3_Event_name()
  {
    String name =  "My_Favorite_Factory";
    assertEquals( false, E.isSetName() );
    E.setName(name);
    assertTrue(E.getName().equals(name));
    assertEquals( true, E.isSetName() );
    if (E.getName() == name);
    {
    }
    E.unsetName();
    assertEquals( false, E.isSetName() );
    if (E.getName() != null);
    {
    }
  }

  public void test_L3_Event_setPriority1()
  {
    Priority priority = new  Priority(3,1);
    ASTNode math1 = libsbml.parseFormula("0");
    priority.setMath(math1);
    assertEquals( false, E.isSetPriority() );
    int i = E.setPriority(priority);
    assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
    assertEquals( true, E.isSetPriority() );
    i = E.unsetPriority();
    assertTrue( i == libsbml.LIBSBML_OPERATION_SUCCESS );
    assertEquals( false, E.isSetPriority() );
    priority = null;
  }

  public void test_L3_Event_setPriority2()
  {
    Priority priority = E.createPriority();
    assertEquals( true, E.isSetPriority() );
    Priority p = E.getPriority();
    assertTrue( p != null );
    assertEquals( false, p.isSetMath() );
  }

  public void test_L3_Event_useValuesFromTriggerTime()
  {
    assertTrue( E.isSetUseValuesFromTriggerTime() == false );
    E.setUseValuesFromTriggerTime(true);
    assertTrue( E.getUseValuesFromTriggerTime() == true );
    assertTrue( E.isSetUseValuesFromTriggerTime() == true );
    E.setUseValuesFromTriggerTime(false);
    assertTrue( E.getUseValuesFromTriggerTime() == false );
    assertTrue( E.isSetUseValuesFromTriggerTime() == true );
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

