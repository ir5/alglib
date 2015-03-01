#!/usr/bin/python
# -*- coding: utf-8 -*-

from mako.template import Template
from mako.lookup import TemplateLookup
from config import CODE_LIST

def main():
    template = Template(filename='html_template/index.html',
        input_encoding='utf-8',
        output_encoding='utf-8')
    html = template.render(code_list=CODE_LIST)

    print html

if __name__ == '__main__':
    main()
