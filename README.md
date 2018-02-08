The Tripal Ortholog module is being developed to allow HWG to track syntenic groups of features and as a starting point for enabling comparative genomics.

The data we're looking to support importing is [OrthoFinder](https://github.com/davidemms/OrthoFinder).  An example zip file of output is included: the list of ortholog groups and feature names is `Orthogroups.txt`.  It's recommended that subsequent group calls are used with the advanced ["add extra species"](https://github.com/davidemms/OrthoFinder#adding-extra-species) option. Analyses (subtype cluster analysis) should then refer to the original analysis.

The module is briefly outlined [here](http://gmod.org/wiki/Chado_Group_Module
).  As far as I can tell, the alternatives used in discussion (a feature that is a group, or using featureprops) are inferior to a dedicated module.


![The Chado Groups schema](/docs/img/chado_group_schema.png)

Initial implementation will focus on defining feature orthogroups, but a good implementation should be generic for the module. The thing is, I don't have a lot of info to go on for this module.  Why would I create groups of organisms in this context?  As a genera?    So we'll focus on feature groups here.


This module is under active development.