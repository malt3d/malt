#!/usr/bin/env python3

import os
import json
import sys

import list_components

class component_decl:
    name = ""

class module_decl:
    name = ""
    version = ""

class module_registry:
    def find_module(self):
        return

class malt_module:
    _json_data = {}
    path = ""
    def __init__(self, path):
        self.path = path
        module_def = open(os.path.join(path, "module.json"), encoding="utf-8")
        self._json_data = json.loads(module_def.read())

    @property
    def name(self):
        return self._json_data["name"]

    @name.setter
    def name(self, name):
        self._json_data["name"] = name

    @property
    def components(self):
        comps = []
        for elem in self._json_data["components"]:
            res = component_decl()
            if isinstance(elem, dict):
                res.name = elem["name"]
            if isinstance(elem, str):
                res.name = elem
            comps.append(res)
        return comps

    @property
    def depends(self):
        deps = []
        for elem in self._json_data["dependencies"]:
            dep = module_decl()
            if isinstance(elem, dict):
                dep.name = elem["name"]
            if isinstance(elem, str):
                dep.name = elem
            deps.append(dep)
        return deps

def main():
    module = malt_module(sys.argv[1])
    print(module.name)
    print("Components: ")
    for comp in module.components:
        print("    + {}".format(comp.name))

    print("Dependencies: ")
    for dep in module.depends:
        print("    + {}".format(dep.name))


if __name__ == '__main__':
    main()
