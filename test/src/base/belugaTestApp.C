//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "belugaTestApp.h"
#include "belugaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
belugaTestApp::validParams()
{
  InputParameters params = belugaApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

belugaTestApp::belugaTestApp(InputParameters parameters) : MooseApp(parameters)
{
  belugaTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

belugaTestApp::~belugaTestApp() {}

void
belugaTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  belugaApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"belugaTestApp"});
    Registry::registerActionsTo(af, {"belugaTestApp"});
  }
}

void
belugaTestApp::registerApps()
{
  registerApp(belugaApp);
  registerApp(belugaTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
belugaTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  belugaTestApp::registerAll(f, af, s);
}
extern "C" void
belugaTestApp__registerApps()
{
  belugaTestApp::registerApps();
}
