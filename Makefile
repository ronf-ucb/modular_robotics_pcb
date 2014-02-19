DESIGNS = camera encoder motor
BOARDS = $(DESIGNS)/board/*.brd

CUR_JOB = panel/current
CFG_FILE = $(CUR_JOB)/layout.cfg
DEF_FILE = $(CUR_JOB)/layout.def

CAM_SCR = panel/33each_cam.sh

%/board/%.zip: %/board/%.brd
	bash $(CAM_SCR) $*/board/$*.brd $*/board/gerber/$*
	mv $*/board/gerber.zip $*/board/$*.zip

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
