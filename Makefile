BOARDS = $(shell ls */board/*.brd)
BOARD_ZIPS = $(addsuffix .zip, $(basename $(BOARDS)))

CUR_JOB = panel/current
CFG_FILE = $(CUR_JOB)/layout.cfg
DEF_FILE = $(CUR_JOB)/layout.def

CAM_SCR = panel/33each_cam.sh

%.zip: %.brd
	bash $(CAM_SCR) $*.brd $(dir $*.brd)gerber/$(notdir $*)
	mv $(dir $*.brd)gerber.zip $*.zip

all-boards: $(BOARD_ZIPS)

print:
	@echo $(BOARDS)
	@echo $(BOARD_ZIPS)

#*/board: $(DESIGNS)
#	$(CAM_SCR) $(CFG_FILE) $(DEF_FILE)

#merge: 
#	gerbmerge $(CFG_FILE) $(DEF_FILE)

#zip: merge

clean:
	find . -name *.*\#* -exec rm {} \;
	rm -rf */board/*.zip
	rm -rf */board/gerber/*.*
	rm -rf $(CUR_JOB)/gerber/*.*
	rm -rf $(CUR_JOB)/*.zip

.PHONY: clean all-boards print
