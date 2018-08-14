rpi-internal-registers-online
=============================

this project contains scripts to automatically
generate a register map from the broadcom-provided: 
* old url - [Brcm_Android_ICS_Graphics_Stack.tar.gz](http://www.broadcom.com/docs/support/videocore/Brcm_Android_ICS_Graphics_Stack.tar.gz) 
* new url - [Brcm_Android_ICS_Graphics_Stack.tar.gz](https://docs.broadcom.com/docs/12358546)

it creates it as a single html and MediaWiki Markup files, and 
as multiple linked files as markdown and html versions:
* [single html](https://rawgithub.com/paulwratt/rpi-internal-registers-online/master/rpi-registers.html)
* [single markup](https://rawgithub.com/paulwratt/rpi-internal-registers-online/master/mediawiki.markup)
* [multiple markdown](md/README.md)
* [multiple html](http://paulwratt.github.io/rpi-internal-registers-online/)

to create it yourself:
* untar the broadcom provided tar to a directory
* clone this project
* in the project directory execute: ```make BCRMBASE=<the dir where you untared the sources> md html docs```

now you get all the registers as files
