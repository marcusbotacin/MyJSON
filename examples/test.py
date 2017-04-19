#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Marcus Botacin

import json # test json
import sys # args

f = open(sys.argv[1],"r").read()
l = json.loads(f)

for entries in l['Movies']:
	print("Title",entries['title'])
	print("Year",entries['year'])
