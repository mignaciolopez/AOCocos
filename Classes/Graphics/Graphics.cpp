// ---------------------------------------
// Sprite definitions for Graphics
// Generated with TexturePacker 4.11.1
//
// https://www.codeandweb.com/texturepacker
// ---------------------------------------

#include "Graphics.h"

USING_NS_CC;

namespace TP
{

void Graphics::addSpriteFramesToCache()
{
    SpriteFrameCache *cache = SpriteFrameCache::getInstance();
	FileUtils* fileUtils = FileUtils::getInstance();
   
	bool restoreNotify = fileUtils->isPopupNotify();
	fileUtils->setPopupNotify(true); // disable warnings


	int files = 6;
	for (int i = 0; i < files; i++)
	{
		std::string plist = fileUtils->fullPathForFilename("Graphics-" + std::to_string(i) + ".plist");
		std::string png = fileUtils->fullPathForFilename("Graphics-" + std::to_string(i) + ".png");

		if (fileUtils->isFileExist(plist) && fileUtils->isFileExist(png))
			cache->addSpriteFramesWithFile(plist, png);
	}

	fileUtils->setPopupNotify(restoreNotify); // reset warnings
}
;

void Graphics::removeSpriteFramesFromCache()
{
    SpriteFrameCache *cache = SpriteFrameCache::getInstance();
	if (!cache)
		return;

	FileUtils* fileUtils = FileUtils::getInstance();
	if (!fileUtils)
		return;

	int files = 6;
	for (int i = 0; i < files; i++)
	{
		std::string plist = fileUtils->fullPathForFilename("Graphics-" + std::to_string(i) + ".plist");

		if (fileUtils->isFileExist(plist))
			if (cache->isSpriteFramesWithFileLoaded(plist))
				cache->removeSpriteFramesFromFile(plist);
	}
};


// ---------------------
// sprite name constants
// ---------------------
const std::string Graphics::blood01                              = "Blood01.png";
const std::string Graphics::blood02                              = "Blood02.png";
const std::string Graphics::blood03                              = "Blood03.png";
const std::string Graphics::blood04                              = "Blood04.png";
const std::string Graphics::blood05                              = "Blood05.png";
const std::string Graphics::clothesGraphic_10                    = "Clothes/Graphic (10).png";
const std::string Graphics::clothesGraphic_100                   = "Clothes/Graphic (100).png";
const std::string Graphics::clothesGraphic_101                   = "Clothes/Graphic (101).png";
const std::string Graphics::clothesGraphic_102                   = "Clothes/Graphic (102).png";
const std::string Graphics::clothesGraphic_103                   = "Clothes/Graphic (103).png";
const std::string Graphics::clothesGraphic_104                   = "Clothes/Graphic (104).png";
const std::string Graphics::clothesGraphic_105                   = "Clothes/Graphic (105).png";
const std::string Graphics::clothesGraphic_106                   = "Clothes/Graphic (106).png";
const std::string Graphics::clothesGraphic_107                   = "Clothes/Graphic (107).png";
const std::string Graphics::clothesGraphic_108                   = "Clothes/Graphic (108).png";
const std::string Graphics::clothesGraphic_109                   = "Clothes/Graphic (109).png";
const std::string Graphics::clothesGraphic_11                    = "Clothes/Graphic (11).png";
const std::string Graphics::clothesGraphic_110                   = "Clothes/Graphic (110).png";
const std::string Graphics::clothesGraphic_111                   = "Clothes/Graphic (111).png";
const std::string Graphics::clothesGraphic_112                   = "Clothes/Graphic (112).png";
const std::string Graphics::clothesGraphic_113                   = "Clothes/Graphic (113).png";
const std::string Graphics::clothesGraphic_114                   = "Clothes/Graphic (114).png";
const std::string Graphics::clothesGraphic_115                   = "Clothes/Graphic (115).png";
const std::string Graphics::clothesGraphic_116                   = "Clothes/Graphic (116).png";
const std::string Graphics::clothesGraphic_117                   = "Clothes/Graphic (117).png";
const std::string Graphics::clothesGraphic_118                   = "Clothes/Graphic (118).png";
const std::string Graphics::clothesGraphic_119                   = "Clothes/Graphic (119).png";
const std::string Graphics::clothesGraphic_12                    = "Clothes/Graphic (12).png";
const std::string Graphics::clothesGraphic_120                   = "Clothes/Graphic (120).png";
const std::string Graphics::clothesGraphic_121                   = "Clothes/Graphic (121).png";
const std::string Graphics::clothesGraphic_122                   = "Clothes/Graphic (122).png";
const std::string Graphics::clothesGraphic_123                   = "Clothes/Graphic (123).png";
const std::string Graphics::clothesGraphic_124                   = "Clothes/Graphic (124).png";
const std::string Graphics::clothesGraphic_125                   = "Clothes/Graphic (125).png";
const std::string Graphics::clothesGraphic_126                   = "Clothes/Graphic (126).png";
const std::string Graphics::clothesGraphic_127                   = "Clothes/Graphic (127).png";
const std::string Graphics::clothesGraphic_128                   = "Clothes/Graphic (128).png";
const std::string Graphics::clothesGraphic_129                   = "Clothes/Graphic (129).png";
const std::string Graphics::clothesGraphic_13                    = "Clothes/Graphic (13).png";
const std::string Graphics::clothesGraphic_130                   = "Clothes/Graphic (130).png";
const std::string Graphics::clothesGraphic_131                   = "Clothes/Graphic (131).png";
const std::string Graphics::clothesGraphic_132                   = "Clothes/Graphic (132).png";
const std::string Graphics::clothesGraphic_133                   = "Clothes/Graphic (133).png";
const std::string Graphics::clothesGraphic_134                   = "Clothes/Graphic (134).png";
const std::string Graphics::clothesGraphic_135                   = "Clothes/Graphic (135).png";
const std::string Graphics::clothesGraphic_136                   = "Clothes/Graphic (136).png";
const std::string Graphics::clothesGraphic_137                   = "Clothes/Graphic (137).png";
const std::string Graphics::clothesGraphic_138                   = "Clothes/Graphic (138).png";
const std::string Graphics::clothesGraphic_139                   = "Clothes/Graphic (139).png";
const std::string Graphics::clothesGraphic_14                    = "Clothes/Graphic (14).png";
const std::string Graphics::clothesGraphic_140                   = "Clothes/Graphic (140).png";
const std::string Graphics::clothesGraphic_141                   = "Clothes/Graphic (141).png";
const std::string Graphics::clothesGraphic_142                   = "Clothes/Graphic (142).png";
const std::string Graphics::clothesGraphic_143                   = "Clothes/Graphic (143).png";
const std::string Graphics::clothesGraphic_144                   = "Clothes/Graphic (144).png";
const std::string Graphics::clothesGraphic_145                   = "Clothes/Graphic (145).png";
const std::string Graphics::clothesGraphic_146                   = "Clothes/Graphic (146).png";
const std::string Graphics::clothesGraphic_147                   = "Clothes/Graphic (147).png";
const std::string Graphics::clothesGraphic_148                   = "Clothes/Graphic (148).png";
const std::string Graphics::clothesGraphic_149                   = "Clothes/Graphic (149).png";
const std::string Graphics::clothesGraphic_15                    = "Clothes/Graphic (15).png";
const std::string Graphics::clothesGraphic_150                   = "Clothes/Graphic (150).png";
const std::string Graphics::clothesGraphic_151                   = "Clothes/Graphic (151).png";
const std::string Graphics::clothesGraphic_152                   = "Clothes/Graphic (152).png";
const std::string Graphics::clothesGraphic_153                   = "Clothes/Graphic (153).png";
const std::string Graphics::clothesGraphic_154                   = "Clothes/Graphic (154).png";
const std::string Graphics::clothesGraphic_155                   = "Clothes/Graphic (155).png";
const std::string Graphics::clothesGraphic_156                   = "Clothes/Graphic (156).png";
const std::string Graphics::clothesGraphic_157                   = "Clothes/Graphic (157).png";
const std::string Graphics::clothesGraphic_158                   = "Clothes/Graphic (158).png";
const std::string Graphics::clothesGraphic_159                   = "Clothes/Graphic (159).png";
const std::string Graphics::clothesGraphic_16                    = "Clothes/Graphic (16).png";
const std::string Graphics::clothesGraphic_160                   = "Clothes/Graphic (160).png";
const std::string Graphics::clothesGraphic_161                   = "Clothes/Graphic (161).png";
const std::string Graphics::clothesGraphic_162                   = "Clothes/Graphic (162).png";
const std::string Graphics::clothesGraphic_163                   = "Clothes/Graphic (163).png";
const std::string Graphics::clothesGraphic_164                   = "Clothes/Graphic (164).png";
const std::string Graphics::clothesGraphic_165                   = "Clothes/Graphic (165).png";
const std::string Graphics::clothesGraphic_166                   = "Clothes/Graphic (166).png";
const std::string Graphics::clothesGraphic_167                   = "Clothes/Graphic (167).png";
const std::string Graphics::clothesGraphic_168                   = "Clothes/Graphic (168).png";
const std::string Graphics::clothesGraphic_169                   = "Clothes/Graphic (169).png";
const std::string Graphics::clothesGraphic_17                    = "Clothes/Graphic (17).png";
const std::string Graphics::clothesGraphic_170                   = "Clothes/Graphic (170).png";
const std::string Graphics::clothesGraphic_171                   = "Clothes/Graphic (171).png";
const std::string Graphics::clothesGraphic_172                   = "Clothes/Graphic (172).png";
const std::string Graphics::clothesGraphic_173                   = "Clothes/Graphic (173).png";
const std::string Graphics::clothesGraphic_174                   = "Clothes/Graphic (174).png";
const std::string Graphics::clothesGraphic_175                   = "Clothes/Graphic (175).png";
const std::string Graphics::clothesGraphic_176                   = "Clothes/Graphic (176).png";
const std::string Graphics::clothesGraphic_177                   = "Clothes/Graphic (177).png";
const std::string Graphics::clothesGraphic_178                   = "Clothes/Graphic (178).png";
const std::string Graphics::clothesGraphic_179                   = "Clothes/Graphic (179).png";
const std::string Graphics::clothesGraphic_180                   = "Clothes/Graphic (180).png";
const std::string Graphics::clothesGraphic_181                   = "Clothes/Graphic (181).png";
const std::string Graphics::clothesGraphic_182                   = "Clothes/Graphic (182).png";
const std::string Graphics::clothesGraphic_183                   = "Clothes/Graphic (183).png";
const std::string Graphics::clothesGraphic_184                   = "Clothes/Graphic (184).png";
const std::string Graphics::clothesGraphic_185                   = "Clothes/Graphic (185).png";
const std::string Graphics::clothesGraphic_186                   = "Clothes/Graphic (186).png";
const std::string Graphics::clothesGraphic_187                   = "Clothes/Graphic (187).png";
const std::string Graphics::clothesGraphic_188                   = "Clothes/Graphic (188).png";
const std::string Graphics::clothesGraphic_189                   = "Clothes/Graphic (189).png";
const std::string Graphics::clothesGraphic_19                    = "Clothes/Graphic (19).png";
const std::string Graphics::clothesGraphic_190                   = "Clothes/Graphic (190).png";
const std::string Graphics::clothesGraphic_191                   = "Clothes/Graphic (191).png";
const std::string Graphics::clothesGraphic_192                   = "Clothes/Graphic (192).png";
const std::string Graphics::clothesGraphic_193                   = "Clothes/Graphic (193).png";
const std::string Graphics::clothesGraphic_194                   = "Clothes/Graphic (194).png";
const std::string Graphics::clothesGraphic_195                   = "Clothes/Graphic (195).png";
const std::string Graphics::clothesGraphic_196                   = "Clothes/Graphic (196).png";
const std::string Graphics::clothesGraphic_197                   = "Clothes/Graphic (197).png";
const std::string Graphics::clothesGraphic_198                   = "Clothes/Graphic (198).png";
const std::string Graphics::clothesGraphic_199                   = "Clothes/Graphic (199).png";
const std::string Graphics::clothesGraphic_20                    = "Clothes/Graphic (20).png";
const std::string Graphics::clothesGraphic_200                   = "Clothes/Graphic (200).png";
const std::string Graphics::clothesGraphic_201                   = "Clothes/Graphic (201).png";
const std::string Graphics::clothesGraphic_202                   = "Clothes/Graphic (202).png";
const std::string Graphics::clothesGraphic_203                   = "Clothes/Graphic (203).png";
const std::string Graphics::clothesGraphic_204                   = "Clothes/Graphic (204).png";
const std::string Graphics::clothesGraphic_205                   = "Clothes/Graphic (205).png";
const std::string Graphics::clothesGraphic_206                   = "Clothes/Graphic (206).png";
const std::string Graphics::clothesGraphic_207                   = "Clothes/Graphic (207).png";
const std::string Graphics::clothesGraphic_208                   = "Clothes/Graphic (208).png";
const std::string Graphics::clothesGraphic_209                   = "Clothes/Graphic (209).png";
const std::string Graphics::clothesGraphic_21                    = "Clothes/Graphic (21).png";
const std::string Graphics::clothesGraphic_210                   = "Clothes/Graphic (210).png";
const std::string Graphics::clothesGraphic_211                   = "Clothes/Graphic (211).png";
const std::string Graphics::clothesGraphic_212                   = "Clothes/Graphic (212).png";
const std::string Graphics::clothesGraphic_213                   = "Clothes/Graphic (213).png";
const std::string Graphics::clothesGraphic_214                   = "Clothes/Graphic (214).png";
const std::string Graphics::clothesGraphic_215                   = "Clothes/Graphic (215).png";
const std::string Graphics::clothesGraphic_216                   = "Clothes/Graphic (216).png";
const std::string Graphics::clothesGraphic_217                   = "Clothes/Graphic (217).png";
const std::string Graphics::clothesGraphic_218                   = "Clothes/Graphic (218).png";
const std::string Graphics::clothesGraphic_219                   = "Clothes/Graphic (219).png";
const std::string Graphics::clothesGraphic_22                    = "Clothes/Graphic (22).png";
const std::string Graphics::clothesGraphic_220                   = "Clothes/Graphic (220).png";
const std::string Graphics::clothesGraphic_221                   = "Clothes/Graphic (221).png";
const std::string Graphics::clothesGraphic_222                   = "Clothes/Graphic (222).png";
const std::string Graphics::clothesGraphic_223                   = "Clothes/Graphic (223).png";
const std::string Graphics::clothesGraphic_224                   = "Clothes/Graphic (224).png";
const std::string Graphics::clothesGraphic_225                   = "Clothes/Graphic (225).png";
const std::string Graphics::clothesGraphic_226                   = "Clothes/Graphic (226).png";
const std::string Graphics::clothesGraphic_227                   = "Clothes/Graphic (227).png";
const std::string Graphics::clothesGraphic_228                   = "Clothes/Graphic (228).png";
const std::string Graphics::clothesGraphic_229                   = "Clothes/Graphic (229).png";
const std::string Graphics::clothesGraphic_23                    = "Clothes/Graphic (23).png";
const std::string Graphics::clothesGraphic_230                   = "Clothes/Graphic (230).png";
const std::string Graphics::clothesGraphic_231                   = "Clothes/Graphic (231).png";
const std::string Graphics::clothesGraphic_232                   = "Clothes/Graphic (232).png";
const std::string Graphics::clothesGraphic_233                   = "Clothes/Graphic (233).png";
const std::string Graphics::clothesGraphic_234                   = "Clothes/Graphic (234).png";
const std::string Graphics::clothesGraphic_235                   = "Clothes/Graphic (235).png";
const std::string Graphics::clothesGraphic_236                   = "Clothes/Graphic (236).png";
const std::string Graphics::clothesGraphic_237                   = "Clothes/Graphic (237).png";
const std::string Graphics::clothesGraphic_238                   = "Clothes/Graphic (238).png";
const std::string Graphics::clothesGraphic_239                   = "Clothes/Graphic (239).png";
const std::string Graphics::clothesGraphic_24                    = "Clothes/Graphic (24).png";
const std::string Graphics::clothesGraphic_240                   = "Clothes/Graphic (240).png";
const std::string Graphics::clothesGraphic_241                   = "Clothes/Graphic (241).png";
const std::string Graphics::clothesGraphic_242                   = "Clothes/Graphic (242).png";
const std::string Graphics::clothesGraphic_243                   = "Clothes/Graphic (243).png";
const std::string Graphics::clothesGraphic_244                   = "Clothes/Graphic (244).png";
const std::string Graphics::clothesGraphic_245                   = "Clothes/Graphic (245).png";
const std::string Graphics::clothesGraphic_246                   = "Clothes/Graphic (246).png";
const std::string Graphics::clothesGraphic_247                   = "Clothes/Graphic (247).png";
const std::string Graphics::clothesGraphic_248                   = "Clothes/Graphic (248).png";
const std::string Graphics::clothesGraphic_249                   = "Clothes/Graphic (249).png";
const std::string Graphics::clothesGraphic_25                    = "Clothes/Graphic (25).png";
const std::string Graphics::clothesGraphic_250                   = "Clothes/Graphic (250).png";
const std::string Graphics::clothesGraphic_251                   = "Clothes/Graphic (251).png";
const std::string Graphics::clothesGraphic_252                   = "Clothes/Graphic (252).png";
const std::string Graphics::clothesGraphic_253                   = "Clothes/Graphic (253).png";
const std::string Graphics::clothesGraphic_254                   = "Clothes/Graphic (254).png";
const std::string Graphics::clothesGraphic_255                   = "Clothes/Graphic (255).png";
const std::string Graphics::clothesGraphic_256                   = "Clothes/Graphic (256).png";
const std::string Graphics::clothesGraphic_257                   = "Clothes/Graphic (257).png";
const std::string Graphics::clothesGraphic_258                   = "Clothes/Graphic (258).png";
const std::string Graphics::clothesGraphic_259                   = "Clothes/Graphic (259).png";
const std::string Graphics::clothesGraphic_26                    = "Clothes/Graphic (26).png";
const std::string Graphics::clothesGraphic_260                   = "Clothes/Graphic (260).png";
const std::string Graphics::clothesGraphic_261                   = "Clothes/Graphic (261).png";
const std::string Graphics::clothesGraphic_262                   = "Clothes/Graphic (262).png";
const std::string Graphics::clothesGraphic_263                   = "Clothes/Graphic (263).png";
const std::string Graphics::clothesGraphic_264                   = "Clothes/Graphic (264).png";
const std::string Graphics::clothesGraphic_265                   = "Clothes/Graphic (265).png";
const std::string Graphics::clothesGraphic_266                   = "Clothes/Graphic (266).png";
const std::string Graphics::clothesGraphic_267                   = "Clothes/Graphic (267).png";
const std::string Graphics::clothesGraphic_268                   = "Clothes/Graphic (268).png";
const std::string Graphics::clothesGraphic_269                   = "Clothes/Graphic (269).png";
const std::string Graphics::clothesGraphic_27                    = "Clothes/Graphic (27).png";
const std::string Graphics::clothesGraphic_270                   = "Clothes/Graphic (270).png";
const std::string Graphics::clothesGraphic_271                   = "Clothes/Graphic (271).png";
const std::string Graphics::clothesGraphic_272                   = "Clothes/Graphic (272).png";
const std::string Graphics::clothesGraphic_273                   = "Clothes/Graphic (273).png";
const std::string Graphics::clothesGraphic_274                   = "Clothes/Graphic (274).png";
const std::string Graphics::clothesGraphic_275                   = "Clothes/Graphic (275).png";
const std::string Graphics::clothesGraphic_276                   = "Clothes/Graphic (276).png";
const std::string Graphics::clothesGraphic_277                   = "Clothes/Graphic (277).png";
const std::string Graphics::clothesGraphic_278                   = "Clothes/Graphic (278).png";
const std::string Graphics::clothesGraphic_279                   = "Clothes/Graphic (279).png";
const std::string Graphics::clothesGraphic_28                    = "Clothes/Graphic (28).png";
const std::string Graphics::clothesGraphic_280                   = "Clothes/Graphic (280).png";
const std::string Graphics::clothesGraphic_281                   = "Clothes/Graphic (281).png";
const std::string Graphics::clothesGraphic_282                   = "Clothes/Graphic (282).png";
const std::string Graphics::clothesGraphic_283                   = "Clothes/Graphic (283).png";
const std::string Graphics::clothesGraphic_284                   = "Clothes/Graphic (284).png";
const std::string Graphics::clothesGraphic_285                   = "Clothes/Graphic (285).png";
const std::string Graphics::clothesGraphic_286                   = "Clothes/Graphic (286).png";
const std::string Graphics::clothesGraphic_287                   = "Clothes/Graphic (287).png";
const std::string Graphics::clothesGraphic_288                   = "Clothes/Graphic (288).png";
const std::string Graphics::clothesGraphic_289                   = "Clothes/Graphic (289).png";
const std::string Graphics::clothesGraphic_29                    = "Clothes/Graphic (29).png";
const std::string Graphics::clothesGraphic_290                   = "Clothes/Graphic (290).png";
const std::string Graphics::clothesGraphic_291                   = "Clothes/Graphic (291).png";
const std::string Graphics::clothesGraphic_292                   = "Clothes/Graphic (292).png";
const std::string Graphics::clothesGraphic_293                   = "Clothes/Graphic (293).png";
const std::string Graphics::clothesGraphic_294                   = "Clothes/Graphic (294).png";
const std::string Graphics::clothesGraphic_295                   = "Clothes/Graphic (295).png";
const std::string Graphics::clothesGraphic_296                   = "Clothes/Graphic (296).png";
const std::string Graphics::clothesGraphic_297                   = "Clothes/Graphic (297).png";
const std::string Graphics::clothesGraphic_298                   = "Clothes/Graphic (298).png";
const std::string Graphics::clothesGraphic_299                   = "Clothes/Graphic (299).png";
const std::string Graphics::clothesGraphic_30                    = "Clothes/Graphic (30).png";
const std::string Graphics::clothesGraphic_300                   = "Clothes/Graphic (300).png";
const std::string Graphics::clothesGraphic_301                   = "Clothes/Graphic (301).png";
const std::string Graphics::clothesGraphic_302                   = "Clothes/Graphic (302).png";
const std::string Graphics::clothesGraphic_303                   = "Clothes/Graphic (303).png";
const std::string Graphics::clothesGraphic_304                   = "Clothes/Graphic (304).png";
const std::string Graphics::clothesGraphic_305                   = "Clothes/Graphic (305).png";
const std::string Graphics::clothesGraphic_306                   = "Clothes/Graphic (306).png";
const std::string Graphics::clothesGraphic_307                   = "Clothes/Graphic (307).png";
const std::string Graphics::clothesGraphic_308                   = "Clothes/Graphic (308).png";
const std::string Graphics::clothesGraphic_309                   = "Clothes/Graphic (309).png";
const std::string Graphics::clothesGraphic_31                    = "Clothes/Graphic (31).png";
const std::string Graphics::clothesGraphic_310                   = "Clothes/Graphic (310).png";
const std::string Graphics::clothesGraphic_311                   = "Clothes/Graphic (311).png";
const std::string Graphics::clothesGraphic_312                   = "Clothes/Graphic (312).png";
const std::string Graphics::clothesGraphic_313                   = "Clothes/Graphic (313).png";
const std::string Graphics::clothesGraphic_314                   = "Clothes/Graphic (314).png";
const std::string Graphics::clothesGraphic_315                   = "Clothes/Graphic (315).png";
const std::string Graphics::clothesGraphic_316                   = "Clothes/Graphic (316).png";
const std::string Graphics::clothesGraphic_317                   = "Clothes/Graphic (317).png";
const std::string Graphics::clothesGraphic_318                   = "Clothes/Graphic (318).png";
const std::string Graphics::clothesGraphic_319                   = "Clothes/Graphic (319).png";
const std::string Graphics::clothesGraphic_32                    = "Clothes/Graphic (32).png";
const std::string Graphics::clothesGraphic_320                   = "Clothes/Graphic (320).png";
const std::string Graphics::clothesGraphic_321                   = "Clothes/Graphic (321).png";
const std::string Graphics::clothesGraphic_322                   = "Clothes/Graphic (322).png";
const std::string Graphics::clothesGraphic_323                   = "Clothes/Graphic (323).png";
const std::string Graphics::clothesGraphic_324                   = "Clothes/Graphic (324).png";
const std::string Graphics::clothesGraphic_325                   = "Clothes/Graphic (325).png";
const std::string Graphics::clothesGraphic_326                   = "Clothes/Graphic (326).png";
const std::string Graphics::clothesGraphic_327                   = "Clothes/Graphic (327).png";
const std::string Graphics::clothesGraphic_328                   = "Clothes/Graphic (328).png";
const std::string Graphics::clothesGraphic_329                   = "Clothes/Graphic (329).png";
const std::string Graphics::clothesGraphic_33                    = "Clothes/Graphic (33).png";
const std::string Graphics::clothesGraphic_330                   = "Clothes/Graphic (330).png";
const std::string Graphics::clothesGraphic_331                   = "Clothes/Graphic (331).png";
const std::string Graphics::clothesGraphic_332                   = "Clothes/Graphic (332).png";
const std::string Graphics::clothesGraphic_333                   = "Clothes/Graphic (333).png";
const std::string Graphics::clothesGraphic_334                   = "Clothes/Graphic (334).png";
const std::string Graphics::clothesGraphic_335                   = "Clothes/Graphic (335).png";
const std::string Graphics::clothesGraphic_336                   = "Clothes/Graphic (336).png";
const std::string Graphics::clothesGraphic_337                   = "Clothes/Graphic (337).png";
const std::string Graphics::clothesGraphic_338                   = "Clothes/Graphic (338).png";
const std::string Graphics::clothesGraphic_339                   = "Clothes/Graphic (339).png";
const std::string Graphics::clothesGraphic_34                    = "Clothes/Graphic (34).png";
const std::string Graphics::clothesGraphic_340                   = "Clothes/Graphic (340).png";
const std::string Graphics::clothesGraphic_341                   = "Clothes/Graphic (341).png";
const std::string Graphics::clothesGraphic_342                   = "Clothes/Graphic (342).png";
const std::string Graphics::clothesGraphic_343                   = "Clothes/Graphic (343).png";
const std::string Graphics::clothesGraphic_344                   = "Clothes/Graphic (344).png";
const std::string Graphics::clothesGraphic_345                   = "Clothes/Graphic (345).png";
const std::string Graphics::clothesGraphic_346                   = "Clothes/Graphic (346).png";
const std::string Graphics::clothesGraphic_347                   = "Clothes/Graphic (347).png";
const std::string Graphics::clothesGraphic_348                   = "Clothes/Graphic (348).png";
const std::string Graphics::clothesGraphic_349                   = "Clothes/Graphic (349).png";
const std::string Graphics::clothesGraphic_35                    = "Clothes/Graphic (35).png";
const std::string Graphics::clothesGraphic_350                   = "Clothes/Graphic (350).png";
const std::string Graphics::clothesGraphic_351                   = "Clothes/Graphic (351).png";
const std::string Graphics::clothesGraphic_352                   = "Clothes/Graphic (352).png";
const std::string Graphics::clothesGraphic_353                   = "Clothes/Graphic (353).png";
const std::string Graphics::clothesGraphic_354                   = "Clothes/Graphic (354).png";
const std::string Graphics::clothesGraphic_355                   = "Clothes/Graphic (355).png";
const std::string Graphics::clothesGraphic_356                   = "Clothes/Graphic (356).png";
const std::string Graphics::clothesGraphic_357                   = "Clothes/Graphic (357).png";
const std::string Graphics::clothesGraphic_358                   = "Clothes/Graphic (358).png";
const std::string Graphics::clothesGraphic_359                   = "Clothes/Graphic (359).png";
const std::string Graphics::clothesGraphic_36                    = "Clothes/Graphic (36).png";
const std::string Graphics::clothesGraphic_360                   = "Clothes/Graphic (360).png";
const std::string Graphics::clothesGraphic_361                   = "Clothes/Graphic (361).png";
const std::string Graphics::clothesGraphic_362                   = "Clothes/Graphic (362).png";
const std::string Graphics::clothesGraphic_363                   = "Clothes/Graphic (363).png";
const std::string Graphics::clothesGraphic_364                   = "Clothes/Graphic (364).png";
const std::string Graphics::clothesGraphic_365                   = "Clothes/Graphic (365).png";
const std::string Graphics::clothesGraphic_366                   = "Clothes/Graphic (366).png";
const std::string Graphics::clothesGraphic_367                   = "Clothes/Graphic (367).png";
const std::string Graphics::clothesGraphic_368                   = "Clothes/Graphic (368).png";
const std::string Graphics::clothesGraphic_369                   = "Clothes/Graphic (369).png";
const std::string Graphics::clothesGraphic_37                    = "Clothes/Graphic (37).png";
const std::string Graphics::clothesGraphic_370                   = "Clothes/Graphic (370).png";
const std::string Graphics::clothesGraphic_371                   = "Clothes/Graphic (371).png";
const std::string Graphics::clothesGraphic_372                   = "Clothes/Graphic (372).png";
const std::string Graphics::clothesGraphic_373                   = "Clothes/Graphic (373).png";
const std::string Graphics::clothesGraphic_374                   = "Clothes/Graphic (374).png";
const std::string Graphics::clothesGraphic_375                   = "Clothes/Graphic (375).png";
const std::string Graphics::clothesGraphic_376                   = "Clothes/Graphic (376).png";
const std::string Graphics::clothesGraphic_377                   = "Clothes/Graphic (377).png";
const std::string Graphics::clothesGraphic_378                   = "Clothes/Graphic (378).png";
const std::string Graphics::clothesGraphic_379                   = "Clothes/Graphic (379).png";
const std::string Graphics::clothesGraphic_38                    = "Clothes/Graphic (38).png";
const std::string Graphics::clothesGraphic_380                   = "Clothes/Graphic (380).png";
const std::string Graphics::clothesGraphic_381                   = "Clothes/Graphic (381).png";
const std::string Graphics::clothesGraphic_382                   = "Clothes/Graphic (382).png";
const std::string Graphics::clothesGraphic_383                   = "Clothes/Graphic (383).png";
const std::string Graphics::clothesGraphic_384                   = "Clothes/Graphic (384).png";
const std::string Graphics::clothesGraphic_385                   = "Clothes/Graphic (385).png";
const std::string Graphics::clothesGraphic_386                   = "Clothes/Graphic (386).png";
const std::string Graphics::clothesGraphic_387                   = "Clothes/Graphic (387).png";
const std::string Graphics::clothesGraphic_388                   = "Clothes/Graphic (388).png";
const std::string Graphics::clothesGraphic_389                   = "Clothes/Graphic (389).png";
const std::string Graphics::clothesGraphic_39                    = "Clothes/Graphic (39).png";
const std::string Graphics::clothesGraphic_390                   = "Clothes/Graphic (390).png";
const std::string Graphics::clothesGraphic_391                   = "Clothes/Graphic (391).png";
const std::string Graphics::clothesGraphic_392                   = "Clothes/Graphic (392).png";
const std::string Graphics::clothesGraphic_393                   = "Clothes/Graphic (393).png";
const std::string Graphics::clothesGraphic_394                   = "Clothes/Graphic (394).png";
const std::string Graphics::clothesGraphic_395                   = "Clothes/Graphic (395).png";
const std::string Graphics::clothesGraphic_396                   = "Clothes/Graphic (396).png";
const std::string Graphics::clothesGraphic_397                   = "Clothes/Graphic (397).png";
const std::string Graphics::clothesGraphic_398                   = "Clothes/Graphic (398).png";
const std::string Graphics::clothesGraphic_399                   = "Clothes/Graphic (399).png";
const std::string Graphics::clothesGraphic_4                     = "Clothes/Graphic (4).png";
const std::string Graphics::clothesGraphic_40                    = "Clothes/Graphic (40).png";
const std::string Graphics::clothesGraphic_400                   = "Clothes/Graphic (400).png";
const std::string Graphics::clothesGraphic_401                   = "Clothes/Graphic (401).png";
const std::string Graphics::clothesGraphic_402                   = "Clothes/Graphic (402).png";
const std::string Graphics::clothesGraphic_403                   = "Clothes/Graphic (403).png";
const std::string Graphics::clothesGraphic_404                   = "Clothes/Graphic (404).png";
const std::string Graphics::clothesGraphic_405                   = "Clothes/Graphic (405).png";
const std::string Graphics::clothesGraphic_406                   = "Clothes/Graphic (406).png";
const std::string Graphics::clothesGraphic_407                   = "Clothes/Graphic (407).png";
const std::string Graphics::clothesGraphic_408                   = "Clothes/Graphic (408).png";
const std::string Graphics::clothesGraphic_409                   = "Clothes/Graphic (409).png";
const std::string Graphics::clothesGraphic_41                    = "Clothes/Graphic (41).png";
const std::string Graphics::clothesGraphic_410                   = "Clothes/Graphic (410).png";
const std::string Graphics::clothesGraphic_411                   = "Clothes/Graphic (411).png";
const std::string Graphics::clothesGraphic_412                   = "Clothes/Graphic (412).png";
const std::string Graphics::clothesGraphic_413                   = "Clothes/Graphic (413).png";
const std::string Graphics::clothesGraphic_414                   = "Clothes/Graphic (414).png";
const std::string Graphics::clothesGraphic_415                   = "Clothes/Graphic (415).png";
const std::string Graphics::clothesGraphic_416                   = "Clothes/Graphic (416).png";
const std::string Graphics::clothesGraphic_417                   = "Clothes/Graphic (417).png";
const std::string Graphics::clothesGraphic_418                   = "Clothes/Graphic (418).png";
const std::string Graphics::clothesGraphic_419                   = "Clothes/Graphic (419).png";
const std::string Graphics::clothesGraphic_42                    = "Clothes/Graphic (42).png";
const std::string Graphics::clothesGraphic_420                   = "Clothes/Graphic (420).png";
const std::string Graphics::clothesGraphic_421                   = "Clothes/Graphic (421).png";
const std::string Graphics::clothesGraphic_422                   = "Clothes/Graphic (422).png";
const std::string Graphics::clothesGraphic_423                   = "Clothes/Graphic (423).png";
const std::string Graphics::clothesGraphic_424                   = "Clothes/Graphic (424).png";
const std::string Graphics::clothesGraphic_425                   = "Clothes/Graphic (425).png";
const std::string Graphics::clothesGraphic_426                   = "Clothes/Graphic (426).png";
const std::string Graphics::clothesGraphic_427                   = "Clothes/Graphic (427).png";
const std::string Graphics::clothesGraphic_428                   = "Clothes/Graphic (428).png";
const std::string Graphics::clothesGraphic_429                   = "Clothes/Graphic (429).png";
const std::string Graphics::clothesGraphic_43                    = "Clothes/Graphic (43).png";
const std::string Graphics::clothesGraphic_430                   = "Clothes/Graphic (430).png";
const std::string Graphics::clothesGraphic_431                   = "Clothes/Graphic (431).png";
const std::string Graphics::clothesGraphic_432                   = "Clothes/Graphic (432).png";
const std::string Graphics::clothesGraphic_433                   = "Clothes/Graphic (433).png";
const std::string Graphics::clothesGraphic_434                   = "Clothes/Graphic (434).png";
const std::string Graphics::clothesGraphic_435                   = "Clothes/Graphic (435).png";
const std::string Graphics::clothesGraphic_436                   = "Clothes/Graphic (436).png";
const std::string Graphics::clothesGraphic_437                   = "Clothes/Graphic (437).png";
const std::string Graphics::clothesGraphic_438                   = "Clothes/Graphic (438).png";
const std::string Graphics::clothesGraphic_439                   = "Clothes/Graphic (439).png";
const std::string Graphics::clothesGraphic_44                    = "Clothes/Graphic (44).png";
const std::string Graphics::clothesGraphic_440                   = "Clothes/Graphic (440).png";
const std::string Graphics::clothesGraphic_441                   = "Clothes/Graphic (441).png";
const std::string Graphics::clothesGraphic_442                   = "Clothes/Graphic (442).png";
const std::string Graphics::clothesGraphic_443                   = "Clothes/Graphic (443).png";
const std::string Graphics::clothesGraphic_444                   = "Clothes/Graphic (444).png";
const std::string Graphics::clothesGraphic_445                   = "Clothes/Graphic (445).png";
const std::string Graphics::clothesGraphic_446                   = "Clothes/Graphic (446).png";
const std::string Graphics::clothesGraphic_447                   = "Clothes/Graphic (447).png";
const std::string Graphics::clothesGraphic_448                   = "Clothes/Graphic (448).png";
const std::string Graphics::clothesGraphic_449                   = "Clothes/Graphic (449).png";
const std::string Graphics::clothesGraphic_45                    = "Clothes/Graphic (45).png";
const std::string Graphics::clothesGraphic_450                   = "Clothes/Graphic (450).png";
const std::string Graphics::clothesGraphic_451                   = "Clothes/Graphic (451).png";
const std::string Graphics::clothesGraphic_452                   = "Clothes/Graphic (452).png";
const std::string Graphics::clothesGraphic_453                   = "Clothes/Graphic (453).png";
const std::string Graphics::clothesGraphic_454                   = "Clothes/Graphic (454).png";
const std::string Graphics::clothesGraphic_455                   = "Clothes/Graphic (455).png";
const std::string Graphics::clothesGraphic_456                   = "Clothes/Graphic (456).png";
const std::string Graphics::clothesGraphic_457                   = "Clothes/Graphic (457).png";
const std::string Graphics::clothesGraphic_458                   = "Clothes/Graphic (458).png";
const std::string Graphics::clothesGraphic_459                   = "Clothes/Graphic (459).png";
const std::string Graphics::clothesGraphic_46                    = "Clothes/Graphic (46).png";
const std::string Graphics::clothesGraphic_460                   = "Clothes/Graphic (460).png";
const std::string Graphics::clothesGraphic_461                   = "Clothes/Graphic (461).png";
const std::string Graphics::clothesGraphic_462                   = "Clothes/Graphic (462).png";
const std::string Graphics::clothesGraphic_463                   = "Clothes/Graphic (463).png";
const std::string Graphics::clothesGraphic_464                   = "Clothes/Graphic (464).png";
const std::string Graphics::clothesGraphic_465                   = "Clothes/Graphic (465).png";
const std::string Graphics::clothesGraphic_466                   = "Clothes/Graphic (466).png";
const std::string Graphics::clothesGraphic_467                   = "Clothes/Graphic (467).png";
const std::string Graphics::clothesGraphic_468                   = "Clothes/Graphic (468).png";
const std::string Graphics::clothesGraphic_469                   = "Clothes/Graphic (469).png";
const std::string Graphics::clothesGraphic_47                    = "Clothes/Graphic (47).png";
const std::string Graphics::clothesGraphic_470                   = "Clothes/Graphic (470).png";
const std::string Graphics::clothesGraphic_471                   = "Clothes/Graphic (471).png";
const std::string Graphics::clothesGraphic_472                   = "Clothes/Graphic (472).png";
const std::string Graphics::clothesGraphic_473                   = "Clothes/Graphic (473).png";
const std::string Graphics::clothesGraphic_474                   = "Clothes/Graphic (474).png";
const std::string Graphics::clothesGraphic_475                   = "Clothes/Graphic (475).png";
const std::string Graphics::clothesGraphic_476                   = "Clothes/Graphic (476).png";
const std::string Graphics::clothesGraphic_477                   = "Clothes/Graphic (477).png";
const std::string Graphics::clothesGraphic_478                   = "Clothes/Graphic (478).png";
const std::string Graphics::clothesGraphic_479                   = "Clothes/Graphic (479).png";
const std::string Graphics::clothesGraphic_48                    = "Clothes/Graphic (48).png";
const std::string Graphics::clothesGraphic_480                   = "Clothes/Graphic (480).png";
const std::string Graphics::clothesGraphic_481                   = "Clothes/Graphic (481).png";
const std::string Graphics::clothesGraphic_482                   = "Clothes/Graphic (482).png";
const std::string Graphics::clothesGraphic_483                   = "Clothes/Graphic (483).png";
const std::string Graphics::clothesGraphic_484                   = "Clothes/Graphic (484).png";
const std::string Graphics::clothesGraphic_485                   = "Clothes/Graphic (485).png";
const std::string Graphics::clothesGraphic_486                   = "Clothes/Graphic (486).png";
const std::string Graphics::clothesGraphic_487                   = "Clothes/Graphic (487).png";
const std::string Graphics::clothesGraphic_488                   = "Clothes/Graphic (488).png";
const std::string Graphics::clothesGraphic_489                   = "Clothes/Graphic (489).png";
const std::string Graphics::clothesGraphic_49                    = "Clothes/Graphic (49).png";
const std::string Graphics::clothesGraphic_490                   = "Clothes/Graphic (490).png";
const std::string Graphics::clothesGraphic_491                   = "Clothes/Graphic (491).png";
const std::string Graphics::clothesGraphic_492                   = "Clothes/Graphic (492).png";
const std::string Graphics::clothesGraphic_493                   = "Clothes/Graphic (493).png";
const std::string Graphics::clothesGraphic_494                   = "Clothes/Graphic (494).png";
const std::string Graphics::clothesGraphic_495                   = "Clothes/Graphic (495).png";
const std::string Graphics::clothesGraphic_496                   = "Clothes/Graphic (496).png";
const std::string Graphics::clothesGraphic_497                   = "Clothes/Graphic (497).png";
const std::string Graphics::clothesGraphic_498                   = "Clothes/Graphic (498).png";
const std::string Graphics::clothesGraphic_499                   = "Clothes/Graphic (499).png";
const std::string Graphics::clothesGraphic_5                     = "Clothes/Graphic (5).png";
const std::string Graphics::clothesGraphic_50                    = "Clothes/Graphic (50).png";
const std::string Graphics::clothesGraphic_500                   = "Clothes/Graphic (500).png";
const std::string Graphics::clothesGraphic_501                   = "Clothes/Graphic (501).png";
const std::string Graphics::clothesGraphic_502                   = "Clothes/Graphic (502).png";
const std::string Graphics::clothesGraphic_503                   = "Clothes/Graphic (503).png";
const std::string Graphics::clothesGraphic_504                   = "Clothes/Graphic (504).png";
const std::string Graphics::clothesGraphic_505                   = "Clothes/Graphic (505).png";
const std::string Graphics::clothesGraphic_506                   = "Clothes/Graphic (506).png";
const std::string Graphics::clothesGraphic_507                   = "Clothes/Graphic (507).png";
const std::string Graphics::clothesGraphic_508                   = "Clothes/Graphic (508).png";
const std::string Graphics::clothesGraphic_509                   = "Clothes/Graphic (509).png";
const std::string Graphics::clothesGraphic_51                    = "Clothes/Graphic (51).png";
const std::string Graphics::clothesGraphic_510                   = "Clothes/Graphic (510).png";
const std::string Graphics::clothesGraphic_511                   = "Clothes/Graphic (511).png";
const std::string Graphics::clothesGraphic_512                   = "Clothes/Graphic (512).png";
const std::string Graphics::clothesGraphic_513                   = "Clothes/Graphic (513).png";
const std::string Graphics::clothesGraphic_514                   = "Clothes/Graphic (514).png";
const std::string Graphics::clothesGraphic_515                   = "Clothes/Graphic (515).png";
const std::string Graphics::clothesGraphic_516                   = "Clothes/Graphic (516).png";
const std::string Graphics::clothesGraphic_517                   = "Clothes/Graphic (517).png";
const std::string Graphics::clothesGraphic_518                   = "Clothes/Graphic (518).png";
const std::string Graphics::clothesGraphic_519                   = "Clothes/Graphic (519).png";
const std::string Graphics::clothesGraphic_52                    = "Clothes/Graphic (52).png";
const std::string Graphics::clothesGraphic_520                   = "Clothes/Graphic (520).png";
const std::string Graphics::clothesGraphic_521                   = "Clothes/Graphic (521).png";
const std::string Graphics::clothesGraphic_522                   = "Clothes/Graphic (522).png";
const std::string Graphics::clothesGraphic_523                   = "Clothes/Graphic (523).png";
const std::string Graphics::clothesGraphic_524                   = "Clothes/Graphic (524).png";
const std::string Graphics::clothesGraphic_525                   = "Clothes/Graphic (525).png";
const std::string Graphics::clothesGraphic_526                   = "Clothes/Graphic (526).png";
const std::string Graphics::clothesGraphic_527                   = "Clothes/Graphic (527).png";
const std::string Graphics::clothesGraphic_528                   = "Clothes/Graphic (528).png";
const std::string Graphics::clothesGraphic_529                   = "Clothes/Graphic (529).png";
const std::string Graphics::clothesGraphic_53                    = "Clothes/Graphic (53).png";
const std::string Graphics::clothesGraphic_530                   = "Clothes/Graphic (530).png";
const std::string Graphics::clothesGraphic_531                   = "Clothes/Graphic (531).png";
const std::string Graphics::clothesGraphic_532                   = "Clothes/Graphic (532).png";
const std::string Graphics::clothesGraphic_533                   = "Clothes/Graphic (533).png";
const std::string Graphics::clothesGraphic_534                   = "Clothes/Graphic (534).png";
const std::string Graphics::clothesGraphic_535                   = "Clothes/Graphic (535).png";
const std::string Graphics::clothesGraphic_536                   = "Clothes/Graphic (536).png";
const std::string Graphics::clothesGraphic_537                   = "Clothes/Graphic (537).png";
const std::string Graphics::clothesGraphic_538                   = "Clothes/Graphic (538).png";
const std::string Graphics::clothesGraphic_539                   = "Clothes/Graphic (539).png";
const std::string Graphics::clothesGraphic_54                    = "Clothes/Graphic (54).png";
const std::string Graphics::clothesGraphic_540                   = "Clothes/Graphic (540).png";
const std::string Graphics::clothesGraphic_541                   = "Clothes/Graphic (541).png";
const std::string Graphics::clothesGraphic_542                   = "Clothes/Graphic (542).png";
const std::string Graphics::clothesGraphic_543                   = "Clothes/Graphic (543).png";
const std::string Graphics::clothesGraphic_544                   = "Clothes/Graphic (544).png";
const std::string Graphics::clothesGraphic_545                   = "Clothes/Graphic (545).png";
const std::string Graphics::clothesGraphic_546                   = "Clothes/Graphic (546).png";
const std::string Graphics::clothesGraphic_547                   = "Clothes/Graphic (547).png";
const std::string Graphics::clothesGraphic_548                   = "Clothes/Graphic (548).png";
const std::string Graphics::clothesGraphic_549                   = "Clothes/Graphic (549).png";
const std::string Graphics::clothesGraphic_55                    = "Clothes/Graphic (55).png";
const std::string Graphics::clothesGraphic_550                   = "Clothes/Graphic (550).png";
const std::string Graphics::clothesGraphic_551                   = "Clothes/Graphic (551).png";
const std::string Graphics::clothesGraphic_552                   = "Clothes/Graphic (552).png";
const std::string Graphics::clothesGraphic_553                   = "Clothes/Graphic (553).png";
const std::string Graphics::clothesGraphic_554                   = "Clothes/Graphic (554).png";
const std::string Graphics::clothesGraphic_555                   = "Clothes/Graphic (555).png";
const std::string Graphics::clothesGraphic_556                   = "Clothes/Graphic (556).png";
const std::string Graphics::clothesGraphic_557                   = "Clothes/Graphic (557).png";
const std::string Graphics::clothesGraphic_558                   = "Clothes/Graphic (558).png";
const std::string Graphics::clothesGraphic_559                   = "Clothes/Graphic (559).png";
const std::string Graphics::clothesGraphic_56                    = "Clothes/Graphic (56).png";
const std::string Graphics::clothesGraphic_560                   = "Clothes/Graphic (560).png";
const std::string Graphics::clothesGraphic_561                   = "Clothes/Graphic (561).png";
const std::string Graphics::clothesGraphic_562                   = "Clothes/Graphic (562).png";
const std::string Graphics::clothesGraphic_563                   = "Clothes/Graphic (563).png";
const std::string Graphics::clothesGraphic_564                   = "Clothes/Graphic (564).png";
const std::string Graphics::clothesGraphic_565                   = "Clothes/Graphic (565).png";
const std::string Graphics::clothesGraphic_566                   = "Clothes/Graphic (566).png";
const std::string Graphics::clothesGraphic_567                   = "Clothes/Graphic (567).png";
const std::string Graphics::clothesGraphic_568                   = "Clothes/Graphic (568).png";
const std::string Graphics::clothesGraphic_569                   = "Clothes/Graphic (569).png";
const std::string Graphics::clothesGraphic_57                    = "Clothes/Graphic (57).png";
const std::string Graphics::clothesGraphic_570                   = "Clothes/Graphic (570).png";
const std::string Graphics::clothesGraphic_571                   = "Clothes/Graphic (571).png";
const std::string Graphics::clothesGraphic_572                   = "Clothes/Graphic (572).png";
const std::string Graphics::clothesGraphic_573                   = "Clothes/Graphic (573).png";
const std::string Graphics::clothesGraphic_574                   = "Clothes/Graphic (574).png";
const std::string Graphics::clothesGraphic_575                   = "Clothes/Graphic (575).png";
const std::string Graphics::clothesGraphic_576                   = "Clothes/Graphic (576).png";
const std::string Graphics::clothesGraphic_577                   = "Clothes/Graphic (577).png";
const std::string Graphics::clothesGraphic_578                   = "Clothes/Graphic (578).png";
const std::string Graphics::clothesGraphic_579                   = "Clothes/Graphic (579).png";
const std::string Graphics::clothesGraphic_58                    = "Clothes/Graphic (58).png";
const std::string Graphics::clothesGraphic_580                   = "Clothes/Graphic (580).png";
const std::string Graphics::clothesGraphic_581                   = "Clothes/Graphic (581).png";
const std::string Graphics::clothesGraphic_582                   = "Clothes/Graphic (582).png";
const std::string Graphics::clothesGraphic_583                   = "Clothes/Graphic (583).png";
const std::string Graphics::clothesGraphic_584                   = "Clothes/Graphic (584).png";
const std::string Graphics::clothesGraphic_585                   = "Clothes/Graphic (585).png";
const std::string Graphics::clothesGraphic_586                   = "Clothes/Graphic (586).png";
const std::string Graphics::clothesGraphic_587                   = "Clothes/Graphic (587).png";
const std::string Graphics::clothesGraphic_588                   = "Clothes/Graphic (588).png";
const std::string Graphics::clothesGraphic_589                   = "Clothes/Graphic (589).png";
const std::string Graphics::clothesGraphic_59                    = "Clothes/Graphic (59).png";
const std::string Graphics::clothesGraphic_590                   = "Clothes/Graphic (590).png";
const std::string Graphics::clothesGraphic_591                   = "Clothes/Graphic (591).png";
const std::string Graphics::clothesGraphic_592                   = "Clothes/Graphic (592).png";
const std::string Graphics::clothesGraphic_593                   = "Clothes/Graphic (593).png";
const std::string Graphics::clothesGraphic_594                   = "Clothes/Graphic (594).png";
const std::string Graphics::clothesGraphic_595                   = "Clothes/Graphic (595).png";
const std::string Graphics::clothesGraphic_596                   = "Clothes/Graphic (596).png";
const std::string Graphics::clothesGraphic_597                   = "Clothes/Graphic (597).png";
const std::string Graphics::clothesGraphic_598                   = "Clothes/Graphic (598).png";
const std::string Graphics::clothesGraphic_599                   = "Clothes/Graphic (599).png";
const std::string Graphics::clothesGraphic_6                     = "Clothes/Graphic (6).png";
const std::string Graphics::clothesGraphic_60                    = "Clothes/Graphic (60).png";
const std::string Graphics::clothesGraphic_600                   = "Clothes/Graphic (600).png";
const std::string Graphics::clothesGraphic_601                   = "Clothes/Graphic (601).png";
const std::string Graphics::clothesGraphic_602                   = "Clothes/Graphic (602).png";
const std::string Graphics::clothesGraphic_603                   = "Clothes/Graphic (603).png";
const std::string Graphics::clothesGraphic_604                   = "Clothes/Graphic (604).png";
const std::string Graphics::clothesGraphic_605                   = "Clothes/Graphic (605).png";
const std::string Graphics::clothesGraphic_606                   = "Clothes/Graphic (606).png";
const std::string Graphics::clothesGraphic_607                   = "Clothes/Graphic (607).png";
const std::string Graphics::clothesGraphic_608                   = "Clothes/Graphic (608).png";
const std::string Graphics::clothesGraphic_609                   = "Clothes/Graphic (609).png";
const std::string Graphics::clothesGraphic_61                    = "Clothes/Graphic (61).png";
const std::string Graphics::clothesGraphic_610                   = "Clothes/Graphic (610).png";
const std::string Graphics::clothesGraphic_611                   = "Clothes/Graphic (611).png";
const std::string Graphics::clothesGraphic_612                   = "Clothes/Graphic (612).png";
const std::string Graphics::clothesGraphic_613                   = "Clothes/Graphic (613).png";
const std::string Graphics::clothesGraphic_614                   = "Clothes/Graphic (614).png";
const std::string Graphics::clothesGraphic_615                   = "Clothes/Graphic (615).png";
const std::string Graphics::clothesGraphic_616                   = "Clothes/Graphic (616).png";
const std::string Graphics::clothesGraphic_617                   = "Clothes/Graphic (617).png";
const std::string Graphics::clothesGraphic_618                   = "Clothes/Graphic (618).png";
const std::string Graphics::clothesGraphic_619                   = "Clothes/Graphic (619).png";
const std::string Graphics::clothesGraphic_62                    = "Clothes/Graphic (62).png";
const std::string Graphics::clothesGraphic_620                   = "Clothes/Graphic (620).png";
const std::string Graphics::clothesGraphic_621                   = "Clothes/Graphic (621).png";
const std::string Graphics::clothesGraphic_622                   = "Clothes/Graphic (622).png";
const std::string Graphics::clothesGraphic_623                   = "Clothes/Graphic (623).png";
const std::string Graphics::clothesGraphic_624                   = "Clothes/Graphic (624).png";
const std::string Graphics::clothesGraphic_625                   = "Clothes/Graphic (625).png";
const std::string Graphics::clothesGraphic_626                   = "Clothes/Graphic (626).png";
const std::string Graphics::clothesGraphic_627                   = "Clothes/Graphic (627).png";
const std::string Graphics::clothesGraphic_628                   = "Clothes/Graphic (628).png";
const std::string Graphics::clothesGraphic_629                   = "Clothes/Graphic (629).png";
const std::string Graphics::clothesGraphic_63                    = "Clothes/Graphic (63).png";
const std::string Graphics::clothesGraphic_630                   = "Clothes/Graphic (630).png";
const std::string Graphics::clothesGraphic_631                   = "Clothes/Graphic (631).png";
const std::string Graphics::clothesGraphic_632                   = "Clothes/Graphic (632).png";
const std::string Graphics::clothesGraphic_633                   = "Clothes/Graphic (633).png";
const std::string Graphics::clothesGraphic_634                   = "Clothes/Graphic (634).png";
const std::string Graphics::clothesGraphic_635                   = "Clothes/Graphic (635).png";
const std::string Graphics::clothesGraphic_636                   = "Clothes/Graphic (636).png";
const std::string Graphics::clothesGraphic_637                   = "Clothes/Graphic (637).png";
const std::string Graphics::clothesGraphic_638                   = "Clothes/Graphic (638).png";
const std::string Graphics::clothesGraphic_639                   = "Clothes/Graphic (639).png";
const std::string Graphics::clothesGraphic_64                    = "Clothes/Graphic (64).png";
const std::string Graphics::clothesGraphic_640                   = "Clothes/Graphic (640).png";
const std::string Graphics::clothesGraphic_641                   = "Clothes/Graphic (641).png";
const std::string Graphics::clothesGraphic_642                   = "Clothes/Graphic (642).png";
const std::string Graphics::clothesGraphic_643                   = "Clothes/Graphic (643).png";
const std::string Graphics::clothesGraphic_644                   = "Clothes/Graphic (644).png";
const std::string Graphics::clothesGraphic_645                   = "Clothes/Graphic (645).png";
const std::string Graphics::clothesGraphic_646                   = "Clothes/Graphic (646).png";
const std::string Graphics::clothesGraphic_647                   = "Clothes/Graphic (647).png";
const std::string Graphics::clothesGraphic_648                   = "Clothes/Graphic (648).png";
const std::string Graphics::clothesGraphic_649                   = "Clothes/Graphic (649).png";
const std::string Graphics::clothesGraphic_65                    = "Clothes/Graphic (65).png";
const std::string Graphics::clothesGraphic_650                   = "Clothes/Graphic (650).png";
const std::string Graphics::clothesGraphic_651                   = "Clothes/Graphic (651).png";
const std::string Graphics::clothesGraphic_652                   = "Clothes/Graphic (652).png";
const std::string Graphics::clothesGraphic_653                   = "Clothes/Graphic (653).png";
const std::string Graphics::clothesGraphic_654                   = "Clothes/Graphic (654).png";
const std::string Graphics::clothesGraphic_655                   = "Clothes/Graphic (655).png";
const std::string Graphics::clothesGraphic_656                   = "Clothes/Graphic (656).png";
const std::string Graphics::clothesGraphic_657                   = "Clothes/Graphic (657).png";
const std::string Graphics::clothesGraphic_658                   = "Clothes/Graphic (658).png";
const std::string Graphics::clothesGraphic_659                   = "Clothes/Graphic (659).png";
const std::string Graphics::clothesGraphic_66                    = "Clothes/Graphic (66).png";
const std::string Graphics::clothesGraphic_660                   = "Clothes/Graphic (660).png";
const std::string Graphics::clothesGraphic_661                   = "Clothes/Graphic (661).png";
const std::string Graphics::clothesGraphic_662                   = "Clothes/Graphic (662).png";
const std::string Graphics::clothesGraphic_663                   = "Clothes/Graphic (663).png";
const std::string Graphics::clothesGraphic_664                   = "Clothes/Graphic (664).png";
const std::string Graphics::clothesGraphic_665                   = "Clothes/Graphic (665).png";
const std::string Graphics::clothesGraphic_666                   = "Clothes/Graphic (666).png";
const std::string Graphics::clothesGraphic_667                   = "Clothes/Graphic (667).png";
const std::string Graphics::clothesGraphic_668                   = "Clothes/Graphic (668).png";
const std::string Graphics::clothesGraphic_669                   = "Clothes/Graphic (669).png";
const std::string Graphics::clothesGraphic_67                    = "Clothes/Graphic (67).png";
const std::string Graphics::clothesGraphic_670                   = "Clothes/Graphic (670).png";
const std::string Graphics::clothesGraphic_671                   = "Clothes/Graphic (671).png";
const std::string Graphics::clothesGraphic_672                   = "Clothes/Graphic (672).png";
const std::string Graphics::clothesGraphic_673                   = "Clothes/Graphic (673).png";
const std::string Graphics::clothesGraphic_674                   = "Clothes/Graphic (674).png";
const std::string Graphics::clothesGraphic_675                   = "Clothes/Graphic (675).png";
const std::string Graphics::clothesGraphic_676                   = "Clothes/Graphic (676).png";
const std::string Graphics::clothesGraphic_677                   = "Clothes/Graphic (677).png";
const std::string Graphics::clothesGraphic_678                   = "Clothes/Graphic (678).png";
const std::string Graphics::clothesGraphic_679                   = "Clothes/Graphic (679).png";
const std::string Graphics::clothesGraphic_68                    = "Clothes/Graphic (68).png";
const std::string Graphics::clothesGraphic_680                   = "Clothes/Graphic (680).png";
const std::string Graphics::clothesGraphic_681                   = "Clothes/Graphic (681).png";
const std::string Graphics::clothesGraphic_682                   = "Clothes/Graphic (682).png";
const std::string Graphics::clothesGraphic_683                   = "Clothes/Graphic (683).png";
const std::string Graphics::clothesGraphic_684                   = "Clothes/Graphic (684).png";
const std::string Graphics::clothesGraphic_69                    = "Clothes/Graphic (69).png";
const std::string Graphics::clothesGraphic_7                     = "Clothes/Graphic (7).png";
const std::string Graphics::clothesGraphic_70                    = "Clothes/Graphic (70).png";
const std::string Graphics::clothesGraphic_71                    = "Clothes/Graphic (71).png";
const std::string Graphics::clothesGraphic_72                    = "Clothes/Graphic (72).png";
const std::string Graphics::clothesGraphic_73                    = "Clothes/Graphic (73).png";
const std::string Graphics::clothesGraphic_74                    = "Clothes/Graphic (74).png";
const std::string Graphics::clothesGraphic_75                    = "Clothes/Graphic (75).png";
const std::string Graphics::clothesGraphic_76                    = "Clothes/Graphic (76).png";
const std::string Graphics::clothesGraphic_77                    = "Clothes/Graphic (77).png";
const std::string Graphics::clothesGraphic_78                    = "Clothes/Graphic (78).png";
const std::string Graphics::clothesGraphic_79                    = "Clothes/Graphic (79).png";
const std::string Graphics::clothesGraphic_8                     = "Clothes/Graphic (8).png";
const std::string Graphics::clothesGraphic_80                    = "Clothes/Graphic (80).png";
const std::string Graphics::clothesGraphic_81                    = "Clothes/Graphic (81).png";
const std::string Graphics::clothesGraphic_82                    = "Clothes/Graphic (82).png";
const std::string Graphics::clothesGraphic_83                    = "Clothes/Graphic (83).png";
const std::string Graphics::clothesGraphic_84                    = "Clothes/Graphic (84).png";
const std::string Graphics::clothesGraphic_85                    = "Clothes/Graphic (85).png";
const std::string Graphics::clothesGraphic_86                    = "Clothes/Graphic (86).png";
const std::string Graphics::clothesGraphic_87                    = "Clothes/Graphic (87).png";
const std::string Graphics::clothesGraphic_88                    = "Clothes/Graphic (88).png";
const std::string Graphics::clothesGraphic_89                    = "Clothes/Graphic (89).png";
const std::string Graphics::clothesGraphic_9                     = "Clothes/Graphic (9).png";
const std::string Graphics::clothesGraphic_90                    = "Clothes/Graphic (90).png";
const std::string Graphics::clothesGraphic_91                    = "Clothes/Graphic (91).png";
const std::string Graphics::clothesGraphic_92                    = "Clothes/Graphic (92).png";
const std::string Graphics::clothesGraphic_93                    = "Clothes/Graphic (93).png";
const std::string Graphics::clothesGraphic_94                    = "Clothes/Graphic (94).png";
const std::string Graphics::clothesGraphic_95                    = "Clothes/Graphic (95).png";
const std::string Graphics::clothesGraphic_96                    = "Clothes/Graphic (96).png";
const std::string Graphics::clothesGraphic_97                    = "Clothes/Graphic (97).png";
const std::string Graphics::clothesGraphic_98                    = "Clothes/Graphic (98).png";
const std::string Graphics::clothesGraphic_99                    = "Clothes/Graphic (99).png";
const std::string Graphics::floorMAPFloor001                     = "Floor/MAP-Floor001.png";
const std::string Graphics::floorMAPFloor002                     = "Floor/MAP-Floor002.png";
const std::string Graphics::floorMAPFloor003                     = "Floor/MAP-Floor003.png";
const std::string Graphics::floorMAPFloor004                     = "Floor/MAP-Floor004.png";
const std::string Graphics::floorMAPFloor_10                     = "Floor/MAP-Floor (10).png";
const std::string Graphics::floorMAPFloor_100                    = "Floor/MAP-Floor (100).png";
const std::string Graphics::floorMAPFloor_11                     = "Floor/MAP-Floor (11).png";
const std::string Graphics::floorMAPFloor_12                     = "Floor/MAP-Floor (12).png";
const std::string Graphics::floorMAPFloor_13                     = "Floor/MAP-Floor (13).png";
const std::string Graphics::floorMAPFloor_14                     = "Floor/MAP-Floor (14).png";
const std::string Graphics::floorMAPFloor_15                     = "Floor/MAP-Floor (15).png";
const std::string Graphics::floorMAPFloor_16                     = "Floor/MAP-Floor (16).png";
const std::string Graphics::floorMAPFloor_17                     = "Floor/MAP-Floor (17).png";
const std::string Graphics::floorMAPFloor_18                     = "Floor/MAP-Floor (18).png";
const std::string Graphics::floorMAPFloor_19                     = "Floor/MAP-Floor (19).png";
const std::string Graphics::floorMAPFloor_20                     = "Floor/MAP-Floor (20).png";
const std::string Graphics::floorMAPFloor_21                     = "Floor/MAP-Floor (21).png";
const std::string Graphics::floorMAPFloor_22                     = "Floor/MAP-Floor (22).png";
const std::string Graphics::floorMAPFloor_23                     = "Floor/MAP-Floor (23).png";
const std::string Graphics::floorMAPFloor_24                     = "Floor/MAP-Floor (24).png";
const std::string Graphics::floorMAPFloor_25                     = "Floor/MAP-Floor (25).png";
const std::string Graphics::floorMAPFloor_26                     = "Floor/MAP-Floor (26).png";
const std::string Graphics::floorMAPFloor_27                     = "Floor/MAP-Floor (27).png";
const std::string Graphics::floorMAPFloor_28                     = "Floor/MAP-Floor (28).png";
const std::string Graphics::floorMAPFloor_29                     = "Floor/MAP-Floor (29).png";
const std::string Graphics::floorMAPFloor_30                     = "Floor/MAP-Floor (30).png";
const std::string Graphics::floorMAPFloor_31                     = "Floor/MAP-Floor (31).png";
const std::string Graphics::floorMAPFloor_32                     = "Floor/MAP-Floor (32).png";
const std::string Graphics::floorMAPFloor_33                     = "Floor/MAP-Floor (33).png";
const std::string Graphics::floorMAPFloor_34                     = "Floor/MAP-Floor (34).png";
const std::string Graphics::floorMAPFloor_35                     = "Floor/MAP-Floor (35).png";
const std::string Graphics::floorMAPFloor_36                     = "Floor/MAP-Floor (36).png";
const std::string Graphics::floorMAPFloor_37                     = "Floor/MAP-Floor (37).png";
const std::string Graphics::floorMAPFloor_38                     = "Floor/MAP-Floor (38).png";
const std::string Graphics::floorMAPFloor_39                     = "Floor/MAP-Floor (39).png";
const std::string Graphics::floorMAPFloor_40                     = "Floor/MAP-Floor (40).png";
const std::string Graphics::floorMAPFloor_41                     = "Floor/MAP-Floor (41).png";
const std::string Graphics::floorMAPFloor_42                     = "Floor/MAP-Floor (42).png";
const std::string Graphics::floorMAPFloor_43                     = "Floor/MAP-Floor (43).png";
const std::string Graphics::floorMAPFloor_44                     = "Floor/MAP-Floor (44).png";
const std::string Graphics::floorMAPFloor_45                     = "Floor/MAP-Floor (45).png";
const std::string Graphics::floorMAPFloor_46                     = "Floor/MAP-Floor (46).png";
const std::string Graphics::floorMAPFloor_47                     = "Floor/MAP-Floor (47).png";
const std::string Graphics::floorMAPFloor_48                     = "Floor/MAP-Floor (48).png";
const std::string Graphics::floorMAPFloor_49                     = "Floor/MAP-Floor (49).png";
const std::string Graphics::floorMAPFloor_5                      = "Floor/MAP-Floor (5).png";
const std::string Graphics::floorMAPFloor_50                     = "Floor/MAP-Floor (50).png";
const std::string Graphics::floorMAPFloor_51                     = "Floor/MAP-Floor (51).png";
const std::string Graphics::floorMAPFloor_52                     = "Floor/MAP-Floor (52).png";
const std::string Graphics::floorMAPFloor_53                     = "Floor/MAP-Floor (53).png";
const std::string Graphics::floorMAPFloor_54                     = "Floor/MAP-Floor (54).png";
const std::string Graphics::floorMAPFloor_55                     = "Floor/MAP-Floor (55).png";
const std::string Graphics::floorMAPFloor_56                     = "Floor/MAP-Floor (56).png";
const std::string Graphics::floorMAPFloor_57                     = "Floor/MAP-Floor (57).png";
const std::string Graphics::floorMAPFloor_58                     = "Floor/MAP-Floor (58).png";
const std::string Graphics::floorMAPFloor_59                     = "Floor/MAP-Floor (59).png";
const std::string Graphics::floorMAPFloor_6                      = "Floor/MAP-Floor (6).png";
const std::string Graphics::floorMAPFloor_60                     = "Floor/MAP-Floor (60).png";
const std::string Graphics::floorMAPFloor_61                     = "Floor/MAP-Floor (61).png";
const std::string Graphics::floorMAPFloor_62                     = "Floor/MAP-Floor (62).png";
const std::string Graphics::floorMAPFloor_63                     = "Floor/MAP-Floor (63).png";
const std::string Graphics::floorMAPFloor_64                     = "Floor/MAP-Floor (64).png";
const std::string Graphics::floorMAPFloor_65                     = "Floor/MAP-Floor (65).png";
const std::string Graphics::floorMAPFloor_66                     = "Floor/MAP-Floor (66).png";
const std::string Graphics::floorMAPFloor_67                     = "Floor/MAP-Floor (67).png";
const std::string Graphics::floorMAPFloor_68                     = "Floor/MAP-Floor (68).png";
const std::string Graphics::floorMAPFloor_69                     = "Floor/MAP-Floor (69).png";
const std::string Graphics::floorMAPFloor_7                      = "Floor/MAP-Floor (7).png";
const std::string Graphics::floorMAPFloor_70                     = "Floor/MAP-Floor (70).png";
const std::string Graphics::floorMAPFloor_71                     = "Floor/MAP-Floor (71).png";
const std::string Graphics::floorMAPFloor_72                     = "Floor/MAP-Floor (72).png";
const std::string Graphics::floorMAPFloor_73                     = "Floor/MAP-Floor (73).png";
const std::string Graphics::floorMAPFloor_74                     = "Floor/MAP-Floor (74).png";
const std::string Graphics::floorMAPFloor_75                     = "Floor/MAP-Floor (75).png";
const std::string Graphics::floorMAPFloor_76                     = "Floor/MAP-Floor (76).png";
const std::string Graphics::floorMAPFloor_77                     = "Floor/MAP-Floor (77).png";
const std::string Graphics::floorMAPFloor_78                     = "Floor/MAP-Floor (78).png";
const std::string Graphics::floorMAPFloor_79                     = "Floor/MAP-Floor (79).png";
const std::string Graphics::floorMAPFloor_8                      = "Floor/MAP-Floor (8).png";
const std::string Graphics::floorMAPFloor_80                     = "Floor/MAP-Floor (80).png";
const std::string Graphics::floorMAPFloor_81                     = "Floor/MAP-Floor (81).png";
const std::string Graphics::floorMAPFloor_82                     = "Floor/MAP-Floor (82).png";
const std::string Graphics::floorMAPFloor_83                     = "Floor/MAP-Floor (83).png";
const std::string Graphics::floorMAPFloor_84                     = "Floor/MAP-Floor (84).png";
const std::string Graphics::floorMAPFloor_85                     = "Floor/MAP-Floor (85).png";
const std::string Graphics::floorMAPFloor_86                     = "Floor/MAP-Floor (86).png";
const std::string Graphics::floorMAPFloor_87                     = "Floor/MAP-Floor (87).png";
const std::string Graphics::floorMAPFloor_88                     = "Floor/MAP-Floor (88).png";
const std::string Graphics::floorMAPFloor_89                     = "Floor/MAP-Floor (89).png";
const std::string Graphics::floorMAPFloor_9                      = "Floor/MAP-Floor (9).png";
const std::string Graphics::floorMAPFloor_90                     = "Floor/MAP-Floor (90).png";
const std::string Graphics::floorMAPFloor_91                     = "Floor/MAP-Floor (91).png";
const std::string Graphics::floorMAPFloor_92                     = "Floor/MAP-Floor (92).png";
const std::string Graphics::floorMAPFloor_93                     = "Floor/MAP-Floor (93).png";
const std::string Graphics::floorMAPFloor_94                     = "Floor/MAP-Floor (94).png";
const std::string Graphics::floorMAPFloor_95                     = "Floor/MAP-Floor (95).png";
const std::string Graphics::floorMAPFloor_96                     = "Floor/MAP-Floor (96).png";
const std::string Graphics::floorMAPFloor_97                     = "Floor/MAP-Floor (97).png";
const std::string Graphics::floorMAPFloor_98                     = "Floor/MAP-Floor (98).png";
const std::string Graphics::floorMAPFloor_99                     = "Floor/MAP-Floor (99).png";
const std::string Graphics::floorMapFloorCrossRoads              = "Floor/Map-Floor-CrossRoads.png";
const std::string Graphics::golemFireEast1                       = "Golem-Fire-East1.png";
const std::string Graphics::golemFireEast2                       = "Golem-Fire-East2.png";
const std::string Graphics::golemFireEast3                       = "Golem-Fire-East3.png";
const std::string Graphics::golemFireEast4                       = "Golem-Fire-East4.png";
const std::string Graphics::golemFireNorth1                      = "Golem-Fire-North1.png";
const std::string Graphics::golemFireNorth2                      = "Golem-Fire-North2.png";
const std::string Graphics::golemFireNorth3                      = "Golem-Fire-North3.png";
const std::string Graphics::golemFireNorth4                      = "Golem-Fire-North4.png";
const std::string Graphics::golemFireNorth5                      = "Golem-Fire-North5.png";
const std::string Graphics::golemFireSouth1                      = "Golem-Fire-South1.png";
const std::string Graphics::golemFireSouth2                      = "Golem-Fire-South2.png";
const std::string Graphics::golemFireSouth3                      = "Golem-Fire-South3.png";
const std::string Graphics::golemFireSouth4                      = "Golem-Fire-South4.png";
const std::string Graphics::golemFireSouth5                      = "Golem-Fire-South5.png";
const std::string Graphics::golemFireStandingEast                = "Golem-Fire-Standing-East.png";
const std::string Graphics::golemFireStandingNorth               = "Golem-Fire-Standing-North.png";
const std::string Graphics::golemFireStandingSouth               = "Golem-Fire-Standing-South.png";
const std::string Graphics::golemFireStandingWest                = "Golem-Fire-Standing-West.png";
const std::string Graphics::golemFireWest1                       = "Golem-Fire-West1.png";
const std::string Graphics::golemFireWest2                       = "Golem-Fire-West2.png";
const std::string Graphics::golemFireWest3                       = "Golem-Fire-West3.png";
const std::string Graphics::golemFireWest4                       = "Golem-Fire-West4.png";
const std::string Graphics::handTorchEast1                       = "Hand-Torch-East1.png";
const std::string Graphics::handTorchEast2                       = "Hand-Torch-East2.png";
const std::string Graphics::handTorchEast3                       = "Hand-Torch-East3.png";
const std::string Graphics::handTorchEast4                       = "Hand-Torch-East4.png";
const std::string Graphics::handTorchEast5                       = "Hand-Torch-East5.png";
const std::string Graphics::handTorchNorth1                      = "Hand-Torch-North1.png";
const std::string Graphics::handTorchNorth2                      = "Hand-Torch-North2.png";
const std::string Graphics::handTorchNorth3                      = "Hand-Torch-North3.png";
const std::string Graphics::handTorchNorth4                      = "Hand-Torch-North4.png";
const std::string Graphics::handTorchNorth5                      = "Hand-Torch-North5.png";
const std::string Graphics::handTorchSouth1                      = "Hand-Torch-South1.png";
const std::string Graphics::handTorchSouth2                      = "Hand-Torch-South2.png";
const std::string Graphics::handTorchSouth3                      = "Hand-Torch-South3.png";
const std::string Graphics::handTorchSouth4                      = "Hand-Torch-South4.png";
const std::string Graphics::handTorchStandingEast                = "Hand-Torch-Standing-East.png";
const std::string Graphics::handTorchStandingNorth               = "Hand-Torch-Standing-North.png";
const std::string Graphics::handTorchStandingSouth               = "Hand-Torch-Standing-South.png";
const std::string Graphics::handTorchStandingWest                = "Hand-Torch-Standing-West.png";
const std::string Graphics::handTorchWest1                       = "Hand-Torch-West1.png";
const std::string Graphics::handTorchWest2                       = "Hand-Torch-West2.png";
const std::string Graphics::handTorchWest3                       = "Hand-Torch-West3.png";
const std::string Graphics::handTorchWest4                       = "Hand-Torch-West4.png";
const std::string Graphics::headsGraphic_700                     = "Heads/Graphic (700).png";
const std::string Graphics::headsGraphic_701                     = "Heads/Graphic (701).png";
const std::string Graphics::headsGraphic_702                     = "Heads/Graphic (702).png";
const std::string Graphics::headsGraphic_703                     = "Heads/Graphic (703).png";
const std::string Graphics::headsGraphic_704                     = "Heads/Graphic (704).png";
const std::string Graphics::headsGraphic_705                     = "Heads/Graphic (705).png";
const std::string Graphics::headsGraphic_706                     = "Heads/Graphic (706).png";
const std::string Graphics::headsGraphic_707                     = "Heads/Graphic (707).png";
const std::string Graphics::headsGraphic_708                     = "Heads/Graphic (708).png";
const std::string Graphics::headsGraphic_709                     = "Heads/Graphic (709).png";
const std::string Graphics::headsGraphic_710                     = "Heads/Graphic (710).png";
const std::string Graphics::headsGraphic_711                     = "Heads/Graphic (711).png";
const std::string Graphics::headsGraphic_712                     = "Heads/Graphic (712).png";
const std::string Graphics::headsGraphic_713                     = "Heads/Graphic (713).png";
const std::string Graphics::headsGraphic_714                     = "Heads/Graphic (714).png";
const std::string Graphics::headsGraphic_715                     = "Heads/Graphic (715).png";
const std::string Graphics::headsGraphic_716                     = "Heads/Graphic (716).png";
const std::string Graphics::headsGraphic_717                     = "Heads/Graphic (717).png";
const std::string Graphics::headsGraphic_718                     = "Heads/Graphic (718).png";
const std::string Graphics::headsGraphic_719                     = "Heads/Graphic (719).png";
const std::string Graphics::headsGraphic_720                     = "Heads/Graphic (720).png";
const std::string Graphics::headsGraphic_721                     = "Heads/Graphic (721).png";
const std::string Graphics::headsGraphic_722                     = "Heads/Graphic (722).png";
const std::string Graphics::headsGraphic_723                     = "Heads/Graphic (723).png";
const std::string Graphics::headsGraphic_724                     = "Heads/Graphic (724).png";
const std::string Graphics::headsGraphic_725                     = "Heads/Graphic (725).png";
const std::string Graphics::headsGraphic_726                     = "Heads/Graphic (726).png";
const std::string Graphics::headsGraphic_727                     = "Heads/Graphic (727).png";
const std::string Graphics::headsGraphic_728                     = "Heads/Graphic (728).png";
const std::string Graphics::headsGraphic_729                     = "Heads/Graphic (729).png";
const std::string Graphics::headsGraphic_730                     = "Heads/Graphic (730).png";
const std::string Graphics::headsGraphic_731                     = "Heads/Graphic (731).png";
const std::string Graphics::headsGraphic_732                     = "Heads/Graphic (732).png";
const std::string Graphics::headsGraphic_733                     = "Heads/Graphic (733).png";
const std::string Graphics::headsGraphic_734                     = "Heads/Graphic (734).png";
const std::string Graphics::headsGraphic_735                     = "Heads/Graphic (735).png";
const std::string Graphics::headsGraphic_736                     = "Heads/Graphic (736).png";
const std::string Graphics::headsGraphic_737                     = "Heads/Graphic (737).png";
const std::string Graphics::headsGraphic_738                     = "Heads/Graphic (738).png";
const std::string Graphics::headsGraphic_739                     = "Heads/Graphic (739).png";
const std::string Graphics::headsGraphic_740                     = "Heads/Graphic (740).png";
const std::string Graphics::headsGraphic_741                     = "Heads/Graphic (741).png";
const std::string Graphics::headsGraphic_742                     = "Heads/Graphic (742).png";
const std::string Graphics::headsGraphic_743                     = "Heads/Graphic (743).png";
const std::string Graphics::headsGraphic_744                     = "Heads/Graphic (744).png";
const std::string Graphics::headsGraphic_745                     = "Heads/Graphic (745).png";
const std::string Graphics::headsGraphic_746                     = "Heads/Graphic (746).png";
const std::string Graphics::headsGraphic_747                     = "Heads/Graphic (747).png";
const std::string Graphics::headsGraphic_748                     = "Heads/Graphic (748).png";
const std::string Graphics::headsGraphic_749                     = "Heads/Graphic (749).png";
const std::string Graphics::headsGraphic_750                     = "Heads/Graphic (750).png";
const std::string Graphics::headsGraphic_751                     = "Heads/Graphic (751).png";
const std::string Graphics::headsGraphic_752                     = "Heads/Graphic (752).png";
const std::string Graphics::headsGraphic_753                     = "Heads/Graphic (753).png";
const std::string Graphics::headsGraphic_754                     = "Heads/Graphic (754).png";
const std::string Graphics::headsGraphic_755                     = "Heads/Graphic (755).png";
const std::string Graphics::headsGraphic_756                     = "Heads/Graphic (756).png";
const std::string Graphics::headsGraphic_757                     = "Heads/Graphic (757).png";
const std::string Graphics::headsGraphic_758                     = "Heads/Graphic (758).png";
const std::string Graphics::headsGraphic_759                     = "Heads/Graphic (759).png";
const std::string Graphics::headsGraphic_760                     = "Heads/Graphic (760).png";
const std::string Graphics::headsGraphic_761                     = "Heads/Graphic (761).png";
const std::string Graphics::headsGraphic_762                     = "Heads/Graphic (762).png";
const std::string Graphics::headsGraphic_763                     = "Heads/Graphic (763).png";
const std::string Graphics::headsGraphic_764                     = "Heads/Graphic (764).png";
const std::string Graphics::headsGraphic_765                     = "Heads/Graphic (765).png";
const std::string Graphics::headsGraphic_766                     = "Heads/Graphic (766).png";
const std::string Graphics::headsGraphic_767                     = "Heads/Graphic (767).png";
const std::string Graphics::headsGraphic_768                     = "Heads/Graphic (768).png";
const std::string Graphics::headsGraphic_769                     = "Heads/Graphic (769).png";
const std::string Graphics::headsGraphic_770                     = "Heads/Graphic (770).png";
const std::string Graphics::headsGraphic_771                     = "Heads/Graphic (771).png";
const std::string Graphics::headsGraphic_772                     = "Heads/Graphic (772).png";
const std::string Graphics::headsGraphic_773                     = "Heads/Graphic (773).png";
const std::string Graphics::headsGraphic_774                     = "Heads/Graphic (774).png";
const std::string Graphics::headsGraphic_775                     = "Heads/Graphic (775).png";
const std::string Graphics::headsGraphic_776                     = "Heads/Graphic (776).png";
const std::string Graphics::headsGraphic_777                     = "Heads/Graphic (777).png";
const std::string Graphics::headsGraphic_778                     = "Heads/Graphic (778).png";
const std::string Graphics::headsGraphic_779                     = "Heads/Graphic (779).png";
const std::string Graphics::headsGraphic_780                     = "Heads/Graphic (780).png";
const std::string Graphics::headsGraphic_781                     = "Heads/Graphic (781).png";
const std::string Graphics::headsGraphic_782                     = "Heads/Graphic (782).png";
const std::string Graphics::headsGraphic_783                     = "Heads/Graphic (783).png";
const std::string Graphics::headsGraphic_784                     = "Heads/Graphic (784).png";
const std::string Graphics::headsGraphic_785                     = "Heads/Graphic (785).png";
const std::string Graphics::headsGraphic_786                     = "Heads/Graphic (786).png";
const std::string Graphics::headsGraphic_787                     = "Heads/Graphic (787).png";
const std::string Graphics::headsGraphic_788                     = "Heads/Graphic (788).png";
const std::string Graphics::headsGraphic_789                     = "Heads/Graphic (789).png";
const std::string Graphics::headsGraphic_790                     = "Heads/Graphic (790).png";
const std::string Graphics::headsGraphic_791                     = "Heads/Graphic (791).png";
const std::string Graphics::headsGraphic_792                     = "Heads/Graphic (792).png";
const std::string Graphics::headsGraphic_793                     = "Heads/Graphic (793).png";
const std::string Graphics::headsGraphic_794                     = "Heads/Graphic (794).png";
const std::string Graphics::headsGraphic_795                     = "Heads/Graphic (795).png";
const std::string Graphics::headsGraphic_796                     = "Heads/Graphic (796).png";
const std::string Graphics::headsGraphic_797                     = "Heads/Graphic (797).png";
const std::string Graphics::headsGraphic_798                     = "Heads/Graphic (798).png";
const std::string Graphics::headsGraphic_799                     = "Heads/Graphic (799).png";
const std::string Graphics::headsGraphic_800                     = "Heads/Graphic (800).png";
const std::string Graphics::headsGraphic_801                     = "Heads/Graphic (801).png";
const std::string Graphics::headsGraphic_802                     = "Heads/Graphic (802).png";
const std::string Graphics::headsGraphic_803                     = "Heads/Graphic (803).png";
const std::string Graphics::headsGraphic_804                     = "Heads/Graphic (804).png";
const std::string Graphics::headsGraphic_805                     = "Heads/Graphic (805).png";
const std::string Graphics::headsGraphic_806                     = "Heads/Graphic (806).png";
const std::string Graphics::headsGraphic_807                     = "Heads/Graphic (807).png";
const std::string Graphics::headsGraphic_808                     = "Heads/Graphic (808).png";
const std::string Graphics::headsGraphic_809                     = "Heads/Graphic (809).png";
const std::string Graphics::headsGraphic_810                     = "Heads/Graphic (810).png";
const std::string Graphics::headsGraphic_811                     = "Heads/Graphic (811).png";
const std::string Graphics::headsGraphic_812                     = "Heads/Graphic (812).png";
const std::string Graphics::headsGraphic_813                     = "Heads/Graphic (813).png";
const std::string Graphics::headsGraphic_814                     = "Heads/Graphic (814).png";
const std::string Graphics::headsGraphic_815                     = "Heads/Graphic (815).png";
const std::string Graphics::headsGraphic_816                     = "Heads/Graphic (816).png";
const std::string Graphics::headsGraphic_817                     = "Heads/Graphic (817).png";
const std::string Graphics::headsGraphic_818                     = "Heads/Graphic (818).png";
const std::string Graphics::headsGraphic_819                     = "Heads/Graphic (819).png";
const std::string Graphics::headsGraphic_820                     = "Heads/Graphic (820).png";
const std::string Graphics::headsGraphic_821                     = "Heads/Graphic (821).png";
const std::string Graphics::headsGraphic_822                     = "Heads/Graphic (822).png";
const std::string Graphics::headsGraphic_823                     = "Heads/Graphic (823).png";
const std::string Graphics::headsGraphic_824                     = "Heads/Graphic (824).png";
const std::string Graphics::headsGraphic_825                     = "Heads/Graphic (825).png";
const std::string Graphics::headsGraphic_826                     = "Heads/Graphic (826).png";
const std::string Graphics::headsGraphic_827                     = "Heads/Graphic (827).png";
const std::string Graphics::headsGraphic_828                     = "Heads/Graphic (828).png";
const std::string Graphics::headsGraphic_829                     = "Heads/Graphic (829).png";
const std::string Graphics::headsGraphic_830                     = "Heads/Graphic (830).png";
const std::string Graphics::headsGraphic_831                     = "Heads/Graphic (831).png";
const std::string Graphics::headsGraphic_832                     = "Heads/Graphic (832).png";
const std::string Graphics::headsGraphic_833                     = "Heads/Graphic (833).png";
const std::string Graphics::headsGraphic_834                     = "Heads/Graphic (834).png";
const std::string Graphics::headsGraphic_835                     = "Heads/Graphic (835).png";
const std::string Graphics::headsGraphic_836                     = "Heads/Graphic (836).png";
const std::string Graphics::headsGraphic_837                     = "Heads/Graphic (837).png";
const std::string Graphics::headsGraphic_838                     = "Heads/Graphic (838).png";
const std::string Graphics::headsGraphic_839                     = "Heads/Graphic (839).png";
const std::string Graphics::headsGraphic_840                     = "Heads/Graphic (840).png";
const std::string Graphics::headsGraphic_841                     = "Heads/Graphic (841).png";
const std::string Graphics::headsGraphic_842                     = "Heads/Graphic (842).png";
const std::string Graphics::headsGraphic_843                     = "Heads/Graphic (843).png";
const std::string Graphics::headsGraphic_844                     = "Heads/Graphic (844).png";
const std::string Graphics::headsGraphic_845                     = "Heads/Graphic (845).png";
const std::string Graphics::headsGraphic_846                     = "Heads/Graphic (846).png";
const std::string Graphics::headsGraphic_847                     = "Heads/Graphic (847).png";
const std::string Graphics::headsGraphic_848                     = "Heads/Graphic (848).png";
const std::string Graphics::headsGraphic_849                     = "Heads/Graphic (849).png";
const std::string Graphics::headsGraphic_850                     = "Heads/Graphic (850).png";
const std::string Graphics::headsGraphic_851                     = "Heads/Graphic (851).png";
const std::string Graphics::headsGraphic_852                     = "Heads/Graphic (852).png";
const std::string Graphics::headsGraphic_853                     = "Heads/Graphic (853).png";
const std::string Graphics::headsGraphic_854                     = "Heads/Graphic (854).png";
const std::string Graphics::headsGraphic_855                     = "Heads/Graphic (855).png";
const std::string Graphics::headsGraphic_856                     = "Heads/Graphic (856).png";
const std::string Graphics::headsGraphic_857                     = "Heads/Graphic (857).png";
const std::string Graphics::headsGraphic_858                     = "Heads/Graphic (858).png";
const std::string Graphics::headsGraphic_859                     = "Heads/Graphic (859).png";
const std::string Graphics::headsGraphic_860                     = "Heads/Graphic (860).png";
const std::string Graphics::headsGraphic_861                     = "Heads/Graphic (861).png";
const std::string Graphics::headsGraphic_862                     = "Heads/Graphic (862).png";
const std::string Graphics::headsGraphic_863                     = "Heads/Graphic (863).png";
const std::string Graphics::headsGraphic_864                     = "Heads/Graphic (864).png";
const std::string Graphics::headsGraphic_865                     = "Heads/Graphic (865).png";
const std::string Graphics::headsGraphic_866                     = "Heads/Graphic (866).png";
const std::string Graphics::headsGraphic_867                     = "Heads/Graphic (867).png";
const std::string Graphics::headsGraphic_868                     = "Heads/Graphic (868).png";
const std::string Graphics::headsGraphic_869                     = "Heads/Graphic (869).png";
const std::string Graphics::headsGraphic_870                     = "Heads/Graphic (870).png";
const std::string Graphics::headsGraphic_871                     = "Heads/Graphic (871).png";
const std::string Graphics::headsGraphic_872                     = "Heads/Graphic (872).png";
const std::string Graphics::headsGraphic_873                     = "Heads/Graphic (873).png";
const std::string Graphics::headsGraphic_874                     = "Heads/Graphic (874).png";
const std::string Graphics::headsGraphic_875                     = "Heads/Graphic (875).png";
const std::string Graphics::headsGraphic_876                     = "Heads/Graphic (876).png";
const std::string Graphics::headsGraphic_877                     = "Heads/Graphic (877).png";
const std::string Graphics::headsGraphic_878                     = "Heads/Graphic (878).png";
const std::string Graphics::headsGraphic_879                     = "Heads/Graphic (879).png";
const std::string Graphics::headsGraphic_880                     = "Heads/Graphic (880).png";
const std::string Graphics::headsGraphic_881                     = "Heads/Graphic (881).png";
const std::string Graphics::headsGraphic_882                     = "Heads/Graphic (882).png";
const std::string Graphics::headsGraphic_883                     = "Heads/Graphic (883).png";
const std::string Graphics::headsGraphic_884                     = "Heads/Graphic (884).png";
const std::string Graphics::headsGraphic_885                     = "Heads/Graphic (885).png";
const std::string Graphics::headsGraphic_886                     = "Heads/Graphic (886).png";
const std::string Graphics::headsGraphic_887                     = "Heads/Graphic (887).png";
const std::string Graphics::headsGraphic_888                     = "Heads/Graphic (888).png";
const std::string Graphics::headsGraphic_889                     = "Heads/Graphic (889).png";
const std::string Graphics::headsGraphic_890                     = "Heads/Graphic (890).png";
const std::string Graphics::headsGraphic_891                     = "Heads/Graphic (891).png";
const std::string Graphics::headsGraphic_892                     = "Heads/Graphic (892).png";
const std::string Graphics::headsGraphic_893                     = "Heads/Graphic (893).png";
const std::string Graphics::headsGraphic_894                     = "Heads/Graphic (894).png";
const std::string Graphics::headsGraphic_895                     = "Heads/Graphic (895).png";
const std::string Graphics::headsGraphic_896                     = "Heads/Graphic (896).png";
const std::string Graphics::headsGraphic_897                     = "Heads/Graphic (897).png";
const std::string Graphics::headsGraphic_898                     = "Heads/Graphic (898).png";
const std::string Graphics::headsGraphic_899                     = "Heads/Graphic (899).png";
const std::string Graphics::headsGraphic_900                     = "Heads/Graphic (900).png";
const std::string Graphics::headsGraphic_901                     = "Heads/Graphic (901).png";
const std::string Graphics::headsGraphic_902                     = "Heads/Graphic (902).png";
const std::string Graphics::headsGraphic_903                     = "Heads/Graphic (903).png";
const std::string Graphics::headsGraphic_904                     = "Heads/Graphic (904).png";
const std::string Graphics::headsGraphic_905                     = "Heads/Graphic (905).png";
const std::string Graphics::headsGraphic_906                     = "Heads/Graphic (906).png";
const std::string Graphics::headsGraphic_907                     = "Heads/Graphic (907).png";
const std::string Graphics::headsGraphic_908                     = "Heads/Graphic (908).png";
const std::string Graphics::headsGraphic_909                     = "Heads/Graphic (909).png";
const std::string Graphics::headsGraphic_910                     = "Heads/Graphic (910).png";
const std::string Graphics::headsGraphic_911                     = "Heads/Graphic (911).png";
const std::string Graphics::headsGraphic_912                     = "Heads/Graphic (912).png";
const std::string Graphics::headsGraphic_913                     = "Heads/Graphic (913).png";
const std::string Graphics::headsGraphic_914                     = "Heads/Graphic (914).png";
const std::string Graphics::headsGraphic_915                     = "Heads/Graphic (915).png";
const std::string Graphics::headsGraphic_916                     = "Heads/Graphic (916).png";
const std::string Graphics::headsGraphic_917                     = "Heads/Graphic (917).png";
const std::string Graphics::headsGraphic_918                     = "Heads/Graphic (918).png";
const std::string Graphics::headsGraphic_919                     = "Heads/Graphic (919).png";
const std::string Graphics::headsGraphic_920                     = "Heads/Graphic (920).png";
const std::string Graphics::headsGraphic_921                     = "Heads/Graphic (921).png";
const std::string Graphics::headsGraphic_922                     = "Heads/Graphic (922).png";
const std::string Graphics::headsGraphic_923                     = "Heads/Graphic (923).png";
const std::string Graphics::headsGraphic_924                     = "Heads/Graphic (924).png";
const std::string Graphics::headsGraphic_925                     = "Heads/Graphic (925).png";
const std::string Graphics::headsPlayerHeadDarkElfA              = "Heads/Player-Head-DarkElf-A.png";
const std::string Graphics::headsPlayerHeadHumanA                = "Heads/Player-Head-HumanA.png";
const std::string Graphics::headsPlayerHeadHumanB                = "Heads/Player-Head-HumanB.png";
const std::string Graphics::headsPlayerHeadHumanC                = "Heads/Player-Head-HumanC.png";
const std::string Graphics::headsPlayerHeadHumanD                = "Heads/Player-Head-HumanD.png";
const std::string Graphics::headsPlayerHeadHumanE                = "Heads/Player-Head-HumanE.png";
const std::string Graphics::headsPlayerHeadHumanF                = "Heads/Player-Head-HumanF.png";
const std::string Graphics::headsPlayerHeadHumanG                = "Heads/Player-Head-HumanG.png";
const std::string Graphics::headsPlayerHeadHumanH                = "Heads/Player-Head-HumanH.png";
const std::string Graphics::headsPlayerHeadPirateEast            = "Heads/Player-Head-Pirate-East.png";
const std::string Graphics::headsPlayerHeadPirateNorth           = "Heads/Player-Head-Pirate-North.png";
const std::string Graphics::headsPlayerHeadPirateSouth           = "Heads/Player-Head-Pirate-South.png";
const std::string Graphics::headsPlayerHeadPirateWest            = "Heads/Player-Head-Pirate-West.png";
const std::string Graphics::interfaceCitizenSafe                 = "Interface-Citizen-Safe.png";
const std::string Graphics::interfaceCitizenUnSafe               = "Interface-Citizen-UnSafe.png";
const std::string Graphics::interfaceResurrectionSafe            = "Interface-Resurrection-Safe.png";
const std::string Graphics::interfaceResurrectionUnSafe          = "Interface-Resurrection-UnSafe.png";
const std::string Graphics::interfaceSpellOff                    = "Interface-Spell-Off.png";
const std::string Graphics::interfaceSpellOn                     = "Interface-Spell-On.png";
const std::string Graphics::interfaceWorkOff                     = "Interface-Work-Off.png";
const std::string Graphics::interfaceWorkOn                      = "Interface-Work-On.png";
const std::string Graphics::itemAtlasArgentum                    = "Item-AtlasArgentum.png";
const std::string Graphics::itemAxeGold                          = "Item-Axe-Gold.png";
const std::string Graphics::itemBedFront                         = "Item-Bed-Front.png";
const std::string Graphics::itemBedSide                          = "Item-Bed-Side.png";
const std::string Graphics::itemBeer                             = "Item-Beer.png";
const std::string Graphics::itemBook                             = "Item-Book.png";
const std::string Graphics::itemCanteenEmpty                     = "Item-Canteen-Empty.png";
const std::string Graphics::itemCanteenFull                      = "Item-Canteen-Full.png";
const std::string Graphics::itemChairFront                       = "Item-Chair-Front.png";
const std::string Graphics::itemChairSide                        = "Item-Chair-Side.png";
const std::string Graphics::itemChaliceGold                      = "Item-Chalice-Gold.png";
const std::string Graphics::itemChaliceSilver                    = "Item-Chalice-Silver.png";
const std::string Graphics::itemClotheTunicaMonkE_G              = "Item-Clothe-Tunica-monk-E.G-.png";
const std::string Graphics::itemClotheTunicaMonkH_E_EO           = "Item-Clothe-Tunica-Monk-H.E.EO.png";
const std::string Graphics::itemDrinkFruitJuice                  = "Item-Drink-FruitJuice.png";
const std::string Graphics::itemDrinkWater                       = "Item-Drink-Water.png";
const std::string Graphics::itemDrinkWine                        = "Item-Drink-Wine.png";
const std::string Graphics::itemDrum                             = "Item-Drum.png";
const std::string Graphics::itemFishHake                         = "Item-Fish-Hake.png";
const std::string Graphics::itemFishSalmon                       = "Item-Fish-Salmon.png";
const std::string Graphics::itemFishSeaHorse                     = "Item-Fish-SeaHorse.png";
const std::string Graphics::itemFishingNet                       = "Item-Fishing-Net.png";
const std::string Graphics::itemFishingRod                       = "Item-Fishing-Rod.png";
const std::string Graphics::itemFlute                            = "Item-Flute.png";
const std::string Graphics::itemFoodApple                        = "Item-Food-Apple.png";
const std::string Graphics::itemFoodBanana                       = "Item-Food-Banana.png";
const std::string Graphics::itemFoodBread                        = "Item-Food-Bread.png";
const std::string Graphics::itemFoodCheese                       = "Item-Food-Cheese.png";
const std::string Graphics::itemFoodChickenCoocked               = "Item-Food-Chicken-Coocked.png";
const std::string Graphics::itemFoodFruits                       = "Item-Food-Fruits.png";
const std::string Graphics::itemFoodMuffin                       = "Item-Food-Muffin.png";
const std::string Graphics::itemFoodPie                          = "Item-Food-Pie.png";
const std::string Graphics::itemFoodRawMeet                      = "Item-Food-RawMeet.png";
const std::string Graphics::itemFoodWaterMelon                   = "Item-Food-WaterMelon.png";
const std::string Graphics::itemFurBear                          = "Item-Fur-Bear.png";
const std::string Graphics::itemFurPolarBear                     = "Item-Fur-PolarBear.png";
const std::string Graphics::itemFurPolarWolf                     = "Item-Fur-PolarWolf.png";
const std::string Graphics::itemFurWolf                          = "Item-Fur-Wolf.png";
const std::string Graphics::itemFurnitureChairSide               = "Item-Furniture-Chair-Side.png";
const std::string Graphics::itemFurnitureCouch                   = "Item-Furniture-Couch.png";
const std::string Graphics::itemFurnitureRustic                  = "Item-Furniture-Rustic.png";
const std::string Graphics::itemFurnitureWoodSpoon               = "Item-Furniture-WoodSpoon.png";
const std::string Graphics::itemGalleon                          = "Item-Galleon.png";
const std::string Graphics::itemGalley                           = "Item-Galley.png";
const std::string Graphics::itemGoldCoins                        = "Item-GoldCoins.png";
const std::string Graphics::itemHammer                           = "Item-Hammer.png";
const std::string Graphics::itemHatBlue                          = "Item-Hat-Blue.png";
const std::string Graphics::itemHatNovice                        = "Item-Hat-Novice.png";
const std::string Graphics::itemHatPro                           = "Item-Hat-Pro.png";
const std::string Graphics::itemHelmetBear                       = "Item-Helmet-Bear.png";
const std::string Graphics::itemHelmetEagle                      = "Item-Helmet-Eagle.png";
const std::string Graphics::itemHelmetIron                       = "Item-Helmet-Iron.png";
const std::string Graphics::itemHelmetIronPro                    = "Item-Helmet-IronPro.png";
const std::string Graphics::itemHelmetSilver                     = "Item-Helmet-Silver.png";
const std::string Graphics::itemHelmetTiger                      = "Item-Helmet-Tiger.png";
const std::string Graphics::itemHelmetWolf                       = "Item-Helmet-Wolf.png";
const std::string Graphics::itemHoodBrown                        = "Item-Hood-Brown.png";
const std::string Graphics::itemIngotGold                        = "Item-Ingot-Gold.png";
const std::string Graphics::itemIngotIron                        = "Item-Ingot-Iron.png";
const std::string Graphics::itemIngotSilver                      = "Item-Ingot-Silver.png";
const std::string Graphics::itemKerchiefRed                      = "Item-Kerchief-Red.png";
const std::string Graphics::itemKey                              = "Item-Key.png";
const std::string Graphics::itemKnottyCane                       = "Item-KnottyCane.png";
const std::string Graphics::itemLogs                             = "Item-Logs.png";
const std::string Graphics::itemLogsAsh                          = "Item-Logs-Ash.png";
const std::string Graphics::itemLute                             = "Item-Lute.png";
const std::string Graphics::itemOreGold                          = "Item-Ore-Gold.png";
const std::string Graphics::itemOreIron                          = "Item-Ore-Iron.png";
const std::string Graphics::itemOreSilver                        = "Item-Ore-Silver.png";
const std::string Graphics::itemPotionBlack                      = "Item-Potion-Black.png";
const std::string Graphics::itemPotionLargeBlue                  = "Item-Potion-Large-Blue.png";
const std::string Graphics::itemPotionLargeGreen                 = "Item-Potion-Large-Green.png";
const std::string Graphics::itemPotionLargePurple                = "Item-Potion-Large-purple.png";
const std::string Graphics::itemPotionLargeRed                   = "Item-Potion-Large-Red.png";
const std::string Graphics::itemPotionLargeYellow                = "Item-Potion-Large-Yellow.png";
const std::string Graphics::itemPotionSmallBlack                 = "Item-Potion-Small-Black.png";
const std::string Graphics::itemPotionSmallBlue                  = "Item-Potion-Small-Blue.png";
const std::string Graphics::itemPotionSmallGreen                 = "Item-Potion-Small-Green.png";
const std::string Graphics::itemPotionSmallPurple                = "Item-Potion-Small-Purple.png";
const std::string Graphics::itemPotionSmallRed                   = "Item-Potion-Small-Red.png";
const std::string Graphics::itemPotionSmallYellow                = "Item-Potion-Small-Yellow.png";
const std::string Graphics::itemRingMagicResL                    = "Item-Ring-MagicRes-L.png";
const std::string Graphics::itemRingMagicResM                    = "Item-Ring-MagicRes-M.png";
const std::string Graphics::itemRingMagicResS                    = "Item-Ring-MagicRes-S.png";
const std::string Graphics::itemRingMagical                      = "Item-Ring-Magical.png";
const std::string Graphics::itemRubyBlue                         = "Item-Ruby-Blue.png";
const std::string Graphics::itemRubyGreen                        = "Item-Ruby-Green.png";
const std::string Graphics::itemRubyLightBlue                    = "Item-Ruby-LightBlue.png";
const std::string Graphics::itemRubyOrange                       = "Item-Ruby-Orange.png";
const std::string Graphics::itemRubyPink                         = "Item-Ruby-Pink.png";
const std::string Graphics::itemRubyPurple                       = "Item-Ruby-Purple.png";
const std::string Graphics::itemRubyRed                          = "Item-Ruby-Red.png";
const std::string Graphics::itemRubyWhite                        = "Item-Ruby-White.png";
const std::string Graphics::itemSaw                              = "Item-Saw.png";
const std::string Graphics::itemScissors                         = "Item-Scissors.png";
const std::string Graphics::itemSewingBox                        = "Item-SewingBox.png";
const std::string Graphics::itemShieldIron                       = "Item-Shield-Iron.png";
const std::string Graphics::itemShieldTurtle                     = "Item-Shield-Turtle.png";
const std::string Graphics::itemShip                             = "Item-Ship.png";
const std::string Graphics::itemSpell                            = "Item-Spell.png";
const std::string Graphics::itemThread                           = "Item-Thread.png";
const std::string Graphics::itemThreadGolden                     = "Item-Thread-Golden.png";
const std::string Graphics::itemWool                             = "Item-Wool.png";
const std::string Graphics::jokeTeletubies                       = "Joke-Teletubies.png";
const std::string Graphics::mAPFungusBlue                        = "MAP-Fungus-Blue.png";
const std::string Graphics::mAPFungusPurple                      = "MAP-Fungus-Purple.png";
const std::string Graphics::mAPFungusRed                         = "MAP-Fungus-Red.png";
const std::string Graphics::mAPFungusYellow                      = "MAP-Fungus-Yellow.png";
const std::string Graphics::mapAnvil                             = "Map-Anvil.png";
const std::string Graphics::mapArrowBroken                       = "Map-Arrow-Broken.png";
const std::string Graphics::mapArrowBrokenAsh                    = "Map-Arrow-Broken-Ash.png";
const std::string Graphics::mapAxeBlood                          = "Map-Axe-Blood.png";
const std::string Graphics::mapBannerBlue                        = "Map-Banner-Blue.png";
const std::string Graphics::mapBannerRed                         = "Map-Banner-Red.png";
const std::string Graphics::mapBarrelA                           = "Map-Barrel-A.png";
const std::string Graphics::mapBarrelB                           = "Map-Barrel-B.png";
const std::string Graphics::mapBedDoubleFront                    = "Map-Bed-Double-Front.png";
const std::string Graphics::mapBirdCage                          = "Map-BirdCage.png";
const std::string Graphics::mapBirdCageDeath                     = "Map-BirdCageDeath.png";
const std::string Graphics::mapBridgeBrickEW                     = "Map-Bridge-Brick-EW.png";
const std::string Graphics::mapBridgeBrickNS                     = "Map-Bridge-Brick-NS.png";
const std::string Graphics::mapBridgeGrayBirckCurveEW            = "Map-Bridge-GrayBirck-Curve-EW.png";
const std::string Graphics::mapBushA                             = "Map-Bush-A.png";
const std::string Graphics::mapBushAA                            = "Map-Bush-AA.png";
const std::string Graphics::mapBushB                             = "Map-Bush-B.png";
const std::string Graphics::mapBushBB                            = "Map-Bush-BB.png";
const std::string Graphics::mapBushC                             = "Map-Bush-C.png";
const std::string Graphics::mapBushD                             = "Map-Bush-D.png";
const std::string Graphics::mapBushE                             = "Map-Bush-E.png";
const std::string Graphics::mapBushF                             = "Map-Bush-F.png";
const std::string Graphics::mapBushG                             = "Map-Bush-G.png";
const std::string Graphics::mapBushH                             = "Map-Bush-H.png";
const std::string Graphics::mapBushI                             = "Map-Bush-I.png";
const std::string Graphics::mapBushJ                             = "Map-Bush-J.png";
const std::string Graphics::mapBushK                             = "Map-Bush-K.png";
const std::string Graphics::mapBushL                             = "Map-Bush-L.png";
const std::string Graphics::mapBushM                             = "Map-Bush-M.png";
const std::string Graphics::mapBushN                             = "Map-Bush-N.png";
const std::string Graphics::mapBushO                             = "Map-Bush-O.png";
const std::string Graphics::mapBushP                             = "Map-Bush-P.png";
const std::string Graphics::mapBushQ                             = "Map-Bush-Q.png";
const std::string Graphics::mapBushX                             = "Map-Bush-X.png";
const std::string Graphics::mapBushY                             = "Map-Bush-Y.png";
const std::string Graphics::mapBushZ                             = "Map-Bush-Z.png";
const std::string Graphics::mapCampFire01                        = "Map-CampFire01.png";
const std::string Graphics::mapCampFire02                        = "Map-CampFire02.png";
const std::string Graphics::mapCampFire03                        = "Map-CampFire03.png";
const std::string Graphics::mapCampFire04                        = "Map-CampFire04.png";
const std::string Graphics::mapCampFire05                        = "Map-CampFire05.png";
const std::string Graphics::mapCampFire06                        = "Map-CampFire06.png";
const std::string Graphics::mapCampFire07                        = "Map-CampFire07.png";
const std::string Graphics::mapCampFire08                        = "Map-CampFire08.png";
const std::string Graphics::mapCampFire09                        = "Map-CampFire09.png";
const std::string Graphics::mapCampFireOff                       = "Map-CampFire-Off.png";
const std::string Graphics::mapCarpenterDesk                     = "Map-Carpenter-Desk.png";
const std::string Graphics::mapDungeonA_1                        = "Map-Dungeon-A (1).png";
const std::string Graphics::mapDungeonA_10                       = "Map-Dungeon-A (10).png";
const std::string Graphics::mapDungeonA_11                       = "Map-Dungeon-A (11).png";
const std::string Graphics::mapDungeonA_12                       = "Map-Dungeon-A (12).png";
const std::string Graphics::mapDungeonA_13                       = "Map-Dungeon-A (13).png";
const std::string Graphics::mapDungeonA_14                       = "Map-Dungeon-A (14).png";
const std::string Graphics::mapDungeonA_2                        = "Map-Dungeon-A (2).png";
const std::string Graphics::mapDungeonA_3                        = "Map-Dungeon-A (3).png";
const std::string Graphics::mapDungeonA_4                        = "Map-Dungeon-A (4).png";
const std::string Graphics::mapDungeonA_5                        = "Map-Dungeon-A (5).png";
const std::string Graphics::mapDungeonA_6                        = "Map-Dungeon-A (6).png";
const std::string Graphics::mapDungeonA_7                        = "Map-Dungeon-A (7).png";
const std::string Graphics::mapDungeonA_8                        = "Map-Dungeon-A (8).png";
const std::string Graphics::mapDungeonA_9                        = "Map-Dungeon-A (9).png";
const std::string Graphics::mapDungeonB_1                        = "Map-Dungeon-B (1).png";
const std::string Graphics::mapDungeonB_10                       = "Map-Dungeon-B (10).png";
const std::string Graphics::mapDungeonB_11                       = "Map-Dungeon-B (11).png";
const std::string Graphics::mapDungeonB_12                       = "Map-Dungeon-B (12).png";
const std::string Graphics::mapDungeonB_13                       = "Map-Dungeon-B (13).png";
const std::string Graphics::mapDungeonB_14                       = "Map-Dungeon-B (14).png";
const std::string Graphics::mapDungeonB_15                       = "Map-Dungeon-B (15).png";
const std::string Graphics::mapDungeonB_16                       = "Map-Dungeon-B (16).png";
const std::string Graphics::mapDungeonB_17                       = "Map-Dungeon-B (17).png";
const std::string Graphics::mapDungeonB_18                       = "Map-Dungeon-B (18).png";
const std::string Graphics::mapDungeonB_19                       = "Map-Dungeon-B (19).png";
const std::string Graphics::mapDungeonB_2                        = "Map-Dungeon-B (2).png";
const std::string Graphics::mapDungeonB_20                       = "Map-Dungeon-B (20).png";
const std::string Graphics::mapDungeonB_21                       = "Map-Dungeon-B (21).png";
const std::string Graphics::mapDungeonB_22                       = "Map-Dungeon-B (22).png";
const std::string Graphics::mapDungeonB_23                       = "Map-Dungeon-B (23).png";
const std::string Graphics::mapDungeonB_24                       = "Map-Dungeon-B (24).png";
const std::string Graphics::mapDungeonB_25                       = "Map-Dungeon-B (25).png";
const std::string Graphics::mapDungeonB_3                        = "Map-Dungeon-B (3).png";
const std::string Graphics::mapDungeonB_4                        = "Map-Dungeon-B (4).png";
const std::string Graphics::mapDungeonB_5                        = "Map-Dungeon-B (5).png";
const std::string Graphics::mapDungeonB_6                        = "Map-Dungeon-B (6).png";
const std::string Graphics::mapDungeonB_7                        = "Map-Dungeon-B (7).png";
const std::string Graphics::mapDungeonB_8                        = "Map-Dungeon-B (8).png";
const std::string Graphics::mapDungeonB_9                        = "Map-Dungeon-B (9).png";
const std::string Graphics::mapDungeonC_1                        = "Map-Dungeon-C (1).png";
const std::string Graphics::mapDungeonC_10                       = "Map-Dungeon-C (10).png";
const std::string Graphics::mapDungeonC_11                       = "Map-Dungeon-C (11).png";
const std::string Graphics::mapDungeonC_12                       = "Map-Dungeon-C (12).png";
const std::string Graphics::mapDungeonC_13                       = "Map-Dungeon-C (13).png";
const std::string Graphics::mapDungeonC_14                       = "Map-Dungeon-C (14).png";
const std::string Graphics::mapDungeonC_15                       = "Map-Dungeon-C (15).png";
const std::string Graphics::mapDungeonC_16                       = "Map-Dungeon-C (16).png";
const std::string Graphics::mapDungeonC_17                       = "Map-Dungeon-C (17).png";
const std::string Graphics::mapDungeonC_2                        = "Map-Dungeon-C (2).png";
const std::string Graphics::mapDungeonC_3                        = "Map-Dungeon-C (3).png";
const std::string Graphics::mapDungeonC_4                        = "Map-Dungeon-C (4).png";
const std::string Graphics::mapDungeonC_5                        = "Map-Dungeon-C (5).png";
const std::string Graphics::mapDungeonC_6                        = "Map-Dungeon-C (6).png";
const std::string Graphics::mapDungeonC_7                        = "Map-Dungeon-C (7).png";
const std::string Graphics::mapDungeonC_8                        = "Map-Dungeon-C (8).png";
const std::string Graphics::mapDungeonC_9                        = "Map-Dungeon-C (9).png";
const std::string Graphics::mapDungeonD_1                        = "Map-Dungeon-D (1).png";
const std::string Graphics::mapDungeonD_10                       = "Map-Dungeon-D (10).png";
const std::string Graphics::mapDungeonD_11                       = "Map-Dungeon-D (11).png";
const std::string Graphics::mapDungeonD_12                       = "Map-Dungeon-D (12).png";
const std::string Graphics::mapDungeonD_13                       = "Map-Dungeon-D (13).png";
const std::string Graphics::mapDungeonD_14                       = "Map-Dungeon-D (14).png";
const std::string Graphics::mapDungeonD_2                        = "Map-Dungeon-D (2).png";
const std::string Graphics::mapDungeonD_3                        = "Map-Dungeon-D (3).png";
const std::string Graphics::mapDungeonD_4                        = "Map-Dungeon-D (4).png";
const std::string Graphics::mapDungeonD_5                        = "Map-Dungeon-D (5).png";
const std::string Graphics::mapDungeonD_6                        = "Map-Dungeon-D (6).png";
const std::string Graphics::mapDungeonD_7                        = "Map-Dungeon-D (7).png";
const std::string Graphics::mapDungeonD_8                        = "Map-Dungeon-D (8).png";
const std::string Graphics::mapDungeonD_9                        = "Map-Dungeon-D (9).png";
const std::string Graphics::mapDungeonE_1                        = "Map-Dungeon-E (1).png";
const std::string Graphics::mapDungeonE_10                       = "Map-Dungeon-E (10).png";
const std::string Graphics::mapDungeonE_11                       = "Map-Dungeon-E (11).png";
const std::string Graphics::mapDungeonE_12                       = "Map-Dungeon-E (12).png";
const std::string Graphics::mapDungeonE_13                       = "Map-Dungeon-E (13).png";
const std::string Graphics::mapDungeonE_14                       = "Map-Dungeon-E (14).png";
const std::string Graphics::mapDungeonE_15                       = "Map-Dungeon-E (15).png";
const std::string Graphics::mapDungeonE_16                       = "Map-Dungeon-E (16).png";
const std::string Graphics::mapDungeonE_17                       = "Map-Dungeon-E (17).png";
const std::string Graphics::mapDungeonE_18                       = "Map-Dungeon-E (18).png";
const std::string Graphics::mapDungeonE_19                       = "Map-Dungeon-E (19).png";
const std::string Graphics::mapDungeonE_2                        = "Map-Dungeon-E (2).png";
const std::string Graphics::mapDungeonE_20                       = "Map-Dungeon-E (20).png";
const std::string Graphics::mapDungeonE_3                        = "Map-Dungeon-E (3).png";
const std::string Graphics::mapDungeonE_4                        = "Map-Dungeon-E (4).png";
const std::string Graphics::mapDungeonE_5                        = "Map-Dungeon-E (5).png";
const std::string Graphics::mapDungeonE_6                        = "Map-Dungeon-E (6).png";
const std::string Graphics::mapDungeonE_7                        = "Map-Dungeon-E (7).png";
const std::string Graphics::mapDungeonE_8                        = "Map-Dungeon-E (8).png";
const std::string Graphics::mapDungeonE_9                        = "Map-Dungeon-E (9).png";
const std::string Graphics::mapDungeonEntranceA                  = "Map-Dungeon-Entrance-A.png";
const std::string Graphics::mapDungeonEntranceB                  = "Map-Dungeon-Entrance-B.png";
const std::string Graphics::mapDungeonEntranceC                  = "Map-Dungeon-Entrance-C.png";
const std::string Graphics::mapDungeonEntranceCommon             = "Map-Dungeon-Entrance-Common.png";
const std::string Graphics::mapDungeonEntranceCommonMossy        = "Map-Dungeon-Entrance-CommonMossy.png";
const std::string Graphics::mapDungeonEntranceD                  = "Map-Dungeon-Entrance-D.png";
const std::string Graphics::mapDungeonEntranceE                  = "Map-Dungeon-Entrance-E.png";
const std::string Graphics::mapDungeonEntranceF                  = "Map-Dungeon-Entrance-F.png";
const std::string Graphics::mapDungeonEntranceG                  = "Map-Dungeon-Entrance-G.png";
const std::string Graphics::mapDungeonEntranceH                  = "Map-Dungeon-Entrance-H.png";
const std::string Graphics::mapDungeonEntranceI                  = "Map-Dungeon-Entrance-I.png";
const std::string Graphics::mapDungeonEntranceJ                  = "Map-Dungeon-Entrance-J.png";
const std::string Graphics::mapDungeonEntranceK                  = "Map-Dungeon-Entrance-K.png";
const std::string Graphics::mapDungeonEntranceNewbie             = "Map-Dungeon-Entrance-Newbie.png";
const std::string Graphics::mapDungeonEntranceShark              = "Map-Dungeon-Entrance-Shark.png";
const std::string Graphics::mapDungeonEntranceVespar             = "Map-Dungeon-Entrance-Vespar.png";
const std::string Graphics::mapDungeonF_1                        = "Map-Dungeon-F (1).png";
const std::string Graphics::mapDungeonF_10                       = "Map-Dungeon-F (10).png";
const std::string Graphics::mapDungeonF_11                       = "Map-Dungeon-F (11).png";
const std::string Graphics::mapDungeonF_12                       = "Map-Dungeon-F (12).png";
const std::string Graphics::mapDungeonF_13                       = "Map-Dungeon-F (13).png";
const std::string Graphics::mapDungeonF_14                       = "Map-Dungeon-F (14).png";
const std::string Graphics::mapDungeonF_15                       = "Map-Dungeon-F (15).png";
const std::string Graphics::mapDungeonF_16                       = "Map-Dungeon-F (16).png";
const std::string Graphics::mapDungeonF_17                       = "Map-Dungeon-F (17).png";
const std::string Graphics::mapDungeonF_2                        = "Map-Dungeon-F (2).png";
const std::string Graphics::mapDungeonF_3                        = "Map-Dungeon-F (3).png";
const std::string Graphics::mapDungeonF_4                        = "Map-Dungeon-F (4).png";
const std::string Graphics::mapDungeonF_5                        = "Map-Dungeon-F (5).png";
const std::string Graphics::mapDungeonF_6                        = "Map-Dungeon-F (6).png";
const std::string Graphics::mapDungeonF_7                        = "Map-Dungeon-F (7).png";
const std::string Graphics::mapDungeonF_8                        = "Map-Dungeon-F (8).png";
const std::string Graphics::mapDungeonF_9                        = "Map-Dungeon-F (9).png";
const std::string Graphics::mapDungeonG_1                        = "Map-Dungeon-G (1).png";
const std::string Graphics::mapDungeonG_10                       = "Map-Dungeon-G (10).png";
const std::string Graphics::mapDungeonG_11                       = "Map-Dungeon-G (11).png";
const std::string Graphics::mapDungeonG_12                       = "Map-Dungeon-G (12).png";
const std::string Graphics::mapDungeonG_13                       = "Map-Dungeon-G (13).png";
const std::string Graphics::mapDungeonG_14                       = "Map-Dungeon-G (14).png";
const std::string Graphics::mapDungeonG_15                       = "Map-Dungeon-G (15).png";
const std::string Graphics::mapDungeonG_16                       = "Map-Dungeon-G (16).png";
const std::string Graphics::mapDungeonG_17                       = "Map-Dungeon-G (17).png";
const std::string Graphics::mapDungeonG_2                        = "Map-Dungeon-G (2).png";
const std::string Graphics::mapDungeonG_3                        = "Map-Dungeon-G (3).png";
const std::string Graphics::mapDungeonG_4                        = "Map-Dungeon-G (4).png";
const std::string Graphics::mapDungeonG_5                        = "Map-Dungeon-G (5).png";
const std::string Graphics::mapDungeonG_6                        = "Map-Dungeon-G (6).png";
const std::string Graphics::mapDungeonG_7                        = "Map-Dungeon-G (7).png";
const std::string Graphics::mapDungeonG_8                        = "Map-Dungeon-G (8).png";
const std::string Graphics::mapDungeonG_9                        = "Map-Dungeon-G (9).png";
const std::string Graphics::mapDungeonMagma_1                    = "Map-Dungeon-Magma (1).png";
const std::string Graphics::mapDungeonMagma_10                   = "Map-Dungeon-Magma (10).png";
const std::string Graphics::mapDungeonMagma_11                   = "Map-Dungeon-Magma (11).png";
const std::string Graphics::mapDungeonMagma_12                   = "Map-Dungeon-Magma (12).png";
const std::string Graphics::mapDungeonMagma_13                   = "Map-Dungeon-Magma (13).png";
const std::string Graphics::mapDungeonMagma_14                   = "Map-Dungeon-Magma (14).png";
const std::string Graphics::mapDungeonMagma_2                    = "Map-Dungeon-Magma (2).png";
const std::string Graphics::mapDungeonMagma_3                    = "Map-Dungeon-Magma (3).png";
const std::string Graphics::mapDungeonMagma_4                    = "Map-Dungeon-Magma (4).png";
const std::string Graphics::mapDungeonMagma_5                    = "Map-Dungeon-Magma (5).png";
const std::string Graphics::mapDungeonMagma_6                    = "Map-Dungeon-Magma (6).png";
const std::string Graphics::mapDungeonMagma_7                    = "Map-Dungeon-Magma (7).png";
const std::string Graphics::mapDungeonMagma_8                    = "Map-Dungeon-Magma (8).png";
const std::string Graphics::mapDungeonMagma_9                    = "Map-Dungeon-Magma (9).png";
const std::string Graphics::mapFence_1                           = "Map-Fence (1).png";
const std::string Graphics::mapFence_10                          = "Map-Fence (10).png";
const std::string Graphics::mapFence_11                          = "Map-Fence (11).png";
const std::string Graphics::mapFence_12                          = "Map-Fence (12).png";
const std::string Graphics::mapFence_13                          = "Map-Fence (13).png";
const std::string Graphics::mapFence_14                          = "Map-Fence (14).png";
const std::string Graphics::mapFence_15                          = "Map-Fence (15).png";
const std::string Graphics::mapFence_16                          = "Map-Fence (16).png";
const std::string Graphics::mapFence_17                          = "Map-Fence (17).png";
const std::string Graphics::mapFence_18                          = "Map-Fence (18).png";
const std::string Graphics::mapFence_19                          = "Map-Fence (19).png";
const std::string Graphics::mapFence_2                           = "Map-Fence (2).png";
const std::string Graphics::mapFence_20                          = "Map-Fence (20).png";
const std::string Graphics::mapFence_21                          = "Map-Fence (21).png";
const std::string Graphics::mapFence_22                          = "Map-Fence (22).png";
const std::string Graphics::mapFence_23                          = "Map-Fence (23).png";
const std::string Graphics::mapFence_3                           = "Map-Fence (3).png";
const std::string Graphics::mapFence_4                           = "Map-Fence (4).png";
const std::string Graphics::mapFence_5                           = "Map-Fence (5).png";
const std::string Graphics::mapFence_6                           = "Map-Fence (6).png";
const std::string Graphics::mapFence_7                           = "Map-Fence (7).png";
const std::string Graphics::mapFence_8                           = "Map-Fence (8).png";
const std::string Graphics::mapFence_9                           = "Map-Fence (9).png";
const std::string Graphics::mapForge                             = "Map-Forge.png";
const std::string Graphics::mapFossilRest                        = "Map-FossilRest.png";
const std::string Graphics::mapGrass                             = "Map-Grass.png";
const std::string Graphics::mapLava                              = "Map-Lava.png";
const std::string Graphics::mapLogLongStanding                   = "Map-Log-Long-Standing.png";
const std::string Graphics::mapMineGold                          = "Map-Mine-Gold.png";
const std::string Graphics::mapMineIron                          = "Map-Mine-Iron.png";
const std::string Graphics::mapMineSilver                        = "Map-Mine-Silver.png";
const std::string Graphics::mapMisticalPlace0                    = "Map-MisticalPlace-0.png";
const std::string Graphics::mapMisticalPlace1                    = "Map-MisticalPlace-1.png";
const std::string Graphics::mapMisticalPlace2                    = "Map-MisticalPlace-2.png";
const std::string Graphics::mapMisticalPlaceB0                   = "Map-MisticalPlaceB-0.png";
const std::string Graphics::mapMisticalPlaceB1                   = "Map-MisticalPlaceB-1.png";
const std::string Graphics::mapMisticalPlaceB2                   = "Map-MisticalPlaceB-2.png";
const std::string Graphics::mapMisticalPlaceB3                   = "Map-MisticalPlaceB-3.png";
const std::string Graphics::mapMisticalPlaceB4                   = "Map-MisticalPlaceB-4.png";
const std::string Graphics::mapMisticalPlaceB5                   = "Map-MisticalPlaceB-5.png";
const std::string Graphics::mapMisticalPlaceB6                   = "Map-MisticalPlaceB-6.png";
const std::string Graphics::mapMisticalPlaceB7                   = "Map-MisticalPlaceB-7.png";
const std::string Graphics::mapMisticalPlaceB8                   = "Map-MisticalPlaceB-8.png";
const std::string Graphics::mapPlantCactusSmall                  = "Map-Plant-Cactus-Small.png";
const std::string Graphics::mapPlantCactusTall                   = "Map-Plant-Cactus-Tall.png";
const std::string Graphics::mapPlantColorful                     = "Map-Plant-Colorful.png";
const std::string Graphics::mapPlantDotsBlue                     = "Map-Plant-Dots-Blue.png";
const std::string Graphics::mapPlantDotsBlueRed                  = "Map-Plant-Dots-BlueRed.png";
const std::string Graphics::mapPlantDotsLightBlue                = "Map-Plant-Dots-LightBlue.png";
const std::string Graphics::mapPlantDotsOrange                   = "Map-Plant-Dots-Orange.png";
const std::string Graphics::mapPlantDotsPurpleA                  = "Map-Plant-Dots-PurpleA.png";
const std::string Graphics::mapPlantDotsPurpleB                  = "Map-Plant-Dots-PurpleB.png";
const std::string Graphics::mapPlantDotsPurpleC                  = "Map-Plant-Dots-PurpleC.png";
const std::string Graphics::mapPlantDotsRed                      = "Map-Plant-Dots-Red.png";
const std::string Graphics::mapPlantFlowerPotA                   = "Map-Plant-FlowerPotA.png";
const std::string Graphics::mapPlantFlowerPotB                   = "Map-Plant-FlowerPotB.png";
const std::string Graphics::mapPlantFlowerPotC                   = "Map-Plant-FlowerPotC.png";
const std::string Graphics::mapPlantFlowerPotE                   = "Map-Plant-FlowerPotE.png";
const std::string Graphics::mapPlantFungusGiant                  = "Map-Plant-Fungus-Giant.png";
const std::string Graphics::mapPlantFungusGrey                   = "Map-Plant-Fungus-Grey.png";
const std::string Graphics::mapPlantFungusWhiteRed               = "Map-Plant-Fungus-WhiteRed.png";
const std::string Graphics::mapPlantLilyPad                      = "Map-Plant-LilyPad.png";
const std::string Graphics::mapPlantOrangeFlowers                = "Map-Plant-OrangeFlowers.png";
const std::string Graphics::mapPlantRedFlowers                   = "Map-Plant-RedFlowers.png";
const std::string Graphics::mapPlantSunFlower                    = "Map-Plant-SunFlower.png";
const std::string Graphics::mapPlantTotA                         = "Map-Plant-TotA.png";
const std::string Graphics::mapPlantTotB                         = "Map-Plant-TotB.png";
const std::string Graphics::mapPlantTotC                         = "Map-Plant-TotC.png";
const std::string Graphics::mapPlantYuka                         = "Map-Plant-Yuka.png";
const std::string Graphics::mapPortalBlue0                       = "Map-Portal-Blue-0.png";
const std::string Graphics::mapPortalBlue1                       = "Map-Portal-Blue-1.png";
const std::string Graphics::mapPortalBlue2                       = "Map-Portal-Blue-2.png";
const std::string Graphics::mapPortalBlue3                       = "Map-Portal-Blue-3.png";
const std::string Graphics::mapPortalBlue4                       = "Map-Portal-Blue-4.png";
const std::string Graphics::mapPortalBlue5                       = "Map-Portal-Blue-5.png";
const std::string Graphics::mapPortalBlue6                       = "Map-Portal-Blue-6.png";
const std::string Graphics::mapPortalBlue7                       = "Map-Portal-Blue-7.png";
const std::string Graphics::mapPortalClasic0                     = "Map-Portal-Clasic-0.png";
const std::string Graphics::mapPortalClasic1                     = "Map-Portal-Clasic-1.png";
const std::string Graphics::mapPortalClasic2                     = "Map-Portal-Clasic-2.png";
const std::string Graphics::mapPortalClasic3                     = "Map-Portal-Clasic-3.png";
const std::string Graphics::mapPortalClasic4                     = "Map-Portal-Clasic-4.png";
const std::string Graphics::mapPortalClasic5                     = "Map-Portal-Clasic-5.png";
const std::string Graphics::mapPortalClasic6                     = "Map-Portal-Clasic-6.png";
const std::string Graphics::mapPortalClasic7                     = "Map-Portal-Clasic-7.png";
const std::string Graphics::mapPortalClasicWarmer0               = "Map-Portal-ClasicWarmer-0.png";
const std::string Graphics::mapPortalClasicWarmer1               = "Map-Portal-ClasicWarmer-1.png";
const std::string Graphics::mapPortalClasicWarmer2               = "Map-Portal-ClasicWarmer-2.png";
const std::string Graphics::mapPortalClasicWarmer3               = "Map-Portal-ClasicWarmer-3.png";
const std::string Graphics::mapPortalClasicWarmer4               = "Map-Portal-ClasicWarmer-4.png";
const std::string Graphics::mapPortalClasicWarmer5               = "Map-Portal-ClasicWarmer-5.png";
const std::string Graphics::mapPortalClasicWarmer6               = "Map-Portal-ClasicWarmer-6.png";
const std::string Graphics::mapPortalClasicWarmer7               = "Map-Portal-ClasicWarmer-7.png";
const std::string Graphics::mapPortalGreen0                      = "Map-Portal-Green-0.png";
const std::string Graphics::mapPortalGreen1                      = "Map-Portal-Green-1.png";
const std::string Graphics::mapPortalGreen2                      = "Map-Portal-Green-2.png";
const std::string Graphics::mapPortalGreen3                      = "Map-Portal-Green-3.png";
const std::string Graphics::mapPortalGreen4                      = "Map-Portal-Green-4.png";
const std::string Graphics::mapPortalGreen5                      = "Map-Portal-Green-5.png";
const std::string Graphics::mapPortalGreen6                      = "Map-Portal-Green-6.png";
const std::string Graphics::mapPortalGreen7                      = "Map-Portal-Green-7.png";
const std::string Graphics::mapPortalLightBlue0                  = "Map-Portal-LightBlue-0.png";
const std::string Graphics::mapPortalLightBlue1                  = "Map-Portal-LightBlue-1.png";
const std::string Graphics::mapPortalLightBlue2                  = "Map-Portal-LightBlue-2.png";
const std::string Graphics::mapPortalLightBlue3                  = "Map-Portal-LightBlue-3.png";
const std::string Graphics::mapPortalLightBlue4                  = "Map-Portal-LightBlue-4.png";
const std::string Graphics::mapPortalLightBlue5                  = "Map-Portal-LightBlue-5.png";
const std::string Graphics::mapPortalLightBlue6                  = "Map-Portal-LightBlue-6.png";
const std::string Graphics::mapPortalLightBlue7                  = "Map-Portal-LightBlue-7.png";
const std::string Graphics::mapPortalPink0                       = "Map-Portal-Pink-0.png";
const std::string Graphics::mapPortalPink1                       = "Map-Portal-Pink-1.png";
const std::string Graphics::mapPortalPink2                       = "Map-Portal-Pink-2.png";
const std::string Graphics::mapPortalPink3                       = "Map-Portal-Pink-3.png";
const std::string Graphics::mapPortalPink4                       = "Map-Portal-Pink-4.png";
const std::string Graphics::mapPortalPink5                       = "Map-Portal-Pink-5.png";
const std::string Graphics::mapPortalPink6                       = "Map-Portal-Pink-6.png";
const std::string Graphics::mapPortalPink7                       = "Map-Portal-Pink-7.png";
const std::string Graphics::mapPortalPurple0                     = "Map-Portal-Purple-0.png";
const std::string Graphics::mapPortalPurple1                     = "Map-Portal-Purple-1.png";
const std::string Graphics::mapPortalPurple2                     = "Map-Portal-Purple-2.png";
const std::string Graphics::mapPortalPurple3                     = "Map-Portal-Purple-3.png";
const std::string Graphics::mapPortalPurple4                     = "Map-Portal-Purple-4.png";
const std::string Graphics::mapPortalPurple5                     = "Map-Portal-Purple-5.png";
const std::string Graphics::mapPortalPurple6                     = "Map-Portal-Purple-6.png";
const std::string Graphics::mapPortalPurple7                     = "Map-Portal-Purple-7.png";
const std::string Graphics::mapPortalYellow0                     = "Map-Portal-Yellow-0.png";
const std::string Graphics::mapPortalYellow1                     = "Map-Portal-Yellow-1.png";
const std::string Graphics::mapPortalYellow2                     = "Map-Portal-Yellow-2.png";
const std::string Graphics::mapPortalYellow3                     = "Map-Portal-Yellow-3.png";
const std::string Graphics::mapPortalYellow4                     = "Map-Portal-Yellow-4.png";
const std::string Graphics::mapPortalYellow5                     = "Map-Portal-Yellow-5.png";
const std::string Graphics::mapPortalYellow6                     = "Map-Portal-Yellow-6.png";
const std::string Graphics::mapPortalYellow7                     = "Map-Portal-Yellow-7.png";
const std::string Graphics::mapPosterAbadia                      = "Map-Poster-Abadia.png";
const std::string Graphics::mapPosterArghalCentralEast           = "Map-Poster-ArghalCentralEast.png";
const std::string Graphics::mapPosterArghalEast                  = "Map-Poster-ArghalEast.png";
const std::string Graphics::mapPosterArmaduras                   = "Map-Poster-Armaduras.png";
const std::string Graphics::mapPosterAsesino                     = "Map-Poster-Asesino.png";
const std::string Graphics::mapPosterBanderville                 = "Map-Poster-Banderville.png";
const std::string Graphics::mapPosterBandido                     = "Map-Poster-Bandido.png";
const std::string Graphics::mapPosterBardo                       = "Map-Poster-Bardo.png";
const std::string Graphics::mapPosterBienvenidosAArghal          = "Map-Poster-BienvenidosAArghal.png";
const std::string Graphics::mapPosterBienvenidosABanderbill      = "Map-Poster-BienvenidosABanderbill.png";
const std::string Graphics::mapPosterBlacksmith                  = "Map-Poster-Blacksmith.png";
const std::string Graphics::mapPosterBosqueDeDorkWestNixSouth    = "Map-Poster-BosqueDeDorkWest-NixSouth.png";
const std::string Graphics::mapPosterCarpinteria                 = "Map-Poster-Carpinteria.png";
const std::string Graphics::mapPosterCasa1                       = "Map-Poster-Casa1.png";
const std::string Graphics::mapPosterCasa10                      = "Map-Poster-Casa10.png";
const std::string Graphics::mapPosterCasa11                      = "Map-Poster-Casa11.png";
const std::string Graphics::mapPosterCasa12                      = "Map-Poster-Casa12.png";
const std::string Graphics::mapPosterCasa13                      = "Map-Poster-Casa13.png";
const std::string Graphics::mapPosterCasa14                      = "Map-Poster-Casa14.png";
const std::string Graphics::mapPosterCasa15                      = "Map-Poster-Casa15.png";
const std::string Graphics::mapPosterCasa16                      = "Map-Poster-Casa16.png";
const std::string Graphics::mapPosterCasa17                      = "Map-Poster-Casa17.png";
const std::string Graphics::mapPosterCasa18                      = "Map-Poster-Casa18.png";
const std::string Graphics::mapPosterCasa19                      = "Map-Poster-Casa19.png";
const std::string Graphics::mapPosterCasa2                       = "Map-Poster-Casa2.png";
const std::string Graphics::mapPosterCasa20                      = "Map-Poster-Casa20.png";
const std::string Graphics::mapPosterCasa3                       = "Map-Poster-Casa3.png";
const std::string Graphics::mapPosterCasa4                       = "Map-Poster-Casa4.png";
const std::string Graphics::mapPosterCasa5                       = "Map-Poster-Casa5.png";
const std::string Graphics::mapPosterCasa6                       = "Map-Poster-Casa6.png";
const std::string Graphics::mapPosterCasa7                       = "Map-Poster-Casa7.png";
const std::string Graphics::mapPosterCasa8                       = "Map-Poster-Casa8.png";
const std::string Graphics::mapPosterCasa9                       = "Map-Poster-Casa9.png";
const std::string Graphics::mapPosterClerigo                     = "Map-Poster-Clerigo.png";
const std::string Graphics::mapPosterDruida                      = "Map-Poster-Druida.png";
const std::string Graphics::mapPosterElGranConsejo               = "Map-Poster-ElGranConsejo.png";
const std::string Graphics::mapPosterElMesonHostigado            = "Map-Poster-ElMesonHostigado.png";
const std::string Graphics::mapPosterElMesonRioGrande            = "Map-Poster-ElMesonRioGrande.png";
const std::string Graphics::mapPosterFinanzas                    = "Map-Poster-Finanzas.png";
const std::string Graphics::mapPosterFinanzasGoliathCasaCentral  = "Map-Poster-FinanzasGoliathCasaCentral.png";
const std::string Graphics::mapPosterFood                        = "Map-Poster-Food.png";
const std::string Graphics::mapPosterForo                        = "Map-Poster-Foro.png";
const std::string Graphics::mapPosterGremioDeTrabajadores        = "Map-Poster-GremioDeTrabajadores.png";
const std::string Graphics::mapPosterGuerrero                    = "Map-Poster-Guerrero.png";
const std::string Graphics::mapPosterLadron                      = "Map-Poster-Ladron.png";
const std::string Graphics::mapPosterLenadores                   = "Map-Poster-Lenadores.png";
const std::string Graphics::mapPosterMagia                       = "Map-Poster-Magia.png";
const std::string Graphics::mapPosterMago                        = "Map-Poster-Mago.png";
const std::string Graphics::mapPosterMapCazador                  = "Map-Poster-Map-Cazador.png";
const std::string Graphics::mapPosterMineria                     = "Map-Poster-Mineria.png";
const std::string Graphics::mapPosterMuellesNorth                = "Map-Poster-MuellesNorth.png";
const std::string Graphics::mapPosterNix                         = "Map-Poster-Nix.png";
const std::string Graphics::mapPosterPalacioReal                 = "Map-Poster-PalacioReal.png";
const std::string Graphics::mapPosterPaladin                     = "Map-Poster-Paladin.png";
const std::string Graphics::mapPosterPeligroBosqueDeDork         = "Map-Poster-Peligro-BosqueDeDork.png";
const std::string Graphics::mapPosterPeligroDungeonVeril         = "Map-Poster-Peligro-DungeonVeril.png";
const std::string Graphics::mapPosterPescadores                  = "Map-Poster-Pescadores.png";
const std::string Graphics::mapPosterPirata                      = "Map-Poster-Pirata.png";
const std::string Graphics::mapPosterPociones                    = "Map-Poster-Pociones.png";
const std::string Graphics::mapPosterPrision                     = "Map-Poster-Prision.png";
const std::string Graphics::mapPosterPrisionWest                 = "Map-Poster-PrisionWest.png";
const std::string Graphics::mapPosterPropiedades                 = "Map-Poster-Propiedades.png";
const std::string Graphics::mapPosterProvisiones                 = "Map-Poster-Provisiones.png";
const std::string Graphics::mapPosterSacerdote                   = "Map-Poster-Sacerdote.png";
const std::string Graphics::mapPosterSastre                      = "Map-Poster-Sastre.png";
const std::string Graphics::mapPosterTeatroElJuglar              = "Map-Poster-TeatroElJuglar.png";
const std::string Graphics::mapPosterTownDisclaimer              = "Map-Poster-TownDisclaimer.png";
const std::string Graphics::mapPosterTrabajador                  = "Map-Poster-Trabajador.png";
const std::string Graphics::mapPosterUllathoreNorthNixWest       = "Map-Poster-UllathoreNorth-NixWest.png";
const std::string Graphics::mapPosterUllathorpe                  = "Map-Poster-Ullathorpe.png";
const std::string Graphics::mapPosterWelcomeDungeonNewbie        = "Map-Poster-WelcomeDungeonNewbie.png";
const std::string Graphics::mapRock01                            = "Map-Rock01.png";
const std::string Graphics::mapSpiderWeb                         = "Map-SpiderWeb.png";
const std::string Graphics::mapStainedGlass                      = "Map-StainedGlass.png";
const std::string Graphics::mapStatue01                          = "Map-Statue-01.png";
const std::string Graphics::mapStatue02                          = "Map-Statue-02.png";
const std::string Graphics::mapStatue03                          = "Map-Statue-03.png";
const std::string Graphics::mapStatue04                          = "Map-Statue-04.png";
const std::string Graphics::mapStatue05                          = "Map-Statue-05.png";
const std::string Graphics::mapStatue06                          = "Map-Statue-06.png";
const std::string Graphics::mapStatue07                          = "Map-Statue-07.png";
const std::string Graphics::mapStatue08                          = "Map-Statue-08.png";
const std::string Graphics::mapStatue09                          = "Map-Statue-09.png";
const std::string Graphics::mapStatue10                          = "Map-Statue-10.png";
const std::string Graphics::mapStatue11                          = "Map-Statue-11.png";
const std::string Graphics::mapStatueBuda                        = "Map-Statue-Buda.png";
const std::string Graphics::mapStreetLight                       = "Map-StreetLight.png";
const std::string Graphics::mapTreeA1                            = "Map-Tree-A-1.png";
const std::string Graphics::mapTreeA2                            = "Map-Tree-A-2.png";
const std::string Graphics::mapTreeA3                            = "Map-Tree-A-3.png";
const std::string Graphics::mapTreeA4                            = "Map-Tree-A-4.png";
const std::string Graphics::mapTreeA5                            = "Map-Tree-A-5.png";
const std::string Graphics::mapTreeA6                            = "Map-Tree-A-6.png";
const std::string Graphics::mapTreeB1                            = "Map-Tree-B-1.png";
const std::string Graphics::mapTreeB2                            = "Map-Tree-B-2.png";
const std::string Graphics::mapTreeC1                            = "Map-Tree-C-1.png";
const std::string Graphics::mapTreeC2                            = "Map-Tree-C-2.png";
const std::string Graphics::mapTreeD1                            = "Map-Tree-D-1.png";
const std::string Graphics::mapTreeD2                            = "Map-Tree-D-2.png";
const std::string Graphics::mapTreeDeath1                        = "Map-Tree-Death1.png";
const std::string Graphics::mapTreeDeath2                        = "Map-Tree-Death2.png";
const std::string Graphics::mapTreeDeath3                        = "Map-Tree-Death3.png";
const std::string Graphics::mapTreeDeath4                        = "Map-Tree-Death4.png";
const std::string Graphics::mapTreeDeathF                        = "Map-Tree-DeathF.png";
const std::string Graphics::mapTreeDeathG                        = "Map-Tree-DeathG.png";
const std::string Graphics::mapTreeE1                            = "Map-Tree-E1.png";
const std::string Graphics::mapTreeE2                            = "Map-Tree-E2.png";
const std::string Graphics::mapTreeF1                            = "Map-Tree-F 1.png";
const std::string Graphics::mapTreeF2                            = "Map-Tree-F 2.png";
const std::string Graphics::mapTreeG1                            = "Map-Tree-G1.png";
const std::string Graphics::mapTreeG2                            = "Map-Tree-G2.png";
const std::string Graphics::mapTreeH1                            = "Map-Tree-H1.png";
const std::string Graphics::mapTreeH2                            = "Map-Tree-H2.png";
const std::string Graphics::mapTreeI1                            = "Map-Tree-I1.png";
const std::string Graphics::mapTreeI2                            = "Map-Tree-I2.png";
const std::string Graphics::mapTreeJ1                            = "Map-Tree-J1.png";
const std::string Graphics::mapTreeJ2                            = "Map-Tree-J2.png";
const std::string Graphics::mapTreeK1                            = "Map-Tree-K1.png";
const std::string Graphics::mapTreeK2                            = "Map-Tree-K2.png";
const std::string Graphics::mapTreeL1                            = "Map-Tree-L1.png";
const std::string Graphics::mapTreeL2                            = "Map-Tree-L2.png";
const std::string Graphics::mapTreeM1                            = "Map-Tree-M1.png";
const std::string Graphics::mapTreeM2                            = "Map-Tree-M2.png";
const std::string Graphics::mapWagonGoldEast                     = "Map-Wagon-Gold-East.png";
const std::string Graphics::mapWagonSilverSouth                  = "Map-Wagon-Silver-South.png";
const std::string Graphics::mapWagonSilverWest                   = "Map-Wagon-Silver-West.png";
const std::string Graphics::mapWaterDeep                         = "Map-Water-Deep.png";
const std::string Graphics::mapWaterLow                          = "Map-Water-Low.png";
const std::string Graphics::mapWheelbarrowFront                  = "Map-wheelbarrow-Front.png";
const std::string Graphics::mapWheelbarrowSide                   = "Map-wheelbarrow-Side.png";
const std::string Graphics::meditationBlue0                      = "Meditation-Blue-0.png";
const std::string Graphics::meditationBlue1                      = "Meditation-Blue-1.png";
const std::string Graphics::meditationBlue2                      = "Meditation-Blue-2.png";
const std::string Graphics::meditationBlue3                      = "Meditation-Blue-3.png";
const std::string Graphics::meditationBlue4                      = "Meditation-Blue-4.png";
const std::string Graphics::meditationBlue5                      = "Meditation-Blue-5.png";
const std::string Graphics::meditationBlue6                      = "Meditation-Blue-6.png";
const std::string Graphics::meditationBlue7                      = "Meditation-Blue-7.png";
const std::string Graphics::meditationBlue8                      = "Meditation-Blue-8.png";
const std::string Graphics::meditationBlue9                      = "Meditation-Blue-9.png";
const std::string Graphics::meditationExtreme0                   = "Meditation-Extreme-0.png";
const std::string Graphics::meditationExtreme1                   = "Meditation-Extreme-1.png";
const std::string Graphics::meditationExtreme2                   = "Meditation-Extreme-2.png";
const std::string Graphics::meditationExtreme3                   = "Meditation-Extreme-3.png";
const std::string Graphics::meditationExtreme4                   = "Meditation-Extreme-4.png";
const std::string Graphics::meditationExtreme5                   = "Meditation-Extreme-5.png";
const std::string Graphics::meditationExtreme6                   = "Meditation-Extreme-6.png";
const std::string Graphics::meditationExtreme7                   = "Meditation-Extreme-7.png";
const std::string Graphics::meditationExtreme8                   = "Meditation-Extreme-8.png";
const std::string Graphics::meditationExtreme9                   = "Meditation-Extreme-9.png";
const std::string Graphics::meditationNewbie0                    = "Meditation-Newbie-0.png";
const std::string Graphics::meditationNewbie1                    = "Meditation-Newbie-1.png";
const std::string Graphics::meditationNewbie2                    = "Meditation-Newbie-2.png";
const std::string Graphics::meditationNewbie3                    = "Meditation-Newbie-3.png";
const std::string Graphics::meditationNewbie4                    = "Meditation-Newbie-4.png";
const std::string Graphics::meditationNewbie5                    = "Meditation-Newbie-5.png";
const std::string Graphics::meditationNewbie6                    = "Meditation-Newbie-6.png";
const std::string Graphics::meditationNewbie7                    = "Meditation-Newbie-7.png";
const std::string Graphics::meditationNewbie8                    = "Meditation-Newbie-8.png";
const std::string Graphics::meditationNewbie9                    = "Meditation-Newbie-9.png";
const std::string Graphics::meditationRed0                       = "Meditation-Red-0.png";
const std::string Graphics::meditationRed1                       = "Meditation-Red-1.png";
const std::string Graphics::meditationRed2                       = "Meditation-Red-2.png";
const std::string Graphics::meditationRed3                       = "Meditation-Red-3.png";
const std::string Graphics::meditationRed4                       = "Meditation-Red-4.png";
const std::string Graphics::meditationRed5                       = "Meditation-Red-5.png";
const std::string Graphics::meditationRed6                       = "Meditation-Red-6.png";
const std::string Graphics::meditationRed7                       = "Meditation-Red-7.png";
const std::string Graphics::meditationRed8                       = "Meditation-Red-8.png";
const std::string Graphics::meditationRed9                       = "Meditation-Red-9.png";
const std::string Graphics::meditationYellow0                    = "Meditation-Yellow-0.png";
const std::string Graphics::meditationYellow1                    = "Meditation-Yellow-1.png";
const std::string Graphics::meditationYellow2                    = "Meditation-Yellow-2.png";
const std::string Graphics::meditationYellow3                    = "Meditation-Yellow-3.png";
const std::string Graphics::meditationYellow4                    = "Meditation-Yellow-4.png";
const std::string Graphics::meditationYellow5                    = "Meditation-Yellow-5.png";
const std::string Graphics::meditationYellow6                    = "Meditation-Yellow-6.png";
const std::string Graphics::meditationYellow7                    = "Meditation-Yellow-7.png";
const std::string Graphics::meditationYellow8                    = "Meditation-Yellow-8.png";
const std::string Graphics::meditationYellow9                    = "Meditation-Yellow-9.png";
const std::string Graphics::miscEyePurple                        = "Misc-Eye-Purple.png";
const std::string Graphics::mobBatEast1                          = "Mob-Bat-East1.png";
const std::string Graphics::mobBatEast2                          = "Mob-Bat-East2.png";
const std::string Graphics::mobBatNorth1                         = "Mob-Bat-North1.png";
const std::string Graphics::mobBatNorth2                         = "Mob-Bat-North2.png";
const std::string Graphics::mobBatSouth1                         = "Mob-Bat-South1.png";
const std::string Graphics::mobBatSouth2                         = "Mob-Bat-South2.png";
const std::string Graphics::mobBatWest1                          = "Mob-Bat-West1.png";
const std::string Graphics::mobBatWest2                          = "Mob-Bat-West2.png";
const std::string Graphics::mobBearEast1                         = "Mob-Bear-East-1.png";
const std::string Graphics::mobBearEast2                         = "Mob-Bear-East-2.png";
const std::string Graphics::mobBearEast3                         = "Mob-Bear-East-3.png";
const std::string Graphics::mobBearEast4                         = "Mob-Bear-East-4.png";
const std::string Graphics::mobBearEast5                         = "Mob-Bear-East-5.png";
const std::string Graphics::mobBearEast6                         = "Mob-Bear-East-6.png";
const std::string Graphics::mobBearEast7                         = "Mob-Bear-East-7.png";
const std::string Graphics::mobBearNorth1                        = "Mob-Bear-North-1.png";
const std::string Graphics::mobBearNorth2                        = "Mob-Bear-North-2.png";
const std::string Graphics::mobBearNorth3                        = "Mob-Bear-North-3.png";
const std::string Graphics::mobBearNorth4                        = "Mob-Bear-North-4.png";
const std::string Graphics::mobBearNorth5                        = "Mob-Bear-North-5.png";
const std::string Graphics::mobBearNorth6                        = "Mob-Bear-North-6.png";
const std::string Graphics::mobBearNorth7                        = "Mob-Bear-North-7.png";
const std::string Graphics::mobBearPolarEast1                    = "Mob-Bear-Polar-East-1.png";
const std::string Graphics::mobBearPolarEast2                    = "Mob-Bear-Polar-East-2.png";
const std::string Graphics::mobBearPolarEast3                    = "Mob-Bear-Polar-East-3.png";
const std::string Graphics::mobBearPolarEast4                    = "Mob-Bear-Polar-East-4.png";
const std::string Graphics::mobBearPolarNorth1                   = "Mob-Bear-Polar-North-1.png";
const std::string Graphics::mobBearPolarNorth2                   = "Mob-Bear-Polar-North-2.png";
const std::string Graphics::mobBearPolarNorth3                   = "Mob-Bear-Polar-North-3.png";
const std::string Graphics::mobBearPolarNorth4                   = "Mob-Bear-Polar-North-4.png";
const std::string Graphics::mobBearPolarSouth1                   = "Mob-Bear-Polar-South-1.png";
const std::string Graphics::mobBearPolarSouth2                   = "Mob-Bear-Polar-South-2.png";
const std::string Graphics::mobBearPolarSouth3                   = "Mob-Bear-Polar-South-3.png";
const std::string Graphics::mobBearPolarSouth4                   = "Mob-Bear-Polar-South-4.png";
const std::string Graphics::mobBearPolarStandingEast             = "Mob-Bear-Polar-Standing-East.png";
const std::string Graphics::mobBearPolarStandingNorth            = "Mob-Bear-Polar-Standing-North.png";
const std::string Graphics::mobBearPolarStandingSouth            = "Mob-Bear-Polar-Standing-South.png";
const std::string Graphics::mobBearPolarStandingWest             = "Mob-Bear-Polar-Standing-West.png";
const std::string Graphics::mobBearPolarWest1                    = "Mob-Bear-Polar-West-1.png";
const std::string Graphics::mobBearPolarWest2                    = "Mob-Bear-Polar-West-2.png";
const std::string Graphics::mobBearPolarWest3                    = "Mob-Bear-Polar-West-3.png";
const std::string Graphics::mobBearPolarWest4                    = "Mob-Bear-Polar-West-4.png";
const std::string Graphics::mobBearSouth1                        = "Mob-Bear-South-1.png";
const std::string Graphics::mobBearSouth2                        = "Mob-Bear-South-2.png";
const std::string Graphics::mobBearSouth3                        = "Mob-Bear-South-3.png";
const std::string Graphics::mobBearSouth4                        = "Mob-Bear-South-4.png";
const std::string Graphics::mobBearSouth5                        = "Mob-Bear-South-5.png";
const std::string Graphics::mobBearSouth6                        = "Mob-Bear-South-6.png";
const std::string Graphics::mobBearSouth7                        = "Mob-Bear-South-7.png";
const std::string Graphics::mobBearStandingEast                  = "Mob-Bear-Standing-East.png";
const std::string Graphics::mobBearStandingNorth                 = "Mob-Bear-Standing-North.png";
const std::string Graphics::mobBearStandingSouth                 = "Mob-Bear-Standing-South.png";
const std::string Graphics::mobBearStandingWest                  = "Mob-Bear-Standing-West.png";
const std::string Graphics::mobBearWest1                         = "Mob-Bear-West-1.png";
const std::string Graphics::mobBearWest2                         = "Mob-Bear-West-2.png";
const std::string Graphics::mobBearWest3                         = "Mob-Bear-West-3.png";
const std::string Graphics::mobBearWest4                         = "Mob-Bear-West-4.png";
const std::string Graphics::mobBearWest5                         = "Mob-Bear-West-5.png";
const std::string Graphics::mobBearWest6                         = "Mob-Bear-West-6.png";
const std::string Graphics::mobBearWest7                         = "Mob-Bear-West-7.png";
const std::string Graphics::mobBeholerEast1                      = "Mob-Beholer-East-1.png";
const std::string Graphics::mobBeholerEast2                      = "Mob-Beholer-East-2.png";
const std::string Graphics::mobBeholerEast3                      = "Mob-Beholer-East-3.png";
const std::string Graphics::mobBeholerEast4                      = "Mob-Beholer-East-4.png";
const std::string Graphics::mobBeholerEast5                      = "Mob-Beholer-East-5.png";
const std::string Graphics::mobBeholerNorth1                     = "Mob-Beholer-North-1.png";
const std::string Graphics::mobBeholerNorth2                     = "Mob-Beholer-North-2.png";
const std::string Graphics::mobBeholerNorth3                     = "Mob-Beholer-North-3.png";
const std::string Graphics::mobBeholerNorth4                     = "Mob-Beholer-North-4.png";
const std::string Graphics::mobBeholerNorth5                     = "Mob-Beholer-North-5.png";
const std::string Graphics::mobBeholerSouth1                     = "Mob-Beholer-South-1.png";
const std::string Graphics::mobBeholerSouth2                     = "Mob-Beholer-South-2.png";
const std::string Graphics::mobBeholerSouth3                     = "Mob-Beholer-South-3.png";
const std::string Graphics::mobBeholerSouth4                     = "Mob-Beholer-South-4.png";
const std::string Graphics::mobBeholerSouth5                     = "Mob-Beholer-South-5.png";
const std::string Graphics::mobBeholerStandingEast               = "Mob-Beholer-Standing-East.png";
const std::string Graphics::mobBeholerStandingNorth              = "Mob-Beholer-Standing-North.png";
const std::string Graphics::mobBeholerStandingSouth              = "Mob-Beholer-Standing-South.png";
const std::string Graphics::mobBeholerStandingWest               = "Mob-Beholer-Standing-West.png";
const std::string Graphics::mobBeholerWest1                      = "Mob-Beholer-West-1.png";
const std::string Graphics::mobBeholerWest2                      = "Mob-Beholer-West-2.png";
const std::string Graphics::mobBeholerWest3                      = "Mob-Beholer-West-3.png";
const std::string Graphics::mobBeholerWest4                      = "Mob-Beholer-West-4.png";
const std::string Graphics::mobBeholerWest5                      = "Mob-Beholer-West-5.png";
const std::string Graphics::mobBirdBlackEast1                    = "Mob-Bird-Black-East1.png";
const std::string Graphics::mobBirdBlackEast2                    = "Mob-Bird-Black-East2.png";
const std::string Graphics::mobBirdBlackEast3                    = "Mob-Bird-Black-East3.png";
const std::string Graphics::mobBirdBlackEast4                    = "Mob-Bird-Black-East4.png";
const std::string Graphics::mobBirdBlackEast5                    = "Mob-Bird-Black-East5.png";
const std::string Graphics::mobBirdBlackNorth1                   = "Mob-Bird-Black-North1.png";
const std::string Graphics::mobBirdBlackNorth2                   = "Mob-Bird-Black-North2.png";
const std::string Graphics::mobBirdBlackNorth3                   = "Mob-Bird-Black-North3.png";
const std::string Graphics::mobBirdBlackNorth4                   = "Mob-Bird-Black-North4.png";
const std::string Graphics::mobBirdBlackNorth5                   = "Mob-Bird-Black-North5.png";
const std::string Graphics::mobBirdBlackSouth1                   = "Mob-Bird-Black-South1.png";
const std::string Graphics::mobBirdBlackSouth2                   = "Mob-Bird-Black-South2.png";
const std::string Graphics::mobBirdBlackSouth3                   = "Mob-Bird-Black-South3.png";
const std::string Graphics::mobBirdBlackSouth4                   = "Mob-Bird-Black-South4.png";
const std::string Graphics::mobBirdBlackSouth5                   = "Mob-Bird-Black-South5.png";
const std::string Graphics::mobBirdBlackWest1                    = "Mob-Bird-Black-West1.png";
const std::string Graphics::mobBirdBlackWest2                    = "Mob-Bird-Black-West2.png";
const std::string Graphics::mobBirdBlackWest3                    = "Mob-Bird-Black-West3.png";
const std::string Graphics::mobBirdBlackWest4                    = "Mob-Bird-Black-West4.png";
const std::string Graphics::mobBirdBlackWest5                    = "Mob-Bird-Black-West5.png";
const std::string Graphics::mobDragonEast1                       = "Mob-Dragon-East-1.png";
const std::string Graphics::mobDragonEast10                      = "Mob-Dragon-East-10.png";
const std::string Graphics::mobDragonEast11                      = "Mob-Dragon-East-11.png";
const std::string Graphics::mobDragonEast2                       = "Mob-Dragon-East-2.png";
const std::string Graphics::mobDragonEast3                       = "Mob-Dragon-East-3.png";
const std::string Graphics::mobDragonEast4                       = "Mob-Dragon-East-4.png";
const std::string Graphics::mobDragonEast5                       = "Mob-Dragon-East-5.png";
const std::string Graphics::mobDragonEast6                       = "Mob-Dragon-East-6.png";
const std::string Graphics::mobDragonEast7                       = "Mob-Dragon-East-7.png";
const std::string Graphics::mobDragonEast8                       = "Mob-Dragon-East-8.png";
const std::string Graphics::mobDragonEast9                       = "Mob-Dragon-East-9.png";
const std::string Graphics::mobDragonNorth1                      = "Mob-Dragon-North-1.png";
const std::string Graphics::mobDragonNorth10                     = "Mob-Dragon-North-10.png";
const std::string Graphics::mobDragonNorth11                     = "Mob-Dragon-North-11.png";
const std::string Graphics::mobDragonNorth2                      = "Mob-Dragon-North-2.png";
const std::string Graphics::mobDragonNorth3                      = "Mob-Dragon-North-3.png";
const std::string Graphics::mobDragonNorth4                      = "Mob-Dragon-North-4.png";
const std::string Graphics::mobDragonNorth5                      = "Mob-Dragon-North-5.png";
const std::string Graphics::mobDragonNorth6                      = "Mob-Dragon-North-6.png";
const std::string Graphics::mobDragonNorth7                      = "Mob-Dragon-North-7.png";
const std::string Graphics::mobDragonNorth8                      = "Mob-Dragon-North-8.png";
const std::string Graphics::mobDragonNorth9                      = "Mob-Dragon-North-9.png";
const std::string Graphics::mobDragonSouth1                      = "Mob-Dragon-South-1.png";
const std::string Graphics::mobDragonSouth10                     = "Mob-Dragon-South-10.png";
const std::string Graphics::mobDragonSouth11                     = "Mob-Dragon-South-11.png";
const std::string Graphics::mobDragonSouth2                      = "Mob-Dragon-South-2.png";
const std::string Graphics::mobDragonSouth3                      = "Mob-Dragon-South-3.png";
const std::string Graphics::mobDragonSouth4                      = "Mob-Dragon-South-4.png";
const std::string Graphics::mobDragonSouth5                      = "Mob-Dragon-South-5.png";
const std::string Graphics::mobDragonSouth6                      = "Mob-Dragon-South-6.png";
const std::string Graphics::mobDragonSouth7                      = "Mob-Dragon-South-7.png";
const std::string Graphics::mobDragonSouth8                      = "Mob-Dragon-South-8.png";
const std::string Graphics::mobDragonSouth9                      = "Mob-Dragon-South-9.png";
const std::string Graphics::mobDragonStandingEast                = "Mob-Dragon-Standing-East.png";
const std::string Graphics::mobDragonStandingNorth               = "Mob-Dragon-Standing-North.png";
const std::string Graphics::mobDragonStandingSouth               = "Mob-Dragon-Standing-South.png";
const std::string Graphics::mobDragonStandingWest                = "Mob-Dragon-Standing-West.png";
const std::string Graphics::mobDragonWest1                       = "Mob-Dragon-West-1.png";
const std::string Graphics::mobDragonWest10                      = "Mob-Dragon-West-10.png";
const std::string Graphics::mobDragonWest11                      = "Mob-Dragon-West-11.png";
const std::string Graphics::mobDragonWest2                       = "Mob-Dragon-West-2.png";
const std::string Graphics::mobDragonWest3                       = "Mob-Dragon-West-3.png";
const std::string Graphics::mobDragonWest4                       = "Mob-Dragon-West-4.png";
const std::string Graphics::mobDragonWest5                       = "Mob-Dragon-West-5.png";
const std::string Graphics::mobDragonWest6                       = "Mob-Dragon-West-6.png";
const std::string Graphics::mobDragonWest7                       = "Mob-Dragon-West-7.png";
const std::string Graphics::mobDragonWest8                       = "Mob-Dragon-West-8.png";
const std::string Graphics::mobDragonWest9                       = "Mob-Dragon-West-9.png";
const std::string Graphics::mobEliEast1                          = "Mob-Eli-East1.png";
const std::string Graphics::mobEliEast2                          = "Mob-Eli-East2.png";
const std::string Graphics::mobEliNorth1                         = "Mob-Eli-North1.png";
const std::string Graphics::mobEliNorth2                         = "Mob-Eli-North2.png";
const std::string Graphics::mobEliSouth1                         = "Mob-Eli-South1.png";
const std::string Graphics::mobEliSouth2                         = "Mob-Eli-South2.png";
const std::string Graphics::mobEliWest1                          = "Mob-Eli-West1.png";
const std::string Graphics::mobEliWest2                          = "Mob-Eli-West2.png";
const std::string Graphics::mobElyEast1                          = "Mob-Ely-East1.png";
const std::string Graphics::mobElyEast2                          = "Mob-Ely-East2.png";
const std::string Graphics::mobElyNorth1                         = "Mob-Ely-North1.png";
const std::string Graphics::mobElyNorth2                         = "Mob-Ely-North2.png";
const std::string Graphics::mobElySouth1                         = "Mob-Ely-South1.png";
const std::string Graphics::mobElySouth2                         = "Mob-Ely-South2.png";
const std::string Graphics::mobElyWest1                          = "Mob-Ely-West1.png";
const std::string Graphics::mobElyWest2                          = "Mob-Ely-West2.png";
const std::string Graphics::mobGolemMagmaEast1                   = "Mob-Golem-Magma-East1.png";
const std::string Graphics::mobGolemMagmaEast2                   = "Mob-Golem-Magma-East2.png";
const std::string Graphics::mobGolemMagmaEast3                   = "Mob-Golem-Magma-East3.png";
const std::string Graphics::mobGolemMagmaEast4                   = "Mob-Golem-Magma-East4.png";
const std::string Graphics::mobGolemMagmaEast5                   = "Mob-Golem-Magma-East5.png";
const std::string Graphics::mobGolemMagmaEast6                   = "Mob-Golem-Magma-East6.png";
const std::string Graphics::mobGolemMagmaEast7                   = "Mob-Golem-Magma-East7.png";
const std::string Graphics::mobGolemMagmaNorth1                  = "Mob-Golem-Magma-North1.png";
const std::string Graphics::mobGolemMagmaNorth2                  = "Mob-Golem-Magma-North2.png";
const std::string Graphics::mobGolemMagmaNorth3                  = "Mob-Golem-Magma-North3.png";
const std::string Graphics::mobGolemMagmaNorth4                  = "Mob-Golem-Magma-North4.png";
const std::string Graphics::mobGolemMagmaNorth5                  = "Mob-Golem-Magma-North5.png";
const std::string Graphics::mobGolemMagmaNorth6                  = "Mob-Golem-Magma-North6.png";
const std::string Graphics::mobGolemMagmaNorth7                  = "Mob-Golem-Magma-North7.png";
const std::string Graphics::mobGolemMagmaSouth1                  = "Mob-Golem-Magma-South1.png";
const std::string Graphics::mobGolemMagmaSouth2                  = "Mob-Golem-Magma-South2.png";
const std::string Graphics::mobGolemMagmaSouth3                  = "Mob-Golem-Magma-South3.png";
const std::string Graphics::mobGolemMagmaSouth4                  = "Mob-Golem-Magma-South4.png";
const std::string Graphics::mobGolemMagmaSouth5                  = "Mob-Golem-Magma-South5.png";
const std::string Graphics::mobGolemMagmaSouth6                  = "Mob-Golem-Magma-South6.png";
const std::string Graphics::mobGolemMagmaSouth7                  = "Mob-Golem-Magma-South7.png";
const std::string Graphics::mobGolemMagmaStandingEast            = "Mob-Golem-Magma-Standing-East.png";
const std::string Graphics::mobGolemMagmaStandingNorth           = "Mob-Golem-Magma-Standing-North.png";
const std::string Graphics::mobGolemMagmaStandingSouth           = "Mob-Golem-Magma-Standing-South.png";
const std::string Graphics::mobGolemMagmaStandingWest            = "Mob-Golem-Magma-Standing-West.png";
const std::string Graphics::mobGolemMagmaWest1                   = "Mob-Golem-Magma-West1.png";
const std::string Graphics::mobGolemMagmaWest2                   = "Mob-Golem-Magma-West2.png";
const std::string Graphics::mobGolemMagmaWest3                   = "Mob-Golem-Magma-West3.png";
const std::string Graphics::mobGolemMagmaWest4                   = "Mob-Golem-Magma-West4.png";
const std::string Graphics::mobGolemMagmaWest5                   = "Mob-Golem-Magma-West5.png";
const std::string Graphics::mobGolemMagmaWest6                   = "Mob-Golem-Magma-West6.png";
const std::string Graphics::mobGolemMagmaWest7                   = "Mob-Golem-Magma-West7.png";
const std::string Graphics::mobGolemStoneEast1                   = "Mob-Golem-Stone-East1.png";
const std::string Graphics::mobGolemStoneEast2                   = "Mob-Golem-Stone-East2.png";
const std::string Graphics::mobGolemStoneEast3                   = "Mob-Golem-Stone-East3.png";
const std::string Graphics::mobGolemStoneEast4                   = "Mob-Golem-Stone-East4.png";
const std::string Graphics::mobGolemStoneEast5                   = "Mob-Golem-Stone-East5.png";
const std::string Graphics::mobGolemStoneEast6                   = "Mob-Golem-Stone-East6.png";
const std::string Graphics::mobGolemStoneEast7                   = "Mob-Golem-Stone-East7.png";
const std::string Graphics::mobGolemStoneNorth1                  = "Mob-Golem-Stone-North1.png";
const std::string Graphics::mobGolemStoneNorth2                  = "Mob-Golem-Stone-North2.png";
const std::string Graphics::mobGolemStoneNorth3                  = "Mob-Golem-Stone-North3.png";
const std::string Graphics::mobGolemStoneNorth4                  = "Mob-Golem-Stone-North4.png";
const std::string Graphics::mobGolemStoneNorth5                  = "Mob-Golem-Stone-North5.png";
const std::string Graphics::mobGolemStoneNorth6                  = "Mob-Golem-Stone-North6.png";
const std::string Graphics::mobGolemStoneNorth7                  = "Mob-Golem-Stone-North7.png";
const std::string Graphics::mobGolemStoneSouth1                  = "Mob-Golem-Stone-South1.png";
const std::string Graphics::mobGolemStoneSouth2                  = "Mob-Golem-Stone-South2.png";
const std::string Graphics::mobGolemStoneSouth3                  = "Mob-Golem-Stone-South3.png";
const std::string Graphics::mobGolemStoneSouth4                  = "Mob-Golem-Stone-South4.png";
const std::string Graphics::mobGolemStoneSouth5                  = "Mob-Golem-Stone-South5.png";
const std::string Graphics::mobGolemStoneSouth6                  = "Mob-Golem-Stone-South6.png";
const std::string Graphics::mobGolemStoneSouth7                  = "Mob-Golem-Stone-South7.png";
const std::string Graphics::mobGolemStoneStandingEast            = "Mob-Golem-Stone-Standing-East.png";
const std::string Graphics::mobGolemStoneStandingNorth           = "Mob-Golem-Stone-Standing-North.png";
const std::string Graphics::mobGolemStoneStandingSouth           = "Mob-Golem-Stone-Standing-South.png";
const std::string Graphics::mobGolemStoneStandingWest            = "Mob-Golem-Stone-Standing-West.png";
const std::string Graphics::mobGolemStoneWest1                   = "Mob-Golem-Stone-West1.png";
const std::string Graphics::mobGolemStoneWest2                   = "Mob-Golem-Stone-West2.png";
const std::string Graphics::mobGolemStoneWest3                   = "Mob-Golem-Stone-West3.png";
const std::string Graphics::mobGolemStoneWest4                   = "Mob-Golem-Stone-West4.png";
const std::string Graphics::mobGolemStoneWest5                   = "Mob-Golem-Stone-West5.png";
const std::string Graphics::mobGolemStoneWest6                   = "Mob-Golem-Stone-West6.png";
const std::string Graphics::mobGolemStoneWest7                   = "Mob-Golem-Stone-West7.png";
const std::string Graphics::mobLeviathanEast1                    = "Mob-Leviathan-East-1.png";
const std::string Graphics::mobLeviathanEast2                    = "Mob-Leviathan-East-2.png";
const std::string Graphics::mobLeviathanEast3                    = "Mob-Leviathan-East-3.png";
const std::string Graphics::mobLeviathanEast4                    = "Mob-Leviathan-East-4.png";
const std::string Graphics::mobLeviathanNorth1                   = "Mob-Leviathan-North-1.png";
const std::string Graphics::mobLeviathanNorth2                   = "Mob-Leviathan-North-2.png";
const std::string Graphics::mobLeviathanNorth3                   = "Mob-Leviathan-North-3.png";
const std::string Graphics::mobLeviathanNorth4                   = "Mob-Leviathan-North-4.png";
const std::string Graphics::mobLeviathanSouth1                   = "Mob-Leviathan-South-1.png";
const std::string Graphics::mobLeviathanSouth2                   = "Mob-Leviathan-South-2.png";
const std::string Graphics::mobLeviathanSouth3                   = "Mob-Leviathan-South-3.png";
const std::string Graphics::mobLeviathanSouth4                   = "Mob-Leviathan-South-4.png";
const std::string Graphics::mobLeviathanStandingEast             = "Mob-Leviathan-Standing-East.png";
const std::string Graphics::mobLeviathanStandingNorth            = "Mob-Leviathan-Standing-North.png";
const std::string Graphics::mobLeviathanStandingSouth            = "Mob-Leviathan-Standing-South.png";
const std::string Graphics::mobLeviathanStandingWest             = "Mob-Leviathan-Standing-West.png";
const std::string Graphics::mobLeviathanWest1                    = "Mob-Leviathan-West-1.png";
const std::string Graphics::mobLeviathanWest2                    = "Mob-Leviathan-West-2.png";
const std::string Graphics::mobLeviathanWest3                    = "Mob-Leviathan-West-3.png";
const std::string Graphics::mobLeviathanWest4                    = "Mob-Leviathan-West-4.png";
const std::string Graphics::mobLicheEast1                        = "Mob-Liche-East1.png";
const std::string Graphics::mobLicheEast2                        = "Mob-Liche-East2.png";
const std::string Graphics::mobLicheEast3                        = "Mob-Liche-East3.png";
const std::string Graphics::mobLicheEast4                        = "Mob-Liche-East4.png";
const std::string Graphics::mobLicheEast5                        = "Mob-Liche-East5.png";
const std::string Graphics::mobLicheEast6                        = "Mob-Liche-East6.png";
const std::string Graphics::mobLicheEast7                        = "Mob-Liche-East7.png";
const std::string Graphics::mobLicheNorth1                       = "Mob-Liche-North1.png";
const std::string Graphics::mobLicheNorth2                       = "Mob-Liche-North2.png";
const std::string Graphics::mobLicheNorth3                       = "Mob-Liche-North3.png";
const std::string Graphics::mobLicheNorth4                       = "Mob-Liche-North4.png";
const std::string Graphics::mobLicheNorth5                       = "Mob-Liche-North5.png";
const std::string Graphics::mobLicheNorth6                       = "Mob-Liche-North6.png";
const std::string Graphics::mobLicheNorth7                       = "Mob-Liche-North7.png";
const std::string Graphics::mobLicheSouth1                       = "Mob-Liche-South1.png";
const std::string Graphics::mobLicheSouth2                       = "Mob-Liche-South2.png";
const std::string Graphics::mobLicheSouth3                       = "Mob-Liche-South3.png";
const std::string Graphics::mobLicheSouth4                       = "Mob-Liche-South4.png";
const std::string Graphics::mobLicheSouth5                       = "Mob-Liche-South5.png";
const std::string Graphics::mobLicheSouth6                       = "Mob-Liche-South6.png";
const std::string Graphics::mobLicheSouth7                       = "Mob-Liche-South7.png";
const std::string Graphics::mobLicheStantdingEast                = "Mob-Liche-Stantding-East.png";
const std::string Graphics::mobLicheStantdingNorth               = "Mob-Liche-Stantding-North.png";
const std::string Graphics::mobLicheStantdingSouth               = "Mob-Liche-Stantding-South.png";
const std::string Graphics::mobLicheStantdingWest                = "Mob-Liche-Stantding-West.png";
const std::string Graphics::mobLicheWest1                        = "Mob-Liche-West1.png";
const std::string Graphics::mobLicheWest2                        = "Mob-Liche-West2.png";
const std::string Graphics::mobLicheWest3                        = "Mob-Liche-West3.png";
const std::string Graphics::mobLicheWest4                        = "Mob-Liche-West4.png";
const std::string Graphics::mobLicheWest5                        = "Mob-Liche-West5.png";
const std::string Graphics::mobLicheWest6                        = "Mob-Liche-West6.png";
const std::string Graphics::mobLicheWest7                        = "Mob-Liche-West7.png";
const std::string Graphics::mobLineEast1                         = "Mob-Line-East1.png";
const std::string Graphics::mobLineEast2                         = "Mob-Line-East2.png";
const std::string Graphics::mobLineEast3                         = "Mob-Line-East3.png";
const std::string Graphics::mobLineEast4                         = "Mob-Line-East4.png";
const std::string Graphics::mobLineEast5                         = "Mob-Line-East5.png";
const std::string Graphics::mobLineEast6                         = "Mob-Line-East6.png";
const std::string Graphics::mobLineNorth1                        = "Mob-Line-North1.png";
const std::string Graphics::mobLineNorth2                        = "Mob-Line-North2.png";
const std::string Graphics::mobLineNorth3                        = "Mob-Line-North3.png";
const std::string Graphics::mobLineNorth4                        = "Mob-Line-North4.png";
const std::string Graphics::mobLineNorth5                        = "Mob-Line-North5.png";
const std::string Graphics::mobLineNorth6                        = "Mob-Line-North6.png";
const std::string Graphics::mobLineSouth1                        = "Mob-Line-South1.png";
const std::string Graphics::mobLineSouth2                        = "Mob-Line-South2.png";
const std::string Graphics::mobLineSouth3                        = "Mob-Line-South3.png";
const std::string Graphics::mobLineSouth4                        = "Mob-Line-South4.png";
const std::string Graphics::mobLineSouth5                        = "Mob-Line-South5.png";
const std::string Graphics::mobLineSouth6                        = "Mob-Line-South6.png";
const std::string Graphics::mobLineWest1                         = "Mob-Line-West1.png";
const std::string Graphics::mobLineWest2                         = "Mob-Line-West2.png";
const std::string Graphics::mobLineWest3                         = "Mob-Line-West3.png";
const std::string Graphics::mobLineWest4                         = "Mob-Line-West4.png";
const std::string Graphics::mobLineWest5                         = "Mob-Line-West5.png";
const std::string Graphics::mobLineWest6                         = "Mob-Line-West6.png";
const std::string Graphics::mobMermaidEast1                      = "Mob-Mermaid-East1.png";
const std::string Graphics::mobMermaidEast2                      = "Mob-Mermaid-East2.png";
const std::string Graphics::mobMermaidEast3                      = "Mob-Mermaid-East3.png";
const std::string Graphics::mobMermaidNorth1                     = "Mob-Mermaid-North1.png";
const std::string Graphics::mobMermaidNorth2                     = "Mob-Mermaid-North2.png";
const std::string Graphics::mobMermaidNorth3                     = "Mob-Mermaid-North3.png";
const std::string Graphics::mobMermaidSouth1                     = "Mob-Mermaid-South1.png";
const std::string Graphics::mobMermaidSouth2                     = "Mob-Mermaid-South2.png";
const std::string Graphics::mobMermaidSouth3                     = "Mob-Mermaid-South3.png";
const std::string Graphics::mobMermaidStandingEast               = "Mob-Mermaid-Standing-East.png";
const std::string Graphics::mobMermaidStandingNorth              = "Mob-Mermaid-Standing-North.png";
const std::string Graphics::mobMermaidStandingSouth              = "Mob-Mermaid-Standing-South.png";
const std::string Graphics::mobMermaidStandingWest               = "Mob-Mermaid-Standing-West.png";
const std::string Graphics::mobMermaidWest1                      = "Mob-Mermaid-West1.png";
const std::string Graphics::mobMermaidWest2                      = "Mob-Mermaid-West2.png";
const std::string Graphics::mobMermaidWest3                      = "Mob-Mermaid-West3.png";
const std::string Graphics::mobOctopusEast1                      = "Mob-Octopus-East1.png";
const std::string Graphics::mobOctopusEast2                      = "Mob-Octopus-East2.png";
const std::string Graphics::mobOctopusEast3                      = "Mob-Octopus-East3.png";
const std::string Graphics::mobOctopusNorth1                     = "Mob-Octopus-North1.png";
const std::string Graphics::mobOctopusNorth2                     = "Mob-Octopus-North2.png";
const std::string Graphics::mobOctopusNorth3                     = "Mob-Octopus-North3.png";
const std::string Graphics::mobOctopusSouth1                     = "Mob-Octopus-South1.png";
const std::string Graphics::mobOctopusSouth2                     = "Mob-Octopus-South2.png";
const std::string Graphics::mobOctopusSouth3                     = "Mob-Octopus-South3.png";
const std::string Graphics::mobOctopusStandingEast               = "Mob-Octopus-Standing-East.png";
const std::string Graphics::mobOctopusStandingNorth              = "Mob-Octopus-Standing-North.png";
const std::string Graphics::mobOctopusStandingSouth              = "Mob-Octopus-Standing-South.png";
const std::string Graphics::mobOctopusStandingWest               = "Mob-Octopus-Standing-West.png";
const std::string Graphics::mobOctopusWest1                      = "Mob-Octopus-West1.png";
const std::string Graphics::mobOctopusWest2                      = "Mob-Octopus-West2.png";
const std::string Graphics::mobOctopusWest3                      = "Mob-Octopus-West3.png";
const std::string Graphics::mobParrotEast1                       = "Mob-Parrot-East1.png";
const std::string Graphics::mobParrotEast2                       = "Mob-Parrot-East2.png";
const std::string Graphics::mobParrotNorth1                      = "Mob-Parrot-North1.png";
const std::string Graphics::mobParrotNorth2                      = "Mob-Parrot-North2.png";
const std::string Graphics::mobParrotSouth1                      = "Mob-Parrot-South1.png";
const std::string Graphics::mobParrotSouth2                      = "Mob-Parrot-South2.png";
const std::string Graphics::mobParrotWest1                       = "Mob-Parrot-West1.png";
const std::string Graphics::mobParrotWest2                       = "Mob-Parrot-West2.png";
const std::string Graphics::mobPiranhaEast1                      = "Mob-Piranha-East1.png";
const std::string Graphics::mobPiranhaEast2                      = "Mob-Piranha-East2.png";
const std::string Graphics::mobPiranhaNorth1                     = "Mob-Piranha-North1.png";
const std::string Graphics::mobPiranhaNorth2                     = "Mob-Piranha-North2.png";
const std::string Graphics::mobPiranhaSouth1                     = "Mob-Piranha-South1.png";
const std::string Graphics::mobPiranhaSouth2                     = "Mob-Piranha-South2.png";
const std::string Graphics::mobPiranhaStandingEast               = "Mob-Piranha-Standing-East.png";
const std::string Graphics::mobPiranhaStandingNorth              = "Mob-Piranha-Standing-North.png";
const std::string Graphics::mobPiranhaStandingSouth              = "Mob-Piranha-Standing-South.png";
const std::string Graphics::mobPiranhaStandingWest               = "Mob-Piranha-Standing-West.png";
const std::string Graphics::mobPiranhaWest1                      = "Mob-Piranha-West1.png";
const std::string Graphics::mobPiranhaWest2                      = "Mob-Piranha-West2.png";
const std::string Graphics::mobRabbitEast1                       = "Mob-Rabbit-East1.png";
const std::string Graphics::mobRabbitEast2                       = "Mob-Rabbit-East2.png";
const std::string Graphics::mobRabbitNorth1                      = "Mob-Rabbit-North1.png";
const std::string Graphics::mobRabbitNorth2                      = "Mob-Rabbit-North2.png";
const std::string Graphics::mobRabbitSouth1                      = "Mob-Rabbit-South1.png";
const std::string Graphics::mobRabbitSouth2                      = "Mob-Rabbit-South2.png";
const std::string Graphics::mobRabbitStandingEast                = "Mob-Rabbit-Standing-East.png";
const std::string Graphics::mobRabbitStandingNorth               = "Mob-Rabbit-Standing-North.png";
const std::string Graphics::mobRabbitStandingSouth               = "Mob-Rabbit-Standing-South.png";
const std::string Graphics::mobRabbitStandingWest                = "Mob-Rabbit-Standing-West.png";
const std::string Graphics::mobRabbitWest1                       = "Mob-Rabbit-West1.png";
const std::string Graphics::mobRabbitWest2                       = "Mob-Rabbit-West2.png";
const std::string Graphics::mobRavenBlackEast1                   = "Mob-Raven-Black-East1.png";
const std::string Graphics::mobRavenBlackEast2                   = "Mob-Raven-Black-East2.png";
const std::string Graphics::mobRavenBlackNorth1                  = "Mob-Raven-Black-North1.png";
const std::string Graphics::mobRavenBlackNorth2                  = "Mob-Raven-Black-North2.png";
const std::string Graphics::mobRavenBlackSouth1                  = "Mob-Raven-Black-South1.png";
const std::string Graphics::mobRavenBlackSouth2                  = "Mob-Raven-Black-South2.png";
const std::string Graphics::mobRavenBlackWest1                   = "Mob-Raven-Black-West1.png";
const std::string Graphics::mobRavenBlackWest2                   = "Mob-Raven-Black-West2.png";
const std::string Graphics::mobRavenWhiteEast1                   = "Mob-Raven-White-East1.png";
const std::string Graphics::mobRavenWhiteEast2                   = "Mob-Raven-White-East2.png";
const std::string Graphics::mobRavenWhiteNorth1                  = "Mob-Raven-White-North1.png";
const std::string Graphics::mobRavenWhiteNorth2                  = "Mob-Raven-White-North2.png";
const std::string Graphics::mobRavenWhiteSouth1                  = "Mob-Raven-White-South1.png";
const std::string Graphics::mobRavenWhiteSouth2                  = "Mob-Raven-White-South2.png";
const std::string Graphics::mobRavenWhiteWest1                   = "Mob-Raven-White-West1.png";
const std::string Graphics::mobRavenWhiteWest2                   = "Mob-Raven-White-West2.png";
const std::string Graphics::mobSnakeDoubleHeadGreenEast1         = "Mob-SnakeDoubleHead-Green-East1.png";
const std::string Graphics::mobSnakeDoubleHeadGreenEast2         = "Mob-SnakeDoubleHead-Green-East2.png";
const std::string Graphics::mobSnakeDoubleHeadGreenNorth1        = "Mob-SnakeDoubleHead-Green-North1.png";
const std::string Graphics::mobSnakeDoubleHeadGreenNorth2        = "Mob-SnakeDoubleHead-Green-North2.png";
const std::string Graphics::mobSnakeDoubleHeadGreenSouth1        = "Mob-SnakeDoubleHead-Green-South1.png";
const std::string Graphics::mobSnakeDoubleHeadGreenSouth2        = "Mob-SnakeDoubleHead-Green-South2.png";
const std::string Graphics::mobSnakeDoubleHeadGreenStandingEast  = "Mob-SnakeDoubleHead-Green-Standing-East.png";
const std::string Graphics::mobSnakeDoubleHeadGreenStandingNorth = "Mob-SnakeDoubleHead-Green-Standing-North.png";
const std::string Graphics::mobSnakeDoubleHeadGreenStandingSouth = "Mob-SnakeDoubleHead-Green-Standing-South.png";
const std::string Graphics::mobSnakeDoubleHeadGreenStandingWest  = "Mob-SnakeDoubleHead-Green-Standing-West.png";
const std::string Graphics::mobSnakeDoubleHeadGreenWest1         = "Mob-SnakeDoubleHead-Green-West1.png";
const std::string Graphics::mobSnakeDoubleHeadGreenWest2         = "Mob-SnakeDoubleHead-Green-West2.png";
const std::string Graphics::mobSnakeGreenEast1                   = "Mob-Snake-Green-East1.png";
const std::string Graphics::mobSnakeGreenEast2                   = "Mob-Snake-Green-East2.png";
const std::string Graphics::mobSnakeGreenNorth1                  = "Mob-Snake-Green-North1.png";
const std::string Graphics::mobSnakeGreenNorth2                  = "Mob-Snake-Green-North2.png";
const std::string Graphics::mobSnakeGreenSouth1                  = "Mob-Snake-Green-South1.png";
const std::string Graphics::mobSnakeGreenSouth2                  = "Mob-Snake-Green-South2.png";
const std::string Graphics::mobSnakeGreenStandingEast            = "Mob-Snake-Green-Standing-East.png";
const std::string Graphics::mobSnakeGreenStandingNorth           = "Mob-Snake-Green-Standing-North.png";
const std::string Graphics::mobSnakeGreenStandingSouth           = "Mob-Snake-Green-Standing-South.png";
const std::string Graphics::mobSnakeGreenStandingWest            = "Mob-Snake-Green-Standing-West.png";
const std::string Graphics::mobSnakeGreenWest1                   = "Mob-Snake-Green-West1.png";
const std::string Graphics::mobSnakeGreenWest2                   = "Mob-Snake-Green-West2.png";
const std::string Graphics::mobSnakeRedEast1                     = "Mob-Snake-Red-East1.png";
const std::string Graphics::mobSnakeRedEast2                     = "Mob-Snake-Red-East2.png";
const std::string Graphics::mobSnakeRedNorth1                    = "Mob-Snake-Red-North1.png";
const std::string Graphics::mobSnakeRedNorth2                    = "Mob-Snake-Red-North2.png";
const std::string Graphics::mobSnakeRedSouth1                    = "Mob-Snake-Red-South1.png";
const std::string Graphics::mobSnakeRedSouth2                    = "Mob-Snake-Red-South2.png";
const std::string Graphics::mobSnakeRedStandingEast              = "Mob-Snake-Red-Standing-East.png";
const std::string Graphics::mobSnakeRedStandingNorth             = "Mob-Snake-Red-Standing-North.png";
const std::string Graphics::mobSnakeRedStandingSouth             = "Mob-Snake-Red-Standing-South.png";
const std::string Graphics::mobSnakeRedStandingWest              = "Mob-Snake-Red-Standing-West.png";
const std::string Graphics::mobSnakeRedWest1                     = "Mob-Snake-Red-West1.png";
const std::string Graphics::mobSnakeRedWest2                     = "Mob-Snake-Red-West2.png";
const std::string Graphics::mobSpiderBrownEast1                  = "Mob-Spider-Brown-East1.png";
const std::string Graphics::mobSpiderBrownEast2                  = "Mob-Spider-Brown-East2.png";
const std::string Graphics::mobSpiderBrownEast3                  = "Mob-Spider-Brown-East3.png";
const std::string Graphics::mobSpiderBrownNorth1                 = "Mob-Spider-Brown-North1.png";
const std::string Graphics::mobSpiderBrownNorth2                 = "Mob-Spider-Brown-North2.png";
const std::string Graphics::mobSpiderBrownNorth3                 = "Mob-Spider-Brown-North3.png";
const std::string Graphics::mobSpiderBrownSouth1                 = "Mob-Spider-Brown-South1.png";
const std::string Graphics::mobSpiderBrownSouth2                 = "Mob-Spider-Brown-South2.png";
const std::string Graphics::mobSpiderBrownSouth3                 = "Mob-Spider-Brown-South3.png";
const std::string Graphics::mobSpiderBrownStandingEast           = "Mob-Spider-Brown-Standing-East.png";
const std::string Graphics::mobSpiderBrownStandingNorth          = "Mob-Spider-Brown-Standing-North.png";
const std::string Graphics::mobSpiderBrownStandingSouth          = "Mob-Spider-Brown-Standing-South.png";
const std::string Graphics::mobSpiderBrownStandingWest           = "Mob-Spider-Brown-Standing-West.png";
const std::string Graphics::mobSpiderBrownWest1                  = "Mob-Spider-Brown-West1.png";
const std::string Graphics::mobSpiderBrownWest2                  = "Mob-Spider-Brown-West2.png";
const std::string Graphics::mobSpiderBrownWest3                  = "Mob-Spider-Brown-West3.png";
const std::string Graphics::mobSpiderNormalEast1                 = "Mob-Spider-Normal-East1.png";
const std::string Graphics::mobSpiderNormalEast2                 = "Mob-Spider-Normal-East2.png";
const std::string Graphics::mobSpiderNormalEast3                 = "Mob-Spider-Normal-East3.png";
const std::string Graphics::mobSpiderNormalNorth1                = "Mob-Spider-Normal-North1.png";
const std::string Graphics::mobSpiderNormalNorth2                = "Mob-Spider-Normal-North2.png";
const std::string Graphics::mobSpiderNormalNorth3                = "Mob-Spider-Normal-North3.png";
const std::string Graphics::mobSpiderNormalSouth1                = "Mob-Spider-Normal-South1.png";
const std::string Graphics::mobSpiderNormalSouth2                = "Mob-Spider-Normal-South2.png";
const std::string Graphics::mobSpiderNormalSouth3                = "Mob-Spider-Normal-South3.png";
const std::string Graphics::mobSpiderNormalStandingEast          = "Mob-Spider-Normal-Standing-East.png";
const std::string Graphics::mobSpiderNormalStandingNorth         = "Mob-Spider-Normal-Standing-North.png";
const std::string Graphics::mobSpiderNormalStandingSouth         = "Mob-Spider-Normal-Standing-South.png";
const std::string Graphics::mobSpiderNormalStandingWest          = "Mob-Spider-Normal-Standing-West.png";
const std::string Graphics::mobSpiderNormalWest1                 = "Mob-Spider-Normal-West1.png";
const std::string Graphics::mobSpiderNormalWest2                 = "Mob-Spider-Normal-West2.png";
const std::string Graphics::mobSpiderNormalWest3                 = "Mob-Spider-Normal-West3.png";
const std::string Graphics::mobTigerEast1                        = "Mob-Tiger-East1.png";
const std::string Graphics::mobTigerEast2                        = "Mob-Tiger-East2.png";
const std::string Graphics::mobTigerEast3                        = "Mob-Tiger-East3.png";
const std::string Graphics::mobTigerNorth1                       = "Mob-Tiger-North1.png";
const std::string Graphics::mobTigerNorth2                       = "Mob-Tiger-North2.png";
const std::string Graphics::mobTigerNorth3                       = "Mob-Tiger-North3.png";
const std::string Graphics::mobTigerSouth1                       = "Mob-Tiger-South1.png";
const std::string Graphics::mobTigerSouth2                       = "Mob-Tiger-South2.png";
const std::string Graphics::mobTigerSouth3                       = "Mob-Tiger-South3.png";
const std::string Graphics::mobTigerStandingEast                 = "Mob-Tiger-Standing-East.png";
const std::string Graphics::mobTigerStandingNorth                = "Mob-Tiger-Standing-North.png";
const std::string Graphics::mobTigerStandingSouth                = "Mob-Tiger-Standing-South.png";
const std::string Graphics::mobTigerStandingWest                 = "Mob-Tiger-Standing-West.png";
const std::string Graphics::mobTigerWest1                        = "Mob-Tiger-West1.png";
const std::string Graphics::mobTigerWest2                        = "Mob-Tiger-West2.png";
const std::string Graphics::mobTigerWest3                        = "Mob-Tiger-West3.png";
const std::string Graphics::mobTurtleEast1                       = "Mob-Turtle-East-1.png";
const std::string Graphics::mobTurtleEast2                       = "Mob-Turtle-East-2.png";
const std::string Graphics::mobTurtleEast3                       = "Mob-Turtle-East-3.png";
const std::string Graphics::mobTurtleEast4                       = "Mob-Turtle-East-4.png";
const std::string Graphics::mobTurtleEast5                       = "Mob-Turtle-East-5.png";
const std::string Graphics::mobTurtleNorth1                      = "Mob-Turtle-North-1.png";
const std::string Graphics::mobTurtleNorth2                      = "Mob-Turtle-North-2.png";
const std::string Graphics::mobTurtleNorth3                      = "Mob-Turtle-North-3.png";
const std::string Graphics::mobTurtleNorth4                      = "Mob-Turtle-North-4.png";
const std::string Graphics::mobTurtleNorth5                      = "Mob-Turtle-North-5.png";
const std::string Graphics::mobTurtleSouth1                      = "Mob-Turtle-South-1.png";
const std::string Graphics::mobTurtleSouth2                      = "Mob-Turtle-South-2.png";
const std::string Graphics::mobTurtleSouth3                      = "Mob-Turtle-South-3.png";
const std::string Graphics::mobTurtleSouth4                      = "Mob-Turtle-South-4.png";
const std::string Graphics::mobTurtleSouth5                      = "Mob-Turtle-South-5.png";
const std::string Graphics::mobTurtleStandingEast                = "Mob-Turtle-Standing-East.png";
const std::string Graphics::mobTurtleStandingNorth               = "Mob-Turtle-Standing-North.png";
const std::string Graphics::mobTurtleStandingSouth               = "Mob-Turtle-Standing-South.png";
const std::string Graphics::mobTurtleStandingWest                = "Mob-Turtle-Standing-West.png";
const std::string Graphics::mobTurtleWest1                       = "Mob-Turtle-West-1.png";
const std::string Graphics::mobTurtleWest2                       = "Mob-Turtle-West-2.png";
const std::string Graphics::mobTurtleWest3                       = "Mob-Turtle-West-3.png";
const std::string Graphics::mobTurtleWest4                       = "Mob-Turtle-West-4.png";
const std::string Graphics::mobTurtleWest5                       = "Mob-Turtle-West-5.png";
const std::string Graphics::mobWildPigEast1                      = "Mob-WildPig-East1.png";
const std::string Graphics::mobWildPigEast2                      = "Mob-WildPig-East2.png";
const std::string Graphics::mobWildPigEast3                      = "Mob-WildPig-East3.png";
const std::string Graphics::mobWildPigEast4                      = "Mob-WildPig-East4.png";
const std::string Graphics::mobWildPigEast5                      = "Mob-WildPig-East5.png";
const std::string Graphics::mobWildPigEast6                      = "Mob-WildPig-East6.png";
const std::string Graphics::mobWildPigEast7                      = "Mob-WildPig-East7.png";
const std::string Graphics::mobWildPigNorth1                     = "Mob-WildPig-North1.png";
const std::string Graphics::mobWildPigNorth2                     = "Mob-WildPig-North2.png";
const std::string Graphics::mobWildPigNorth3                     = "Mob-WildPig-North3.png";
const std::string Graphics::mobWildPigNorth4                     = "Mob-WildPig-North4.png";
const std::string Graphics::mobWildPigNorth5                     = "Mob-WildPig-North5.png";
const std::string Graphics::mobWildPigNorth6                     = "Mob-WildPig-North6.png";
const std::string Graphics::mobWildPigNorth7                     = "Mob-WildPig-North7.png";
const std::string Graphics::mobWildPigSouth1                     = "Mob-WildPig-South1.png";
const std::string Graphics::mobWildPigSouth2                     = "Mob-WildPig-South2.png";
const std::string Graphics::mobWildPigSouth3                     = "Mob-WildPig-South3.png";
const std::string Graphics::mobWildPigSouth4                     = "Mob-WildPig-South4.png";
const std::string Graphics::mobWildPigSouth5                     = "Mob-WildPig-South5.png";
const std::string Graphics::mobWildPigSouth6                     = "Mob-WildPig-South6.png";
const std::string Graphics::mobWildPigSouth7                     = "Mob-WildPig-South7.png";
const std::string Graphics::mobWildPigStandingEast               = "Mob-WildPig-Standing-East.png";
const std::string Graphics::mobWildPigStandingNorth              = "Mob-WildPig-Standing-North.png";
const std::string Graphics::mobWildPigStandingSouth              = "Mob-WildPig-Standing-South.png";
const std::string Graphics::mobWildPigStandingWest               = "Mob-WildPig-Standing-West.png";
const std::string Graphics::mobWildPigWest1                      = "Mob-WildPig-West1.png";
const std::string Graphics::mobWildPigWest2                      = "Mob-WildPig-West2.png";
const std::string Graphics::mobWildPigWest3                      = "Mob-WildPig-West3.png";
const std::string Graphics::mobWildPigWest4                      = "Mob-WildPig-West4.png";
const std::string Graphics::mobWildPigWest5                      = "Mob-WildPig-West5.png";
const std::string Graphics::mobWildPigWest6                      = "Mob-WildPig-West6.png";
const std::string Graphics::mobWildPigWest7                      = "Mob-WildPig-West7.png";
const std::string Graphics::nPCBankEast1                         = "NPC-Bank-East1.png";
const std::string Graphics::nPCBankEast2                         = "NPC-Bank-East2.png";
const std::string Graphics::nPCBankEast3                         = "NPC-Bank-East3.png";
const std::string Graphics::nPCBankEast4                         = "NPC-Bank-East4.png";
const std::string Graphics::nPCBankEast5                         = "NPC-Bank-East5.png";
const std::string Graphics::nPCBankNorth1                        = "NPC-Bank-North1.png";
const std::string Graphics::nPCBankNorth2                        = "NPC-Bank-North2.png";
const std::string Graphics::nPCBankNorth3                        = "NPC-Bank-North3.png";
const std::string Graphics::nPCBankNorth4                        = "NPC-Bank-North4.png";
const std::string Graphics::nPCBankNorth5                        = "NPC-Bank-North5.png";
const std::string Graphics::nPCBankSouth1                        = "NPC-Bank-South1.png";
const std::string Graphics::nPCBankSouth2                        = "NPC-Bank-South2.png";
const std::string Graphics::nPCBankSouth3                        = "NPC-Bank-South3.png";
const std::string Graphics::nPCBankSouth4                        = "NPC-Bank-South4.png";
const std::string Graphics::nPCBankSouth5                        = "NPC-Bank-South5.png";
const std::string Graphics::nPCBankStandingEast                  = "NPC-Bank-Standing-East.png";
const std::string Graphics::nPCBankStandingNorth                 = "NPC-Bank-Standing-North.png";
const std::string Graphics::nPCBankStandingSouth                 = "NPC-Bank-Standing-South.png";
const std::string Graphics::nPCBankStandingWest                  = "NPC-Bank-Standing-West.png";
const std::string Graphics::nPCBankWest1                         = "NPC-Bank-West1.png";
const std::string Graphics::nPCBankWest2                         = "NPC-Bank-West2.png";
const std::string Graphics::nPCBankWest3                         = "NPC-Bank-West3.png";
const std::string Graphics::nPCBankWest4                         = "NPC-Bank-West4.png";
const std::string Graphics::nPCBankWest5                         = "NPC-Bank-West5.png";
const std::string Graphics::nPCClothesEast1                      = "NPC-Clothes-East1.png";
const std::string Graphics::nPCClothesEast2                      = "NPC-Clothes-East2.png";
const std::string Graphics::nPCClothesNorth1                     = "NPC-Clothes-North1.png";
const std::string Graphics::nPCClothesNorth2                     = "NPC-Clothes-North2.png";
const std::string Graphics::nPCClothesSouth1                     = "NPC-Clothes-South1.png";
const std::string Graphics::nPCClothesSouth2                     = "NPC-Clothes-South2.png";
const std::string Graphics::nPCClothesStandingEast               = "NPC-Clothes-Standing-East.png";
const std::string Graphics::nPCClothesStandingNorth              = "NPC-Clothes-Standing-North.png";
const std::string Graphics::nPCClothesStandingSouth              = "NPC-Clothes-Standing-South.png";
const std::string Graphics::nPCClothesStandingWest               = "NPC-Clothes-Standing-West.png";
const std::string Graphics::nPCClothesWest1                      = "NPC-Clothes-West1.png";
const std::string Graphics::nPCClothesWest2                      = "NPC-Clothes-West2.png";
const std::string Graphics::nPCFoodAndDrinksEast1                = "NPC-FoodAndDrinks-East1.png";
const std::string Graphics::nPCFoodAndDrinksEast2                = "NPC-FoodAndDrinks-East2.png";
const std::string Graphics::nPCFoodAndDrinksEast3                = "NPC-FoodAndDrinks-East3.png";
const std::string Graphics::nPCFoodAndDrinksEast4                = "NPC-FoodAndDrinks-East4.png";
const std::string Graphics::nPCFoodAndDrinksEast5                = "NPC-FoodAndDrinks-East5.png";
const std::string Graphics::nPCFoodAndDrinksNorth1               = "NPC-FoodAndDrinks-North1.png";
const std::string Graphics::nPCFoodAndDrinksNorth2               = "NPC-FoodAndDrinks-North2.png";
const std::string Graphics::nPCFoodAndDrinksNorth3               = "NPC-FoodAndDrinks-North3.png";
const std::string Graphics::nPCFoodAndDrinksNorth4               = "NPC-FoodAndDrinks-North4.png";
const std::string Graphics::nPCFoodAndDrinksNorth5               = "NPC-FoodAndDrinks-North5.png";
const std::string Graphics::nPCFoodAndDrinksSouth1               = "NPC-FoodAndDrinks-South1.png";
const std::string Graphics::nPCFoodAndDrinksSouth2               = "NPC-FoodAndDrinks-South2.png";
const std::string Graphics::nPCFoodAndDrinksSouth3               = "NPC-FoodAndDrinks-South3.png";
const std::string Graphics::nPCFoodAndDrinksSouth4               = "NPC-FoodAndDrinks-South4.png";
const std::string Graphics::nPCFoodAndDrinksSouth5               = "NPC-FoodAndDrinks-South5.png";
const std::string Graphics::nPCFoodAndDrinksStandingEast         = "NPC-FoodAndDrinks-Standing-East.png";
const std::string Graphics::nPCFoodAndDrinksStandingNorth        = "NPC-FoodAndDrinks-Standing-North.png";
const std::string Graphics::nPCFoodAndDrinksStandingSouth        = "NPC-FoodAndDrinks-Standing-South.png";
const std::string Graphics::nPCFoodAndDrinksStandingWest         = "NPC-FoodAndDrinks-Standing-West.png";
const std::string Graphics::nPCFoodAndDrinksWest1                = "NPC-FoodAndDrinks-West1.png";
const std::string Graphics::nPCFoodAndDrinksWest2                = "NPC-FoodAndDrinks-West2.png";
const std::string Graphics::nPCFoodAndDrinksWest3                = "NPC-FoodAndDrinks-West3.png";
const std::string Graphics::nPCFoodAndDrinksWest4                = "NPC-FoodAndDrinks-West4.png";
const std::string Graphics::nPCFoodAndDrinksWest5                = "NPC-FoodAndDrinks-West5.png";
const std::string Graphics::nPCHomeLessAEast                     = "NPC-HomeLess-A-East.png";
const std::string Graphics::nPCHomeLessASouth                    = "NPC-HomeLess-A-South.png";
const std::string Graphics::nPCHomeLessAWest                     = "NPC-HomeLess-A-West.png";
const std::string Graphics::nPCHomeLessBEast                     = "NPC-HomeLess-B-East.png";
const std::string Graphics::nPCHomeLessBSouth                    = "NPC-HomeLess-B-South.png";
const std::string Graphics::nPCHomeLessBWest                     = "NPC-HomeLess-B-West.png";
const std::string Graphics::nPCHomeLessCEast                     = "NPC-HomeLess-C-East.png";
const std::string Graphics::nPCHomeLessCSouth                    = "NPC-HomeLess-C-South.png";
const std::string Graphics::nPCHomeLessCWest                     = "NPC-HomeLess-C-West.png";
const std::string Graphics::nPCHomeLessDEast                     = "NPC-HomeLess-D-East.png";
const std::string Graphics::nPCHomeLessDSouth                    = "NPC-HomeLess-D-South.png";
const std::string Graphics::nPCPotionsEast1                      = "NPC-Potions-East1.png";
const std::string Graphics::nPCPotionsEast2                      = "NPC-Potions-East2.png";
const std::string Graphics::nPCPotionsNorth1                     = "NPC-Potions-North1.png";
const std::string Graphics::nPCPotionsNorth2                     = "NPC-Potions-North2.png";
const std::string Graphics::nPCPotionsSouth1                     = "NPC-Potions-South1.png";
const std::string Graphics::nPCPotionsSouth2                     = "NPC-Potions-South2.png";
const std::string Graphics::nPCPotionsStandingEast               = "NPC-Potions-Standing-East.png";
const std::string Graphics::nPCPotionsStandingNorth              = "NPC-Potions-Standing-North.png";
const std::string Graphics::nPCPotionsStandingSouth              = "NPC-Potions-Standing-South.png";
const std::string Graphics::nPCPotionsStandingWest               = "NPC-Potions-Standing-West.png";
const std::string Graphics::nPCPotionsWest1                      = "NPC-Potions-West1.png";
const std::string Graphics::nPCPotionsWest2                      = "NPC-Potions-West2.png";
const std::string Graphics::nPCStreetArtistA0                    = "NPC-StreetArtist-A-0.png";
const std::string Graphics::nPCStreetArtistA1                    = "NPC-StreetArtist-A-1.png";
const std::string Graphics::nPCStreetArtistA2                    = "NPC-StreetArtist-A-2.png";
const std::string Graphics::nPCStreetArtistB0                    = "NPC-StreetArtist-B-0.png";
const std::string Graphics::nPCStreetArtistB1                    = "NPC-StreetArtist-B-1.png";
const std::string Graphics::nPCStreetArtistB2                    = "NPC-StreetArtist-B-2.png";
const std::string Graphics::nPCStreetArtistC0                    = "NPC-StreetArtist-C-0.png";
const std::string Graphics::nPCStreetArtistC1                    = "NPC-StreetArtist-C-1.png";
const std::string Graphics::nPCStreetArtistC2                    = "NPC-StreetArtist-C-2.png";
const std::string Graphics::playerBodyDarkElfFemaleEast01        = "Player-Body-DarkElf-Female-East01.png";
const std::string Graphics::playerBodyDarkElfFemaleEast02        = "Player-Body-DarkElf-Female-East02.png";
const std::string Graphics::playerBodyDarkElfFemaleEast03        = "Player-Body-DarkElf-Female-East03.png";
const std::string Graphics::playerBodyDarkElfFemaleEast04        = "Player-Body-DarkElf-Female-East04.png";
const std::string Graphics::playerBodyDarkElfFemaleNorth01       = "Player-Body-DarkElf-Female-North01.png";
const std::string Graphics::playerBodyDarkElfFemaleNorth02       = "Player-Body-DarkElf-Female-North02.png";
const std::string Graphics::playerBodyDarkElfFemaleNorth03       = "Player-Body-DarkElf-Female-North03.png";
const std::string Graphics::playerBodyDarkElfFemaleNorth04       = "Player-Body-DarkElf-Female-North04.png";
const std::string Graphics::playerBodyDarkElfFemaleNorth05       = "Player-Body-DarkElf-Female-North05.png";
const std::string Graphics::playerBodyDarkElfFemaleSouth01       = "Player-Body-DarkElf-Female-South01.png";
const std::string Graphics::playerBodyDarkElfFemaleSouth02       = "Player-Body-DarkElf-Female-South02.png";
const std::string Graphics::playerBodyDarkElfFemaleSouth03       = "Player-Body-DarkElf-Female-South03.png";
const std::string Graphics::playerBodyDarkElfFemaleSouth04       = "Player-Body-DarkElf-Female-South04.png";
const std::string Graphics::playerBodyDarkElfFemaleSouth05       = "Player-Body-DarkElf-Female-South05.png";
const std::string Graphics::playerBodyDarkElfFemaleStandingEast  = "Player-Body-DarkElf-Female-Standing-East.png";
const std::string Graphics::playerBodyDarkElfFemaleStandingNorth = "Player-Body-DarkElf-Female-Standing-North.png";
const std::string Graphics::playerBodyDarkElfFemaleStandingSouth = "Player-Body-DarkElf-Female-Standing-South.png";
const std::string Graphics::playerBodyDarkElfFemaleStandingWest  = "Player-Body-DarkElf-Female-Standing-West.png";
const std::string Graphics::playerBodyDarkElfFemaleWest01        = "Player-Body-DarkElf-Female-West01.png";
const std::string Graphics::playerBodyDarkElfFemaleWest02        = "Player-Body-DarkElf-Female-West02.png";
const std::string Graphics::playerBodyDarkElfFemaleWest03        = "Player-Body-DarkElf-Female-West03.png";
const std::string Graphics::playerBodyDarkElfFemaleWest04        = "Player-Body-DarkElf-Female-West04.png";
const std::string Graphics::playerBodyDarkElfMaleEast1           = "Player-Body-DarkElf-Male-East1.png";
const std::string Graphics::playerBodyDarkElfMaleEast2           = "Player-Body-DarkElf-Male-East2.png";
const std::string Graphics::playerBodyDarkElfMaleEast3           = "Player-Body-DarkElf-Male-East3.png";
const std::string Graphics::playerBodyDarkElfMaleEast4           = "Player-Body-DarkElf-Male-East4.png";
const std::string Graphics::playerBodyDarkElfMaleNorth1          = "Player-Body-DarkElf-Male-North1.png";
const std::string Graphics::playerBodyDarkElfMaleNorth2          = "Player-Body-DarkElf-Male-North2.png";
const std::string Graphics::playerBodyDarkElfMaleNorth3          = "Player-Body-DarkElf-Male-North3.png";
const std::string Graphics::playerBodyDarkElfMaleNorth4          = "Player-Body-DarkElf-Male-North4.png";
const std::string Graphics::playerBodyDarkElfMaleNorth5          = "Player-Body-DarkElf-Male-North5.png";
const std::string Graphics::playerBodyDarkElfMaleSouth1          = "Player-Body-DarkElf-Male-South1.png";
const std::string Graphics::playerBodyDarkElfMaleSouth2          = "Player-Body-DarkElf-Male-South2.png";
const std::string Graphics::playerBodyDarkElfMaleSouth3          = "Player-Body-DarkElf-Male-South3.png";
const std::string Graphics::playerBodyDarkElfMaleSouth4          = "Player-Body-DarkElf-Male-South4.png";
const std::string Graphics::playerBodyDarkElfMaleSouth5          = "Player-Body-DarkElf-Male-South5.png";
const std::string Graphics::playerBodyDarkElfMaleStandingEast    = "Player-Body-DarkElf-Male-Standing-East.png";
const std::string Graphics::playerBodyDarkElfMaleStandingNorth   = "Player-Body-DarkElf-Male-Standing-North.png";
const std::string Graphics::playerBodyDarkElfMaleStandingSouth   = "Player-Body-DarkElf-Male-Standing-South.png";
const std::string Graphics::playerBodyDarkElfMaleStandingWest    = "Player-Body-DarkElf-Male-Standing-West.png";
const std::string Graphics::playerBodyDarkElfMaleWest1           = "Player-Body-DarkElf-Male-West1.png";
const std::string Graphics::playerBodyDarkElfMaleWest2           = "Player-Body-DarkElf-Male-West2.png";
const std::string Graphics::playerBodyDarkElfMaleWest3           = "Player-Body-DarkElf-Male-West3.png";
const std::string Graphics::playerBodyDarkElfMaleWest4           = "Player-Body-DarkElf-Male-West4.png";
const std::string Graphics::playerBodyDwarfFemaleEast1           = "Player-Body-Dwarf-Female-East1.png";
const std::string Graphics::playerBodyDwarfFemaleEast2           = "Player-Body-Dwarf-Female-East2.png";
const std::string Graphics::playerBodyDwarfFemaleEast3           = "Player-Body-Dwarf-Female-East3.png";
const std::string Graphics::playerBodyDwarfFemaleEast4           = "Player-Body-Dwarf-Female-East4.png";
const std::string Graphics::playerBodyDwarfFemaleNorth1          = "Player-Body-Dwarf-Female-North1.png";
const std::string Graphics::playerBodyDwarfFemaleNorth2          = "Player-Body-Dwarf-Female-North2.png";
const std::string Graphics::playerBodyDwarfFemaleNorth3          = "Player-Body-Dwarf-Female-North3.png";
const std::string Graphics::playerBodyDwarfFemaleNorth4          = "Player-Body-Dwarf-Female-North4.png";
const std::string Graphics::playerBodyDwarfFemaleNorth5          = "Player-Body-Dwarf-Female-North5.png";
const std::string Graphics::playerBodyDwarfFemaleSouth1          = "Player-Body-Dwarf-Female-South1.png";
const std::string Graphics::playerBodyDwarfFemaleSouth2          = "Player-Body-Dwarf-Female-South2.png";
const std::string Graphics::playerBodyDwarfFemaleSouth3          = "Player-Body-Dwarf-Female-South3.png";
const std::string Graphics::playerBodyDwarfFemaleSouth4          = "Player-Body-Dwarf-Female-South4.png";
const std::string Graphics::playerBodyDwarfFemaleSouth5          = "Player-Body-Dwarf-Female-South5.png";
const std::string Graphics::playerBodyDwarfFemaleStandingEast    = "Player-Body-Dwarf-Female-Standing-East.png";
const std::string Graphics::playerBodyDwarfFemaleStandingNorth   = "Player-Body-Dwarf-Female-Standing-North.png";
const std::string Graphics::playerBodyDwarfFemaleStandingSouth   = "Player-Body-Dwarf-Female-Standing-South.png";
const std::string Graphics::playerBodyDwarfFemaleStandingWest    = "Player-Body-Dwarf-Female-Standing-West.png";
const std::string Graphics::playerBodyDwarfFemaleWest1           = "Player-Body-Dwarf-Female-West1.png";
const std::string Graphics::playerBodyDwarfFemaleWest2           = "Player-Body-Dwarf-Female-West2.png";
const std::string Graphics::playerBodyDwarfFemaleWest3           = "Player-Body-Dwarf-Female-West3.png";
const std::string Graphics::playerBodyDwarfFemaleWest4           = "Player-Body-Dwarf-Female-West4.png";
const std::string Graphics::playerBodyDwarfMaleEast1             = "Player-Body-Dwarf-Male-East1.png";
const std::string Graphics::playerBodyDwarfMaleEast2             = "Player-Body-Dwarf-Male-East2.png";
const std::string Graphics::playerBodyDwarfMaleEast3             = "Player-Body-Dwarf-Male-East3.png";
const std::string Graphics::playerBodyDwarfMaleEast4             = "Player-Body-Dwarf-Male-East4.png";
const std::string Graphics::playerBodyDwarfMaleNorth1            = "Player-Body-Dwarf-Male-North1.png";
const std::string Graphics::playerBodyDwarfMaleNorth2            = "Player-Body-Dwarf-Male-North2.png";
const std::string Graphics::playerBodyDwarfMaleNorth3            = "Player-Body-Dwarf-Male-North3.png";
const std::string Graphics::playerBodyDwarfMaleNorth4            = "Player-Body-Dwarf-Male-North4.png";
const std::string Graphics::playerBodyDwarfMaleNorth5            = "Player-Body-Dwarf-Male-North5.png";
const std::string Graphics::playerBodyDwarfMaleSouth1            = "Player-Body-Dwarf-Male-South1.png";
const std::string Graphics::playerBodyDwarfMaleSouth2            = "Player-Body-Dwarf-Male-South2.png";
const std::string Graphics::playerBodyDwarfMaleSouth3            = "Player-Body-Dwarf-Male-South3.png";
const std::string Graphics::playerBodyDwarfMaleSouth4            = "Player-Body-Dwarf-Male-South4.png";
const std::string Graphics::playerBodyDwarfMaleSouth5            = "Player-Body-Dwarf-Male-South5.png";
const std::string Graphics::playerBodyDwarfMaleStandingEast      = "Player-Body-Dwarf-Male-Standing-East.png";
const std::string Graphics::playerBodyDwarfMaleStandingNorth     = "Player-Body-Dwarf-Male-Standing-North.png";
const std::string Graphics::playerBodyDwarfMaleStandingSouth     = "Player-Body-Dwarf-Male-Standing-South.png";
const std::string Graphics::playerBodyDwarfMaleStandingWest      = "Player-Body-Dwarf-Male-Standing-West.png";
const std::string Graphics::playerBodyDwarfMaleWest1             = "Player-Body-Dwarf-Male-West1.png";
const std::string Graphics::playerBodyDwarfMaleWest2             = "Player-Body-Dwarf-Male-West2.png";
const std::string Graphics::playerBodyDwarfMaleWest3             = "Player-Body-Dwarf-Male-West3.png";
const std::string Graphics::playerBodyDwarfMaleWest4             = "Player-Body-Dwarf-Male-West4.png";
const std::string Graphics::playerBodyElfFemaleEast1             = "Player-Body-Elf-Female-East1.png";
const std::string Graphics::playerBodyElfFemaleEast2             = "Player-Body-Elf-Female-East2.png";
const std::string Graphics::playerBodyElfFemaleEast3             = "Player-Body-Elf-Female-East3.png";
const std::string Graphics::playerBodyElfFemaleEast4             = "Player-Body-Elf-Female-East4.png";
const std::string Graphics::playerBodyElfFemaleNorth1            = "Player-Body-Elf-Female-North1.png";
const std::string Graphics::playerBodyElfFemaleNorth2            = "Player-Body-Elf-Female-North2.png";
const std::string Graphics::playerBodyElfFemaleNorth3            = "Player-Body-Elf-Female-North3.png";
const std::string Graphics::playerBodyElfFemaleNorth4            = "Player-Body-Elf-Female-North4.png";
const std::string Graphics::playerBodyElfFemaleNorth5            = "Player-Body-Elf-Female-North5.png";
const std::string Graphics::playerBodyElfFemaleSouth1            = "Player-Body-Elf-Female-South1.png";
const std::string Graphics::playerBodyElfFemaleSouth2            = "Player-Body-Elf-Female-South2.png";
const std::string Graphics::playerBodyElfFemaleSouth3            = "Player-Body-Elf-Female-South3.png";
const std::string Graphics::playerBodyElfFemaleSouth4            = "Player-Body-Elf-Female-South4.png";
const std::string Graphics::playerBodyElfFemaleSouth5            = "Player-Body-Elf-Female-South5.png";
const std::string Graphics::playerBodyElfFemaleStandingEast      = "Player-Body-Elf-Female-Standing-East.png";
const std::string Graphics::playerBodyElfFemaleStandingNorth     = "Player-Body-Elf-Female-Standing-North.png";
const std::string Graphics::playerBodyElfFemaleStandingSouth     = "Player-Body-Elf-Female-Standing-South.png";
const std::string Graphics::playerBodyElfFemaleStandingWest      = "Player-Body-Elf-Female-Standing-West.png";
const std::string Graphics::playerBodyElfFemaleWest1             = "Player-Body-Elf-Female-West1.png";
const std::string Graphics::playerBodyElfFemaleWest2             = "Player-Body-Elf-Female-West2.png";
const std::string Graphics::playerBodyElfFemaleWest3             = "Player-Body-Elf-Female-West3.png";
const std::string Graphics::playerBodyElfFemaleWest4             = "Player-Body-Elf-Female-West4.png";
const std::string Graphics::playerBodyElfMaleEast1               = "Player-Body-Elf-Male-East1.png";
const std::string Graphics::playerBodyElfMaleEast2               = "Player-Body-Elf-Male-East2.png";
const std::string Graphics::playerBodyElfMaleEast3               = "Player-Body-Elf-Male-East3.png";
const std::string Graphics::playerBodyElfMaleEast4               = "Player-Body-Elf-Male-East4.png";
const std::string Graphics::playerBodyElfMaleNorth1              = "Player-Body-Elf-Male-North1.png";
const std::string Graphics::playerBodyElfMaleNorth2              = "Player-Body-Elf-Male-North2.png";
const std::string Graphics::playerBodyElfMaleNorth3              = "Player-Body-Elf-Male-North3.png";
const std::string Graphics::playerBodyElfMaleNorth4              = "Player-Body-Elf-Male-North4.png";
const std::string Graphics::playerBodyElfMaleNorth5              = "Player-Body-Elf-Male-North5.png";
const std::string Graphics::playerBodyElfMaleSouth1              = "Player-Body-Elf-Male-South1.png";
const std::string Graphics::playerBodyElfMaleSouth2              = "Player-Body-Elf-Male-South2.png";
const std::string Graphics::playerBodyElfMaleSouth3              = "Player-Body-Elf-Male-South3.png";
const std::string Graphics::playerBodyElfMaleSouth4              = "Player-Body-Elf-Male-South4.png";
const std::string Graphics::playerBodyElfMaleSouth5              = "Player-Body-Elf-Male-South5.png";
const std::string Graphics::playerBodyElfMaleStandingEast        = "Player-Body-Elf-Male-Standing-East.png";
const std::string Graphics::playerBodyElfMaleStandingNorth       = "Player-Body-Elf-Male-Standing-North.png";
const std::string Graphics::playerBodyElfMaleStandingSouth       = "Player-Body-Elf-Male-Standing-South.png";
const std::string Graphics::playerBodyElfMaleStandingWest        = "Player-Body-Elf-Male-Standing-West.png";
const std::string Graphics::playerBodyElfMaleWest1               = "Player-Body-Elf-Male-West1.png";
const std::string Graphics::playerBodyElfMaleWest2               = "Player-Body-Elf-Male-West2.png";
const std::string Graphics::playerBodyElfMaleWest3               = "Player-Body-Elf-Male-West3.png";
const std::string Graphics::playerBodyElfMaleWest4               = "Player-Body-Elf-Male-West4.png";
const std::string Graphics::playerBodyGnomeFemaleEast1           = "Player-Body-Gnome-Female-East1.png";
const std::string Graphics::playerBodyGnomeFemaleEast2           = "Player-Body-Gnome-Female-East2.png";
const std::string Graphics::playerBodyGnomeFemaleEast3           = "Player-Body-Gnome-Female-East3.png";
const std::string Graphics::playerBodyGnomeFemaleEast4           = "Player-Body-Gnome-Female-East4.png";
const std::string Graphics::playerBodyGnomeFemaleNorth1          = "Player-Body-Gnome-Female-North1.png";
const std::string Graphics::playerBodyGnomeFemaleNorth2          = "Player-Body-Gnome-Female-North2.png";
const std::string Graphics::playerBodyGnomeFemaleNorth3          = "Player-Body-Gnome-Female-North3.png";
const std::string Graphics::playerBodyGnomeFemaleNorth4          = "Player-Body-Gnome-Female-North4.png";
const std::string Graphics::playerBodyGnomeFemaleNorth5          = "Player-Body-Gnome-Female-North5.png";
const std::string Graphics::playerBodyGnomeFemaleSouth1          = "Player-Body-Gnome-Female-South1.png";
const std::string Graphics::playerBodyGnomeFemaleSouth2          = "Player-Body-Gnome-Female-South2.png";
const std::string Graphics::playerBodyGnomeFemaleSouth3          = "Player-Body-Gnome-Female-South3.png";
const std::string Graphics::playerBodyGnomeFemaleSouth4          = "Player-Body-Gnome-Female-South4.png";
const std::string Graphics::playerBodyGnomeFemaleSouth5          = "Player-Body-Gnome-Female-South5.png";
const std::string Graphics::playerBodyGnomeFemaleStandingEast    = "Player-Body-Gnome-Female-Standing-East.png";
const std::string Graphics::playerBodyGnomeFemaleStandingNorth   = "Player-Body-Gnome-Female-Standing-North.png";
const std::string Graphics::playerBodyGnomeFemaleStandingSouth   = "Player-Body-Gnome-Female-Standing-South.png";
const std::string Graphics::playerBodyGnomeFemaleStandingWest    = "Player-Body-Gnome-Female-Standing-West.png";
const std::string Graphics::playerBodyGnomeFemaleWest1           = "Player-Body-Gnome-Female-West1.png";
const std::string Graphics::playerBodyGnomeFemaleWest2           = "Player-Body-Gnome-Female-West2.png";
const std::string Graphics::playerBodyGnomeFemaleWest3           = "Player-Body-Gnome-Female-West3.png";
const std::string Graphics::playerBodyGnomeFemaleWest4           = "Player-Body-Gnome-Female-West4.png";
const std::string Graphics::playerBodyGnomeMaleEast1             = "Player-Body-Gnome-Male-East1.png";
const std::string Graphics::playerBodyGnomeMaleEast2             = "Player-Body-Gnome-Male-East2.png";
const std::string Graphics::playerBodyGnomeMaleEast3             = "Player-Body-Gnome-Male-East3.png";
const std::string Graphics::playerBodyGnomeMaleEast4             = "Player-Body-Gnome-Male-East4.png";
const std::string Graphics::playerBodyGnomeMaleNorth1            = "Player-Body-Gnome-Male-North1.png";
const std::string Graphics::playerBodyGnomeMaleNorth2            = "Player-Body-Gnome-Male-North2.png";
const std::string Graphics::playerBodyGnomeMaleNorth3            = "Player-Body-Gnome-Male-North3.png";
const std::string Graphics::playerBodyGnomeMaleNorth4            = "Player-Body-Gnome-Male-North4.png";
const std::string Graphics::playerBodyGnomeMaleNorth5            = "Player-Body-Gnome-Male-North5.png";
const std::string Graphics::playerBodyGnomeMaleSouth1            = "Player-Body-Gnome-Male-South1.png";
const std::string Graphics::playerBodyGnomeMaleSouth2            = "Player-Body-Gnome-Male-South2.png";
const std::string Graphics::playerBodyGnomeMaleSouth3            = "Player-Body-Gnome-Male-South3.png";
const std::string Graphics::playerBodyGnomeMaleSouth4            = "Player-Body-Gnome-Male-South4.png";
const std::string Graphics::playerBodyGnomeMaleSouth5            = "Player-Body-Gnome-Male-South5.png";
const std::string Graphics::playerBodyGnomeMaleStandingEast      = "Player-Body-Gnome-Male-Standing-East.png";
const std::string Graphics::playerBodyGnomeMaleStandingNorth     = "Player-Body-Gnome-Male-Standing-North.png";
const std::string Graphics::playerBodyGnomeMaleStandingSouth     = "Player-Body-Gnome-Male-Standing-South.png";
const std::string Graphics::playerBodyGnomeMaleStandingWest      = "Player-Body-Gnome-Male-Standing-West.png";
const std::string Graphics::playerBodyGnomeMaleWest1             = "Player-Body-Gnome-Male-West1.png";
const std::string Graphics::playerBodyGnomeMaleWest2             = "Player-Body-Gnome-Male-West2.png";
const std::string Graphics::playerBodyGnomeMaleWest3             = "Player-Body-Gnome-Male-West3.png";
const std::string Graphics::playerBodyGnomeMaleWest4             = "Player-Body-Gnome-Male-West4.png";
const std::string Graphics::playerBodyHumanFemaleEast1           = "Player-Body-Human-Female-East1.png";
const std::string Graphics::playerBodyHumanFemaleEast2           = "Player-Body-Human-Female-East2.png";
const std::string Graphics::playerBodyHumanFemaleEast3           = "Player-Body-Human-Female-East3.png";
const std::string Graphics::playerBodyHumanFemaleEast4           = "Player-Body-Human-Female-East4.png";
const std::string Graphics::playerBodyHumanFemaleNorth1          = "Player-Body-Human-Female-North1.png";
const std::string Graphics::playerBodyHumanFemaleNorth2          = "Player-Body-Human-Female-North2.png";
const std::string Graphics::playerBodyHumanFemaleNorth3          = "Player-Body-Human-Female-North3.png";
const std::string Graphics::playerBodyHumanFemaleNorth4          = "Player-Body-Human-Female-North4.png";
const std::string Graphics::playerBodyHumanFemaleNorth5          = "Player-Body-Human-Female-North5.png";
const std::string Graphics::playerBodyHumanFemaleSouth1          = "Player-Body-Human-Female-South1.png";
const std::string Graphics::playerBodyHumanFemaleSouth2          = "Player-Body-Human-Female-South2.png";
const std::string Graphics::playerBodyHumanFemaleSouth3          = "Player-Body-Human-Female-South3.png";
const std::string Graphics::playerBodyHumanFemaleSouth4          = "Player-Body-Human-Female-South4.png";
const std::string Graphics::playerBodyHumanFemaleSouth5          = "Player-Body-Human-Female-South5.png";
const std::string Graphics::playerBodyHumanFemaleStandingEast    = "Player-Body-Human-Female-Standing-East.png";
const std::string Graphics::playerBodyHumanFemaleStandingNorth   = "Player-Body-Human-Female-Standing-North.png";
const std::string Graphics::playerBodyHumanFemaleStandingSouth   = "Player-Body-Human-Female-Standing-South.png";
const std::string Graphics::playerBodyHumanFemaleStandingWest    = "Player-Body-Human-Female-Standing-West.png";
const std::string Graphics::playerBodyHumanFemaleWest1           = "Player-Body-Human-Female-West1.png";
const std::string Graphics::playerBodyHumanFemaleWest2           = "Player-Body-Human-Female-West2.png";
const std::string Graphics::playerBodyHumanFemaleWest3           = "Player-Body-Human-Female-West3.png";
const std::string Graphics::playerBodyHumanFemaleWest4           = "Player-Body-Human-Female-West4.png";
const std::string Graphics::playerBodyHumanMaleEast1             = "Player-Body-Human-Male-East1.png";
const std::string Graphics::playerBodyHumanMaleEast2             = "Player-Body-Human-Male-East2.png";
const std::string Graphics::playerBodyHumanMaleEast3             = "Player-Body-Human-Male-East3.png";
const std::string Graphics::playerBodyHumanMaleEast4             = "Player-Body-Human-Male-East4.png";
const std::string Graphics::playerBodyHumanMaleNorth1            = "Player-Body-Human-Male-North1.png";
const std::string Graphics::playerBodyHumanMaleNorth2            = "Player-Body-Human-Male-North2.png";
const std::string Graphics::playerBodyHumanMaleNorth3            = "Player-Body-Human-Male-North3.png";
const std::string Graphics::playerBodyHumanMaleNorth4            = "Player-Body-Human-Male-North4.png";
const std::string Graphics::playerBodyHumanMaleNorth5            = "Player-Body-Human-Male-North5.png";
const std::string Graphics::playerBodyHumanMaleSouth1            = "Player-Body-Human-Male-South1.png";
const std::string Graphics::playerBodyHumanMaleSouth2            = "Player-Body-Human-Male-South2.png";
const std::string Graphics::playerBodyHumanMaleSouth3            = "Player-Body-Human-Male-South3.png";
const std::string Graphics::playerBodyHumanMaleSouth4            = "Player-Body-Human-Male-South4.png";
const std::string Graphics::playerBodyHumanMaleSouth5            = "Player-Body-Human-Male-South5.png";
const std::string Graphics::playerBodyHumanMaleStandingEast      = "Player-Body-Human-Male-Standing-East.png";
const std::string Graphics::playerBodyHumanMaleStandingNorth     = "Player-Body-Human-Male-Standing-North.png";
const std::string Graphics::playerBodyHumanMaleStandingSouth     = "Player-Body-Human-Male-Standing-South.png";
const std::string Graphics::playerBodyHumanMaleStandingWest      = "Player-Body-Human-Male-Standing-West.png";
const std::string Graphics::playerBodyHumanMaleWest1             = "Player-Body-Human-Male-West1.png";
const std::string Graphics::playerBodyHumanMaleWest2             = "Player-Body-Human-Male-West2.png";
const std::string Graphics::playerBodyHumanMaleWest3             = "Player-Body-Human-Male-West3.png";
const std::string Graphics::playerBodyHumanMaleWest4             = "Player-Body-Human-Male-West4.png";
const std::string Graphics::playerCasperBodyEast1                = "Player-Casper-Body-East1.png";
const std::string Graphics::playerCasperBodyEast2                = "Player-Casper-Body-East2.png";
const std::string Graphics::playerCasperBodyNorth1               = "Player-Casper-Body-North1.png";
const std::string Graphics::playerCasperBodyNorth2               = "Player-Casper-Body-North2.png";
const std::string Graphics::playerCasperBodySouth1               = "Player-Casper-Body-South1.png";
const std::string Graphics::playerCasperBodySouth2               = "Player-Casper-Body-South2.png";
const std::string Graphics::playerCasperBodyStandingEast         = "Player-Casper-Body-Standing-East.png";
const std::string Graphics::playerCasperBodyStandingNorth        = "Player-Casper-Body-Standing-North.png";
const std::string Graphics::playerCasperBodyStandingSouth        = "Player-Casper-Body-Standing-South.png";
const std::string Graphics::playerCasperBodyStandingWest         = "Player-Casper-Body-Standing-West.png";
const std::string Graphics::playerCasperBodyWest1                = "Player-Casper-Body-West1.png";
const std::string Graphics::playerCasperBodyWest2                = "Player-Casper-Body-West2.png";
const std::string Graphics::playerCasperDarkEast1                = "Player-Casper-Dark-East1.png";
const std::string Graphics::playerCasperDarkEast2                = "Player-Casper-Dark-East2.png";
const std::string Graphics::playerCasperDarkNorth1               = "Player-Casper-Dark-North1.png";
const std::string Graphics::playerCasperDarkNorth2               = "Player-Casper-Dark-North2.png";
const std::string Graphics::playerCasperDarkSouth1               = "Player-Casper-Dark-South1.png";
const std::string Graphics::playerCasperDarkSouth2               = "Player-Casper-Dark-South2.png";
const std::string Graphics::playerCasperDarkStandingEast         = "Player-Casper-Dark-Standing-East.png";
const std::string Graphics::playerCasperDarkStandingNorth        = "Player-Casper-Dark-Standing-North.png";
const std::string Graphics::playerCasperDarkStandingSouth        = "Player-Casper-Dark-Standing-South.png";
const std::string Graphics::playerCasperDarkStandingWest         = "Player-Casper-Dark-Standing-West.png";
const std::string Graphics::playerCasperDarkWest1                = "Player-Casper-Dark-West1.png";
const std::string Graphics::playerCasperDarkWest2                = "Player-Casper-Dark-West2.png";
const std::string Graphics::playerHandShieldIronEast1            = "Player-Hand-Shield-Iron-East1.png";
const std::string Graphics::playerHandShieldIronEast2            = "Player-Hand-Shield-Iron-East2.png";
const std::string Graphics::playerHandShieldIronEast3            = "Player-Hand-Shield-Iron-East3.png";
const std::string Graphics::playerHandShieldIronEast4            = "Player-Hand-Shield-Iron-East4.png";
const std::string Graphics::playerHandShieldIronNorth1           = "Player-Hand-Shield-Iron-North1.png";
const std::string Graphics::playerHandShieldIronNorth2           = "Player-Hand-Shield-Iron-North2.png";
const std::string Graphics::playerHandShieldIronNorth3           = "Player-Hand-Shield-Iron-North3.png";
const std::string Graphics::playerHandShieldIronNorth4           = "Player-Hand-Shield-Iron-North4.png";
const std::string Graphics::playerHandShieldIronNorth5           = "Player-Hand-Shield-Iron-North5.png";
const std::string Graphics::playerHandShieldIronSouth1           = "Player-Hand-Shield-Iron-South1.png";
const std::string Graphics::playerHandShieldIronSouth2           = "Player-Hand-Shield-Iron-South2.png";
const std::string Graphics::playerHandShieldIronSouth3           = "Player-Hand-Shield-Iron-South3.png";
const std::string Graphics::playerHandShieldIronSouth4           = "Player-Hand-Shield-Iron-South4.png";
const std::string Graphics::playerHandShieldIronSouth5           = "Player-Hand-Shield-Iron-South5.png";
const std::string Graphics::playerHandShieldIronStandingEast     = "Player-Hand-Shield-Iron-Standing-East.png";
const std::string Graphics::playerHandShieldIronStandingNorth    = "Player-Hand-Shield-Iron-Standing-North.png";
const std::string Graphics::playerHandShieldIronStandingSouth    = "Player-Hand-Shield-Iron-Standing-South.png";
const std::string Graphics::playerHandShieldIronStandingWest     = "Player-Hand-Shield-Iron-Standing-West.png";
const std::string Graphics::playerHandShieldIronWest1            = "Player-Hand-Shield-Iron-West1.png";
const std::string Graphics::playerHandShieldIronWest2            = "Player-Hand-Shield-Iron-West2.png";
const std::string Graphics::playerHandShieldIronWest3            = "Player-Hand-Shield-Iron-West3.png";
const std::string Graphics::playerHandShieldIronWest4            = "Player-Hand-Shield-Iron-West4.png";
const std::string Graphics::playerHatBlueEast                    = "Player-Hat-Blue-East.png";
const std::string Graphics::playerHatBlueNorth                   = "Player-Hat-Blue-North.png";
const std::string Graphics::playerHatBlueSouth                   = "Player-Hat-Blue-South.png";
const std::string Graphics::playerHatBlueWest                    = "Player-Hat-Blue-West.png";
const std::string Graphics::playerHatNoviceEast                  = "Player-Hat-Novice-East.png";
const std::string Graphics::playerHatNoviceNorth                 = "Player-Hat-Novice-North.png";
const std::string Graphics::playerHatNoviceSouth                 = "Player-Hat-Novice-South.png";
const std::string Graphics::playerHatNoviceWest                  = "Player-Hat-Novice-West.png";
const std::string Graphics::playerHatProEast                     = "Player-Hat-Pro-East.png";
const std::string Graphics::playerHatProNorth                    = "Player-Hat-Pro-North.png";
const std::string Graphics::playerHatProSouth                    = "Player-Hat-Pro-South.png";
const std::string Graphics::playerHatProWest                     = "Player-Hat-Pro-West.png";
const std::string Graphics::playerHelmetBearEast                 = "Player-Helmet-Bear-East.png";
const std::string Graphics::playerHelmetBearNorth                = "Player-Helmet-Bear-North.png";
const std::string Graphics::playerHelmetBearSouth                = "Player-Helmet-Bear-South.png";
const std::string Graphics::playerHelmetBearWest                 = "Player-Helmet-Bear-West.png";
const std::string Graphics::playerHelmetEagleEast                = "Player-Helmet-Eagle-East.png";
const std::string Graphics::playerHelmetEagleNorth               = "Player-Helmet-Eagle-North.png";
const std::string Graphics::playerHelmetEagleSouth               = "Player-Helmet-Eagle-South.png";
const std::string Graphics::playerHelmetEagleWest                = "Player-Helmet-Eagle-West.png";
const std::string Graphics::playerHelmetIronEast                 = "Player-Helmet-Iron-East.png";
const std::string Graphics::playerHelmetIronNorth                = "Player-Helmet-Iron-North.png";
const std::string Graphics::playerHelmetIronProEast              = "Player-Helmet-IronPro-East.png";
const std::string Graphics::playerHelmetIronProNorth             = "Player-Helmet-IronPro-North.png";
const std::string Graphics::playerHelmetIronProSouth             = "Player-Helmet-IronPro-South.png";
const std::string Graphics::playerHelmetIronProWest              = "Player-Helmet-IronPro-West.png";
const std::string Graphics::playerHelmetIronSouth                = "Player-Helmet-Iron-South.png";
const std::string Graphics::playerHelmetIronWest                 = "Player-Helmet-Iron-West.png";
const std::string Graphics::playerHelmetSilverEast               = "Player-Helmet-Silver-East.png";
const std::string Graphics::playerHelmetSilverNorth              = "Player-Helmet-Silver-North.png";
const std::string Graphics::playerHelmetSilverSouth              = "Player-Helmet-Silver-South.png";
const std::string Graphics::playerHelmetSilverWest               = "Player-Helmet-Silver-West.png";
const std::string Graphics::playerHelmetTigerEast                = "Player-Helmet-Tiger-East.png";
const std::string Graphics::playerHelmetTigerNorth               = "Player-Helmet-Tiger-North.png";
const std::string Graphics::playerHelmetTigerSouth               = "Player-Helmet-Tiger-South.png";
const std::string Graphics::playerHelmetTigerWest                = "Player-Helmet-Tiger-West.png";
const std::string Graphics::playerHelmetWolfEast                 = "Player-Helmet-Wolf-East.png";
const std::string Graphics::playerHelmetWolfNorth                = "Player-Helmet-Wolf-North.png";
const std::string Graphics::playerHelmetWolfSouth                = "Player-Helmet-Wolf-South.png";
const std::string Graphics::playerHelmetWolfWest                 = "Player-Helmet-Wolf-West.png";
const std::string Graphics::playerHoodBlackEast                  = "Player-Hood-Black-East.png";
const std::string Graphics::playerHoodBlackNorth                 = "Player-Hood-Black-North.png";
const std::string Graphics::playerHoodBlackSouth                 = "Player-Hood-Black-South.png";
const std::string Graphics::playerHoodBlackWest                  = "Player-Hood-Black-West.png";
const std::string Graphics::playerHoodBrownEast                  = "Player-Hood-Brown-East.png";
const std::string Graphics::playerHoodBrownNorth                 = "Player-Hood-Brown-North.png";
const std::string Graphics::playerHoodBrownSouth                 = "Player-Hood-Brown-South.png";
const std::string Graphics::playerHoodBrownWest                  = "Player-Hood-Brown-West.png";
const std::string Graphics::playerKerchiefRedEast                = "Player-Kerchief-Red-East.png";
const std::string Graphics::playerKerchiefRedNorth               = "Player-Kerchief-Red-North.png";
const std::string Graphics::playerKerchiefRedSouth               = "Player-Kerchief-Red-South.png";
const std::string Graphics::playerKerchiefRedWest                = "Player-Kerchief-Red-West.png";
const std::string Graphics::spawnBrown01                         = "Spawn-Brown01.png";
const std::string Graphics::spawnBrown02                         = "Spawn-Brown02.png";
const std::string Graphics::spawnBrown03                         = "Spawn-Brown03.png";
const std::string Graphics::spawnBrown04                         = "Spawn-Brown04.png";
const std::string Graphics::spawnBrown05                         = "Spawn-Brown05.png";
const std::string Graphics::spawnBrown06                         = "Spawn-Brown06.png";
const std::string Graphics::spawnBrown07                         = "Spawn-Brown07.png";
const std::string Graphics::spawnBrown08                         = "Spawn-Brown08.png";
const std::string Graphics::spawnBrown09                         = "Spawn-Brown09.png";
const std::string Graphics::spawnBrown10                         = "Spawn-Brown10.png";
const std::string Graphics::spawnBrown11                         = "Spawn-Brown11.png";
const std::string Graphics::spawnBrown12                         = "Spawn-Brown12.png";
const std::string Graphics::spawnBrown13                         = "Spawn-Brown13.png";
const std::string Graphics::spawnBrown14                         = "Spawn-Brown14.png";
const std::string Graphics::spawnBrown15                         = "Spawn-Brown15.png";
const std::string Graphics::spawnGreen01                         = "Spawn-Green01.png";
const std::string Graphics::spawnGreen02                         = "Spawn-Green02.png";
const std::string Graphics::spawnGreen03                         = "Spawn-Green03.png";
const std::string Graphics::spawnGreen04                         = "Spawn-Green04.png";
const std::string Graphics::spawnGreen05                         = "Spawn-Green05.png";
const std::string Graphics::spawnGreen06                         = "Spawn-Green06.png";
const std::string Graphics::spawnGreen07                         = "Spawn-Green07.png";
const std::string Graphics::spawnGreen08                         = "Spawn-Green08.png";
const std::string Graphics::spawnGreen09                         = "Spawn-Green09.png";
const std::string Graphics::spawnGreen10                         = "Spawn-Green10.png";
const std::string Graphics::spawnGreen11                         = "Spawn-Green11.png";
const std::string Graphics::spawnGreen12                         = "Spawn-Green12.png";
const std::string Graphics::spawnGreen13                         = "Spawn-Green13.png";
const std::string Graphics::spawnGreen14                         = "Spawn-Green14.png";
const std::string Graphics::spawnGreen15                         = "Spawn-Green15.png";
const std::string Graphics::spellApocalipsis01                   = "Spell-Apocalipsis01.png";
const std::string Graphics::spellApocalipsis02                   = "Spell-Apocalipsis02.png";
const std::string Graphics::spellApocalipsis03                   = "Spell-Apocalipsis03.png";
const std::string Graphics::spellApocalipsis04                   = "Spell-Apocalipsis04.png";
const std::string Graphics::spellApocalipsis05                   = "Spell-Apocalipsis05.png";
const std::string Graphics::spellApocalipsis06                   = "Spell-Apocalipsis06.png";
const std::string Graphics::spellApocalipsis07                   = "Spell-Apocalipsis07.png";
const std::string Graphics::spellApocalipsis08                   = "Spell-Apocalipsis08.png";
const std::string Graphics::spellApocalipsis09                   = "Spell-Apocalipsis09.png";
const std::string Graphics::spellApocalipsis10                   = "Spell-Apocalipsis10.png";
const std::string Graphics::spellApocalipsis11                   = "Spell-Apocalipsis11.png";
const std::string Graphics::spellApocalipsis12                   = "Spell-Apocalipsis12.png";
const std::string Graphics::spellApocalipsis13                   = "Spell-Apocalipsis13.png";
const std::string Graphics::spellApocalipsis14                   = "Spell-Apocalipsis14.png";
const std::string Graphics::spellApocalipsis15                   = "Spell-Apocalipsis15.png";
const std::string Graphics::spellApocalipsis16                   = "Spell-Apocalipsis16.png";
const std::string Graphics::spellApocalipsis17                   = "Spell-Apocalipsis17.png";
const std::string Graphics::spellApocalipsis18                   = "Spell-Apocalipsis18.png";
const std::string Graphics::spellApocalipsis19                   = "Spell-Apocalipsis19.png";
const std::string Graphics::spellApocalipsis20                   = "Spell-Apocalipsis20.png";
const std::string Graphics::spellApocalipsis21                   = "Spell-Apocalipsis21.png";
const std::string Graphics::spellDescargaElectrica01             = "Spell-DescargaElectrica01.png";
const std::string Graphics::spellDescargaElectrica02             = "Spell-DescargaElectrica02.png";
const std::string Graphics::spellDescargaElectrica03             = "Spell-DescargaElectrica03.png";
const std::string Graphics::spellDescargaElectrica04             = "Spell-DescargaElectrica04.png";
const std::string Graphics::spellDescargaElectrica05             = "Spell-DescargaElectrica05.png";
const std::string Graphics::spellDescargaElectrica06             = "Spell-DescargaElectrica06.png";
const std::string Graphics::spellDescargaElectrica07             = "Spell-DescargaElectrica07.png";
const std::string Graphics::spellDescargaElectrica08             = "Spell-DescargaElectrica08.png";
const std::string Graphics::spellDescargaElectrica09             = "Spell-DescargaElectrica09.png";
const std::string Graphics::spellDescargaElectrica10             = "Spell-DescargaElectrica10.png";
const std::string Graphics::spellDescargaElectrica11             = "Spell-DescargaElectrica11.png";
const std::string Graphics::spellDescargaElectrica12             = "Spell-DescargaElectrica12.png";
const std::string Graphics::spellDescargaElectrica13             = "Spell-DescargaElectrica13.png";
const std::string Graphics::spellDescargaElectrica14             = "Spell-DescargaElectrica14.png";
const std::string Graphics::spellDescargaElectrica15             = "Spell-DescargaElectrica15.png";
const std::string Graphics::spellFireStorm01                     = "Spell-FireStorm-01.png";
const std::string Graphics::spellFireStorm02                     = "Spell-FireStorm-02.png";
const std::string Graphics::spellFireStorm03                     = "Spell-FireStorm-03.png";
const std::string Graphics::spellFireStorm04                     = "Spell-FireStorm-04.png";
const std::string Graphics::spellFireStorm05                     = "Spell-FireStorm-05.png";
const std::string Graphics::spellFireStorm06                     = "Spell-FireStorm-06.png";
const std::string Graphics::spellFireStorm07                     = "Spell-FireStorm-07.png";
const std::string Graphics::spellFireStorm08                     = "Spell-FireStorm-08.png";
const std::string Graphics::spellFireStorm09                     = "Spell-FireStorm-09.png";
const std::string Graphics::spellFireStorm10                     = "Spell-FireStorm-10.png";
const std::string Graphics::spellFireStorm11                     = "Spell-FireStorm-11.png";
const std::string Graphics::spellFireStorm12                     = "Spell-FireStorm-12.png";
const std::string Graphics::spellFireStorm13                     = "Spell-FireStorm-13.png";
const std::string Graphics::spellFireStorm14                     = "Spell-FireStorm-14.png";
const std::string Graphics::spellFireStorm15                     = "Spell-FireStorm-15.png";
const std::string Graphics::spellHealPoison0                     = "Spell-HealPoison-0.png";
const std::string Graphics::spellHealPoison1                     = "Spell-HealPoison-1.png";
const std::string Graphics::spellHealPoison2                     = "Spell-HealPoison-2.png";
const std::string Graphics::spellImmobilize0                     = "Spell-Immobilize-0.png";
const std::string Graphics::spellImmobilize1                     = "Spell-Immobilize-1.png";
const std::string Graphics::spellImmobilize10                    = "Spell-Immobilize-10.png";
const std::string Graphics::spellImmobilize11                    = "Spell-Immobilize-11.png";
const std::string Graphics::spellImmobilize12                    = "Spell-Immobilize-12.png";
const std::string Graphics::spellImmobilize13                    = "Spell-Immobilize-13.png";
const std::string Graphics::spellImmobilize14                    = "Spell-Immobilize-14.png";
const std::string Graphics::spellImmobilize2                     = "Spell-Immobilize-2.png";
const std::string Graphics::spellImmobilize3                     = "Spell-Immobilize-3.png";
const std::string Graphics::spellImmobilize4                     = "Spell-Immobilize-4.png";
const std::string Graphics::spellImmobilize5                     = "Spell-Immobilize-5.png";
const std::string Graphics::spellImmobilize6                     = "Spell-Immobilize-6.png";
const std::string Graphics::spellImmobilize7                     = "Spell-Immobilize-7.png";
const std::string Graphics::spellImmobilize8                     = "Spell-Immobilize-8.png";
const std::string Graphics::spellImmobilize9                     = "Spell-Immobilize-9.png";
const std::string Graphics::spellMagicalArrow0                   = "Spell-MagicalArrow-0.png";
const std::string Graphics::spellMagicalArrow1                   = "Spell-MagicalArrow-1.png";
const std::string Graphics::spellMagicalArrow2                   = "Spell-MagicalArrow-2.png";
const std::string Graphics::spellMagicalArrow3                   = "Spell-MagicalArrow-3.png";
const std::string Graphics::spellMagicalArrow4                   = "Spell-MagicalArrow-4.png";
const std::string Graphics::spellMagicalDart0                    = "Spell-MagicalDart-0.png";
const std::string Graphics::spellMagicalDart1                    = "Spell-MagicalDart-1.png";
const std::string Graphics::spellMagicalDart2                    = "Spell-MagicalDart-2.png";
const std::string Graphics::spellMagicalDart3                    = "Spell-MagicalDart-3.png";
const std::string Graphics::spellMagicalDart4                    = "Spell-MagicalDart-4.png";
const std::string Graphics::spellMagicalDart5                    = "Spell-MagicalDart-5.png";
const std::string Graphics::spellMagicalDart6                    = "Spell-MagicalDart-6.png";
const std::string Graphics::spellMagicalDart7                    = "Spell-MagicalDart-7.png";
const std::string Graphics::spellMagicalMissile01                = "Spell-MagicalMissile-01.png";
const std::string Graphics::spellMagicalMissile02                = "Spell-MagicalMissile-02.png";
const std::string Graphics::spellMagicalMissile03                = "Spell-MagicalMissile-03.png";
const std::string Graphics::spellMagicalMissile04                = "Spell-MagicalMissile-04.png";
const std::string Graphics::spellMagicalMissile05                = "Spell-MagicalMissile-05.png";
const std::string Graphics::spellMagicalMissile06                = "Spell-MagicalMissile-06.png";
const std::string Graphics::spellMagicalMissile07                = "Spell-MagicalMissile-07.png";
const std::string Graphics::spellMagicalMissile08                = "Spell-MagicalMissile-08.png";
const std::string Graphics::spellMagicalMissile09                = "Spell-MagicalMissile-09.png";
const std::string Graphics::spellMagicalMissile10                = "Spell-MagicalMissile-10.png";
const std::string Graphics::spellParalyze0                       = "Spell-Paralyze-0.png";
const std::string Graphics::spellParalyze1                       = "Spell-Paralyze-1.png";
const std::string Graphics::spellParalyze2                       = "Spell-Paralyze-2.png";
const std::string Graphics::spellParalyze3                       = "Spell-Paralyze-3.png";
const std::string Graphics::spellParalyze4                       = "Spell-Paralyze-4.png";
const std::string Graphics::spellParalyze5                       = "Spell-Paralyze-5.png";
const std::string Graphics::spellParalyze6                       = "Spell-Paralyze-6.png";
const std::string Graphics::spellParalyze7                       = "Spell-Paralyze-7.png";
const std::string Graphics::spellParalyze8                       = "Spell-Paralyze-8.png";
const std::string Graphics::spellParalyze9                       = "Spell-Paralyze-9.png";
const std::string Graphics::spellStrength0                       = "Spell-Strength-0.png";
const std::string Graphics::spellStrength1                       = "Spell-Strength-1.png";
const std::string Graphics::spellStrength2                       = "Spell-Strength-2.png";
const std::string Graphics::spellStrength3                       = "Spell-Strength-3.png";
const std::string Graphics::spellStrength4                       = "Spell-Strength-4.png";
const std::string Graphics::spellTownPortalBlue0                 = "Spell-TownPortal-Blue-0.png";
const std::string Graphics::spellTownPortalBlue1                 = "Spell-TownPortal-Blue-1.png";
const std::string Graphics::spellTownPortalBlue2                 = "Spell-TownPortal-Blue-2.png";
const std::string Graphics::spellTownPortalBlue3                 = "Spell-TownPortal-Blue-3.png";
const std::string Graphics::spellTownPortalBlue4                 = "Spell-TownPortal-Blue-4.png";
const std::string Graphics::spellTownPortalBlue5                 = "Spell-TownPortal-Blue-5.png";
const std::string Graphics::spellTownPortalBlue6                 = "Spell-TownPortal-Blue-6.png";
const std::string Graphics::spellTownPortalBlue7                 = "Spell-TownPortal-Blue-7.png";
const std::string Graphics::spellTownPortalBlue8                 = "Spell-TownPortal-Blue-8.png";
const std::string Graphics::spellTownPortalBlue9                 = "Spell-TownPortal-Blue-9.png";
const std::string Graphics::wagonEast1                           = "Wagon-East1.png";
const std::string Graphics::wagonEast2                           = "Wagon-East2.png";
const std::string Graphics::wagonEast3                           = "Wagon-East3.png";
const std::string Graphics::wagonNorth1                          = "Wagon-North1.png";
const std::string Graphics::wagonNorth2                          = "Wagon-North2.png";
const std::string Graphics::wagonNorth3                          = "Wagon-North3.png";
const std::string Graphics::wagonSouth1                          = "Wagon-South1.png";
const std::string Graphics::wagonSouth2                          = "Wagon-South2.png";
const std::string Graphics::wagonSouth3                          = "Wagon-South3.png";
const std::string Graphics::wagonStandingEast                    = "Wagon-Standing-East.png";
const std::string Graphics::wagonStandingNorth                   = "Wagon-Standing-North.png";
const std::string Graphics::wagonStandingSouth                   = "Wagon-Standing-South.png";
const std::string Graphics::wagonStandingWest                    = "Wagon-Standing-West.png";
const std::string Graphics::wagonWest1                           = "Wagon-West1.png";
const std::string Graphics::wagonWest2                           = "Wagon-West2.png";
const std::string Graphics::wagonWest3                           = "Wagon-West3.png";

// ---------------------------------------------------------
// convenience functions returing pointers to Sprite objects
// ---------------------------------------------------------
Sprite* Graphics::createBlood01Sprite()
{
	return Sprite::createWithSpriteFrameName(blood01);
}

Sprite* Graphics::createBlood02Sprite()
{
    return Sprite::createWithSpriteFrameName(blood02);
}

Sprite* Graphics::createBlood03Sprite()
{
    return Sprite::createWithSpriteFrameName(blood03);
}

Sprite* Graphics::createBlood04Sprite()
{
    return Sprite::createWithSpriteFrameName(blood04);
}

Sprite* Graphics::createBlood05Sprite()
{
    return Sprite::createWithSpriteFrameName(blood05);
}

Sprite* Graphics::createClothesGraphic_10Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_10);
}

Sprite* Graphics::createClothesGraphic_100Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_100);
}

Sprite* Graphics::createClothesGraphic_101Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_101);
}

Sprite* Graphics::createClothesGraphic_102Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_102);
}

Sprite* Graphics::createClothesGraphic_103Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_103);
}

Sprite* Graphics::createClothesGraphic_104Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_104);
}

Sprite* Graphics::createClothesGraphic_105Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_105);
}

Sprite* Graphics::createClothesGraphic_106Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_106);
}

Sprite* Graphics::createClothesGraphic_107Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_107);
}

Sprite* Graphics::createClothesGraphic_108Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_108);
}

Sprite* Graphics::createClothesGraphic_109Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_109);
}

Sprite* Graphics::createClothesGraphic_11Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_11);
}

Sprite* Graphics::createClothesGraphic_110Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_110);
}

Sprite* Graphics::createClothesGraphic_111Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_111);
}

Sprite* Graphics::createClothesGraphic_112Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_112);
}

Sprite* Graphics::createClothesGraphic_113Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_113);
}

Sprite* Graphics::createClothesGraphic_114Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_114);
}

Sprite* Graphics::createClothesGraphic_115Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_115);
}

Sprite* Graphics::createClothesGraphic_116Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_116);
}

Sprite* Graphics::createClothesGraphic_117Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_117);
}

Sprite* Graphics::createClothesGraphic_118Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_118);
}

Sprite* Graphics::createClothesGraphic_119Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_119);
}

Sprite* Graphics::createClothesGraphic_12Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_12);
}

Sprite* Graphics::createClothesGraphic_120Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_120);
}

Sprite* Graphics::createClothesGraphic_121Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_121);
}

Sprite* Graphics::createClothesGraphic_122Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_122);
}

Sprite* Graphics::createClothesGraphic_123Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_123);
}

Sprite* Graphics::createClothesGraphic_124Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_124);
}

Sprite* Graphics::createClothesGraphic_125Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_125);
}

Sprite* Graphics::createClothesGraphic_126Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_126);
}

Sprite* Graphics::createClothesGraphic_127Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_127);
}

Sprite* Graphics::createClothesGraphic_128Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_128);
}

Sprite* Graphics::createClothesGraphic_129Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_129);
}

Sprite* Graphics::createClothesGraphic_13Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_13);
}

Sprite* Graphics::createClothesGraphic_130Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_130);
}

Sprite* Graphics::createClothesGraphic_131Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_131);
}

Sprite* Graphics::createClothesGraphic_132Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_132);
}

Sprite* Graphics::createClothesGraphic_133Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_133);
}

Sprite* Graphics::createClothesGraphic_134Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_134);
}

Sprite* Graphics::createClothesGraphic_135Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_135);
}

Sprite* Graphics::createClothesGraphic_136Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_136);
}

Sprite* Graphics::createClothesGraphic_137Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_137);
}

Sprite* Graphics::createClothesGraphic_138Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_138);
}

Sprite* Graphics::createClothesGraphic_139Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_139);
}

Sprite* Graphics::createClothesGraphic_14Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_14);
}

Sprite* Graphics::createClothesGraphic_140Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_140);
}

Sprite* Graphics::createClothesGraphic_141Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_141);
}

Sprite* Graphics::createClothesGraphic_142Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_142);
}

Sprite* Graphics::createClothesGraphic_143Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_143);
}

Sprite* Graphics::createClothesGraphic_144Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_144);
}

Sprite* Graphics::createClothesGraphic_145Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_145);
}

Sprite* Graphics::createClothesGraphic_146Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_146);
}

Sprite* Graphics::createClothesGraphic_147Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_147);
}

Sprite* Graphics::createClothesGraphic_148Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_148);
}

Sprite* Graphics::createClothesGraphic_149Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_149);
}

Sprite* Graphics::createClothesGraphic_15Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_15);
}

Sprite* Graphics::createClothesGraphic_150Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_150);
}

Sprite* Graphics::createClothesGraphic_151Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_151);
}

Sprite* Graphics::createClothesGraphic_152Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_152);
}

Sprite* Graphics::createClothesGraphic_153Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_153);
}

Sprite* Graphics::createClothesGraphic_154Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_154);
}

Sprite* Graphics::createClothesGraphic_155Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_155);
}

Sprite* Graphics::createClothesGraphic_156Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_156);
}

Sprite* Graphics::createClothesGraphic_157Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_157);
}

Sprite* Graphics::createClothesGraphic_158Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_158);
}

Sprite* Graphics::createClothesGraphic_159Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_159);
}

Sprite* Graphics::createClothesGraphic_16Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_16);
}

Sprite* Graphics::createClothesGraphic_160Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_160);
}

Sprite* Graphics::createClothesGraphic_161Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_161);
}

Sprite* Graphics::createClothesGraphic_162Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_162);
}

Sprite* Graphics::createClothesGraphic_163Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_163);
}

Sprite* Graphics::createClothesGraphic_164Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_164);
}

Sprite* Graphics::createClothesGraphic_165Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_165);
}

Sprite* Graphics::createClothesGraphic_166Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_166);
}

Sprite* Graphics::createClothesGraphic_167Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_167);
}

Sprite* Graphics::createClothesGraphic_168Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_168);
}

Sprite* Graphics::createClothesGraphic_169Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_169);
}

Sprite* Graphics::createClothesGraphic_17Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_17);
}

Sprite* Graphics::createClothesGraphic_170Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_170);
}

Sprite* Graphics::createClothesGraphic_171Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_171);
}

Sprite* Graphics::createClothesGraphic_172Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_172);
}

Sprite* Graphics::createClothesGraphic_173Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_173);
}

Sprite* Graphics::createClothesGraphic_174Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_174);
}

Sprite* Graphics::createClothesGraphic_175Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_175);
}

Sprite* Graphics::createClothesGraphic_176Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_176);
}

Sprite* Graphics::createClothesGraphic_177Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_177);
}

Sprite* Graphics::createClothesGraphic_178Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_178);
}

Sprite* Graphics::createClothesGraphic_179Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_179);
}

Sprite* Graphics::createClothesGraphic_180Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_180);
}

Sprite* Graphics::createClothesGraphic_181Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_181);
}

Sprite* Graphics::createClothesGraphic_182Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_182);
}

Sprite* Graphics::createClothesGraphic_183Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_183);
}

Sprite* Graphics::createClothesGraphic_184Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_184);
}

Sprite* Graphics::createClothesGraphic_185Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_185);
}

Sprite* Graphics::createClothesGraphic_186Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_186);
}

Sprite* Graphics::createClothesGraphic_187Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_187);
}

Sprite* Graphics::createClothesGraphic_188Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_188);
}

Sprite* Graphics::createClothesGraphic_189Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_189);
}

Sprite* Graphics::createClothesGraphic_19Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_19);
}

Sprite* Graphics::createClothesGraphic_190Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_190);
}

Sprite* Graphics::createClothesGraphic_191Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_191);
}

Sprite* Graphics::createClothesGraphic_192Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_192);
}

Sprite* Graphics::createClothesGraphic_193Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_193);
}

Sprite* Graphics::createClothesGraphic_194Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_194);
}

Sprite* Graphics::createClothesGraphic_195Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_195);
}

Sprite* Graphics::createClothesGraphic_196Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_196);
}

Sprite* Graphics::createClothesGraphic_197Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_197);
}

Sprite* Graphics::createClothesGraphic_198Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_198);
}

Sprite* Graphics::createClothesGraphic_199Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_199);
}

Sprite* Graphics::createClothesGraphic_20Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_20);
}

Sprite* Graphics::createClothesGraphic_200Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_200);
}

Sprite* Graphics::createClothesGraphic_201Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_201);
}

Sprite* Graphics::createClothesGraphic_202Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_202);
}

Sprite* Graphics::createClothesGraphic_203Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_203);
}

Sprite* Graphics::createClothesGraphic_204Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_204);
}

Sprite* Graphics::createClothesGraphic_205Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_205);
}

Sprite* Graphics::createClothesGraphic_206Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_206);
}

Sprite* Graphics::createClothesGraphic_207Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_207);
}

Sprite* Graphics::createClothesGraphic_208Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_208);
}

Sprite* Graphics::createClothesGraphic_209Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_209);
}

Sprite* Graphics::createClothesGraphic_21Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_21);
}

Sprite* Graphics::createClothesGraphic_210Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_210);
}

Sprite* Graphics::createClothesGraphic_211Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_211);
}

Sprite* Graphics::createClothesGraphic_212Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_212);
}

Sprite* Graphics::createClothesGraphic_213Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_213);
}

Sprite* Graphics::createClothesGraphic_214Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_214);
}

Sprite* Graphics::createClothesGraphic_215Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_215);
}

Sprite* Graphics::createClothesGraphic_216Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_216);
}

Sprite* Graphics::createClothesGraphic_217Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_217);
}

Sprite* Graphics::createClothesGraphic_218Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_218);
}

Sprite* Graphics::createClothesGraphic_219Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_219);
}

Sprite* Graphics::createClothesGraphic_22Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_22);
}

Sprite* Graphics::createClothesGraphic_220Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_220);
}

Sprite* Graphics::createClothesGraphic_221Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_221);
}

Sprite* Graphics::createClothesGraphic_222Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_222);
}

Sprite* Graphics::createClothesGraphic_223Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_223);
}

Sprite* Graphics::createClothesGraphic_224Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_224);
}

Sprite* Graphics::createClothesGraphic_225Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_225);
}

Sprite* Graphics::createClothesGraphic_226Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_226);
}

Sprite* Graphics::createClothesGraphic_227Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_227);
}

Sprite* Graphics::createClothesGraphic_228Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_228);
}

Sprite* Graphics::createClothesGraphic_229Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_229);
}

Sprite* Graphics::createClothesGraphic_23Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_23);
}

Sprite* Graphics::createClothesGraphic_230Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_230);
}

Sprite* Graphics::createClothesGraphic_231Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_231);
}

Sprite* Graphics::createClothesGraphic_232Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_232);
}

Sprite* Graphics::createClothesGraphic_233Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_233);
}

Sprite* Graphics::createClothesGraphic_234Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_234);
}

Sprite* Graphics::createClothesGraphic_235Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_235);
}

Sprite* Graphics::createClothesGraphic_236Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_236);
}

Sprite* Graphics::createClothesGraphic_237Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_237);
}

Sprite* Graphics::createClothesGraphic_238Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_238);
}

Sprite* Graphics::createClothesGraphic_239Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_239);
}

Sprite* Graphics::createClothesGraphic_24Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_24);
}

Sprite* Graphics::createClothesGraphic_240Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_240);
}

Sprite* Graphics::createClothesGraphic_241Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_241);
}

Sprite* Graphics::createClothesGraphic_242Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_242);
}

Sprite* Graphics::createClothesGraphic_243Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_243);
}

Sprite* Graphics::createClothesGraphic_244Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_244);
}

Sprite* Graphics::createClothesGraphic_245Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_245);
}

Sprite* Graphics::createClothesGraphic_246Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_246);
}

Sprite* Graphics::createClothesGraphic_247Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_247);
}

Sprite* Graphics::createClothesGraphic_248Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_248);
}

Sprite* Graphics::createClothesGraphic_249Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_249);
}

Sprite* Graphics::createClothesGraphic_25Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_25);
}

Sprite* Graphics::createClothesGraphic_250Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_250);
}

Sprite* Graphics::createClothesGraphic_251Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_251);
}

Sprite* Graphics::createClothesGraphic_252Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_252);
}

Sprite* Graphics::createClothesGraphic_253Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_253);
}

Sprite* Graphics::createClothesGraphic_254Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_254);
}

Sprite* Graphics::createClothesGraphic_255Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_255);
}

Sprite* Graphics::createClothesGraphic_256Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_256);
}

Sprite* Graphics::createClothesGraphic_257Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_257);
}

Sprite* Graphics::createClothesGraphic_258Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_258);
}

Sprite* Graphics::createClothesGraphic_259Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_259);
}

Sprite* Graphics::createClothesGraphic_26Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_26);
}

Sprite* Graphics::createClothesGraphic_260Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_260);
}

Sprite* Graphics::createClothesGraphic_261Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_261);
}

Sprite* Graphics::createClothesGraphic_262Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_262);
}

Sprite* Graphics::createClothesGraphic_263Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_263);
}

Sprite* Graphics::createClothesGraphic_264Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_264);
}

Sprite* Graphics::createClothesGraphic_265Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_265);
}

Sprite* Graphics::createClothesGraphic_266Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_266);
}

Sprite* Graphics::createClothesGraphic_267Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_267);
}

Sprite* Graphics::createClothesGraphic_268Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_268);
}

Sprite* Graphics::createClothesGraphic_269Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_269);
}

Sprite* Graphics::createClothesGraphic_27Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_27);
}

Sprite* Graphics::createClothesGraphic_270Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_270);
}

Sprite* Graphics::createClothesGraphic_271Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_271);
}

Sprite* Graphics::createClothesGraphic_272Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_272);
}

Sprite* Graphics::createClothesGraphic_273Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_273);
}

Sprite* Graphics::createClothesGraphic_274Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_274);
}

Sprite* Graphics::createClothesGraphic_275Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_275);
}

Sprite* Graphics::createClothesGraphic_276Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_276);
}

Sprite* Graphics::createClothesGraphic_277Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_277);
}

Sprite* Graphics::createClothesGraphic_278Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_278);
}

Sprite* Graphics::createClothesGraphic_279Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_279);
}

Sprite* Graphics::createClothesGraphic_28Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_28);
}

Sprite* Graphics::createClothesGraphic_280Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_280);
}

Sprite* Graphics::createClothesGraphic_281Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_281);
}

Sprite* Graphics::createClothesGraphic_282Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_282);
}

Sprite* Graphics::createClothesGraphic_283Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_283);
}

Sprite* Graphics::createClothesGraphic_284Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_284);
}

Sprite* Graphics::createClothesGraphic_285Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_285);
}

Sprite* Graphics::createClothesGraphic_286Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_286);
}

Sprite* Graphics::createClothesGraphic_287Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_287);
}

Sprite* Graphics::createClothesGraphic_288Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_288);
}

Sprite* Graphics::createClothesGraphic_289Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_289);
}

Sprite* Graphics::createClothesGraphic_29Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_29);
}

Sprite* Graphics::createClothesGraphic_290Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_290);
}

Sprite* Graphics::createClothesGraphic_291Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_291);
}

Sprite* Graphics::createClothesGraphic_292Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_292);
}

Sprite* Graphics::createClothesGraphic_293Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_293);
}

Sprite* Graphics::createClothesGraphic_294Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_294);
}

Sprite* Graphics::createClothesGraphic_295Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_295);
}

Sprite* Graphics::createClothesGraphic_296Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_296);
}

Sprite* Graphics::createClothesGraphic_297Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_297);
}

Sprite* Graphics::createClothesGraphic_298Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_298);
}

Sprite* Graphics::createClothesGraphic_299Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_299);
}

Sprite* Graphics::createClothesGraphic_30Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_30);
}

Sprite* Graphics::createClothesGraphic_300Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_300);
}

Sprite* Graphics::createClothesGraphic_301Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_301);
}

Sprite* Graphics::createClothesGraphic_302Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_302);
}

Sprite* Graphics::createClothesGraphic_303Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_303);
}

Sprite* Graphics::createClothesGraphic_304Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_304);
}

Sprite* Graphics::createClothesGraphic_305Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_305);
}

Sprite* Graphics::createClothesGraphic_306Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_306);
}

Sprite* Graphics::createClothesGraphic_307Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_307);
}

Sprite* Graphics::createClothesGraphic_308Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_308);
}

Sprite* Graphics::createClothesGraphic_309Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_309);
}

Sprite* Graphics::createClothesGraphic_31Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_31);
}

Sprite* Graphics::createClothesGraphic_310Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_310);
}

Sprite* Graphics::createClothesGraphic_311Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_311);
}

Sprite* Graphics::createClothesGraphic_312Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_312);
}

Sprite* Graphics::createClothesGraphic_313Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_313);
}

Sprite* Graphics::createClothesGraphic_314Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_314);
}

Sprite* Graphics::createClothesGraphic_315Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_315);
}

Sprite* Graphics::createClothesGraphic_316Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_316);
}

Sprite* Graphics::createClothesGraphic_317Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_317);
}

Sprite* Graphics::createClothesGraphic_318Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_318);
}

Sprite* Graphics::createClothesGraphic_319Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_319);
}

Sprite* Graphics::createClothesGraphic_32Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_32);
}

Sprite* Graphics::createClothesGraphic_320Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_320);
}

Sprite* Graphics::createClothesGraphic_321Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_321);
}

Sprite* Graphics::createClothesGraphic_322Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_322);
}

Sprite* Graphics::createClothesGraphic_323Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_323);
}

Sprite* Graphics::createClothesGraphic_324Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_324);
}

Sprite* Graphics::createClothesGraphic_325Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_325);
}

Sprite* Graphics::createClothesGraphic_326Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_326);
}

Sprite* Graphics::createClothesGraphic_327Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_327);
}

Sprite* Graphics::createClothesGraphic_328Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_328);
}

Sprite* Graphics::createClothesGraphic_329Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_329);
}

Sprite* Graphics::createClothesGraphic_33Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_33);
}

Sprite* Graphics::createClothesGraphic_330Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_330);
}

Sprite* Graphics::createClothesGraphic_331Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_331);
}

Sprite* Graphics::createClothesGraphic_332Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_332);
}

Sprite* Graphics::createClothesGraphic_333Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_333);
}

Sprite* Graphics::createClothesGraphic_334Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_334);
}

Sprite* Graphics::createClothesGraphic_335Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_335);
}

Sprite* Graphics::createClothesGraphic_336Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_336);
}

Sprite* Graphics::createClothesGraphic_337Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_337);
}

Sprite* Graphics::createClothesGraphic_338Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_338);
}

Sprite* Graphics::createClothesGraphic_339Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_339);
}

Sprite* Graphics::createClothesGraphic_34Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_34);
}

Sprite* Graphics::createClothesGraphic_340Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_340);
}

Sprite* Graphics::createClothesGraphic_341Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_341);
}

Sprite* Graphics::createClothesGraphic_342Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_342);
}

Sprite* Graphics::createClothesGraphic_343Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_343);
}

Sprite* Graphics::createClothesGraphic_344Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_344);
}

Sprite* Graphics::createClothesGraphic_345Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_345);
}

Sprite* Graphics::createClothesGraphic_346Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_346);
}

Sprite* Graphics::createClothesGraphic_347Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_347);
}

Sprite* Graphics::createClothesGraphic_348Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_348);
}

Sprite* Graphics::createClothesGraphic_349Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_349);
}

Sprite* Graphics::createClothesGraphic_35Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_35);
}

Sprite* Graphics::createClothesGraphic_350Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_350);
}

Sprite* Graphics::createClothesGraphic_351Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_351);
}

Sprite* Graphics::createClothesGraphic_352Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_352);
}

Sprite* Graphics::createClothesGraphic_353Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_353);
}

Sprite* Graphics::createClothesGraphic_354Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_354);
}

Sprite* Graphics::createClothesGraphic_355Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_355);
}

Sprite* Graphics::createClothesGraphic_356Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_356);
}

Sprite* Graphics::createClothesGraphic_357Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_357);
}

Sprite* Graphics::createClothesGraphic_358Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_358);
}

Sprite* Graphics::createClothesGraphic_359Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_359);
}

Sprite* Graphics::createClothesGraphic_36Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_36);
}

Sprite* Graphics::createClothesGraphic_360Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_360);
}

Sprite* Graphics::createClothesGraphic_361Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_361);
}

Sprite* Graphics::createClothesGraphic_362Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_362);
}

Sprite* Graphics::createClothesGraphic_363Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_363);
}

Sprite* Graphics::createClothesGraphic_364Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_364);
}

Sprite* Graphics::createClothesGraphic_365Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_365);
}

Sprite* Graphics::createClothesGraphic_366Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_366);
}

Sprite* Graphics::createClothesGraphic_367Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_367);
}

Sprite* Graphics::createClothesGraphic_368Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_368);
}

Sprite* Graphics::createClothesGraphic_369Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_369);
}

Sprite* Graphics::createClothesGraphic_37Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_37);
}

Sprite* Graphics::createClothesGraphic_370Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_370);
}

Sprite* Graphics::createClothesGraphic_371Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_371);
}

Sprite* Graphics::createClothesGraphic_372Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_372);
}

Sprite* Graphics::createClothesGraphic_373Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_373);
}

Sprite* Graphics::createClothesGraphic_374Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_374);
}

Sprite* Graphics::createClothesGraphic_375Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_375);
}

Sprite* Graphics::createClothesGraphic_376Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_376);
}

Sprite* Graphics::createClothesGraphic_377Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_377);
}

Sprite* Graphics::createClothesGraphic_378Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_378);
}

Sprite* Graphics::createClothesGraphic_379Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_379);
}

Sprite* Graphics::createClothesGraphic_38Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_38);
}

Sprite* Graphics::createClothesGraphic_380Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_380);
}

Sprite* Graphics::createClothesGraphic_381Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_381);
}

Sprite* Graphics::createClothesGraphic_382Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_382);
}

Sprite* Graphics::createClothesGraphic_383Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_383);
}

Sprite* Graphics::createClothesGraphic_384Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_384);
}

Sprite* Graphics::createClothesGraphic_385Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_385);
}

Sprite* Graphics::createClothesGraphic_386Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_386);
}

Sprite* Graphics::createClothesGraphic_387Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_387);
}

Sprite* Graphics::createClothesGraphic_388Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_388);
}

Sprite* Graphics::createClothesGraphic_389Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_389);
}

Sprite* Graphics::createClothesGraphic_39Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_39);
}

Sprite* Graphics::createClothesGraphic_390Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_390);
}

Sprite* Graphics::createClothesGraphic_391Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_391);
}

Sprite* Graphics::createClothesGraphic_392Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_392);
}

Sprite* Graphics::createClothesGraphic_393Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_393);
}

Sprite* Graphics::createClothesGraphic_394Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_394);
}

Sprite* Graphics::createClothesGraphic_395Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_395);
}

Sprite* Graphics::createClothesGraphic_396Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_396);
}

Sprite* Graphics::createClothesGraphic_397Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_397);
}

Sprite* Graphics::createClothesGraphic_398Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_398);
}

Sprite* Graphics::createClothesGraphic_399Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_399);
}

Sprite* Graphics::createClothesGraphic_4Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_4);
}

Sprite* Graphics::createClothesGraphic_40Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_40);
}

Sprite* Graphics::createClothesGraphic_400Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_400);
}

Sprite* Graphics::createClothesGraphic_401Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_401);
}

Sprite* Graphics::createClothesGraphic_402Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_402);
}

Sprite* Graphics::createClothesGraphic_403Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_403);
}

Sprite* Graphics::createClothesGraphic_404Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_404);
}

Sprite* Graphics::createClothesGraphic_405Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_405);
}

Sprite* Graphics::createClothesGraphic_406Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_406);
}

Sprite* Graphics::createClothesGraphic_407Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_407);
}

Sprite* Graphics::createClothesGraphic_408Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_408);
}

Sprite* Graphics::createClothesGraphic_409Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_409);
}

Sprite* Graphics::createClothesGraphic_41Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_41);
}

Sprite* Graphics::createClothesGraphic_410Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_410);
}

Sprite* Graphics::createClothesGraphic_411Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_411);
}

Sprite* Graphics::createClothesGraphic_412Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_412);
}

Sprite* Graphics::createClothesGraphic_413Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_413);
}

Sprite* Graphics::createClothesGraphic_414Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_414);
}

Sprite* Graphics::createClothesGraphic_415Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_415);
}

Sprite* Graphics::createClothesGraphic_416Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_416);
}

Sprite* Graphics::createClothesGraphic_417Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_417);
}

Sprite* Graphics::createClothesGraphic_418Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_418);
}

Sprite* Graphics::createClothesGraphic_419Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_419);
}

Sprite* Graphics::createClothesGraphic_42Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_42);
}

Sprite* Graphics::createClothesGraphic_420Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_420);
}

Sprite* Graphics::createClothesGraphic_421Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_421);
}

Sprite* Graphics::createClothesGraphic_422Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_422);
}

Sprite* Graphics::createClothesGraphic_423Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_423);
}

Sprite* Graphics::createClothesGraphic_424Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_424);
}

Sprite* Graphics::createClothesGraphic_425Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_425);
}

Sprite* Graphics::createClothesGraphic_426Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_426);
}

Sprite* Graphics::createClothesGraphic_427Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_427);
}

Sprite* Graphics::createClothesGraphic_428Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_428);
}

Sprite* Graphics::createClothesGraphic_429Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_429);
}

Sprite* Graphics::createClothesGraphic_43Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_43);
}

Sprite* Graphics::createClothesGraphic_430Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_430);
}

Sprite* Graphics::createClothesGraphic_431Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_431);
}

Sprite* Graphics::createClothesGraphic_432Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_432);
}

Sprite* Graphics::createClothesGraphic_433Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_433);
}

Sprite* Graphics::createClothesGraphic_434Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_434);
}

Sprite* Graphics::createClothesGraphic_435Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_435);
}

Sprite* Graphics::createClothesGraphic_436Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_436);
}

Sprite* Graphics::createClothesGraphic_437Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_437);
}

Sprite* Graphics::createClothesGraphic_438Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_438);
}

Sprite* Graphics::createClothesGraphic_439Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_439);
}

Sprite* Graphics::createClothesGraphic_44Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_44);
}

Sprite* Graphics::createClothesGraphic_440Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_440);
}

Sprite* Graphics::createClothesGraphic_441Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_441);
}

Sprite* Graphics::createClothesGraphic_442Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_442);
}

Sprite* Graphics::createClothesGraphic_443Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_443);
}

Sprite* Graphics::createClothesGraphic_444Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_444);
}

Sprite* Graphics::createClothesGraphic_445Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_445);
}

Sprite* Graphics::createClothesGraphic_446Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_446);
}

Sprite* Graphics::createClothesGraphic_447Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_447);
}

Sprite* Graphics::createClothesGraphic_448Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_448);
}

Sprite* Graphics::createClothesGraphic_449Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_449);
}

Sprite* Graphics::createClothesGraphic_45Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_45);
}

Sprite* Graphics::createClothesGraphic_450Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_450);
}

Sprite* Graphics::createClothesGraphic_451Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_451);
}

Sprite* Graphics::createClothesGraphic_452Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_452);
}

Sprite* Graphics::createClothesGraphic_453Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_453);
}

Sprite* Graphics::createClothesGraphic_454Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_454);
}

Sprite* Graphics::createClothesGraphic_455Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_455);
}

Sprite* Graphics::createClothesGraphic_456Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_456);
}

Sprite* Graphics::createClothesGraphic_457Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_457);
}

Sprite* Graphics::createClothesGraphic_458Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_458);
}

Sprite* Graphics::createClothesGraphic_459Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_459);
}

Sprite* Graphics::createClothesGraphic_46Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_46);
}

Sprite* Graphics::createClothesGraphic_460Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_460);
}

Sprite* Graphics::createClothesGraphic_461Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_461);
}

Sprite* Graphics::createClothesGraphic_462Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_462);
}

Sprite* Graphics::createClothesGraphic_463Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_463);
}

Sprite* Graphics::createClothesGraphic_464Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_464);
}

Sprite* Graphics::createClothesGraphic_465Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_465);
}

Sprite* Graphics::createClothesGraphic_466Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_466);
}

Sprite* Graphics::createClothesGraphic_467Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_467);
}

Sprite* Graphics::createClothesGraphic_468Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_468);
}

Sprite* Graphics::createClothesGraphic_469Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_469);
}

Sprite* Graphics::createClothesGraphic_47Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_47);
}

Sprite* Graphics::createClothesGraphic_470Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_470);
}

Sprite* Graphics::createClothesGraphic_471Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_471);
}

Sprite* Graphics::createClothesGraphic_472Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_472);
}

Sprite* Graphics::createClothesGraphic_473Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_473);
}

Sprite* Graphics::createClothesGraphic_474Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_474);
}

Sprite* Graphics::createClothesGraphic_475Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_475);
}

Sprite* Graphics::createClothesGraphic_476Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_476);
}

Sprite* Graphics::createClothesGraphic_477Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_477);
}

Sprite* Graphics::createClothesGraphic_478Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_478);
}

Sprite* Graphics::createClothesGraphic_479Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_479);
}

Sprite* Graphics::createClothesGraphic_48Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_48);
}

Sprite* Graphics::createClothesGraphic_480Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_480);
}

Sprite* Graphics::createClothesGraphic_481Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_481);
}

Sprite* Graphics::createClothesGraphic_482Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_482);
}

Sprite* Graphics::createClothesGraphic_483Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_483);
}

Sprite* Graphics::createClothesGraphic_484Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_484);
}

Sprite* Graphics::createClothesGraphic_485Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_485);
}

Sprite* Graphics::createClothesGraphic_486Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_486);
}

Sprite* Graphics::createClothesGraphic_487Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_487);
}

Sprite* Graphics::createClothesGraphic_488Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_488);
}

Sprite* Graphics::createClothesGraphic_489Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_489);
}

Sprite* Graphics::createClothesGraphic_49Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_49);
}

Sprite* Graphics::createClothesGraphic_490Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_490);
}

Sprite* Graphics::createClothesGraphic_491Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_491);
}

Sprite* Graphics::createClothesGraphic_492Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_492);
}

Sprite* Graphics::createClothesGraphic_493Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_493);
}

Sprite* Graphics::createClothesGraphic_494Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_494);
}

Sprite* Graphics::createClothesGraphic_495Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_495);
}

Sprite* Graphics::createClothesGraphic_496Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_496);
}

Sprite* Graphics::createClothesGraphic_497Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_497);
}

Sprite* Graphics::createClothesGraphic_498Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_498);
}

Sprite* Graphics::createClothesGraphic_499Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_499);
}

Sprite* Graphics::createClothesGraphic_5Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_5);
}

Sprite* Graphics::createClothesGraphic_50Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_50);
}

Sprite* Graphics::createClothesGraphic_500Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_500);
}

Sprite* Graphics::createClothesGraphic_501Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_501);
}

Sprite* Graphics::createClothesGraphic_502Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_502);
}

Sprite* Graphics::createClothesGraphic_503Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_503);
}

Sprite* Graphics::createClothesGraphic_504Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_504);
}

Sprite* Graphics::createClothesGraphic_505Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_505);
}

Sprite* Graphics::createClothesGraphic_506Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_506);
}

Sprite* Graphics::createClothesGraphic_507Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_507);
}

Sprite* Graphics::createClothesGraphic_508Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_508);
}

Sprite* Graphics::createClothesGraphic_509Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_509);
}

Sprite* Graphics::createClothesGraphic_51Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_51);
}

Sprite* Graphics::createClothesGraphic_510Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_510);
}

Sprite* Graphics::createClothesGraphic_511Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_511);
}

Sprite* Graphics::createClothesGraphic_512Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_512);
}

Sprite* Graphics::createClothesGraphic_513Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_513);
}

Sprite* Graphics::createClothesGraphic_514Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_514);
}

Sprite* Graphics::createClothesGraphic_515Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_515);
}

Sprite* Graphics::createClothesGraphic_516Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_516);
}

Sprite* Graphics::createClothesGraphic_517Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_517);
}

Sprite* Graphics::createClothesGraphic_518Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_518);
}

Sprite* Graphics::createClothesGraphic_519Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_519);
}

Sprite* Graphics::createClothesGraphic_52Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_52);
}

Sprite* Graphics::createClothesGraphic_520Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_520);
}

Sprite* Graphics::createClothesGraphic_521Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_521);
}

Sprite* Graphics::createClothesGraphic_522Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_522);
}

Sprite* Graphics::createClothesGraphic_523Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_523);
}

Sprite* Graphics::createClothesGraphic_524Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_524);
}

Sprite* Graphics::createClothesGraphic_525Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_525);
}

Sprite* Graphics::createClothesGraphic_526Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_526);
}

Sprite* Graphics::createClothesGraphic_527Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_527);
}

Sprite* Graphics::createClothesGraphic_528Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_528);
}

Sprite* Graphics::createClothesGraphic_529Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_529);
}

Sprite* Graphics::createClothesGraphic_53Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_53);
}

Sprite* Graphics::createClothesGraphic_530Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_530);
}

Sprite* Graphics::createClothesGraphic_531Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_531);
}

Sprite* Graphics::createClothesGraphic_532Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_532);
}

Sprite* Graphics::createClothesGraphic_533Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_533);
}

Sprite* Graphics::createClothesGraphic_534Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_534);
}

Sprite* Graphics::createClothesGraphic_535Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_535);
}

Sprite* Graphics::createClothesGraphic_536Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_536);
}

Sprite* Graphics::createClothesGraphic_537Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_537);
}

Sprite* Graphics::createClothesGraphic_538Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_538);
}

Sprite* Graphics::createClothesGraphic_539Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_539);
}

Sprite* Graphics::createClothesGraphic_54Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_54);
}

Sprite* Graphics::createClothesGraphic_540Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_540);
}

Sprite* Graphics::createClothesGraphic_541Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_541);
}

Sprite* Graphics::createClothesGraphic_542Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_542);
}

Sprite* Graphics::createClothesGraphic_543Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_543);
}

Sprite* Graphics::createClothesGraphic_544Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_544);
}

Sprite* Graphics::createClothesGraphic_545Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_545);
}

Sprite* Graphics::createClothesGraphic_546Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_546);
}

Sprite* Graphics::createClothesGraphic_547Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_547);
}

Sprite* Graphics::createClothesGraphic_548Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_548);
}

Sprite* Graphics::createClothesGraphic_549Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_549);
}

Sprite* Graphics::createClothesGraphic_55Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_55);
}

Sprite* Graphics::createClothesGraphic_550Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_550);
}

Sprite* Graphics::createClothesGraphic_551Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_551);
}

Sprite* Graphics::createClothesGraphic_552Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_552);
}

Sprite* Graphics::createClothesGraphic_553Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_553);
}

Sprite* Graphics::createClothesGraphic_554Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_554);
}

Sprite* Graphics::createClothesGraphic_555Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_555);
}

Sprite* Graphics::createClothesGraphic_556Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_556);
}

Sprite* Graphics::createClothesGraphic_557Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_557);
}

Sprite* Graphics::createClothesGraphic_558Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_558);
}

Sprite* Graphics::createClothesGraphic_559Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_559);
}

Sprite* Graphics::createClothesGraphic_56Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_56);
}

Sprite* Graphics::createClothesGraphic_560Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_560);
}

Sprite* Graphics::createClothesGraphic_561Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_561);
}

Sprite* Graphics::createClothesGraphic_562Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_562);
}

Sprite* Graphics::createClothesGraphic_563Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_563);
}

Sprite* Graphics::createClothesGraphic_564Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_564);
}

Sprite* Graphics::createClothesGraphic_565Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_565);
}

Sprite* Graphics::createClothesGraphic_566Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_566);
}

Sprite* Graphics::createClothesGraphic_567Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_567);
}

Sprite* Graphics::createClothesGraphic_568Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_568);
}

Sprite* Graphics::createClothesGraphic_569Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_569);
}

Sprite* Graphics::createClothesGraphic_57Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_57);
}

Sprite* Graphics::createClothesGraphic_570Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_570);
}

Sprite* Graphics::createClothesGraphic_571Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_571);
}

Sprite* Graphics::createClothesGraphic_572Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_572);
}

Sprite* Graphics::createClothesGraphic_573Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_573);
}

Sprite* Graphics::createClothesGraphic_574Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_574);
}

Sprite* Graphics::createClothesGraphic_575Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_575);
}

Sprite* Graphics::createClothesGraphic_576Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_576);
}

Sprite* Graphics::createClothesGraphic_577Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_577);
}

Sprite* Graphics::createClothesGraphic_578Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_578);
}

Sprite* Graphics::createClothesGraphic_579Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_579);
}

Sprite* Graphics::createClothesGraphic_58Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_58);
}

Sprite* Graphics::createClothesGraphic_580Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_580);
}

Sprite* Graphics::createClothesGraphic_581Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_581);
}

Sprite* Graphics::createClothesGraphic_582Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_582);
}

Sprite* Graphics::createClothesGraphic_583Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_583);
}

Sprite* Graphics::createClothesGraphic_584Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_584);
}

Sprite* Graphics::createClothesGraphic_585Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_585);
}

Sprite* Graphics::createClothesGraphic_586Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_586);
}

Sprite* Graphics::createClothesGraphic_587Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_587);
}

Sprite* Graphics::createClothesGraphic_588Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_588);
}

Sprite* Graphics::createClothesGraphic_589Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_589);
}

Sprite* Graphics::createClothesGraphic_59Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_59);
}

Sprite* Graphics::createClothesGraphic_590Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_590);
}

Sprite* Graphics::createClothesGraphic_591Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_591);
}

Sprite* Graphics::createClothesGraphic_592Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_592);
}

Sprite* Graphics::createClothesGraphic_593Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_593);
}

Sprite* Graphics::createClothesGraphic_594Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_594);
}

Sprite* Graphics::createClothesGraphic_595Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_595);
}

Sprite* Graphics::createClothesGraphic_596Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_596);
}

Sprite* Graphics::createClothesGraphic_597Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_597);
}

Sprite* Graphics::createClothesGraphic_598Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_598);
}

Sprite* Graphics::createClothesGraphic_599Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_599);
}

Sprite* Graphics::createClothesGraphic_6Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_6);
}

Sprite* Graphics::createClothesGraphic_60Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_60);
}

Sprite* Graphics::createClothesGraphic_600Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_600);
}

Sprite* Graphics::createClothesGraphic_601Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_601);
}

Sprite* Graphics::createClothesGraphic_602Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_602);
}

Sprite* Graphics::createClothesGraphic_603Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_603);
}

Sprite* Graphics::createClothesGraphic_604Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_604);
}

Sprite* Graphics::createClothesGraphic_605Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_605);
}

Sprite* Graphics::createClothesGraphic_606Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_606);
}

Sprite* Graphics::createClothesGraphic_607Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_607);
}

Sprite* Graphics::createClothesGraphic_608Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_608);
}

Sprite* Graphics::createClothesGraphic_609Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_609);
}

Sprite* Graphics::createClothesGraphic_61Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_61);
}

Sprite* Graphics::createClothesGraphic_610Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_610);
}

Sprite* Graphics::createClothesGraphic_611Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_611);
}

Sprite* Graphics::createClothesGraphic_612Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_612);
}

Sprite* Graphics::createClothesGraphic_613Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_613);
}

Sprite* Graphics::createClothesGraphic_614Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_614);
}

Sprite* Graphics::createClothesGraphic_615Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_615);
}

Sprite* Graphics::createClothesGraphic_616Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_616);
}

Sprite* Graphics::createClothesGraphic_617Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_617);
}

Sprite* Graphics::createClothesGraphic_618Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_618);
}

Sprite* Graphics::createClothesGraphic_619Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_619);
}

Sprite* Graphics::createClothesGraphic_62Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_62);
}

Sprite* Graphics::createClothesGraphic_620Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_620);
}

Sprite* Graphics::createClothesGraphic_621Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_621);
}

Sprite* Graphics::createClothesGraphic_622Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_622);
}

Sprite* Graphics::createClothesGraphic_623Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_623);
}

Sprite* Graphics::createClothesGraphic_624Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_624);
}

Sprite* Graphics::createClothesGraphic_625Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_625);
}

Sprite* Graphics::createClothesGraphic_626Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_626);
}

Sprite* Graphics::createClothesGraphic_627Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_627);
}

Sprite* Graphics::createClothesGraphic_628Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_628);
}

Sprite* Graphics::createClothesGraphic_629Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_629);
}

Sprite* Graphics::createClothesGraphic_63Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_63);
}

Sprite* Graphics::createClothesGraphic_630Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_630);
}

Sprite* Graphics::createClothesGraphic_631Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_631);
}

Sprite* Graphics::createClothesGraphic_632Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_632);
}

Sprite* Graphics::createClothesGraphic_633Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_633);
}

Sprite* Graphics::createClothesGraphic_634Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_634);
}

Sprite* Graphics::createClothesGraphic_635Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_635);
}

Sprite* Graphics::createClothesGraphic_636Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_636);
}

Sprite* Graphics::createClothesGraphic_637Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_637);
}

Sprite* Graphics::createClothesGraphic_638Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_638);
}

Sprite* Graphics::createClothesGraphic_639Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_639);
}

Sprite* Graphics::createClothesGraphic_64Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_64);
}

Sprite* Graphics::createClothesGraphic_640Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_640);
}

Sprite* Graphics::createClothesGraphic_641Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_641);
}

Sprite* Graphics::createClothesGraphic_642Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_642);
}

Sprite* Graphics::createClothesGraphic_643Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_643);
}

Sprite* Graphics::createClothesGraphic_644Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_644);
}

Sprite* Graphics::createClothesGraphic_645Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_645);
}

Sprite* Graphics::createClothesGraphic_646Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_646);
}

Sprite* Graphics::createClothesGraphic_647Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_647);
}

Sprite* Graphics::createClothesGraphic_648Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_648);
}

Sprite* Graphics::createClothesGraphic_649Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_649);
}

Sprite* Graphics::createClothesGraphic_65Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_65);
}

Sprite* Graphics::createClothesGraphic_650Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_650);
}

Sprite* Graphics::createClothesGraphic_651Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_651);
}

Sprite* Graphics::createClothesGraphic_652Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_652);
}

Sprite* Graphics::createClothesGraphic_653Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_653);
}

Sprite* Graphics::createClothesGraphic_654Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_654);
}

Sprite* Graphics::createClothesGraphic_655Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_655);
}

Sprite* Graphics::createClothesGraphic_656Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_656);
}

Sprite* Graphics::createClothesGraphic_657Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_657);
}

Sprite* Graphics::createClothesGraphic_658Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_658);
}

Sprite* Graphics::createClothesGraphic_659Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_659);
}

Sprite* Graphics::createClothesGraphic_66Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_66);
}

Sprite* Graphics::createClothesGraphic_660Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_660);
}

Sprite* Graphics::createClothesGraphic_661Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_661);
}

Sprite* Graphics::createClothesGraphic_662Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_662);
}

Sprite* Graphics::createClothesGraphic_663Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_663);
}

Sprite* Graphics::createClothesGraphic_664Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_664);
}

Sprite* Graphics::createClothesGraphic_665Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_665);
}

Sprite* Graphics::createClothesGraphic_666Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_666);
}

Sprite* Graphics::createClothesGraphic_667Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_667);
}

Sprite* Graphics::createClothesGraphic_668Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_668);
}

Sprite* Graphics::createClothesGraphic_669Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_669);
}

Sprite* Graphics::createClothesGraphic_67Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_67);
}

Sprite* Graphics::createClothesGraphic_670Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_670);
}

Sprite* Graphics::createClothesGraphic_671Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_671);
}

Sprite* Graphics::createClothesGraphic_672Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_672);
}

Sprite* Graphics::createClothesGraphic_673Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_673);
}

Sprite* Graphics::createClothesGraphic_674Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_674);
}

Sprite* Graphics::createClothesGraphic_675Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_675);
}

Sprite* Graphics::createClothesGraphic_676Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_676);
}

Sprite* Graphics::createClothesGraphic_677Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_677);
}

Sprite* Graphics::createClothesGraphic_678Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_678);
}

Sprite* Graphics::createClothesGraphic_679Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_679);
}

Sprite* Graphics::createClothesGraphic_68Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_68);
}

Sprite* Graphics::createClothesGraphic_680Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_680);
}

Sprite* Graphics::createClothesGraphic_681Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_681);
}

Sprite* Graphics::createClothesGraphic_682Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_682);
}

Sprite* Graphics::createClothesGraphic_683Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_683);
}

Sprite* Graphics::createClothesGraphic_684Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_684);
}

Sprite* Graphics::createClothesGraphic_69Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_69);
}

Sprite* Graphics::createClothesGraphic_7Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_7);
}

Sprite* Graphics::createClothesGraphic_70Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_70);
}

Sprite* Graphics::createClothesGraphic_71Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_71);
}

Sprite* Graphics::createClothesGraphic_72Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_72);
}

Sprite* Graphics::createClothesGraphic_73Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_73);
}

Sprite* Graphics::createClothesGraphic_74Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_74);
}

Sprite* Graphics::createClothesGraphic_75Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_75);
}

Sprite* Graphics::createClothesGraphic_76Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_76);
}

Sprite* Graphics::createClothesGraphic_77Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_77);
}

Sprite* Graphics::createClothesGraphic_78Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_78);
}

Sprite* Graphics::createClothesGraphic_79Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_79);
}

Sprite* Graphics::createClothesGraphic_8Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_8);
}

Sprite* Graphics::createClothesGraphic_80Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_80);
}

Sprite* Graphics::createClothesGraphic_81Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_81);
}

Sprite* Graphics::createClothesGraphic_82Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_82);
}

Sprite* Graphics::createClothesGraphic_83Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_83);
}

Sprite* Graphics::createClothesGraphic_84Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_84);
}

Sprite* Graphics::createClothesGraphic_85Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_85);
}

Sprite* Graphics::createClothesGraphic_86Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_86);
}

Sprite* Graphics::createClothesGraphic_87Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_87);
}

Sprite* Graphics::createClothesGraphic_88Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_88);
}

Sprite* Graphics::createClothesGraphic_89Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_89);
}

Sprite* Graphics::createClothesGraphic_9Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_9);
}

Sprite* Graphics::createClothesGraphic_90Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_90);
}

Sprite* Graphics::createClothesGraphic_91Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_91);
}

Sprite* Graphics::createClothesGraphic_92Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_92);
}

Sprite* Graphics::createClothesGraphic_93Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_93);
}

Sprite* Graphics::createClothesGraphic_94Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_94);
}

Sprite* Graphics::createClothesGraphic_95Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_95);
}

Sprite* Graphics::createClothesGraphic_96Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_96);
}

Sprite* Graphics::createClothesGraphic_97Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_97);
}

Sprite* Graphics::createClothesGraphic_98Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_98);
}

Sprite* Graphics::createClothesGraphic_99Sprite()
{
    return Sprite::createWithSpriteFrameName(clothesGraphic_99);
}

Sprite* Graphics::createFloorMAPFloor001Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor001);
}

Sprite* Graphics::createFloorMAPFloor002Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor002);
}

Sprite* Graphics::createFloorMAPFloor003Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor003);
}

Sprite* Graphics::createFloorMAPFloor004Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor004);
}

Sprite* Graphics::createFloorMAPFloor_10Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_10);
}

Sprite* Graphics::createFloorMAPFloor_100Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_100);
}

Sprite* Graphics::createFloorMAPFloor_11Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_11);
}

Sprite* Graphics::createFloorMAPFloor_12Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_12);
}

Sprite* Graphics::createFloorMAPFloor_13Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_13);
}

Sprite* Graphics::createFloorMAPFloor_14Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_14);
}

Sprite* Graphics::createFloorMAPFloor_15Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_15);
}

Sprite* Graphics::createFloorMAPFloor_16Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_16);
}

Sprite* Graphics::createFloorMAPFloor_17Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_17);
}

Sprite* Graphics::createFloorMAPFloor_18Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_18);
}

Sprite* Graphics::createFloorMAPFloor_19Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_19);
}

Sprite* Graphics::createFloorMAPFloor_20Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_20);
}

Sprite* Graphics::createFloorMAPFloor_21Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_21);
}

Sprite* Graphics::createFloorMAPFloor_22Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_22);
}

Sprite* Graphics::createFloorMAPFloor_23Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_23);
}

Sprite* Graphics::createFloorMAPFloor_24Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_24);
}

Sprite* Graphics::createFloorMAPFloor_25Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_25);
}

Sprite* Graphics::createFloorMAPFloor_26Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_26);
}

Sprite* Graphics::createFloorMAPFloor_27Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_27);
}

Sprite* Graphics::createFloorMAPFloor_28Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_28);
}

Sprite* Graphics::createFloorMAPFloor_29Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_29);
}

Sprite* Graphics::createFloorMAPFloor_30Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_30);
}

Sprite* Graphics::createFloorMAPFloor_31Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_31);
}

Sprite* Graphics::createFloorMAPFloor_32Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_32);
}

Sprite* Graphics::createFloorMAPFloor_33Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_33);
}

Sprite* Graphics::createFloorMAPFloor_34Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_34);
}

Sprite* Graphics::createFloorMAPFloor_35Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_35);
}

Sprite* Graphics::createFloorMAPFloor_36Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_36);
}

Sprite* Graphics::createFloorMAPFloor_37Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_37);
}

Sprite* Graphics::createFloorMAPFloor_38Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_38);
}

Sprite* Graphics::createFloorMAPFloor_39Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_39);
}

Sprite* Graphics::createFloorMAPFloor_40Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_40);
}

Sprite* Graphics::createFloorMAPFloor_41Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_41);
}

Sprite* Graphics::createFloorMAPFloor_42Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_42);
}

Sprite* Graphics::createFloorMAPFloor_43Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_43);
}

Sprite* Graphics::createFloorMAPFloor_44Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_44);
}

Sprite* Graphics::createFloorMAPFloor_45Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_45);
}

Sprite* Graphics::createFloorMAPFloor_46Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_46);
}

Sprite* Graphics::createFloorMAPFloor_47Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_47);
}

Sprite* Graphics::createFloorMAPFloor_48Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_48);
}

Sprite* Graphics::createFloorMAPFloor_49Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_49);
}

Sprite* Graphics::createFloorMAPFloor_5Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_5);
}

Sprite* Graphics::createFloorMAPFloor_50Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_50);
}

Sprite* Graphics::createFloorMAPFloor_51Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_51);
}

Sprite* Graphics::createFloorMAPFloor_52Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_52);
}

Sprite* Graphics::createFloorMAPFloor_53Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_53);
}

Sprite* Graphics::createFloorMAPFloor_54Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_54);
}

Sprite* Graphics::createFloorMAPFloor_55Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_55);
}

Sprite* Graphics::createFloorMAPFloor_56Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_56);
}

Sprite* Graphics::createFloorMAPFloor_57Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_57);
}

Sprite* Graphics::createFloorMAPFloor_58Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_58);
}

Sprite* Graphics::createFloorMAPFloor_59Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_59);
}

Sprite* Graphics::createFloorMAPFloor_6Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_6);
}

Sprite* Graphics::createFloorMAPFloor_60Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_60);
}

Sprite* Graphics::createFloorMAPFloor_61Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_61);
}

Sprite* Graphics::createFloorMAPFloor_62Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_62);
}

Sprite* Graphics::createFloorMAPFloor_63Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_63);
}

Sprite* Graphics::createFloorMAPFloor_64Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_64);
}

Sprite* Graphics::createFloorMAPFloor_65Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_65);
}

Sprite* Graphics::createFloorMAPFloor_66Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_66);
}

Sprite* Graphics::createFloorMAPFloor_67Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_67);
}

Sprite* Graphics::createFloorMAPFloor_68Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_68);
}

Sprite* Graphics::createFloorMAPFloor_69Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_69);
}

Sprite* Graphics::createFloorMAPFloor_7Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_7);
}

Sprite* Graphics::createFloorMAPFloor_70Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_70);
}

Sprite* Graphics::createFloorMAPFloor_71Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_71);
}

Sprite* Graphics::createFloorMAPFloor_72Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_72);
}

Sprite* Graphics::createFloorMAPFloor_73Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_73);
}

Sprite* Graphics::createFloorMAPFloor_74Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_74);
}

Sprite* Graphics::createFloorMAPFloor_75Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_75);
}

Sprite* Graphics::createFloorMAPFloor_76Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_76);
}

Sprite* Graphics::createFloorMAPFloor_77Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_77);
}

Sprite* Graphics::createFloorMAPFloor_78Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_78);
}

Sprite* Graphics::createFloorMAPFloor_79Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_79);
}

Sprite* Graphics::createFloorMAPFloor_8Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_8);
}

Sprite* Graphics::createFloorMAPFloor_80Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_80);
}

Sprite* Graphics::createFloorMAPFloor_81Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_81);
}

Sprite* Graphics::createFloorMAPFloor_82Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_82);
}

Sprite* Graphics::createFloorMAPFloor_83Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_83);
}

Sprite* Graphics::createFloorMAPFloor_84Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_84);
}

Sprite* Graphics::createFloorMAPFloor_85Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_85);
}

Sprite* Graphics::createFloorMAPFloor_86Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_86);
}

Sprite* Graphics::createFloorMAPFloor_87Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_87);
}

Sprite* Graphics::createFloorMAPFloor_88Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_88);
}

Sprite* Graphics::createFloorMAPFloor_89Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_89);
}

Sprite* Graphics::createFloorMAPFloor_9Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_9);
}

Sprite* Graphics::createFloorMAPFloor_90Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_90);
}

Sprite* Graphics::createFloorMAPFloor_91Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_91);
}

Sprite* Graphics::createFloorMAPFloor_92Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_92);
}

Sprite* Graphics::createFloorMAPFloor_93Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_93);
}

Sprite* Graphics::createFloorMAPFloor_94Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_94);
}

Sprite* Graphics::createFloorMAPFloor_95Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_95);
}

Sprite* Graphics::createFloorMAPFloor_96Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_96);
}

Sprite* Graphics::createFloorMAPFloor_97Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_97);
}

Sprite* Graphics::createFloorMAPFloor_98Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_98);
}

Sprite* Graphics::createFloorMAPFloor_99Sprite()
{
    return Sprite::createWithSpriteFrameName(floorMAPFloor_99);
}

Sprite* Graphics::createFloorMapFloorCrossRoadsSprite()
{
    return Sprite::createWithSpriteFrameName(floorMapFloorCrossRoads);
}

Sprite* Graphics::createGolemFireEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(golemFireEast1);
}

Sprite* Graphics::createGolemFireEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(golemFireEast2);
}

Sprite* Graphics::createGolemFireEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(golemFireEast3);
}

Sprite* Graphics::createGolemFireEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(golemFireEast4);
}

Sprite* Graphics::createGolemFireNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(golemFireNorth1);
}

Sprite* Graphics::createGolemFireNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(golemFireNorth2);
}

Sprite* Graphics::createGolemFireNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(golemFireNorth3);
}

Sprite* Graphics::createGolemFireNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(golemFireNorth4);
}

Sprite* Graphics::createGolemFireNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(golemFireNorth5);
}

Sprite* Graphics::createGolemFireSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(golemFireSouth1);
}

Sprite* Graphics::createGolemFireSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(golemFireSouth2);
}

Sprite* Graphics::createGolemFireSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(golemFireSouth3);
}

Sprite* Graphics::createGolemFireSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(golemFireSouth4);
}

Sprite* Graphics::createGolemFireSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(golemFireSouth5);
}

Sprite* Graphics::createGolemFireStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(golemFireStandingEast);
}

Sprite* Graphics::createGolemFireStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(golemFireStandingNorth);
}

Sprite* Graphics::createGolemFireStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(golemFireStandingSouth);
}

Sprite* Graphics::createGolemFireStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(golemFireStandingWest);
}

Sprite* Graphics::createGolemFireWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(golemFireWest1);
}

Sprite* Graphics::createGolemFireWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(golemFireWest2);
}

Sprite* Graphics::createGolemFireWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(golemFireWest3);
}

Sprite* Graphics::createGolemFireWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(golemFireWest4);
}

Sprite* Graphics::createHandTorchEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(handTorchEast1);
}

Sprite* Graphics::createHandTorchEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(handTorchEast2);
}

Sprite* Graphics::createHandTorchEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(handTorchEast3);
}

Sprite* Graphics::createHandTorchEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(handTorchEast4);
}

Sprite* Graphics::createHandTorchEast5Sprite()
{
    return Sprite::createWithSpriteFrameName(handTorchEast5);
}

Sprite* Graphics::createHandTorchNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(handTorchNorth1);
}

Sprite* Graphics::createHandTorchNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(handTorchNorth2);
}

Sprite* Graphics::createHandTorchNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(handTorchNorth3);
}

Sprite* Graphics::createHandTorchNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(handTorchNorth4);
}

Sprite* Graphics::createHandTorchNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(handTorchNorth5);
}

Sprite* Graphics::createHandTorchSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(handTorchSouth1);
}

Sprite* Graphics::createHandTorchSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(handTorchSouth2);
}

Sprite* Graphics::createHandTorchSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(handTorchSouth3);
}

Sprite* Graphics::createHandTorchSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(handTorchSouth4);
}

Sprite* Graphics::createHandTorchStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(handTorchStandingEast);
}

Sprite* Graphics::createHandTorchStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(handTorchStandingNorth);
}

Sprite* Graphics::createHandTorchStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(handTorchStandingSouth);
}

Sprite* Graphics::createHandTorchStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(handTorchStandingWest);
}

Sprite* Graphics::createHandTorchWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(handTorchWest1);
}

Sprite* Graphics::createHandTorchWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(handTorchWest2);
}

Sprite* Graphics::createHandTorchWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(handTorchWest3);
}

Sprite* Graphics::createHandTorchWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(handTorchWest4);
}

Sprite* Graphics::createHeadsGraphic_700Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_700);
}

Sprite* Graphics::createHeadsGraphic_701Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_701);
}

Sprite* Graphics::createHeadsGraphic_702Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_702);
}

Sprite* Graphics::createHeadsGraphic_703Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_703);
}

Sprite* Graphics::createHeadsGraphic_704Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_704);
}

Sprite* Graphics::createHeadsGraphic_705Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_705);
}

Sprite* Graphics::createHeadsGraphic_706Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_706);
}

Sprite* Graphics::createHeadsGraphic_707Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_707);
}

Sprite* Graphics::createHeadsGraphic_708Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_708);
}

Sprite* Graphics::createHeadsGraphic_709Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_709);
}

Sprite* Graphics::createHeadsGraphic_710Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_710);
}

Sprite* Graphics::createHeadsGraphic_711Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_711);
}

Sprite* Graphics::createHeadsGraphic_712Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_712);
}

Sprite* Graphics::createHeadsGraphic_713Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_713);
}

Sprite* Graphics::createHeadsGraphic_714Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_714);
}

Sprite* Graphics::createHeadsGraphic_715Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_715);
}

Sprite* Graphics::createHeadsGraphic_716Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_716);
}

Sprite* Graphics::createHeadsGraphic_717Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_717);
}

Sprite* Graphics::createHeadsGraphic_718Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_718);
}

Sprite* Graphics::createHeadsGraphic_719Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_719);
}

Sprite* Graphics::createHeadsGraphic_720Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_720);
}

Sprite* Graphics::createHeadsGraphic_721Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_721);
}

Sprite* Graphics::createHeadsGraphic_722Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_722);
}

Sprite* Graphics::createHeadsGraphic_723Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_723);
}

Sprite* Graphics::createHeadsGraphic_724Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_724);
}

Sprite* Graphics::createHeadsGraphic_725Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_725);
}

Sprite* Graphics::createHeadsGraphic_726Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_726);
}

Sprite* Graphics::createHeadsGraphic_727Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_727);
}

Sprite* Graphics::createHeadsGraphic_728Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_728);
}

Sprite* Graphics::createHeadsGraphic_729Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_729);
}

Sprite* Graphics::createHeadsGraphic_730Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_730);
}

Sprite* Graphics::createHeadsGraphic_731Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_731);
}

Sprite* Graphics::createHeadsGraphic_732Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_732);
}

Sprite* Graphics::createHeadsGraphic_733Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_733);
}

Sprite* Graphics::createHeadsGraphic_734Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_734);
}

Sprite* Graphics::createHeadsGraphic_735Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_735);
}

Sprite* Graphics::createHeadsGraphic_736Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_736);
}

Sprite* Graphics::createHeadsGraphic_737Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_737);
}

Sprite* Graphics::createHeadsGraphic_738Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_738);
}

Sprite* Graphics::createHeadsGraphic_739Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_739);
}

Sprite* Graphics::createHeadsGraphic_740Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_740);
}

Sprite* Graphics::createHeadsGraphic_741Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_741);
}

Sprite* Graphics::createHeadsGraphic_742Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_742);
}

Sprite* Graphics::createHeadsGraphic_743Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_743);
}

Sprite* Graphics::createHeadsGraphic_744Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_744);
}

Sprite* Graphics::createHeadsGraphic_745Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_745);
}

Sprite* Graphics::createHeadsGraphic_746Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_746);
}

Sprite* Graphics::createHeadsGraphic_747Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_747);
}

Sprite* Graphics::createHeadsGraphic_748Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_748);
}

Sprite* Graphics::createHeadsGraphic_749Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_749);
}

Sprite* Graphics::createHeadsGraphic_750Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_750);
}

Sprite* Graphics::createHeadsGraphic_751Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_751);
}

Sprite* Graphics::createHeadsGraphic_752Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_752);
}

Sprite* Graphics::createHeadsGraphic_753Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_753);
}

Sprite* Graphics::createHeadsGraphic_754Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_754);
}

Sprite* Graphics::createHeadsGraphic_755Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_755);
}

Sprite* Graphics::createHeadsGraphic_756Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_756);
}

Sprite* Graphics::createHeadsGraphic_757Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_757);
}

Sprite* Graphics::createHeadsGraphic_758Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_758);
}

Sprite* Graphics::createHeadsGraphic_759Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_759);
}

Sprite* Graphics::createHeadsGraphic_760Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_760);
}

Sprite* Graphics::createHeadsGraphic_761Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_761);
}

Sprite* Graphics::createHeadsGraphic_762Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_762);
}

Sprite* Graphics::createHeadsGraphic_763Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_763);
}

Sprite* Graphics::createHeadsGraphic_764Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_764);
}

Sprite* Graphics::createHeadsGraphic_765Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_765);
}

Sprite* Graphics::createHeadsGraphic_766Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_766);
}

Sprite* Graphics::createHeadsGraphic_767Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_767);
}

Sprite* Graphics::createHeadsGraphic_768Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_768);
}

Sprite* Graphics::createHeadsGraphic_769Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_769);
}

Sprite* Graphics::createHeadsGraphic_770Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_770);
}

Sprite* Graphics::createHeadsGraphic_771Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_771);
}

Sprite* Graphics::createHeadsGraphic_772Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_772);
}

Sprite* Graphics::createHeadsGraphic_773Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_773);
}

Sprite* Graphics::createHeadsGraphic_774Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_774);
}

Sprite* Graphics::createHeadsGraphic_775Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_775);
}

Sprite* Graphics::createHeadsGraphic_776Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_776);
}

Sprite* Graphics::createHeadsGraphic_777Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_777);
}

Sprite* Graphics::createHeadsGraphic_778Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_778);
}

Sprite* Graphics::createHeadsGraphic_779Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_779);
}

Sprite* Graphics::createHeadsGraphic_780Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_780);
}

Sprite* Graphics::createHeadsGraphic_781Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_781);
}

Sprite* Graphics::createHeadsGraphic_782Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_782);
}

Sprite* Graphics::createHeadsGraphic_783Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_783);
}

Sprite* Graphics::createHeadsGraphic_784Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_784);
}

Sprite* Graphics::createHeadsGraphic_785Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_785);
}

Sprite* Graphics::createHeadsGraphic_786Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_786);
}

Sprite* Graphics::createHeadsGraphic_787Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_787);
}

Sprite* Graphics::createHeadsGraphic_788Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_788);
}

Sprite* Graphics::createHeadsGraphic_789Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_789);
}

Sprite* Graphics::createHeadsGraphic_790Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_790);
}

Sprite* Graphics::createHeadsGraphic_791Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_791);
}

Sprite* Graphics::createHeadsGraphic_792Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_792);
}

Sprite* Graphics::createHeadsGraphic_793Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_793);
}

Sprite* Graphics::createHeadsGraphic_794Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_794);
}

Sprite* Graphics::createHeadsGraphic_795Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_795);
}

Sprite* Graphics::createHeadsGraphic_796Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_796);
}

Sprite* Graphics::createHeadsGraphic_797Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_797);
}

Sprite* Graphics::createHeadsGraphic_798Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_798);
}

Sprite* Graphics::createHeadsGraphic_799Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_799);
}

Sprite* Graphics::createHeadsGraphic_800Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_800);
}

Sprite* Graphics::createHeadsGraphic_801Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_801);
}

Sprite* Graphics::createHeadsGraphic_802Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_802);
}

Sprite* Graphics::createHeadsGraphic_803Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_803);
}

Sprite* Graphics::createHeadsGraphic_804Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_804);
}

Sprite* Graphics::createHeadsGraphic_805Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_805);
}

Sprite* Graphics::createHeadsGraphic_806Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_806);
}

Sprite* Graphics::createHeadsGraphic_807Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_807);
}

Sprite* Graphics::createHeadsGraphic_808Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_808);
}

Sprite* Graphics::createHeadsGraphic_809Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_809);
}

Sprite* Graphics::createHeadsGraphic_810Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_810);
}

Sprite* Graphics::createHeadsGraphic_811Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_811);
}

Sprite* Graphics::createHeadsGraphic_812Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_812);
}

Sprite* Graphics::createHeadsGraphic_813Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_813);
}

Sprite* Graphics::createHeadsGraphic_814Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_814);
}

Sprite* Graphics::createHeadsGraphic_815Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_815);
}

Sprite* Graphics::createHeadsGraphic_816Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_816);
}

Sprite* Graphics::createHeadsGraphic_817Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_817);
}

Sprite* Graphics::createHeadsGraphic_818Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_818);
}

Sprite* Graphics::createHeadsGraphic_819Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_819);
}

Sprite* Graphics::createHeadsGraphic_820Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_820);
}

Sprite* Graphics::createHeadsGraphic_821Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_821);
}

Sprite* Graphics::createHeadsGraphic_822Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_822);
}

Sprite* Graphics::createHeadsGraphic_823Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_823);
}

Sprite* Graphics::createHeadsGraphic_824Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_824);
}

Sprite* Graphics::createHeadsGraphic_825Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_825);
}

Sprite* Graphics::createHeadsGraphic_826Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_826);
}

Sprite* Graphics::createHeadsGraphic_827Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_827);
}

Sprite* Graphics::createHeadsGraphic_828Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_828);
}

Sprite* Graphics::createHeadsGraphic_829Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_829);
}

Sprite* Graphics::createHeadsGraphic_830Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_830);
}

Sprite* Graphics::createHeadsGraphic_831Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_831);
}

Sprite* Graphics::createHeadsGraphic_832Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_832);
}

Sprite* Graphics::createHeadsGraphic_833Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_833);
}

Sprite* Graphics::createHeadsGraphic_834Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_834);
}

Sprite* Graphics::createHeadsGraphic_835Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_835);
}

Sprite* Graphics::createHeadsGraphic_836Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_836);
}

Sprite* Graphics::createHeadsGraphic_837Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_837);
}

Sprite* Graphics::createHeadsGraphic_838Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_838);
}

Sprite* Graphics::createHeadsGraphic_839Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_839);
}

Sprite* Graphics::createHeadsGraphic_840Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_840);
}

Sprite* Graphics::createHeadsGraphic_841Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_841);
}

Sprite* Graphics::createHeadsGraphic_842Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_842);
}

Sprite* Graphics::createHeadsGraphic_843Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_843);
}

Sprite* Graphics::createHeadsGraphic_844Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_844);
}

Sprite* Graphics::createHeadsGraphic_845Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_845);
}

Sprite* Graphics::createHeadsGraphic_846Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_846);
}

Sprite* Graphics::createHeadsGraphic_847Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_847);
}

Sprite* Graphics::createHeadsGraphic_848Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_848);
}

Sprite* Graphics::createHeadsGraphic_849Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_849);
}

Sprite* Graphics::createHeadsGraphic_850Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_850);
}

Sprite* Graphics::createHeadsGraphic_851Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_851);
}

Sprite* Graphics::createHeadsGraphic_852Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_852);
}

Sprite* Graphics::createHeadsGraphic_853Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_853);
}

Sprite* Graphics::createHeadsGraphic_854Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_854);
}

Sprite* Graphics::createHeadsGraphic_855Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_855);
}

Sprite* Graphics::createHeadsGraphic_856Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_856);
}

Sprite* Graphics::createHeadsGraphic_857Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_857);
}

Sprite* Graphics::createHeadsGraphic_858Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_858);
}

Sprite* Graphics::createHeadsGraphic_859Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_859);
}

Sprite* Graphics::createHeadsGraphic_860Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_860);
}

Sprite* Graphics::createHeadsGraphic_861Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_861);
}

Sprite* Graphics::createHeadsGraphic_862Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_862);
}

Sprite* Graphics::createHeadsGraphic_863Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_863);
}

Sprite* Graphics::createHeadsGraphic_864Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_864);
}

Sprite* Graphics::createHeadsGraphic_865Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_865);
}

Sprite* Graphics::createHeadsGraphic_866Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_866);
}

Sprite* Graphics::createHeadsGraphic_867Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_867);
}

Sprite* Graphics::createHeadsGraphic_868Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_868);
}

Sprite* Graphics::createHeadsGraphic_869Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_869);
}

Sprite* Graphics::createHeadsGraphic_870Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_870);
}

Sprite* Graphics::createHeadsGraphic_871Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_871);
}

Sprite* Graphics::createHeadsGraphic_872Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_872);
}

Sprite* Graphics::createHeadsGraphic_873Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_873);
}

Sprite* Graphics::createHeadsGraphic_874Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_874);
}

Sprite* Graphics::createHeadsGraphic_875Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_875);
}

Sprite* Graphics::createHeadsGraphic_876Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_876);
}

Sprite* Graphics::createHeadsGraphic_877Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_877);
}

Sprite* Graphics::createHeadsGraphic_878Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_878);
}

Sprite* Graphics::createHeadsGraphic_879Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_879);
}

Sprite* Graphics::createHeadsGraphic_880Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_880);
}

Sprite* Graphics::createHeadsGraphic_881Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_881);
}

Sprite* Graphics::createHeadsGraphic_882Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_882);
}

Sprite* Graphics::createHeadsGraphic_883Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_883);
}

Sprite* Graphics::createHeadsGraphic_884Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_884);
}

Sprite* Graphics::createHeadsGraphic_885Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_885);
}

Sprite* Graphics::createHeadsGraphic_886Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_886);
}

Sprite* Graphics::createHeadsGraphic_887Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_887);
}

Sprite* Graphics::createHeadsGraphic_888Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_888);
}

Sprite* Graphics::createHeadsGraphic_889Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_889);
}

Sprite* Graphics::createHeadsGraphic_890Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_890);
}

Sprite* Graphics::createHeadsGraphic_891Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_891);
}

Sprite* Graphics::createHeadsGraphic_892Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_892);
}

Sprite* Graphics::createHeadsGraphic_893Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_893);
}

Sprite* Graphics::createHeadsGraphic_894Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_894);
}

Sprite* Graphics::createHeadsGraphic_895Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_895);
}

Sprite* Graphics::createHeadsGraphic_896Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_896);
}

Sprite* Graphics::createHeadsGraphic_897Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_897);
}

Sprite* Graphics::createHeadsGraphic_898Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_898);
}

Sprite* Graphics::createHeadsGraphic_899Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_899);
}

Sprite* Graphics::createHeadsGraphic_900Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_900);
}

Sprite* Graphics::createHeadsGraphic_901Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_901);
}

Sprite* Graphics::createHeadsGraphic_902Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_902);
}

Sprite* Graphics::createHeadsGraphic_903Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_903);
}

Sprite* Graphics::createHeadsGraphic_904Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_904);
}

Sprite* Graphics::createHeadsGraphic_905Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_905);
}

Sprite* Graphics::createHeadsGraphic_906Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_906);
}

Sprite* Graphics::createHeadsGraphic_907Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_907);
}

Sprite* Graphics::createHeadsGraphic_908Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_908);
}

Sprite* Graphics::createHeadsGraphic_909Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_909);
}

Sprite* Graphics::createHeadsGraphic_910Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_910);
}

Sprite* Graphics::createHeadsGraphic_911Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_911);
}

Sprite* Graphics::createHeadsGraphic_912Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_912);
}

Sprite* Graphics::createHeadsGraphic_913Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_913);
}

Sprite* Graphics::createHeadsGraphic_914Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_914);
}

Sprite* Graphics::createHeadsGraphic_915Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_915);
}

Sprite* Graphics::createHeadsGraphic_916Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_916);
}

Sprite* Graphics::createHeadsGraphic_917Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_917);
}

Sprite* Graphics::createHeadsGraphic_918Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_918);
}

Sprite* Graphics::createHeadsGraphic_919Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_919);
}

Sprite* Graphics::createHeadsGraphic_920Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_920);
}

Sprite* Graphics::createHeadsGraphic_921Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_921);
}

Sprite* Graphics::createHeadsGraphic_922Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_922);
}

Sprite* Graphics::createHeadsGraphic_923Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_923);
}

Sprite* Graphics::createHeadsGraphic_924Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_924);
}

Sprite* Graphics::createHeadsGraphic_925Sprite()
{
    return Sprite::createWithSpriteFrameName(headsGraphic_925);
}

Sprite* Graphics::createHeadsPlayerHeadDarkElfASprite()
{
    return Sprite::createWithSpriteFrameName(headsPlayerHeadDarkElfA);
}

Sprite* Graphics::createHeadsPlayerHeadHumanASprite()
{
    return Sprite::createWithSpriteFrameName(headsPlayerHeadHumanA);
}

Sprite* Graphics::createHeadsPlayerHeadHumanBSprite()
{
    return Sprite::createWithSpriteFrameName(headsPlayerHeadHumanB);
}

Sprite* Graphics::createHeadsPlayerHeadHumanCSprite()
{
    return Sprite::createWithSpriteFrameName(headsPlayerHeadHumanC);
}

Sprite* Graphics::createHeadsPlayerHeadHumanDSprite()
{
    return Sprite::createWithSpriteFrameName(headsPlayerHeadHumanD);
}

Sprite* Graphics::createHeadsPlayerHeadHumanESprite()
{
    return Sprite::createWithSpriteFrameName(headsPlayerHeadHumanE);
}

Sprite* Graphics::createHeadsPlayerHeadHumanFSprite()
{
    return Sprite::createWithSpriteFrameName(headsPlayerHeadHumanF);
}

Sprite* Graphics::createHeadsPlayerHeadHumanGSprite()
{
    return Sprite::createWithSpriteFrameName(headsPlayerHeadHumanG);
}

Sprite* Graphics::createHeadsPlayerHeadHumanHSprite()
{
    return Sprite::createWithSpriteFrameName(headsPlayerHeadHumanH);
}

Sprite* Graphics::createHeadsPlayerHeadPirateEastSprite()
{
    return Sprite::createWithSpriteFrameName(headsPlayerHeadPirateEast);
}

Sprite* Graphics::createHeadsPlayerHeadPirateNorthSprite()
{
    return Sprite::createWithSpriteFrameName(headsPlayerHeadPirateNorth);
}

Sprite* Graphics::createHeadsPlayerHeadPirateSouthSprite()
{
    return Sprite::createWithSpriteFrameName(headsPlayerHeadPirateSouth);
}

Sprite* Graphics::createHeadsPlayerHeadPirateWestSprite()
{
    return Sprite::createWithSpriteFrameName(headsPlayerHeadPirateWest);
}

Sprite* Graphics::createInterfaceCitizenSafeSprite()
{
    return Sprite::createWithSpriteFrameName(interfaceCitizenSafe);
}

Sprite* Graphics::createInterfaceCitizenUnSafeSprite()
{
    return Sprite::createWithSpriteFrameName(interfaceCitizenUnSafe);
}

Sprite* Graphics::createInterfaceResurrectionSafeSprite()
{
    return Sprite::createWithSpriteFrameName(interfaceResurrectionSafe);
}

Sprite* Graphics::createInterfaceResurrectionUnSafeSprite()
{
    return Sprite::createWithSpriteFrameName(interfaceResurrectionUnSafe);
}

Sprite* Graphics::createInterfaceSpellOffSprite()
{
    return Sprite::createWithSpriteFrameName(interfaceSpellOff);
}

Sprite* Graphics::createInterfaceSpellOnSprite()
{
    return Sprite::createWithSpriteFrameName(interfaceSpellOn);
}

Sprite* Graphics::createInterfaceWorkOffSprite()
{
    return Sprite::createWithSpriteFrameName(interfaceWorkOff);
}

Sprite* Graphics::createInterfaceWorkOnSprite()
{
    return Sprite::createWithSpriteFrameName(interfaceWorkOn);
}

Sprite* Graphics::createItemAtlasArgentumSprite()
{
    return Sprite::createWithSpriteFrameName(itemAtlasArgentum);
}

Sprite* Graphics::createItemAxeGoldSprite()
{
    return Sprite::createWithSpriteFrameName(itemAxeGold);
}

Sprite* Graphics::createItemBedFrontSprite()
{
    return Sprite::createWithSpriteFrameName(itemBedFront);
}

Sprite* Graphics::createItemBedSideSprite()
{
    return Sprite::createWithSpriteFrameName(itemBedSide);
}

Sprite* Graphics::createItemBeerSprite()
{
    return Sprite::createWithSpriteFrameName(itemBeer);
}

Sprite* Graphics::createItemBookSprite()
{
    return Sprite::createWithSpriteFrameName(itemBook);
}

Sprite* Graphics::createItemCanteenEmptySprite()
{
    return Sprite::createWithSpriteFrameName(itemCanteenEmpty);
}

Sprite* Graphics::createItemCanteenFullSprite()
{
    return Sprite::createWithSpriteFrameName(itemCanteenFull);
}

Sprite* Graphics::createItemChairFrontSprite()
{
    return Sprite::createWithSpriteFrameName(itemChairFront);
}

Sprite* Graphics::createItemChairSideSprite()
{
    return Sprite::createWithSpriteFrameName(itemChairSide);
}

Sprite* Graphics::createItemChaliceGoldSprite()
{
    return Sprite::createWithSpriteFrameName(itemChaliceGold);
}

Sprite* Graphics::createItemChaliceSilverSprite()
{
    return Sprite::createWithSpriteFrameName(itemChaliceSilver);
}

Sprite* Graphics::createItemClotheTunicaMonkE_GSprite()
{
    return Sprite::createWithSpriteFrameName(itemClotheTunicaMonkE_G);
}

Sprite* Graphics::createItemClotheTunicaMonkH_E_EOSprite()
{
    return Sprite::createWithSpriteFrameName(itemClotheTunicaMonkH_E_EO);
}

Sprite* Graphics::createItemDrinkFruitJuiceSprite()
{
    return Sprite::createWithSpriteFrameName(itemDrinkFruitJuice);
}

Sprite* Graphics::createItemDrinkWaterSprite()
{
    return Sprite::createWithSpriteFrameName(itemDrinkWater);
}

Sprite* Graphics::createItemDrinkWineSprite()
{
    return Sprite::createWithSpriteFrameName(itemDrinkWine);
}

Sprite* Graphics::createItemDrumSprite()
{
    return Sprite::createWithSpriteFrameName(itemDrum);
}

Sprite* Graphics::createItemFishHakeSprite()
{
    return Sprite::createWithSpriteFrameName(itemFishHake);
}

Sprite* Graphics::createItemFishSalmonSprite()
{
    return Sprite::createWithSpriteFrameName(itemFishSalmon);
}

Sprite* Graphics::createItemFishSeaHorseSprite()
{
    return Sprite::createWithSpriteFrameName(itemFishSeaHorse);
}

Sprite* Graphics::createItemFishingNetSprite()
{
    return Sprite::createWithSpriteFrameName(itemFishingNet);
}

Sprite* Graphics::createItemFishingRodSprite()
{
    return Sprite::createWithSpriteFrameName(itemFishingRod);
}

Sprite* Graphics::createItemFluteSprite()
{
    return Sprite::createWithSpriteFrameName(itemFlute);
}

Sprite* Graphics::createItemFoodAppleSprite()
{
    return Sprite::createWithSpriteFrameName(itemFoodApple);
}

Sprite* Graphics::createItemFoodBananaSprite()
{
    return Sprite::createWithSpriteFrameName(itemFoodBanana);
}

Sprite* Graphics::createItemFoodBreadSprite()
{
    return Sprite::createWithSpriteFrameName(itemFoodBread);
}

Sprite* Graphics::createItemFoodCheeseSprite()
{
    return Sprite::createWithSpriteFrameName(itemFoodCheese);
}

Sprite* Graphics::createItemFoodChickenCoockedSprite()
{
    return Sprite::createWithSpriteFrameName(itemFoodChickenCoocked);
}

Sprite* Graphics::createItemFoodFruitsSprite()
{
    return Sprite::createWithSpriteFrameName(itemFoodFruits);
}

Sprite* Graphics::createItemFoodMuffinSprite()
{
    return Sprite::createWithSpriteFrameName(itemFoodMuffin);
}

Sprite* Graphics::createItemFoodPieSprite()
{
    return Sprite::createWithSpriteFrameName(itemFoodPie);
}

Sprite* Graphics::createItemFoodRawMeetSprite()
{
    return Sprite::createWithSpriteFrameName(itemFoodRawMeet);
}

Sprite* Graphics::createItemFoodWaterMelonSprite()
{
    return Sprite::createWithSpriteFrameName(itemFoodWaterMelon);
}

Sprite* Graphics::createItemFurBearSprite()
{
    return Sprite::createWithSpriteFrameName(itemFurBear);
}

Sprite* Graphics::createItemFurPolarBearSprite()
{
    return Sprite::createWithSpriteFrameName(itemFurPolarBear);
}

Sprite* Graphics::createItemFurPolarWolfSprite()
{
    return Sprite::createWithSpriteFrameName(itemFurPolarWolf);
}

Sprite* Graphics::createItemFurWolfSprite()
{
    return Sprite::createWithSpriteFrameName(itemFurWolf);
}

Sprite* Graphics::createItemFurnitureChairSideSprite()
{
    return Sprite::createWithSpriteFrameName(itemFurnitureChairSide);
}

Sprite* Graphics::createItemFurnitureCouchSprite()
{
    return Sprite::createWithSpriteFrameName(itemFurnitureCouch);
}

Sprite* Graphics::createItemFurnitureRusticSprite()
{
    return Sprite::createWithSpriteFrameName(itemFurnitureRustic);
}

Sprite* Graphics::createItemFurnitureWoodSpoonSprite()
{
    return Sprite::createWithSpriteFrameName(itemFurnitureWoodSpoon);
}

Sprite* Graphics::createItemGalleonSprite()
{
    return Sprite::createWithSpriteFrameName(itemGalleon);
}

Sprite* Graphics::createItemGalleySprite()
{
    return Sprite::createWithSpriteFrameName(itemGalley);
}

Sprite* Graphics::createItemGoldCoinsSprite()
{
    return Sprite::createWithSpriteFrameName(itemGoldCoins);
}

Sprite* Graphics::createItemHammerSprite()
{
    return Sprite::createWithSpriteFrameName(itemHammer);
}

Sprite* Graphics::createItemHatBlueSprite()
{
    return Sprite::createWithSpriteFrameName(itemHatBlue);
}

Sprite* Graphics::createItemHatNoviceSprite()
{
    return Sprite::createWithSpriteFrameName(itemHatNovice);
}

Sprite* Graphics::createItemHatProSprite()
{
    return Sprite::createWithSpriteFrameName(itemHatPro);
}

Sprite* Graphics::createItemHelmetBearSprite()
{
    return Sprite::createWithSpriteFrameName(itemHelmetBear);
}

Sprite* Graphics::createItemHelmetEagleSprite()
{
    return Sprite::createWithSpriteFrameName(itemHelmetEagle);
}

Sprite* Graphics::createItemHelmetIronSprite()
{
    return Sprite::createWithSpriteFrameName(itemHelmetIron);
}

Sprite* Graphics::createItemHelmetIronProSprite()
{
    return Sprite::createWithSpriteFrameName(itemHelmetIronPro);
}

Sprite* Graphics::createItemHelmetSilverSprite()
{
    return Sprite::createWithSpriteFrameName(itemHelmetSilver);
}

Sprite* Graphics::createItemHelmetTigerSprite()
{
    return Sprite::createWithSpriteFrameName(itemHelmetTiger);
}

Sprite* Graphics::createItemHelmetWolfSprite()
{
    return Sprite::createWithSpriteFrameName(itemHelmetWolf);
}

Sprite* Graphics::createItemHoodBrownSprite()
{
    return Sprite::createWithSpriteFrameName(itemHoodBrown);
}

Sprite* Graphics::createItemIngotGoldSprite()
{
    return Sprite::createWithSpriteFrameName(itemIngotGold);
}

Sprite* Graphics::createItemIngotIronSprite()
{
    return Sprite::createWithSpriteFrameName(itemIngotIron);
}

Sprite* Graphics::createItemIngotSilverSprite()
{
    return Sprite::createWithSpriteFrameName(itemIngotSilver);
}

Sprite* Graphics::createItemKerchiefRedSprite()
{
    return Sprite::createWithSpriteFrameName(itemKerchiefRed);
}

Sprite* Graphics::createItemKeySprite()
{
    return Sprite::createWithSpriteFrameName(itemKey);
}

Sprite* Graphics::createItemKnottyCaneSprite()
{
    return Sprite::createWithSpriteFrameName(itemKnottyCane);
}

Sprite* Graphics::createItemLogsSprite()
{
    return Sprite::createWithSpriteFrameName(itemLogs);
}

Sprite* Graphics::createItemLogsAshSprite()
{
    return Sprite::createWithSpriteFrameName(itemLogsAsh);
}

Sprite* Graphics::createItemLuteSprite()
{
    return Sprite::createWithSpriteFrameName(itemLute);
}

Sprite* Graphics::createItemOreGoldSprite()
{
    return Sprite::createWithSpriteFrameName(itemOreGold);
}

Sprite* Graphics::createItemOreIronSprite()
{
    return Sprite::createWithSpriteFrameName(itemOreIron);
}

Sprite* Graphics::createItemOreSilverSprite()
{
    return Sprite::createWithSpriteFrameName(itemOreSilver);
}

Sprite* Graphics::createItemPotionBlackSprite()
{
    return Sprite::createWithSpriteFrameName(itemPotionBlack);
}

Sprite* Graphics::createItemPotionLargeBlueSprite()
{
    return Sprite::createWithSpriteFrameName(itemPotionLargeBlue);
}

Sprite* Graphics::createItemPotionLargeGreenSprite()
{
    return Sprite::createWithSpriteFrameName(itemPotionLargeGreen);
}

Sprite* Graphics::createItemPotionLargePurpleSprite()
{
    return Sprite::createWithSpriteFrameName(itemPotionLargePurple);
}

Sprite* Graphics::createItemPotionLargeRedSprite()
{
    return Sprite::createWithSpriteFrameName(itemPotionLargeRed);
}

Sprite* Graphics::createItemPotionLargeYellowSprite()
{
    return Sprite::createWithSpriteFrameName(itemPotionLargeYellow);
}

Sprite* Graphics::createItemPotionSmallBlackSprite()
{
    return Sprite::createWithSpriteFrameName(itemPotionSmallBlack);
}

Sprite* Graphics::createItemPotionSmallBlueSprite()
{
    return Sprite::createWithSpriteFrameName(itemPotionSmallBlue);
}

Sprite* Graphics::createItemPotionSmallGreenSprite()
{
    return Sprite::createWithSpriteFrameName(itemPotionSmallGreen);
}

Sprite* Graphics::createItemPotionSmallPurpleSprite()
{
    return Sprite::createWithSpriteFrameName(itemPotionSmallPurple);
}

Sprite* Graphics::createItemPotionSmallRedSprite()
{
    return Sprite::createWithSpriteFrameName(itemPotionSmallRed);
}

Sprite* Graphics::createItemPotionSmallYellowSprite()
{
    return Sprite::createWithSpriteFrameName(itemPotionSmallYellow);
}

Sprite* Graphics::createItemRingMagicResLSprite()
{
    return Sprite::createWithSpriteFrameName(itemRingMagicResL);
}

Sprite* Graphics::createItemRingMagicResMSprite()
{
    return Sprite::createWithSpriteFrameName(itemRingMagicResM);
}

Sprite* Graphics::createItemRingMagicResSSprite()
{
    return Sprite::createWithSpriteFrameName(itemRingMagicResS);
}

Sprite* Graphics::createItemRingMagicalSprite()
{
    return Sprite::createWithSpriteFrameName(itemRingMagical);
}

Sprite* Graphics::createItemRubyBlueSprite()
{
    return Sprite::createWithSpriteFrameName(itemRubyBlue);
}

Sprite* Graphics::createItemRubyGreenSprite()
{
    return Sprite::createWithSpriteFrameName(itemRubyGreen);
}

Sprite* Graphics::createItemRubyLightBlueSprite()
{
    return Sprite::createWithSpriteFrameName(itemRubyLightBlue);
}

Sprite* Graphics::createItemRubyOrangeSprite()
{
    return Sprite::createWithSpriteFrameName(itemRubyOrange);
}

Sprite* Graphics::createItemRubyPinkSprite()
{
    return Sprite::createWithSpriteFrameName(itemRubyPink);
}

Sprite* Graphics::createItemRubyPurpleSprite()
{
    return Sprite::createWithSpriteFrameName(itemRubyPurple);
}

Sprite* Graphics::createItemRubyRedSprite()
{
    return Sprite::createWithSpriteFrameName(itemRubyRed);
}

Sprite* Graphics::createItemRubyWhiteSprite()
{
    return Sprite::createWithSpriteFrameName(itemRubyWhite);
}

Sprite* Graphics::createItemSawSprite()
{
    return Sprite::createWithSpriteFrameName(itemSaw);
}

Sprite* Graphics::createItemScissorsSprite()
{
    return Sprite::createWithSpriteFrameName(itemScissors);
}

Sprite* Graphics::createItemSewingBoxSprite()
{
    return Sprite::createWithSpriteFrameName(itemSewingBox);
}

Sprite* Graphics::createItemShieldIronSprite()
{
    return Sprite::createWithSpriteFrameName(itemShieldIron);
}

Sprite* Graphics::createItemShieldTurtleSprite()
{
    return Sprite::createWithSpriteFrameName(itemShieldTurtle);
}

Sprite* Graphics::createItemShipSprite()
{
    return Sprite::createWithSpriteFrameName(itemShip);
}

Sprite* Graphics::createItemSpellSprite()
{
    return Sprite::createWithSpriteFrameName(itemSpell);
}

Sprite* Graphics::createItemThreadSprite()
{
    return Sprite::createWithSpriteFrameName(itemThread);
}

Sprite* Graphics::createItemThreadGoldenSprite()
{
    return Sprite::createWithSpriteFrameName(itemThreadGolden);
}

Sprite* Graphics::createItemWoolSprite()
{
    return Sprite::createWithSpriteFrameName(itemWool);
}

Sprite* Graphics::createJokeTeletubiesSprite()
{
    return Sprite::createWithSpriteFrameName(jokeTeletubies);
}

Sprite* Graphics::createMAPFungusBlueSprite()
{
    return Sprite::createWithSpriteFrameName(mAPFungusBlue);
}

Sprite* Graphics::createMAPFungusPurpleSprite()
{
    return Sprite::createWithSpriteFrameName(mAPFungusPurple);
}

Sprite* Graphics::createMAPFungusRedSprite()
{
    return Sprite::createWithSpriteFrameName(mAPFungusRed);
}

Sprite* Graphics::createMAPFungusYellowSprite()
{
    return Sprite::createWithSpriteFrameName(mAPFungusYellow);
}

Sprite* Graphics::createMapAnvilSprite()
{
    return Sprite::createWithSpriteFrameName(mapAnvil);
}

Sprite* Graphics::createMapArrowBrokenSprite()
{
    return Sprite::createWithSpriteFrameName(mapArrowBroken);
}

Sprite* Graphics::createMapArrowBrokenAshSprite()
{
    return Sprite::createWithSpriteFrameName(mapArrowBrokenAsh);
}

Sprite* Graphics::createMapAxeBloodSprite()
{
    return Sprite::createWithSpriteFrameName(mapAxeBlood);
}

Sprite* Graphics::createMapBannerBlueSprite()
{
    return Sprite::createWithSpriteFrameName(mapBannerBlue);
}

Sprite* Graphics::createMapBannerRedSprite()
{
    return Sprite::createWithSpriteFrameName(mapBannerRed);
}

Sprite* Graphics::createMapBarrelASprite()
{
    return Sprite::createWithSpriteFrameName(mapBarrelA);
}

Sprite* Graphics::createMapBarrelBSprite()
{
    return Sprite::createWithSpriteFrameName(mapBarrelB);
}

Sprite* Graphics::createMapBedDoubleFrontSprite()
{
    return Sprite::createWithSpriteFrameName(mapBedDoubleFront);
}

Sprite* Graphics::createMapBirdCageSprite()
{
    return Sprite::createWithSpriteFrameName(mapBirdCage);
}

Sprite* Graphics::createMapBirdCageDeathSprite()
{
    return Sprite::createWithSpriteFrameName(mapBirdCageDeath);
}

Sprite* Graphics::createMapBridgeBrickEWSprite()
{
    return Sprite::createWithSpriteFrameName(mapBridgeBrickEW);
}

Sprite* Graphics::createMapBridgeBrickNSSprite()
{
    return Sprite::createWithSpriteFrameName(mapBridgeBrickNS);
}

Sprite* Graphics::createMapBridgeGrayBirckCurveEWSprite()
{
    return Sprite::createWithSpriteFrameName(mapBridgeGrayBirckCurveEW);
}

Sprite* Graphics::createMapBushASprite()
{
    return Sprite::createWithSpriteFrameName(mapBushA);
}

Sprite* Graphics::createMapBushAASprite()
{
    return Sprite::createWithSpriteFrameName(mapBushAA);
}

Sprite* Graphics::createMapBushBSprite()
{
    return Sprite::createWithSpriteFrameName(mapBushB);
}

Sprite* Graphics::createMapBushBBSprite()
{
    return Sprite::createWithSpriteFrameName(mapBushBB);
}

Sprite* Graphics::createMapBushCSprite()
{
    return Sprite::createWithSpriteFrameName(mapBushC);
}

Sprite* Graphics::createMapBushDSprite()
{
    return Sprite::createWithSpriteFrameName(mapBushD);
}

Sprite* Graphics::createMapBushESprite()
{
    return Sprite::createWithSpriteFrameName(mapBushE);
}

Sprite* Graphics::createMapBushFSprite()
{
    return Sprite::createWithSpriteFrameName(mapBushF);
}

Sprite* Graphics::createMapBushGSprite()
{
    return Sprite::createWithSpriteFrameName(mapBushG);
}

Sprite* Graphics::createMapBushHSprite()
{
    return Sprite::createWithSpriteFrameName(mapBushH);
}

Sprite* Graphics::createMapBushISprite()
{
    return Sprite::createWithSpriteFrameName(mapBushI);
}

Sprite* Graphics::createMapBushJSprite()
{
    return Sprite::createWithSpriteFrameName(mapBushJ);
}

Sprite* Graphics::createMapBushKSprite()
{
    return Sprite::createWithSpriteFrameName(mapBushK);
}

Sprite* Graphics::createMapBushLSprite()
{
    return Sprite::createWithSpriteFrameName(mapBushL);
}

Sprite* Graphics::createMapBushMSprite()
{
    return Sprite::createWithSpriteFrameName(mapBushM);
}

Sprite* Graphics::createMapBushNSprite()
{
    return Sprite::createWithSpriteFrameName(mapBushN);
}

Sprite* Graphics::createMapBushOSprite()
{
    return Sprite::createWithSpriteFrameName(mapBushO);
}

Sprite* Graphics::createMapBushPSprite()
{
    return Sprite::createWithSpriteFrameName(mapBushP);
}

Sprite* Graphics::createMapBushQSprite()
{
    return Sprite::createWithSpriteFrameName(mapBushQ);
}

Sprite* Graphics::createMapBushXSprite()
{
    return Sprite::createWithSpriteFrameName(mapBushX);
}

Sprite* Graphics::createMapBushYSprite()
{
    return Sprite::createWithSpriteFrameName(mapBushY);
}

Sprite* Graphics::createMapBushZSprite()
{
    return Sprite::createWithSpriteFrameName(mapBushZ);
}

Sprite* Graphics::createMapCampFire01Sprite()
{
    return Sprite::createWithSpriteFrameName(mapCampFire01);
}

Sprite* Graphics::createMapCampFire02Sprite()
{
    return Sprite::createWithSpriteFrameName(mapCampFire02);
}

Sprite* Graphics::createMapCampFire03Sprite()
{
    return Sprite::createWithSpriteFrameName(mapCampFire03);
}

Sprite* Graphics::createMapCampFire04Sprite()
{
    return Sprite::createWithSpriteFrameName(mapCampFire04);
}

Sprite* Graphics::createMapCampFire05Sprite()
{
    return Sprite::createWithSpriteFrameName(mapCampFire05);
}

Sprite* Graphics::createMapCampFire06Sprite()
{
    return Sprite::createWithSpriteFrameName(mapCampFire06);
}

Sprite* Graphics::createMapCampFire07Sprite()
{
    return Sprite::createWithSpriteFrameName(mapCampFire07);
}

Sprite* Graphics::createMapCampFire08Sprite()
{
    return Sprite::createWithSpriteFrameName(mapCampFire08);
}

Sprite* Graphics::createMapCampFire09Sprite()
{
    return Sprite::createWithSpriteFrameName(mapCampFire09);
}

Sprite* Graphics::createMapCampFireOffSprite()
{
    return Sprite::createWithSpriteFrameName(mapCampFireOff);
}

Sprite* Graphics::createMapCarpenterDeskSprite()
{
    return Sprite::createWithSpriteFrameName(mapCarpenterDesk);
}

Sprite* Graphics::createMapDungeonA_1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonA_1);
}

Sprite* Graphics::createMapDungeonA_10Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonA_10);
}

Sprite* Graphics::createMapDungeonA_11Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonA_11);
}

Sprite* Graphics::createMapDungeonA_12Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonA_12);
}

Sprite* Graphics::createMapDungeonA_13Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonA_13);
}

Sprite* Graphics::createMapDungeonA_14Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonA_14);
}

Sprite* Graphics::createMapDungeonA_2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonA_2);
}

Sprite* Graphics::createMapDungeonA_3Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonA_3);
}

Sprite* Graphics::createMapDungeonA_4Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonA_4);
}

Sprite* Graphics::createMapDungeonA_5Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonA_5);
}

Sprite* Graphics::createMapDungeonA_6Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonA_6);
}

Sprite* Graphics::createMapDungeonA_7Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonA_7);
}

Sprite* Graphics::createMapDungeonA_8Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonA_8);
}

Sprite* Graphics::createMapDungeonA_9Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonA_9);
}

Sprite* Graphics::createMapDungeonB_1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_1);
}

Sprite* Graphics::createMapDungeonB_10Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_10);
}

Sprite* Graphics::createMapDungeonB_11Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_11);
}

Sprite* Graphics::createMapDungeonB_12Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_12);
}

Sprite* Graphics::createMapDungeonB_13Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_13);
}

Sprite* Graphics::createMapDungeonB_14Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_14);
}

Sprite* Graphics::createMapDungeonB_15Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_15);
}

Sprite* Graphics::createMapDungeonB_16Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_16);
}

Sprite* Graphics::createMapDungeonB_17Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_17);
}

Sprite* Graphics::createMapDungeonB_18Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_18);
}

Sprite* Graphics::createMapDungeonB_19Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_19);
}

Sprite* Graphics::createMapDungeonB_2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_2);
}

Sprite* Graphics::createMapDungeonB_20Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_20);
}

Sprite* Graphics::createMapDungeonB_21Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_21);
}

Sprite* Graphics::createMapDungeonB_22Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_22);
}

Sprite* Graphics::createMapDungeonB_23Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_23);
}

Sprite* Graphics::createMapDungeonB_24Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_24);
}

Sprite* Graphics::createMapDungeonB_25Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_25);
}

Sprite* Graphics::createMapDungeonB_3Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_3);
}

Sprite* Graphics::createMapDungeonB_4Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_4);
}

Sprite* Graphics::createMapDungeonB_5Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_5);
}

Sprite* Graphics::createMapDungeonB_6Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_6);
}

Sprite* Graphics::createMapDungeonB_7Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_7);
}

Sprite* Graphics::createMapDungeonB_8Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_8);
}

Sprite* Graphics::createMapDungeonB_9Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonB_9);
}

Sprite* Graphics::createMapDungeonC_1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonC_1);
}

Sprite* Graphics::createMapDungeonC_10Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonC_10);
}

Sprite* Graphics::createMapDungeonC_11Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonC_11);
}

Sprite* Graphics::createMapDungeonC_12Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonC_12);
}

Sprite* Graphics::createMapDungeonC_13Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonC_13);
}

Sprite* Graphics::createMapDungeonC_14Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonC_14);
}

Sprite* Graphics::createMapDungeonC_15Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonC_15);
}

Sprite* Graphics::createMapDungeonC_16Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonC_16);
}

Sprite* Graphics::createMapDungeonC_17Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonC_17);
}

Sprite* Graphics::createMapDungeonC_2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonC_2);
}

Sprite* Graphics::createMapDungeonC_3Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonC_3);
}

Sprite* Graphics::createMapDungeonC_4Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonC_4);
}

Sprite* Graphics::createMapDungeonC_5Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonC_5);
}

Sprite* Graphics::createMapDungeonC_6Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonC_6);
}

Sprite* Graphics::createMapDungeonC_7Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonC_7);
}

Sprite* Graphics::createMapDungeonC_8Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonC_8);
}

Sprite* Graphics::createMapDungeonC_9Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonC_9);
}

Sprite* Graphics::createMapDungeonD_1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonD_1);
}

Sprite* Graphics::createMapDungeonD_10Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonD_10);
}

Sprite* Graphics::createMapDungeonD_11Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonD_11);
}

Sprite* Graphics::createMapDungeonD_12Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonD_12);
}

Sprite* Graphics::createMapDungeonD_13Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonD_13);
}

Sprite* Graphics::createMapDungeonD_14Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonD_14);
}

Sprite* Graphics::createMapDungeonD_2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonD_2);
}

Sprite* Graphics::createMapDungeonD_3Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonD_3);
}

Sprite* Graphics::createMapDungeonD_4Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonD_4);
}

Sprite* Graphics::createMapDungeonD_5Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonD_5);
}

Sprite* Graphics::createMapDungeonD_6Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonD_6);
}

Sprite* Graphics::createMapDungeonD_7Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonD_7);
}

Sprite* Graphics::createMapDungeonD_8Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonD_8);
}

Sprite* Graphics::createMapDungeonD_9Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonD_9);
}

Sprite* Graphics::createMapDungeonE_1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonE_1);
}

Sprite* Graphics::createMapDungeonE_10Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonE_10);
}

Sprite* Graphics::createMapDungeonE_11Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonE_11);
}

Sprite* Graphics::createMapDungeonE_12Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonE_12);
}

Sprite* Graphics::createMapDungeonE_13Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonE_13);
}

Sprite* Graphics::createMapDungeonE_14Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonE_14);
}

Sprite* Graphics::createMapDungeonE_15Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonE_15);
}

Sprite* Graphics::createMapDungeonE_16Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonE_16);
}

Sprite* Graphics::createMapDungeonE_17Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonE_17);
}

Sprite* Graphics::createMapDungeonE_18Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonE_18);
}

Sprite* Graphics::createMapDungeonE_19Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonE_19);
}

Sprite* Graphics::createMapDungeonE_2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonE_2);
}

Sprite* Graphics::createMapDungeonE_20Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonE_20);
}

Sprite* Graphics::createMapDungeonE_3Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonE_3);
}

Sprite* Graphics::createMapDungeonE_4Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonE_4);
}

Sprite* Graphics::createMapDungeonE_5Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonE_5);
}

Sprite* Graphics::createMapDungeonE_6Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonE_6);
}

Sprite* Graphics::createMapDungeonE_7Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonE_7);
}

Sprite* Graphics::createMapDungeonE_8Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonE_8);
}

Sprite* Graphics::createMapDungeonE_9Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonE_9);
}

Sprite* Graphics::createMapDungeonEntranceASprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonEntranceA);
}

Sprite* Graphics::createMapDungeonEntranceBSprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonEntranceB);
}

Sprite* Graphics::createMapDungeonEntranceCSprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonEntranceC);
}

Sprite* Graphics::createMapDungeonEntranceCommonSprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonEntranceCommon);
}

Sprite* Graphics::createMapDungeonEntranceCommonMossySprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonEntranceCommonMossy);
}

Sprite* Graphics::createMapDungeonEntranceDSprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonEntranceD);
}

Sprite* Graphics::createMapDungeonEntranceESprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonEntranceE);
}

Sprite* Graphics::createMapDungeonEntranceFSprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonEntranceF);
}

Sprite* Graphics::createMapDungeonEntranceGSprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonEntranceG);
}

Sprite* Graphics::createMapDungeonEntranceHSprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonEntranceH);
}

Sprite* Graphics::createMapDungeonEntranceISprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonEntranceI);
}

Sprite* Graphics::createMapDungeonEntranceJSprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonEntranceJ);
}

Sprite* Graphics::createMapDungeonEntranceKSprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonEntranceK);
}

Sprite* Graphics::createMapDungeonEntranceNewbieSprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonEntranceNewbie);
}

Sprite* Graphics::createMapDungeonEntranceSharkSprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonEntranceShark);
}

Sprite* Graphics::createMapDungeonEntranceVesparSprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonEntranceVespar);
}

Sprite* Graphics::createMapDungeonF_1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonF_1);
}

Sprite* Graphics::createMapDungeonF_10Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonF_10);
}

Sprite* Graphics::createMapDungeonF_11Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonF_11);
}

Sprite* Graphics::createMapDungeonF_12Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonF_12);
}

Sprite* Graphics::createMapDungeonF_13Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonF_13);
}

Sprite* Graphics::createMapDungeonF_14Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonF_14);
}

Sprite* Graphics::createMapDungeonF_15Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonF_15);
}

Sprite* Graphics::createMapDungeonF_16Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonF_16);
}

Sprite* Graphics::createMapDungeonF_17Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonF_17);
}

Sprite* Graphics::createMapDungeonF_2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonF_2);
}

Sprite* Graphics::createMapDungeonF_3Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonF_3);
}

Sprite* Graphics::createMapDungeonF_4Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonF_4);
}

Sprite* Graphics::createMapDungeonF_5Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonF_5);
}

Sprite* Graphics::createMapDungeonF_6Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonF_6);
}

Sprite* Graphics::createMapDungeonF_7Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonF_7);
}

Sprite* Graphics::createMapDungeonF_8Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonF_8);
}

Sprite* Graphics::createMapDungeonF_9Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonF_9);
}

Sprite* Graphics::createMapDungeonG_1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonG_1);
}

Sprite* Graphics::createMapDungeonG_10Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonG_10);
}

Sprite* Graphics::createMapDungeonG_11Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonG_11);
}

Sprite* Graphics::createMapDungeonG_12Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonG_12);
}

Sprite* Graphics::createMapDungeonG_13Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonG_13);
}

Sprite* Graphics::createMapDungeonG_14Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonG_14);
}

Sprite* Graphics::createMapDungeonG_15Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonG_15);
}

Sprite* Graphics::createMapDungeonG_16Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonG_16);
}

Sprite* Graphics::createMapDungeonG_17Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonG_17);
}

Sprite* Graphics::createMapDungeonG_2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonG_2);
}

Sprite* Graphics::createMapDungeonG_3Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonG_3);
}

Sprite* Graphics::createMapDungeonG_4Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonG_4);
}

Sprite* Graphics::createMapDungeonG_5Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonG_5);
}

Sprite* Graphics::createMapDungeonG_6Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonG_6);
}

Sprite* Graphics::createMapDungeonG_7Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonG_7);
}

Sprite* Graphics::createMapDungeonG_8Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonG_8);
}

Sprite* Graphics::createMapDungeonG_9Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonG_9);
}

Sprite* Graphics::createMapDungeonMagma_1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonMagma_1);
}

Sprite* Graphics::createMapDungeonMagma_10Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonMagma_10);
}

Sprite* Graphics::createMapDungeonMagma_11Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonMagma_11);
}

Sprite* Graphics::createMapDungeonMagma_12Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonMagma_12);
}

Sprite* Graphics::createMapDungeonMagma_13Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonMagma_13);
}

Sprite* Graphics::createMapDungeonMagma_14Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonMagma_14);
}

Sprite* Graphics::createMapDungeonMagma_2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonMagma_2);
}

Sprite* Graphics::createMapDungeonMagma_3Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonMagma_3);
}

Sprite* Graphics::createMapDungeonMagma_4Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonMagma_4);
}

Sprite* Graphics::createMapDungeonMagma_5Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonMagma_5);
}

Sprite* Graphics::createMapDungeonMagma_6Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonMagma_6);
}

Sprite* Graphics::createMapDungeonMagma_7Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonMagma_7);
}

Sprite* Graphics::createMapDungeonMagma_8Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonMagma_8);
}

Sprite* Graphics::createMapDungeonMagma_9Sprite()
{
    return Sprite::createWithSpriteFrameName(mapDungeonMagma_9);
}

Sprite* Graphics::createMapFence_1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_1);
}

Sprite* Graphics::createMapFence_10Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_10);
}

Sprite* Graphics::createMapFence_11Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_11);
}

Sprite* Graphics::createMapFence_12Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_12);
}

Sprite* Graphics::createMapFence_13Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_13);
}

Sprite* Graphics::createMapFence_14Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_14);
}

Sprite* Graphics::createMapFence_15Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_15);
}

Sprite* Graphics::createMapFence_16Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_16);
}

Sprite* Graphics::createMapFence_17Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_17);
}

Sprite* Graphics::createMapFence_18Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_18);
}

Sprite* Graphics::createMapFence_19Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_19);
}

Sprite* Graphics::createMapFence_2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_2);
}

Sprite* Graphics::createMapFence_20Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_20);
}

Sprite* Graphics::createMapFence_21Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_21);
}

Sprite* Graphics::createMapFence_22Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_22);
}

Sprite* Graphics::createMapFence_23Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_23);
}

Sprite* Graphics::createMapFence_3Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_3);
}

Sprite* Graphics::createMapFence_4Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_4);
}

Sprite* Graphics::createMapFence_5Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_5);
}

Sprite* Graphics::createMapFence_6Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_6);
}

Sprite* Graphics::createMapFence_7Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_7);
}

Sprite* Graphics::createMapFence_8Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_8);
}

Sprite* Graphics::createMapFence_9Sprite()
{
    return Sprite::createWithSpriteFrameName(mapFence_9);
}

Sprite* Graphics::createMapForgeSprite()
{
    return Sprite::createWithSpriteFrameName(mapForge);
}

Sprite* Graphics::createMapFossilRestSprite()
{
    return Sprite::createWithSpriteFrameName(mapFossilRest);
}

Sprite* Graphics::createMapGrassSprite()
{
    return Sprite::createWithSpriteFrameName(mapGrass);
}

Sprite* Graphics::createMapLavaSprite()
{
    return Sprite::createWithSpriteFrameName(mapLava);
}

Sprite* Graphics::createMapLogLongStandingSprite()
{
    return Sprite::createWithSpriteFrameName(mapLogLongStanding);
}

Sprite* Graphics::createMapMineGoldSprite()
{
    return Sprite::createWithSpriteFrameName(mapMineGold);
}

Sprite* Graphics::createMapMineIronSprite()
{
    return Sprite::createWithSpriteFrameName(mapMineIron);
}

Sprite* Graphics::createMapMineSilverSprite()
{
    return Sprite::createWithSpriteFrameName(mapMineSilver);
}

Sprite* Graphics::createMapMisticalPlace0Sprite()
{
    return Sprite::createWithSpriteFrameName(mapMisticalPlace0);
}

Sprite* Graphics::createMapMisticalPlace1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapMisticalPlace1);
}

Sprite* Graphics::createMapMisticalPlace2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapMisticalPlace2);
}

Sprite* Graphics::createMapMisticalPlaceB0Sprite()
{
    return Sprite::createWithSpriteFrameName(mapMisticalPlaceB0);
}

Sprite* Graphics::createMapMisticalPlaceB1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapMisticalPlaceB1);
}

Sprite* Graphics::createMapMisticalPlaceB2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapMisticalPlaceB2);
}

Sprite* Graphics::createMapMisticalPlaceB3Sprite()
{
    return Sprite::createWithSpriteFrameName(mapMisticalPlaceB3);
}

Sprite* Graphics::createMapMisticalPlaceB4Sprite()
{
    return Sprite::createWithSpriteFrameName(mapMisticalPlaceB4);
}

Sprite* Graphics::createMapMisticalPlaceB5Sprite()
{
    return Sprite::createWithSpriteFrameName(mapMisticalPlaceB5);
}

Sprite* Graphics::createMapMisticalPlaceB6Sprite()
{
    return Sprite::createWithSpriteFrameName(mapMisticalPlaceB6);
}

Sprite* Graphics::createMapMisticalPlaceB7Sprite()
{
    return Sprite::createWithSpriteFrameName(mapMisticalPlaceB7);
}

Sprite* Graphics::createMapMisticalPlaceB8Sprite()
{
    return Sprite::createWithSpriteFrameName(mapMisticalPlaceB8);
}

Sprite* Graphics::createMapPlantCactusSmallSprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantCactusSmall);
}

Sprite* Graphics::createMapPlantCactusTallSprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantCactusTall);
}

Sprite* Graphics::createMapPlantColorfulSprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantColorful);
}

Sprite* Graphics::createMapPlantDotsBlueSprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantDotsBlue);
}

Sprite* Graphics::createMapPlantDotsBlueRedSprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantDotsBlueRed);
}

Sprite* Graphics::createMapPlantDotsLightBlueSprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantDotsLightBlue);
}

Sprite* Graphics::createMapPlantDotsOrangeSprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantDotsOrange);
}

Sprite* Graphics::createMapPlantDotsPurpleASprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantDotsPurpleA);
}

Sprite* Graphics::createMapPlantDotsPurpleBSprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantDotsPurpleB);
}

Sprite* Graphics::createMapPlantDotsPurpleCSprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantDotsPurpleC);
}

Sprite* Graphics::createMapPlantDotsRedSprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantDotsRed);
}

Sprite* Graphics::createMapPlantFlowerPotASprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantFlowerPotA);
}

Sprite* Graphics::createMapPlantFlowerPotBSprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantFlowerPotB);
}

Sprite* Graphics::createMapPlantFlowerPotCSprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantFlowerPotC);
}

Sprite* Graphics::createMapPlantFlowerPotESprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantFlowerPotE);
}

Sprite* Graphics::createMapPlantFungusGiantSprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantFungusGiant);
}

Sprite* Graphics::createMapPlantFungusGreySprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantFungusGrey);
}

Sprite* Graphics::createMapPlantFungusWhiteRedSprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantFungusWhiteRed);
}

Sprite* Graphics::createMapPlantLilyPadSprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantLilyPad);
}

Sprite* Graphics::createMapPlantOrangeFlowersSprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantOrangeFlowers);
}

Sprite* Graphics::createMapPlantRedFlowersSprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantRedFlowers);
}

Sprite* Graphics::createMapPlantSunFlowerSprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantSunFlower);
}

Sprite* Graphics::createMapPlantTotASprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantTotA);
}

Sprite* Graphics::createMapPlantTotBSprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantTotB);
}

Sprite* Graphics::createMapPlantTotCSprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantTotC);
}

Sprite* Graphics::createMapPlantYukaSprite()
{
    return Sprite::createWithSpriteFrameName(mapPlantYuka);
}

Sprite* Graphics::createMapPortalBlue0Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalBlue0);
}

Sprite* Graphics::createMapPortalBlue1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalBlue1);
}

Sprite* Graphics::createMapPortalBlue2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalBlue2);
}

Sprite* Graphics::createMapPortalBlue3Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalBlue3);
}

Sprite* Graphics::createMapPortalBlue4Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalBlue4);
}

Sprite* Graphics::createMapPortalBlue5Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalBlue5);
}

Sprite* Graphics::createMapPortalBlue6Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalBlue6);
}

Sprite* Graphics::createMapPortalBlue7Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalBlue7);
}

Sprite* Graphics::createMapPortalClasic0Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalClasic0);
}

Sprite* Graphics::createMapPortalClasic1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalClasic1);
}

Sprite* Graphics::createMapPortalClasic2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalClasic2);
}

Sprite* Graphics::createMapPortalClasic3Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalClasic3);
}

Sprite* Graphics::createMapPortalClasic4Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalClasic4);
}

Sprite* Graphics::createMapPortalClasic5Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalClasic5);
}

Sprite* Graphics::createMapPortalClasic6Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalClasic6);
}

Sprite* Graphics::createMapPortalClasic7Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalClasic7);
}

Sprite* Graphics::createMapPortalClasicWarmer0Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalClasicWarmer0);
}

Sprite* Graphics::createMapPortalClasicWarmer1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalClasicWarmer1);
}

Sprite* Graphics::createMapPortalClasicWarmer2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalClasicWarmer2);
}

Sprite* Graphics::createMapPortalClasicWarmer3Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalClasicWarmer3);
}

Sprite* Graphics::createMapPortalClasicWarmer4Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalClasicWarmer4);
}

Sprite* Graphics::createMapPortalClasicWarmer5Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalClasicWarmer5);
}

Sprite* Graphics::createMapPortalClasicWarmer6Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalClasicWarmer6);
}

Sprite* Graphics::createMapPortalClasicWarmer7Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalClasicWarmer7);
}

Sprite* Graphics::createMapPortalGreen0Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalGreen0);
}

Sprite* Graphics::createMapPortalGreen1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalGreen1);
}

Sprite* Graphics::createMapPortalGreen2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalGreen2);
}

Sprite* Graphics::createMapPortalGreen3Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalGreen3);
}

Sprite* Graphics::createMapPortalGreen4Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalGreen4);
}

Sprite* Graphics::createMapPortalGreen5Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalGreen5);
}

Sprite* Graphics::createMapPortalGreen6Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalGreen6);
}

Sprite* Graphics::createMapPortalGreen7Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalGreen7);
}

Sprite* Graphics::createMapPortalLightBlue0Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalLightBlue0);
}

Sprite* Graphics::createMapPortalLightBlue1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalLightBlue1);
}

Sprite* Graphics::createMapPortalLightBlue2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalLightBlue2);
}

Sprite* Graphics::createMapPortalLightBlue3Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalLightBlue3);
}

Sprite* Graphics::createMapPortalLightBlue4Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalLightBlue4);
}

Sprite* Graphics::createMapPortalLightBlue5Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalLightBlue5);
}

Sprite* Graphics::createMapPortalLightBlue6Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalLightBlue6);
}

Sprite* Graphics::createMapPortalLightBlue7Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalLightBlue7);
}

Sprite* Graphics::createMapPortalPink0Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalPink0);
}

Sprite* Graphics::createMapPortalPink1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalPink1);
}

Sprite* Graphics::createMapPortalPink2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalPink2);
}

Sprite* Graphics::createMapPortalPink3Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalPink3);
}

Sprite* Graphics::createMapPortalPink4Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalPink4);
}

Sprite* Graphics::createMapPortalPink5Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalPink5);
}

Sprite* Graphics::createMapPortalPink6Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalPink6);
}

Sprite* Graphics::createMapPortalPink7Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalPink7);
}

Sprite* Graphics::createMapPortalPurple0Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalPurple0);
}

Sprite* Graphics::createMapPortalPurple1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalPurple1);
}

Sprite* Graphics::createMapPortalPurple2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalPurple2);
}

Sprite* Graphics::createMapPortalPurple3Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalPurple3);
}

Sprite* Graphics::createMapPortalPurple4Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalPurple4);
}

Sprite* Graphics::createMapPortalPurple5Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalPurple5);
}

Sprite* Graphics::createMapPortalPurple6Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalPurple6);
}

Sprite* Graphics::createMapPortalPurple7Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalPurple7);
}

Sprite* Graphics::createMapPortalYellow0Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalYellow0);
}

Sprite* Graphics::createMapPortalYellow1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalYellow1);
}

Sprite* Graphics::createMapPortalYellow2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalYellow2);
}

Sprite* Graphics::createMapPortalYellow3Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalYellow3);
}

Sprite* Graphics::createMapPortalYellow4Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalYellow4);
}

Sprite* Graphics::createMapPortalYellow5Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalYellow5);
}

Sprite* Graphics::createMapPortalYellow6Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalYellow6);
}

Sprite* Graphics::createMapPortalYellow7Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPortalYellow7);
}

Sprite* Graphics::createMapPosterAbadiaSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterAbadia);
}

Sprite* Graphics::createMapPosterArghalCentralEastSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterArghalCentralEast);
}

Sprite* Graphics::createMapPosterArghalEastSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterArghalEast);
}

Sprite* Graphics::createMapPosterArmadurasSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterArmaduras);
}

Sprite* Graphics::createMapPosterAsesinoSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterAsesino);
}

Sprite* Graphics::createMapPosterBandervilleSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterBanderville);
}

Sprite* Graphics::createMapPosterBandidoSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterBandido);
}

Sprite* Graphics::createMapPosterBardoSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterBardo);
}

Sprite* Graphics::createMapPosterBienvenidosAArghalSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterBienvenidosAArghal);
}

Sprite* Graphics::createMapPosterBienvenidosABanderbillSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterBienvenidosABanderbill);
}

Sprite* Graphics::createMapPosterBlacksmithSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterBlacksmith);
}

Sprite* Graphics::createMapPosterBosqueDeDorkWestNixSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterBosqueDeDorkWestNixSouth);
}

Sprite* Graphics::createMapPosterCarpinteriaSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterCarpinteria);
}

Sprite* Graphics::createMapPosterCasa1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterCasa1);
}

Sprite* Graphics::createMapPosterCasa10Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterCasa10);
}

Sprite* Graphics::createMapPosterCasa11Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterCasa11);
}

Sprite* Graphics::createMapPosterCasa12Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterCasa12);
}

Sprite* Graphics::createMapPosterCasa13Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterCasa13);
}

Sprite* Graphics::createMapPosterCasa14Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterCasa14);
}

Sprite* Graphics::createMapPosterCasa15Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterCasa15);
}

Sprite* Graphics::createMapPosterCasa16Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterCasa16);
}

Sprite* Graphics::createMapPosterCasa17Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterCasa17);
}

Sprite* Graphics::createMapPosterCasa18Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterCasa18);
}

Sprite* Graphics::createMapPosterCasa19Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterCasa19);
}

Sprite* Graphics::createMapPosterCasa2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterCasa2);
}

Sprite* Graphics::createMapPosterCasa20Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterCasa20);
}

Sprite* Graphics::createMapPosterCasa3Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterCasa3);
}

Sprite* Graphics::createMapPosterCasa4Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterCasa4);
}

Sprite* Graphics::createMapPosterCasa5Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterCasa5);
}

Sprite* Graphics::createMapPosterCasa6Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterCasa6);
}

Sprite* Graphics::createMapPosterCasa7Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterCasa7);
}

Sprite* Graphics::createMapPosterCasa8Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterCasa8);
}

Sprite* Graphics::createMapPosterCasa9Sprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterCasa9);
}

Sprite* Graphics::createMapPosterClerigoSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterClerigo);
}

Sprite* Graphics::createMapPosterDruidaSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterDruida);
}

Sprite* Graphics::createMapPosterElGranConsejoSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterElGranConsejo);
}

Sprite* Graphics::createMapPosterElMesonHostigadoSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterElMesonHostigado);
}

Sprite* Graphics::createMapPosterElMesonRioGrandeSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterElMesonRioGrande);
}

Sprite* Graphics::createMapPosterFinanzasSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterFinanzas);
}

Sprite* Graphics::createMapPosterFinanzasGoliathCasaCentralSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterFinanzasGoliathCasaCentral);
}

Sprite* Graphics::createMapPosterFoodSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterFood);
}

Sprite* Graphics::createMapPosterForoSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterForo);
}

Sprite* Graphics::createMapPosterGremioDeTrabajadoresSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterGremioDeTrabajadores);
}

Sprite* Graphics::createMapPosterGuerreroSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterGuerrero);
}

Sprite* Graphics::createMapPosterLadronSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterLadron);
}

Sprite* Graphics::createMapPosterLenadoresSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterLenadores);
}

Sprite* Graphics::createMapPosterMagiaSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterMagia);
}

Sprite* Graphics::createMapPosterMagoSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterMago);
}

Sprite* Graphics::createMapPosterMapCazadorSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterMapCazador);
}

Sprite* Graphics::createMapPosterMineriaSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterMineria);
}

Sprite* Graphics::createMapPosterMuellesNorthSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterMuellesNorth);
}

Sprite* Graphics::createMapPosterNixSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterNix);
}

Sprite* Graphics::createMapPosterPalacioRealSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterPalacioReal);
}

Sprite* Graphics::createMapPosterPaladinSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterPaladin);
}

Sprite* Graphics::createMapPosterPeligroBosqueDeDorkSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterPeligroBosqueDeDork);
}

Sprite* Graphics::createMapPosterPeligroDungeonVerilSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterPeligroDungeonVeril);
}

Sprite* Graphics::createMapPosterPescadoresSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterPescadores);
}

Sprite* Graphics::createMapPosterPirataSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterPirata);
}

Sprite* Graphics::createMapPosterPocionesSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterPociones);
}

Sprite* Graphics::createMapPosterPrisionSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterPrision);
}

Sprite* Graphics::createMapPosterPrisionWestSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterPrisionWest);
}

Sprite* Graphics::createMapPosterPropiedadesSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterPropiedades);
}

Sprite* Graphics::createMapPosterProvisionesSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterProvisiones);
}

Sprite* Graphics::createMapPosterSacerdoteSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterSacerdote);
}

Sprite* Graphics::createMapPosterSastreSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterSastre);
}

Sprite* Graphics::createMapPosterTeatroElJuglarSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterTeatroElJuglar);
}

Sprite* Graphics::createMapPosterTownDisclaimerSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterTownDisclaimer);
}

Sprite* Graphics::createMapPosterTrabajadorSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterTrabajador);
}

Sprite* Graphics::createMapPosterUllathoreNorthNixWestSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterUllathoreNorthNixWest);
}

Sprite* Graphics::createMapPosterUllathorpeSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterUllathorpe);
}

Sprite* Graphics::createMapPosterWelcomeDungeonNewbieSprite()
{
    return Sprite::createWithSpriteFrameName(mapPosterWelcomeDungeonNewbie);
}

Sprite* Graphics::createMapRock01Sprite()
{
    return Sprite::createWithSpriteFrameName(mapRock01);
}

Sprite* Graphics::createMapSpiderWebSprite()
{
    return Sprite::createWithSpriteFrameName(mapSpiderWeb);
}

Sprite* Graphics::createMapStainedGlassSprite()
{
    return Sprite::createWithSpriteFrameName(mapStainedGlass);
}

Sprite* Graphics::createMapStatue01Sprite()
{
    return Sprite::createWithSpriteFrameName(mapStatue01);
}

Sprite* Graphics::createMapStatue02Sprite()
{
    return Sprite::createWithSpriteFrameName(mapStatue02);
}

Sprite* Graphics::createMapStatue03Sprite()
{
    return Sprite::createWithSpriteFrameName(mapStatue03);
}

Sprite* Graphics::createMapStatue04Sprite()
{
    return Sprite::createWithSpriteFrameName(mapStatue04);
}

Sprite* Graphics::createMapStatue05Sprite()
{
    return Sprite::createWithSpriteFrameName(mapStatue05);
}

Sprite* Graphics::createMapStatue06Sprite()
{
    return Sprite::createWithSpriteFrameName(mapStatue06);
}

Sprite* Graphics::createMapStatue07Sprite()
{
    return Sprite::createWithSpriteFrameName(mapStatue07);
}

Sprite* Graphics::createMapStatue08Sprite()
{
    return Sprite::createWithSpriteFrameName(mapStatue08);
}

Sprite* Graphics::createMapStatue09Sprite()
{
    return Sprite::createWithSpriteFrameName(mapStatue09);
}

Sprite* Graphics::createMapStatue10Sprite()
{
    return Sprite::createWithSpriteFrameName(mapStatue10);
}

Sprite* Graphics::createMapStatue11Sprite()
{
    return Sprite::createWithSpriteFrameName(mapStatue11);
}

Sprite* Graphics::createMapStatueBudaSprite()
{
    return Sprite::createWithSpriteFrameName(mapStatueBuda);
}

Sprite* Graphics::createMapStreetLightSprite()
{
    return Sprite::createWithSpriteFrameName(mapStreetLight);
}

Sprite* Graphics::createMapTreeA1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeA1);
}

Sprite* Graphics::createMapTreeA2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeA2);
}

Sprite* Graphics::createMapTreeA3Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeA3);
}

Sprite* Graphics::createMapTreeA4Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeA4);
}

Sprite* Graphics::createMapTreeA5Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeA5);
}

Sprite* Graphics::createMapTreeA6Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeA6);
}

Sprite* Graphics::createMapTreeB1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeB1);
}

Sprite* Graphics::createMapTreeB2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeB2);
}

Sprite* Graphics::createMapTreeC1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeC1);
}

Sprite* Graphics::createMapTreeC2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeC2);
}

Sprite* Graphics::createMapTreeD1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeD1);
}

Sprite* Graphics::createMapTreeD2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeD2);
}

Sprite* Graphics::createMapTreeDeath1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeDeath1);
}

Sprite* Graphics::createMapTreeDeath2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeDeath2);
}

Sprite* Graphics::createMapTreeDeath3Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeDeath3);
}

Sprite* Graphics::createMapTreeDeath4Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeDeath4);
}

Sprite* Graphics::createMapTreeDeathFSprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeDeathF);
}

Sprite* Graphics::createMapTreeDeathGSprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeDeathG);
}

Sprite* Graphics::createMapTreeE1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeE1);
}

Sprite* Graphics::createMapTreeE2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeE2);
}

Sprite* Graphics::createMapTreeF1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeF1);
}

Sprite* Graphics::createMapTreeF2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeF2);
}

Sprite* Graphics::createMapTreeG1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeG1);
}

Sprite* Graphics::createMapTreeG2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeG2);
}

Sprite* Graphics::createMapTreeH1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeH1);
}

Sprite* Graphics::createMapTreeH2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeH2);
}

Sprite* Graphics::createMapTreeI1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeI1);
}

Sprite* Graphics::createMapTreeI2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeI2);
}

Sprite* Graphics::createMapTreeJ1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeJ1);
}

Sprite* Graphics::createMapTreeJ2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeJ2);
}

Sprite* Graphics::createMapTreeK1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeK1);
}

Sprite* Graphics::createMapTreeK2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeK2);
}

Sprite* Graphics::createMapTreeL1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeL1);
}

Sprite* Graphics::createMapTreeL2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeL2);
}

Sprite* Graphics::createMapTreeM1Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeM1);
}

Sprite* Graphics::createMapTreeM2Sprite()
{
    return Sprite::createWithSpriteFrameName(mapTreeM2);
}

Sprite* Graphics::createMapWagonGoldEastSprite()
{
    return Sprite::createWithSpriteFrameName(mapWagonGoldEast);
}

Sprite* Graphics::createMapWagonSilverSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mapWagonSilverSouth);
}

Sprite* Graphics::createMapWagonSilverWestSprite()
{
    return Sprite::createWithSpriteFrameName(mapWagonSilverWest);
}

Sprite* Graphics::createMapWaterDeepSprite()
{
    return Sprite::createWithSpriteFrameName(mapWaterDeep);
}

Sprite* Graphics::createMapWaterLowSprite()
{
    return Sprite::createWithSpriteFrameName(mapWaterLow);
}

Sprite* Graphics::createMapWheelbarrowFrontSprite()
{
    return Sprite::createWithSpriteFrameName(mapWheelbarrowFront);
}

Sprite* Graphics::createMapWheelbarrowSideSprite()
{
    return Sprite::createWithSpriteFrameName(mapWheelbarrowSide);
}

Sprite* Graphics::createMeditationBlue0Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationBlue0);
}

Sprite* Graphics::createMeditationBlue1Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationBlue1);
}

Sprite* Graphics::createMeditationBlue2Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationBlue2);
}

Sprite* Graphics::createMeditationBlue3Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationBlue3);
}

Sprite* Graphics::createMeditationBlue4Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationBlue4);
}

Sprite* Graphics::createMeditationBlue5Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationBlue5);
}

Sprite* Graphics::createMeditationBlue6Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationBlue6);
}

Sprite* Graphics::createMeditationBlue7Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationBlue7);
}

Sprite* Graphics::createMeditationBlue8Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationBlue8);
}

Sprite* Graphics::createMeditationBlue9Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationBlue9);
}

Sprite* Graphics::createMeditationExtreme0Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationExtreme0);
}

Sprite* Graphics::createMeditationExtreme1Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationExtreme1);
}

Sprite* Graphics::createMeditationExtreme2Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationExtreme2);
}

Sprite* Graphics::createMeditationExtreme3Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationExtreme3);
}

Sprite* Graphics::createMeditationExtreme4Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationExtreme4);
}

Sprite* Graphics::createMeditationExtreme5Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationExtreme5);
}

Sprite* Graphics::createMeditationExtreme6Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationExtreme6);
}

Sprite* Graphics::createMeditationExtreme7Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationExtreme7);
}

Sprite* Graphics::createMeditationExtreme8Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationExtreme8);
}

Sprite* Graphics::createMeditationExtreme9Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationExtreme9);
}

Sprite* Graphics::createMeditationNewbie0Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationNewbie0);
}

Sprite* Graphics::createMeditationNewbie1Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationNewbie1);
}

Sprite* Graphics::createMeditationNewbie2Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationNewbie2);
}

Sprite* Graphics::createMeditationNewbie3Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationNewbie3);
}

Sprite* Graphics::createMeditationNewbie4Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationNewbie4);
}

Sprite* Graphics::createMeditationNewbie5Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationNewbie5);
}

Sprite* Graphics::createMeditationNewbie6Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationNewbie6);
}

Sprite* Graphics::createMeditationNewbie7Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationNewbie7);
}

Sprite* Graphics::createMeditationNewbie8Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationNewbie8);
}

Sprite* Graphics::createMeditationNewbie9Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationNewbie9);
}

Sprite* Graphics::createMeditationRed0Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationRed0);
}

Sprite* Graphics::createMeditationRed1Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationRed1);
}

Sprite* Graphics::createMeditationRed2Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationRed2);
}

Sprite* Graphics::createMeditationRed3Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationRed3);
}

Sprite* Graphics::createMeditationRed4Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationRed4);
}

Sprite* Graphics::createMeditationRed5Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationRed5);
}

Sprite* Graphics::createMeditationRed6Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationRed6);
}

Sprite* Graphics::createMeditationRed7Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationRed7);
}

Sprite* Graphics::createMeditationRed8Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationRed8);
}

Sprite* Graphics::createMeditationRed9Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationRed9);
}

Sprite* Graphics::createMeditationYellow0Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationYellow0);
}

Sprite* Graphics::createMeditationYellow1Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationYellow1);
}

Sprite* Graphics::createMeditationYellow2Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationYellow2);
}

Sprite* Graphics::createMeditationYellow3Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationYellow3);
}

Sprite* Graphics::createMeditationYellow4Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationYellow4);
}

Sprite* Graphics::createMeditationYellow5Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationYellow5);
}

Sprite* Graphics::createMeditationYellow6Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationYellow6);
}

Sprite* Graphics::createMeditationYellow7Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationYellow7);
}

Sprite* Graphics::createMeditationYellow8Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationYellow8);
}

Sprite* Graphics::createMeditationYellow9Sprite()
{
    return Sprite::createWithSpriteFrameName(meditationYellow9);
}

Sprite* Graphics::createMiscEyePurpleSprite()
{
    return Sprite::createWithSpriteFrameName(miscEyePurple);
}

Sprite* Graphics::createMobBatEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBatEast1);
}

Sprite* Graphics::createMobBatEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBatEast2);
}

Sprite* Graphics::createMobBatNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBatNorth1);
}

Sprite* Graphics::createMobBatNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBatNorth2);
}

Sprite* Graphics::createMobBatSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBatSouth1);
}

Sprite* Graphics::createMobBatSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBatSouth2);
}

Sprite* Graphics::createMobBatWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBatWest1);
}

Sprite* Graphics::createMobBatWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBatWest2);
}

Sprite* Graphics::createMobBearEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearEast1);
}

Sprite* Graphics::createMobBearEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearEast2);
}

Sprite* Graphics::createMobBearEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearEast3);
}

Sprite* Graphics::createMobBearEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearEast4);
}

Sprite* Graphics::createMobBearEast5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearEast5);
}

Sprite* Graphics::createMobBearEast6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearEast6);
}

Sprite* Graphics::createMobBearEast7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearEast7);
}

Sprite* Graphics::createMobBearNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearNorth1);
}

Sprite* Graphics::createMobBearNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearNorth2);
}

Sprite* Graphics::createMobBearNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearNorth3);
}

Sprite* Graphics::createMobBearNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearNorth4);
}

Sprite* Graphics::createMobBearNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearNorth5);
}

Sprite* Graphics::createMobBearNorth6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearNorth6);
}

Sprite* Graphics::createMobBearNorth7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearNorth7);
}

Sprite* Graphics::createMobBearPolarEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearPolarEast1);
}

Sprite* Graphics::createMobBearPolarEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearPolarEast2);
}

Sprite* Graphics::createMobBearPolarEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearPolarEast3);
}

Sprite* Graphics::createMobBearPolarEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearPolarEast4);
}

Sprite* Graphics::createMobBearPolarNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearPolarNorth1);
}

Sprite* Graphics::createMobBearPolarNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearPolarNorth2);
}

Sprite* Graphics::createMobBearPolarNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearPolarNorth3);
}

Sprite* Graphics::createMobBearPolarNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearPolarNorth4);
}

Sprite* Graphics::createMobBearPolarSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearPolarSouth1);
}

Sprite* Graphics::createMobBearPolarSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearPolarSouth2);
}

Sprite* Graphics::createMobBearPolarSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearPolarSouth3);
}

Sprite* Graphics::createMobBearPolarSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearPolarSouth4);
}

Sprite* Graphics::createMobBearPolarStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(mobBearPolarStandingEast);
}

Sprite* Graphics::createMobBearPolarStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(mobBearPolarStandingNorth);
}

Sprite* Graphics::createMobBearPolarStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mobBearPolarStandingSouth);
}

Sprite* Graphics::createMobBearPolarStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(mobBearPolarStandingWest);
}

Sprite* Graphics::createMobBearPolarWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearPolarWest1);
}

Sprite* Graphics::createMobBearPolarWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearPolarWest2);
}

Sprite* Graphics::createMobBearPolarWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearPolarWest3);
}

Sprite* Graphics::createMobBearPolarWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearPolarWest4);
}

Sprite* Graphics::createMobBearSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearSouth1);
}

Sprite* Graphics::createMobBearSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearSouth2);
}

Sprite* Graphics::createMobBearSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearSouth3);
}

Sprite* Graphics::createMobBearSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearSouth4);
}

Sprite* Graphics::createMobBearSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearSouth5);
}

Sprite* Graphics::createMobBearSouth6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearSouth6);
}

Sprite* Graphics::createMobBearSouth7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearSouth7);
}

Sprite* Graphics::createMobBearStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(mobBearStandingEast);
}

Sprite* Graphics::createMobBearStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(mobBearStandingNorth);
}

Sprite* Graphics::createMobBearStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mobBearStandingSouth);
}

Sprite* Graphics::createMobBearStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(mobBearStandingWest);
}

Sprite* Graphics::createMobBearWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearWest1);
}

Sprite* Graphics::createMobBearWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearWest2);
}

Sprite* Graphics::createMobBearWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearWest3);
}

Sprite* Graphics::createMobBearWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearWest4);
}

Sprite* Graphics::createMobBearWest5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearWest5);
}

Sprite* Graphics::createMobBearWest6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearWest6);
}

Sprite* Graphics::createMobBearWest7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBearWest7);
}

Sprite* Graphics::createMobBeholerEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerEast1);
}

Sprite* Graphics::createMobBeholerEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerEast2);
}

Sprite* Graphics::createMobBeholerEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerEast3);
}

Sprite* Graphics::createMobBeholerEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerEast4);
}

Sprite* Graphics::createMobBeholerEast5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerEast5);
}

Sprite* Graphics::createMobBeholerNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerNorth1);
}

Sprite* Graphics::createMobBeholerNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerNorth2);
}

Sprite* Graphics::createMobBeholerNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerNorth3);
}

Sprite* Graphics::createMobBeholerNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerNorth4);
}

Sprite* Graphics::createMobBeholerNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerNorth5);
}

Sprite* Graphics::createMobBeholerSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerSouth1);
}

Sprite* Graphics::createMobBeholerSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerSouth2);
}

Sprite* Graphics::createMobBeholerSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerSouth3);
}

Sprite* Graphics::createMobBeholerSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerSouth4);
}

Sprite* Graphics::createMobBeholerSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerSouth5);
}

Sprite* Graphics::createMobBeholerStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerStandingEast);
}

Sprite* Graphics::createMobBeholerStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerStandingNorth);
}

Sprite* Graphics::createMobBeholerStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerStandingSouth);
}

Sprite* Graphics::createMobBeholerStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerStandingWest);
}

Sprite* Graphics::createMobBeholerWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerWest1);
}

Sprite* Graphics::createMobBeholerWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerWest2);
}

Sprite* Graphics::createMobBeholerWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerWest3);
}

Sprite* Graphics::createMobBeholerWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerWest4);
}

Sprite* Graphics::createMobBeholerWest5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBeholerWest5);
}

Sprite* Graphics::createMobBirdBlackEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBirdBlackEast1);
}

Sprite* Graphics::createMobBirdBlackEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBirdBlackEast2);
}

Sprite* Graphics::createMobBirdBlackEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBirdBlackEast3);
}

Sprite* Graphics::createMobBirdBlackEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBirdBlackEast4);
}

Sprite* Graphics::createMobBirdBlackEast5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBirdBlackEast5);
}

Sprite* Graphics::createMobBirdBlackNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBirdBlackNorth1);
}

Sprite* Graphics::createMobBirdBlackNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBirdBlackNorth2);
}

Sprite* Graphics::createMobBirdBlackNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBirdBlackNorth3);
}

Sprite* Graphics::createMobBirdBlackNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBirdBlackNorth4);
}

Sprite* Graphics::createMobBirdBlackNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBirdBlackNorth5);
}

Sprite* Graphics::createMobBirdBlackSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBirdBlackSouth1);
}

Sprite* Graphics::createMobBirdBlackSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBirdBlackSouth2);
}

Sprite* Graphics::createMobBirdBlackSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBirdBlackSouth3);
}

Sprite* Graphics::createMobBirdBlackSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBirdBlackSouth4);
}

Sprite* Graphics::createMobBirdBlackSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBirdBlackSouth5);
}

Sprite* Graphics::createMobBirdBlackWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBirdBlackWest1);
}

Sprite* Graphics::createMobBirdBlackWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBirdBlackWest2);
}

Sprite* Graphics::createMobBirdBlackWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBirdBlackWest3);
}

Sprite* Graphics::createMobBirdBlackWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBirdBlackWest4);
}

Sprite* Graphics::createMobBirdBlackWest5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobBirdBlackWest5);
}

Sprite* Graphics::createMobDragonEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonEast1);
}

Sprite* Graphics::createMobDragonEast10Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonEast10);
}

Sprite* Graphics::createMobDragonEast11Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonEast11);
}

Sprite* Graphics::createMobDragonEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonEast2);
}

Sprite* Graphics::createMobDragonEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonEast3);
}

Sprite* Graphics::createMobDragonEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonEast4);
}

Sprite* Graphics::createMobDragonEast5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonEast5);
}

Sprite* Graphics::createMobDragonEast6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonEast6);
}

Sprite* Graphics::createMobDragonEast7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonEast7);
}

Sprite* Graphics::createMobDragonEast8Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonEast8);
}

Sprite* Graphics::createMobDragonEast9Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonEast9);
}

Sprite* Graphics::createMobDragonNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonNorth1);
}

Sprite* Graphics::createMobDragonNorth10Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonNorth10);
}

Sprite* Graphics::createMobDragonNorth11Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonNorth11);
}

Sprite* Graphics::createMobDragonNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonNorth2);
}

Sprite* Graphics::createMobDragonNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonNorth3);
}

Sprite* Graphics::createMobDragonNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonNorth4);
}

Sprite* Graphics::createMobDragonNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonNorth5);
}

Sprite* Graphics::createMobDragonNorth6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonNorth6);
}

Sprite* Graphics::createMobDragonNorth7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonNorth7);
}

Sprite* Graphics::createMobDragonNorth8Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonNorth8);
}

Sprite* Graphics::createMobDragonNorth9Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonNorth9);
}

Sprite* Graphics::createMobDragonSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonSouth1);
}

Sprite* Graphics::createMobDragonSouth10Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonSouth10);
}

Sprite* Graphics::createMobDragonSouth11Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonSouth11);
}

Sprite* Graphics::createMobDragonSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonSouth2);
}

Sprite* Graphics::createMobDragonSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonSouth3);
}

Sprite* Graphics::createMobDragonSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonSouth4);
}

Sprite* Graphics::createMobDragonSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonSouth5);
}

Sprite* Graphics::createMobDragonSouth6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonSouth6);
}

Sprite* Graphics::createMobDragonSouth7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonSouth7);
}

Sprite* Graphics::createMobDragonSouth8Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonSouth8);
}

Sprite* Graphics::createMobDragonSouth9Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonSouth9);
}

Sprite* Graphics::createMobDragonStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonStandingEast);
}

Sprite* Graphics::createMobDragonStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonStandingNorth);
}

Sprite* Graphics::createMobDragonStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonStandingSouth);
}

Sprite* Graphics::createMobDragonStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonStandingWest);
}

Sprite* Graphics::createMobDragonWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonWest1);
}

Sprite* Graphics::createMobDragonWest10Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonWest10);
}

Sprite* Graphics::createMobDragonWest11Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonWest11);
}

Sprite* Graphics::createMobDragonWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonWest2);
}

Sprite* Graphics::createMobDragonWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonWest3);
}

Sprite* Graphics::createMobDragonWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonWest4);
}

Sprite* Graphics::createMobDragonWest5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonWest5);
}

Sprite* Graphics::createMobDragonWest6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonWest6);
}

Sprite* Graphics::createMobDragonWest7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonWest7);
}

Sprite* Graphics::createMobDragonWest8Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonWest8);
}

Sprite* Graphics::createMobDragonWest9Sprite()
{
    return Sprite::createWithSpriteFrameName(mobDragonWest9);
}

Sprite* Graphics::createMobEliEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobEliEast1);
}

Sprite* Graphics::createMobEliEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobEliEast2);
}

Sprite* Graphics::createMobEliNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobEliNorth1);
}

Sprite* Graphics::createMobEliNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobEliNorth2);
}

Sprite* Graphics::createMobEliSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobEliSouth1);
}

Sprite* Graphics::createMobEliSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobEliSouth2);
}

Sprite* Graphics::createMobEliWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobEliWest1);
}

Sprite* Graphics::createMobEliWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobEliWest2);
}

Sprite* Graphics::createMobElyEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobElyEast1);
}

Sprite* Graphics::createMobElyEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobElyEast2);
}

Sprite* Graphics::createMobElyNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobElyNorth1);
}

Sprite* Graphics::createMobElyNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobElyNorth2);
}

Sprite* Graphics::createMobElySouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobElySouth1);
}

Sprite* Graphics::createMobElySouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobElySouth2);
}

Sprite* Graphics::createMobElyWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobElyWest1);
}

Sprite* Graphics::createMobElyWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobElyWest2);
}

Sprite* Graphics::createMobGolemMagmaEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaEast1);
}

Sprite* Graphics::createMobGolemMagmaEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaEast2);
}

Sprite* Graphics::createMobGolemMagmaEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaEast3);
}

Sprite* Graphics::createMobGolemMagmaEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaEast4);
}

Sprite* Graphics::createMobGolemMagmaEast5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaEast5);
}

Sprite* Graphics::createMobGolemMagmaEast6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaEast6);
}

Sprite* Graphics::createMobGolemMagmaEast7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaEast7);
}

Sprite* Graphics::createMobGolemMagmaNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaNorth1);
}

Sprite* Graphics::createMobGolemMagmaNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaNorth2);
}

Sprite* Graphics::createMobGolemMagmaNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaNorth3);
}

Sprite* Graphics::createMobGolemMagmaNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaNorth4);
}

Sprite* Graphics::createMobGolemMagmaNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaNorth5);
}

Sprite* Graphics::createMobGolemMagmaNorth6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaNorth6);
}

Sprite* Graphics::createMobGolemMagmaNorth7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaNorth7);
}

Sprite* Graphics::createMobGolemMagmaSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaSouth1);
}

Sprite* Graphics::createMobGolemMagmaSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaSouth2);
}

Sprite* Graphics::createMobGolemMagmaSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaSouth3);
}

Sprite* Graphics::createMobGolemMagmaSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaSouth4);
}

Sprite* Graphics::createMobGolemMagmaSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaSouth5);
}

Sprite* Graphics::createMobGolemMagmaSouth6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaSouth6);
}

Sprite* Graphics::createMobGolemMagmaSouth7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaSouth7);
}

Sprite* Graphics::createMobGolemMagmaStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaStandingEast);
}

Sprite* Graphics::createMobGolemMagmaStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaStandingNorth);
}

Sprite* Graphics::createMobGolemMagmaStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaStandingSouth);
}

Sprite* Graphics::createMobGolemMagmaStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaStandingWest);
}

Sprite* Graphics::createMobGolemMagmaWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaWest1);
}

Sprite* Graphics::createMobGolemMagmaWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaWest2);
}

Sprite* Graphics::createMobGolemMagmaWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaWest3);
}

Sprite* Graphics::createMobGolemMagmaWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaWest4);
}

Sprite* Graphics::createMobGolemMagmaWest5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaWest5);
}

Sprite* Graphics::createMobGolemMagmaWest6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaWest6);
}

Sprite* Graphics::createMobGolemMagmaWest7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemMagmaWest7);
}

Sprite* Graphics::createMobGolemStoneEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneEast1);
}

Sprite* Graphics::createMobGolemStoneEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneEast2);
}

Sprite* Graphics::createMobGolemStoneEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneEast3);
}

Sprite* Graphics::createMobGolemStoneEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneEast4);
}

Sprite* Graphics::createMobGolemStoneEast5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneEast5);
}

Sprite* Graphics::createMobGolemStoneEast6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneEast6);
}

Sprite* Graphics::createMobGolemStoneEast7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneEast7);
}

Sprite* Graphics::createMobGolemStoneNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneNorth1);
}

Sprite* Graphics::createMobGolemStoneNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneNorth2);
}

Sprite* Graphics::createMobGolemStoneNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneNorth3);
}

Sprite* Graphics::createMobGolemStoneNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneNorth4);
}

Sprite* Graphics::createMobGolemStoneNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneNorth5);
}

Sprite* Graphics::createMobGolemStoneNorth6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneNorth6);
}

Sprite* Graphics::createMobGolemStoneNorth7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneNorth7);
}

Sprite* Graphics::createMobGolemStoneSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneSouth1);
}

Sprite* Graphics::createMobGolemStoneSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneSouth2);
}

Sprite* Graphics::createMobGolemStoneSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneSouth3);
}

Sprite* Graphics::createMobGolemStoneSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneSouth4);
}

Sprite* Graphics::createMobGolemStoneSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneSouth5);
}

Sprite* Graphics::createMobGolemStoneSouth6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneSouth6);
}

Sprite* Graphics::createMobGolemStoneSouth7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneSouth7);
}

Sprite* Graphics::createMobGolemStoneStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneStandingEast);
}

Sprite* Graphics::createMobGolemStoneStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneStandingNorth);
}

Sprite* Graphics::createMobGolemStoneStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneStandingSouth);
}

Sprite* Graphics::createMobGolemStoneStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneStandingWest);
}

Sprite* Graphics::createMobGolemStoneWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneWest1);
}

Sprite* Graphics::createMobGolemStoneWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneWest2);
}

Sprite* Graphics::createMobGolemStoneWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneWest3);
}

Sprite* Graphics::createMobGolemStoneWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneWest4);
}

Sprite* Graphics::createMobGolemStoneWest5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneWest5);
}

Sprite* Graphics::createMobGolemStoneWest6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneWest6);
}

Sprite* Graphics::createMobGolemStoneWest7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobGolemStoneWest7);
}

Sprite* Graphics::createMobLeviathanEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLeviathanEast1);
}

Sprite* Graphics::createMobLeviathanEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLeviathanEast2);
}

Sprite* Graphics::createMobLeviathanEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLeviathanEast3);
}

Sprite* Graphics::createMobLeviathanEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLeviathanEast4);
}

Sprite* Graphics::createMobLeviathanNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLeviathanNorth1);
}

Sprite* Graphics::createMobLeviathanNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLeviathanNorth2);
}

Sprite* Graphics::createMobLeviathanNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLeviathanNorth3);
}

Sprite* Graphics::createMobLeviathanNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLeviathanNorth4);
}

Sprite* Graphics::createMobLeviathanSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLeviathanSouth1);
}

Sprite* Graphics::createMobLeviathanSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLeviathanSouth2);
}

Sprite* Graphics::createMobLeviathanSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLeviathanSouth3);
}

Sprite* Graphics::createMobLeviathanSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLeviathanSouth4);
}

Sprite* Graphics::createMobLeviathanStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(mobLeviathanStandingEast);
}

Sprite* Graphics::createMobLeviathanStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(mobLeviathanStandingNorth);
}

Sprite* Graphics::createMobLeviathanStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mobLeviathanStandingSouth);
}

Sprite* Graphics::createMobLeviathanStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(mobLeviathanStandingWest);
}

Sprite* Graphics::createMobLeviathanWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLeviathanWest1);
}

Sprite* Graphics::createMobLeviathanWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLeviathanWest2);
}

Sprite* Graphics::createMobLeviathanWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLeviathanWest3);
}

Sprite* Graphics::createMobLeviathanWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLeviathanWest4);
}

Sprite* Graphics::createMobLicheEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheEast1);
}

Sprite* Graphics::createMobLicheEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheEast2);
}

Sprite* Graphics::createMobLicheEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheEast3);
}

Sprite* Graphics::createMobLicheEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheEast4);
}

Sprite* Graphics::createMobLicheEast5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheEast5);
}

Sprite* Graphics::createMobLicheEast6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheEast6);
}

Sprite* Graphics::createMobLicheEast7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheEast7);
}

Sprite* Graphics::createMobLicheNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheNorth1);
}

Sprite* Graphics::createMobLicheNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheNorth2);
}

Sprite* Graphics::createMobLicheNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheNorth3);
}

Sprite* Graphics::createMobLicheNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheNorth4);
}

Sprite* Graphics::createMobLicheNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheNorth5);
}

Sprite* Graphics::createMobLicheNorth6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheNorth6);
}

Sprite* Graphics::createMobLicheNorth7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheNorth7);
}

Sprite* Graphics::createMobLicheSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheSouth1);
}

Sprite* Graphics::createMobLicheSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheSouth2);
}

Sprite* Graphics::createMobLicheSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheSouth3);
}

Sprite* Graphics::createMobLicheSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheSouth4);
}

Sprite* Graphics::createMobLicheSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheSouth5);
}

Sprite* Graphics::createMobLicheSouth6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheSouth6);
}

Sprite* Graphics::createMobLicheSouth7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheSouth7);
}

Sprite* Graphics::createMobLicheStantdingEastSprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheStantdingEast);
}

Sprite* Graphics::createMobLicheStantdingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheStantdingNorth);
}

Sprite* Graphics::createMobLicheStantdingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheStantdingSouth);
}

Sprite* Graphics::createMobLicheStantdingWestSprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheStantdingWest);
}

Sprite* Graphics::createMobLicheWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheWest1);
}

Sprite* Graphics::createMobLicheWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheWest2);
}

Sprite* Graphics::createMobLicheWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheWest3);
}

Sprite* Graphics::createMobLicheWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheWest4);
}

Sprite* Graphics::createMobLicheWest5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheWest5);
}

Sprite* Graphics::createMobLicheWest6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheWest6);
}

Sprite* Graphics::createMobLicheWest7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLicheWest7);
}

Sprite* Graphics::createMobLineEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineEast1);
}

Sprite* Graphics::createMobLineEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineEast2);
}

Sprite* Graphics::createMobLineEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineEast3);
}

Sprite* Graphics::createMobLineEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineEast4);
}

Sprite* Graphics::createMobLineEast5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineEast5);
}

Sprite* Graphics::createMobLineEast6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineEast6);
}

Sprite* Graphics::createMobLineNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineNorth1);
}

Sprite* Graphics::createMobLineNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineNorth2);
}

Sprite* Graphics::createMobLineNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineNorth3);
}

Sprite* Graphics::createMobLineNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineNorth4);
}

Sprite* Graphics::createMobLineNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineNorth5);
}

Sprite* Graphics::createMobLineNorth6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineNorth6);
}

Sprite* Graphics::createMobLineSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineSouth1);
}

Sprite* Graphics::createMobLineSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineSouth2);
}

Sprite* Graphics::createMobLineSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineSouth3);
}

Sprite* Graphics::createMobLineSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineSouth4);
}

Sprite* Graphics::createMobLineSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineSouth5);
}

Sprite* Graphics::createMobLineSouth6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineSouth6);
}

Sprite* Graphics::createMobLineWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineWest1);
}

Sprite* Graphics::createMobLineWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineWest2);
}

Sprite* Graphics::createMobLineWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineWest3);
}

Sprite* Graphics::createMobLineWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineWest4);
}

Sprite* Graphics::createMobLineWest5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineWest5);
}

Sprite* Graphics::createMobLineWest6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobLineWest6);
}

Sprite* Graphics::createMobMermaidEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobMermaidEast1);
}

Sprite* Graphics::createMobMermaidEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobMermaidEast2);
}

Sprite* Graphics::createMobMermaidEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobMermaidEast3);
}

Sprite* Graphics::createMobMermaidNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobMermaidNorth1);
}

Sprite* Graphics::createMobMermaidNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobMermaidNorth2);
}

Sprite* Graphics::createMobMermaidNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobMermaidNorth3);
}

Sprite* Graphics::createMobMermaidSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobMermaidSouth1);
}

Sprite* Graphics::createMobMermaidSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobMermaidSouth2);
}

Sprite* Graphics::createMobMermaidSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobMermaidSouth3);
}

Sprite* Graphics::createMobMermaidStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(mobMermaidStandingEast);
}

Sprite* Graphics::createMobMermaidStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(mobMermaidStandingNorth);
}

Sprite* Graphics::createMobMermaidStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mobMermaidStandingSouth);
}

Sprite* Graphics::createMobMermaidStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(mobMermaidStandingWest);
}

Sprite* Graphics::createMobMermaidWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobMermaidWest1);
}

Sprite* Graphics::createMobMermaidWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobMermaidWest2);
}

Sprite* Graphics::createMobMermaidWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobMermaidWest3);
}

Sprite* Graphics::createMobOctopusEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobOctopusEast1);
}

Sprite* Graphics::createMobOctopusEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobOctopusEast2);
}

Sprite* Graphics::createMobOctopusEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobOctopusEast3);
}

Sprite* Graphics::createMobOctopusNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobOctopusNorth1);
}

Sprite* Graphics::createMobOctopusNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobOctopusNorth2);
}

Sprite* Graphics::createMobOctopusNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobOctopusNorth3);
}

Sprite* Graphics::createMobOctopusSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobOctopusSouth1);
}

Sprite* Graphics::createMobOctopusSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobOctopusSouth2);
}

Sprite* Graphics::createMobOctopusSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobOctopusSouth3);
}

Sprite* Graphics::createMobOctopusStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(mobOctopusStandingEast);
}

Sprite* Graphics::createMobOctopusStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(mobOctopusStandingNorth);
}

Sprite* Graphics::createMobOctopusStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mobOctopusStandingSouth);
}

Sprite* Graphics::createMobOctopusStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(mobOctopusStandingWest);
}

Sprite* Graphics::createMobOctopusWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobOctopusWest1);
}

Sprite* Graphics::createMobOctopusWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobOctopusWest2);
}

Sprite* Graphics::createMobOctopusWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobOctopusWest3);
}

Sprite* Graphics::createMobParrotEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobParrotEast1);
}

Sprite* Graphics::createMobParrotEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobParrotEast2);
}

Sprite* Graphics::createMobParrotNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobParrotNorth1);
}

Sprite* Graphics::createMobParrotNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobParrotNorth2);
}

Sprite* Graphics::createMobParrotSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobParrotSouth1);
}

Sprite* Graphics::createMobParrotSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobParrotSouth2);
}

Sprite* Graphics::createMobParrotWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobParrotWest1);
}

Sprite* Graphics::createMobParrotWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobParrotWest2);
}

Sprite* Graphics::createMobPiranhaEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobPiranhaEast1);
}

Sprite* Graphics::createMobPiranhaEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobPiranhaEast2);
}

Sprite* Graphics::createMobPiranhaNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobPiranhaNorth1);
}

Sprite* Graphics::createMobPiranhaNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobPiranhaNorth2);
}

Sprite* Graphics::createMobPiranhaSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobPiranhaSouth1);
}

Sprite* Graphics::createMobPiranhaSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobPiranhaSouth2);
}

Sprite* Graphics::createMobPiranhaStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(mobPiranhaStandingEast);
}

Sprite* Graphics::createMobPiranhaStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(mobPiranhaStandingNorth);
}

Sprite* Graphics::createMobPiranhaStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mobPiranhaStandingSouth);
}

Sprite* Graphics::createMobPiranhaStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(mobPiranhaStandingWest);
}

Sprite* Graphics::createMobPiranhaWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobPiranhaWest1);
}

Sprite* Graphics::createMobPiranhaWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobPiranhaWest2);
}

Sprite* Graphics::createMobRabbitEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRabbitEast1);
}

Sprite* Graphics::createMobRabbitEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRabbitEast2);
}

Sprite* Graphics::createMobRabbitNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRabbitNorth1);
}

Sprite* Graphics::createMobRabbitNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRabbitNorth2);
}

Sprite* Graphics::createMobRabbitSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRabbitSouth1);
}

Sprite* Graphics::createMobRabbitSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRabbitSouth2);
}

Sprite* Graphics::createMobRabbitStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(mobRabbitStandingEast);
}

Sprite* Graphics::createMobRabbitStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(mobRabbitStandingNorth);
}

Sprite* Graphics::createMobRabbitStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mobRabbitStandingSouth);
}

Sprite* Graphics::createMobRabbitStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(mobRabbitStandingWest);
}

Sprite* Graphics::createMobRabbitWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRabbitWest1);
}

Sprite* Graphics::createMobRabbitWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRabbitWest2);
}

Sprite* Graphics::createMobRavenBlackEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRavenBlackEast1);
}

Sprite* Graphics::createMobRavenBlackEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRavenBlackEast2);
}

Sprite* Graphics::createMobRavenBlackNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRavenBlackNorth1);
}

Sprite* Graphics::createMobRavenBlackNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRavenBlackNorth2);
}

Sprite* Graphics::createMobRavenBlackSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRavenBlackSouth1);
}

Sprite* Graphics::createMobRavenBlackSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRavenBlackSouth2);
}

Sprite* Graphics::createMobRavenBlackWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRavenBlackWest1);
}

Sprite* Graphics::createMobRavenBlackWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRavenBlackWest2);
}

Sprite* Graphics::createMobRavenWhiteEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRavenWhiteEast1);
}

Sprite* Graphics::createMobRavenWhiteEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRavenWhiteEast2);
}

Sprite* Graphics::createMobRavenWhiteNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRavenWhiteNorth1);
}

Sprite* Graphics::createMobRavenWhiteNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRavenWhiteNorth2);
}

Sprite* Graphics::createMobRavenWhiteSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRavenWhiteSouth1);
}

Sprite* Graphics::createMobRavenWhiteSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRavenWhiteSouth2);
}

Sprite* Graphics::createMobRavenWhiteWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRavenWhiteWest1);
}

Sprite* Graphics::createMobRavenWhiteWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobRavenWhiteWest2);
}

Sprite* Graphics::createMobSnakeDoubleHeadGreenEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeDoubleHeadGreenEast1);
}

Sprite* Graphics::createMobSnakeDoubleHeadGreenEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeDoubleHeadGreenEast2);
}

Sprite* Graphics::createMobSnakeDoubleHeadGreenNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeDoubleHeadGreenNorth1);
}

Sprite* Graphics::createMobSnakeDoubleHeadGreenNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeDoubleHeadGreenNorth2);
}

Sprite* Graphics::createMobSnakeDoubleHeadGreenSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeDoubleHeadGreenSouth1);
}

Sprite* Graphics::createMobSnakeDoubleHeadGreenSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeDoubleHeadGreenSouth2);
}

Sprite* Graphics::createMobSnakeDoubleHeadGreenStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeDoubleHeadGreenStandingEast);
}

Sprite* Graphics::createMobSnakeDoubleHeadGreenStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeDoubleHeadGreenStandingNorth);
}

Sprite* Graphics::createMobSnakeDoubleHeadGreenStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeDoubleHeadGreenStandingSouth);
}

Sprite* Graphics::createMobSnakeDoubleHeadGreenStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeDoubleHeadGreenStandingWest);
}

Sprite* Graphics::createMobSnakeDoubleHeadGreenWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeDoubleHeadGreenWest1);
}

Sprite* Graphics::createMobSnakeDoubleHeadGreenWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeDoubleHeadGreenWest2);
}

Sprite* Graphics::createMobSnakeGreenEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeGreenEast1);
}

Sprite* Graphics::createMobSnakeGreenEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeGreenEast2);
}

Sprite* Graphics::createMobSnakeGreenNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeGreenNorth1);
}

Sprite* Graphics::createMobSnakeGreenNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeGreenNorth2);
}

Sprite* Graphics::createMobSnakeGreenSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeGreenSouth1);
}

Sprite* Graphics::createMobSnakeGreenSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeGreenSouth2);
}

Sprite* Graphics::createMobSnakeGreenStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeGreenStandingEast);
}

Sprite* Graphics::createMobSnakeGreenStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeGreenStandingNorth);
}

Sprite* Graphics::createMobSnakeGreenStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeGreenStandingSouth);
}

Sprite* Graphics::createMobSnakeGreenStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeGreenStandingWest);
}

Sprite* Graphics::createMobSnakeGreenWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeGreenWest1);
}

Sprite* Graphics::createMobSnakeGreenWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeGreenWest2);
}

Sprite* Graphics::createMobSnakeRedEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeRedEast1);
}

Sprite* Graphics::createMobSnakeRedEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeRedEast2);
}

Sprite* Graphics::createMobSnakeRedNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeRedNorth1);
}

Sprite* Graphics::createMobSnakeRedNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeRedNorth2);
}

Sprite* Graphics::createMobSnakeRedSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeRedSouth1);
}

Sprite* Graphics::createMobSnakeRedSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeRedSouth2);
}

Sprite* Graphics::createMobSnakeRedStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeRedStandingEast);
}

Sprite* Graphics::createMobSnakeRedStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeRedStandingNorth);
}

Sprite* Graphics::createMobSnakeRedStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeRedStandingSouth);
}

Sprite* Graphics::createMobSnakeRedStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeRedStandingWest);
}

Sprite* Graphics::createMobSnakeRedWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeRedWest1);
}

Sprite* Graphics::createMobSnakeRedWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSnakeRedWest2);
}

Sprite* Graphics::createMobSpiderBrownEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderBrownEast1);
}

Sprite* Graphics::createMobSpiderBrownEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderBrownEast2);
}

Sprite* Graphics::createMobSpiderBrownEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderBrownEast3);
}

Sprite* Graphics::createMobSpiderBrownNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderBrownNorth1);
}

Sprite* Graphics::createMobSpiderBrownNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderBrownNorth2);
}

Sprite* Graphics::createMobSpiderBrownNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderBrownNorth3);
}

Sprite* Graphics::createMobSpiderBrownSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderBrownSouth1);
}

Sprite* Graphics::createMobSpiderBrownSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderBrownSouth2);
}

Sprite* Graphics::createMobSpiderBrownSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderBrownSouth3);
}

Sprite* Graphics::createMobSpiderBrownStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderBrownStandingEast);
}

Sprite* Graphics::createMobSpiderBrownStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderBrownStandingNorth);
}

Sprite* Graphics::createMobSpiderBrownStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderBrownStandingSouth);
}

Sprite* Graphics::createMobSpiderBrownStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderBrownStandingWest);
}

Sprite* Graphics::createMobSpiderBrownWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderBrownWest1);
}

Sprite* Graphics::createMobSpiderBrownWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderBrownWest2);
}

Sprite* Graphics::createMobSpiderBrownWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderBrownWest3);
}

Sprite* Graphics::createMobSpiderNormalEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderNormalEast1);
}

Sprite* Graphics::createMobSpiderNormalEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderNormalEast2);
}

Sprite* Graphics::createMobSpiderNormalEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderNormalEast3);
}

Sprite* Graphics::createMobSpiderNormalNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderNormalNorth1);
}

Sprite* Graphics::createMobSpiderNormalNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderNormalNorth2);
}

Sprite* Graphics::createMobSpiderNormalNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderNormalNorth3);
}

Sprite* Graphics::createMobSpiderNormalSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderNormalSouth1);
}

Sprite* Graphics::createMobSpiderNormalSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderNormalSouth2);
}

Sprite* Graphics::createMobSpiderNormalSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderNormalSouth3);
}

Sprite* Graphics::createMobSpiderNormalStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderNormalStandingEast);
}

Sprite* Graphics::createMobSpiderNormalStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderNormalStandingNorth);
}

Sprite* Graphics::createMobSpiderNormalStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderNormalStandingSouth);
}

Sprite* Graphics::createMobSpiderNormalStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderNormalStandingWest);
}

Sprite* Graphics::createMobSpiderNormalWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderNormalWest1);
}

Sprite* Graphics::createMobSpiderNormalWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderNormalWest2);
}

Sprite* Graphics::createMobSpiderNormalWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobSpiderNormalWest3);
}

Sprite* Graphics::createMobTigerEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTigerEast1);
}

Sprite* Graphics::createMobTigerEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTigerEast2);
}

Sprite* Graphics::createMobTigerEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTigerEast3);
}

Sprite* Graphics::createMobTigerNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTigerNorth1);
}

Sprite* Graphics::createMobTigerNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTigerNorth2);
}

Sprite* Graphics::createMobTigerNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTigerNorth3);
}

Sprite* Graphics::createMobTigerSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTigerSouth1);
}

Sprite* Graphics::createMobTigerSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTigerSouth2);
}

Sprite* Graphics::createMobTigerSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTigerSouth3);
}

Sprite* Graphics::createMobTigerStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(mobTigerStandingEast);
}

Sprite* Graphics::createMobTigerStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(mobTigerStandingNorth);
}

Sprite* Graphics::createMobTigerStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mobTigerStandingSouth);
}

Sprite* Graphics::createMobTigerStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(mobTigerStandingWest);
}

Sprite* Graphics::createMobTigerWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTigerWest1);
}

Sprite* Graphics::createMobTigerWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTigerWest2);
}

Sprite* Graphics::createMobTigerWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTigerWest3);
}

Sprite* Graphics::createMobTurtleEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleEast1);
}

Sprite* Graphics::createMobTurtleEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleEast2);
}

Sprite* Graphics::createMobTurtleEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleEast3);
}

Sprite* Graphics::createMobTurtleEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleEast4);
}

Sprite* Graphics::createMobTurtleEast5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleEast5);
}

Sprite* Graphics::createMobTurtleNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleNorth1);
}

Sprite* Graphics::createMobTurtleNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleNorth2);
}

Sprite* Graphics::createMobTurtleNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleNorth3);
}

Sprite* Graphics::createMobTurtleNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleNorth4);
}

Sprite* Graphics::createMobTurtleNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleNorth5);
}

Sprite* Graphics::createMobTurtleSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleSouth1);
}

Sprite* Graphics::createMobTurtleSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleSouth2);
}

Sprite* Graphics::createMobTurtleSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleSouth3);
}

Sprite* Graphics::createMobTurtleSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleSouth4);
}

Sprite* Graphics::createMobTurtleSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleSouth5);
}

Sprite* Graphics::createMobTurtleStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleStandingEast);
}

Sprite* Graphics::createMobTurtleStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleStandingNorth);
}

Sprite* Graphics::createMobTurtleStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleStandingSouth);
}

Sprite* Graphics::createMobTurtleStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleStandingWest);
}

Sprite* Graphics::createMobTurtleWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleWest1);
}

Sprite* Graphics::createMobTurtleWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleWest2);
}

Sprite* Graphics::createMobTurtleWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleWest3);
}

Sprite* Graphics::createMobTurtleWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleWest4);
}

Sprite* Graphics::createMobTurtleWest5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobTurtleWest5);
}

Sprite* Graphics::createMobWildPigEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigEast1);
}

Sprite* Graphics::createMobWildPigEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigEast2);
}

Sprite* Graphics::createMobWildPigEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigEast3);
}

Sprite* Graphics::createMobWildPigEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigEast4);
}

Sprite* Graphics::createMobWildPigEast5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigEast5);
}

Sprite* Graphics::createMobWildPigEast6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigEast6);
}

Sprite* Graphics::createMobWildPigEast7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigEast7);
}

Sprite* Graphics::createMobWildPigNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigNorth1);
}

Sprite* Graphics::createMobWildPigNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigNorth2);
}

Sprite* Graphics::createMobWildPigNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigNorth3);
}

Sprite* Graphics::createMobWildPigNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigNorth4);
}

Sprite* Graphics::createMobWildPigNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigNorth5);
}

Sprite* Graphics::createMobWildPigNorth6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigNorth6);
}

Sprite* Graphics::createMobWildPigNorth7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigNorth7);
}

Sprite* Graphics::createMobWildPigSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigSouth1);
}

Sprite* Graphics::createMobWildPigSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigSouth2);
}

Sprite* Graphics::createMobWildPigSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigSouth3);
}

Sprite* Graphics::createMobWildPigSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigSouth4);
}

Sprite* Graphics::createMobWildPigSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigSouth5);
}

Sprite* Graphics::createMobWildPigSouth6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigSouth6);
}

Sprite* Graphics::createMobWildPigSouth7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigSouth7);
}

Sprite* Graphics::createMobWildPigStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigStandingEast);
}

Sprite* Graphics::createMobWildPigStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigStandingNorth);
}

Sprite* Graphics::createMobWildPigStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigStandingSouth);
}

Sprite* Graphics::createMobWildPigStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigStandingWest);
}

Sprite* Graphics::createMobWildPigWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigWest1);
}

Sprite* Graphics::createMobWildPigWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigWest2);
}

Sprite* Graphics::createMobWildPigWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigWest3);
}

Sprite* Graphics::createMobWildPigWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigWest4);
}

Sprite* Graphics::createMobWildPigWest5Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigWest5);
}

Sprite* Graphics::createMobWildPigWest6Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigWest6);
}

Sprite* Graphics::createMobWildPigWest7Sprite()
{
    return Sprite::createWithSpriteFrameName(mobWildPigWest7);
}

Sprite* Graphics::createNPCBankEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankEast1);
}

Sprite* Graphics::createNPCBankEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankEast2);
}

Sprite* Graphics::createNPCBankEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankEast3);
}

Sprite* Graphics::createNPCBankEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankEast4);
}

Sprite* Graphics::createNPCBankEast5Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankEast5);
}

Sprite* Graphics::createNPCBankNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankNorth1);
}

Sprite* Graphics::createNPCBankNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankNorth2);
}

Sprite* Graphics::createNPCBankNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankNorth3);
}

Sprite* Graphics::createNPCBankNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankNorth4);
}

Sprite* Graphics::createNPCBankNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankNorth5);
}

Sprite* Graphics::createNPCBankSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankSouth1);
}

Sprite* Graphics::createNPCBankSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankSouth2);
}

Sprite* Graphics::createNPCBankSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankSouth3);
}

Sprite* Graphics::createNPCBankSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankSouth4);
}

Sprite* Graphics::createNPCBankSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankSouth5);
}

Sprite* Graphics::createNPCBankStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankStandingEast);
}

Sprite* Graphics::createNPCBankStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankStandingNorth);
}

Sprite* Graphics::createNPCBankStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankStandingSouth);
}

Sprite* Graphics::createNPCBankStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankStandingWest);
}

Sprite* Graphics::createNPCBankWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankWest1);
}

Sprite* Graphics::createNPCBankWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankWest2);
}

Sprite* Graphics::createNPCBankWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankWest3);
}

Sprite* Graphics::createNPCBankWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankWest4);
}

Sprite* Graphics::createNPCBankWest5Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCBankWest5);
}

Sprite* Graphics::createNPCClothesEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCClothesEast1);
}

Sprite* Graphics::createNPCClothesEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCClothesEast2);
}

Sprite* Graphics::createNPCClothesNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCClothesNorth1);
}

Sprite* Graphics::createNPCClothesNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCClothesNorth2);
}

Sprite* Graphics::createNPCClothesSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCClothesSouth1);
}

Sprite* Graphics::createNPCClothesSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCClothesSouth2);
}

Sprite* Graphics::createNPCClothesStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(nPCClothesStandingEast);
}

Sprite* Graphics::createNPCClothesStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(nPCClothesStandingNorth);
}

Sprite* Graphics::createNPCClothesStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(nPCClothesStandingSouth);
}

Sprite* Graphics::createNPCClothesStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(nPCClothesStandingWest);
}

Sprite* Graphics::createNPCClothesWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCClothesWest1);
}

Sprite* Graphics::createNPCClothesWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCClothesWest2);
}

Sprite* Graphics::createNPCFoodAndDrinksEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksEast1);
}

Sprite* Graphics::createNPCFoodAndDrinksEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksEast2);
}

Sprite* Graphics::createNPCFoodAndDrinksEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksEast3);
}

Sprite* Graphics::createNPCFoodAndDrinksEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksEast4);
}

Sprite* Graphics::createNPCFoodAndDrinksEast5Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksEast5);
}

Sprite* Graphics::createNPCFoodAndDrinksNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksNorth1);
}

Sprite* Graphics::createNPCFoodAndDrinksNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksNorth2);
}

Sprite* Graphics::createNPCFoodAndDrinksNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksNorth3);
}

Sprite* Graphics::createNPCFoodAndDrinksNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksNorth4);
}

Sprite* Graphics::createNPCFoodAndDrinksNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksNorth5);
}

Sprite* Graphics::createNPCFoodAndDrinksSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksSouth1);
}

Sprite* Graphics::createNPCFoodAndDrinksSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksSouth2);
}

Sprite* Graphics::createNPCFoodAndDrinksSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksSouth3);
}

Sprite* Graphics::createNPCFoodAndDrinksSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksSouth4);
}

Sprite* Graphics::createNPCFoodAndDrinksSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksSouth5);
}

Sprite* Graphics::createNPCFoodAndDrinksStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksStandingEast);
}

Sprite* Graphics::createNPCFoodAndDrinksStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksStandingNorth);
}

Sprite* Graphics::createNPCFoodAndDrinksStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksStandingSouth);
}

Sprite* Graphics::createNPCFoodAndDrinksStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksStandingWest);
}

Sprite* Graphics::createNPCFoodAndDrinksWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksWest1);
}

Sprite* Graphics::createNPCFoodAndDrinksWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksWest2);
}

Sprite* Graphics::createNPCFoodAndDrinksWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksWest3);
}

Sprite* Graphics::createNPCFoodAndDrinksWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksWest4);
}

Sprite* Graphics::createNPCFoodAndDrinksWest5Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCFoodAndDrinksWest5);
}

Sprite* Graphics::createNPCHomeLessAEastSprite()
{
    return Sprite::createWithSpriteFrameName(nPCHomeLessAEast);
}

Sprite* Graphics::createNPCHomeLessASouthSprite()
{
    return Sprite::createWithSpriteFrameName(nPCHomeLessASouth);
}

Sprite* Graphics::createNPCHomeLessAWestSprite()
{
    return Sprite::createWithSpriteFrameName(nPCHomeLessAWest);
}

Sprite* Graphics::createNPCHomeLessBEastSprite()
{
    return Sprite::createWithSpriteFrameName(nPCHomeLessBEast);
}

Sprite* Graphics::createNPCHomeLessBSouthSprite()
{
    return Sprite::createWithSpriteFrameName(nPCHomeLessBSouth);
}

Sprite* Graphics::createNPCHomeLessBWestSprite()
{
    return Sprite::createWithSpriteFrameName(nPCHomeLessBWest);
}

Sprite* Graphics::createNPCHomeLessCEastSprite()
{
    return Sprite::createWithSpriteFrameName(nPCHomeLessCEast);
}

Sprite* Graphics::createNPCHomeLessCSouthSprite()
{
    return Sprite::createWithSpriteFrameName(nPCHomeLessCSouth);
}

Sprite* Graphics::createNPCHomeLessCWestSprite()
{
    return Sprite::createWithSpriteFrameName(nPCHomeLessCWest);
}

Sprite* Graphics::createNPCHomeLessDEastSprite()
{
    return Sprite::createWithSpriteFrameName(nPCHomeLessDEast);
}

Sprite* Graphics::createNPCHomeLessDSouthSprite()
{
    return Sprite::createWithSpriteFrameName(nPCHomeLessDSouth);
}

Sprite* Graphics::createNPCPotionsEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCPotionsEast1);
}

Sprite* Graphics::createNPCPotionsEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCPotionsEast2);
}

Sprite* Graphics::createNPCPotionsNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCPotionsNorth1);
}

Sprite* Graphics::createNPCPotionsNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCPotionsNorth2);
}

Sprite* Graphics::createNPCPotionsSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCPotionsSouth1);
}

Sprite* Graphics::createNPCPotionsSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCPotionsSouth2);
}

Sprite* Graphics::createNPCPotionsStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(nPCPotionsStandingEast);
}

Sprite* Graphics::createNPCPotionsStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(nPCPotionsStandingNorth);
}

Sprite* Graphics::createNPCPotionsStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(nPCPotionsStandingSouth);
}

Sprite* Graphics::createNPCPotionsStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(nPCPotionsStandingWest);
}

Sprite* Graphics::createNPCPotionsWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCPotionsWest1);
}

Sprite* Graphics::createNPCPotionsWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCPotionsWest2);
}

Sprite* Graphics::createNPCStreetArtistA0Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCStreetArtistA0);
}

Sprite* Graphics::createNPCStreetArtistA1Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCStreetArtistA1);
}

Sprite* Graphics::createNPCStreetArtistA2Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCStreetArtistA2);
}

Sprite* Graphics::createNPCStreetArtistB0Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCStreetArtistB0);
}

Sprite* Graphics::createNPCStreetArtistB1Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCStreetArtistB1);
}

Sprite* Graphics::createNPCStreetArtistB2Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCStreetArtistB2);
}

Sprite* Graphics::createNPCStreetArtistC0Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCStreetArtistC0);
}

Sprite* Graphics::createNPCStreetArtistC1Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCStreetArtistC1);
}

Sprite* Graphics::createNPCStreetArtistC2Sprite()
{
    return Sprite::createWithSpriteFrameName(nPCStreetArtistC2);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleEast01Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleEast01);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleEast02Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleEast02);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleEast03Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleEast03);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleEast04Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleEast04);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleNorth01Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleNorth01);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleNorth02Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleNorth02);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleNorth03Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleNorth03);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleNorth04Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleNorth04);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleNorth05Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleNorth05);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleSouth01Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleSouth01);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleSouth02Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleSouth02);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleSouth03Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleSouth03);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleSouth04Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleSouth04);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleSouth05Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleSouth05);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleStandingEast);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleStandingNorth);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleStandingSouth);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleStandingWest);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleWest01Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleWest01);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleWest02Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleWest02);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleWest03Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleWest03);
}

Sprite* Graphics::createPlayerBodyDarkElfFemaleWest04Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfFemaleWest04);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleEast1);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleEast2);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleEast3);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleEast4);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleNorth1);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleNorth2);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleNorth3);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleNorth4);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleNorth5);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleSouth1);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleSouth2);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleSouth3);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleSouth4);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleSouth5);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleStandingEast);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleStandingNorth);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleStandingSouth);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleStandingWest);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleWest1);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleWest2);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleWest3);
}

Sprite* Graphics::createPlayerBodyDarkElfMaleWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDarkElfMaleWest4);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleEast1);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleEast2);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleEast3);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleEast4);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleNorth1);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleNorth2);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleNorth3);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleNorth4);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleNorth5);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleSouth1);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleSouth2);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleSouth3);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleSouth4);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleSouth5);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleStandingEast);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleStandingNorth);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleStandingSouth);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleStandingWest);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleWest1);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleWest2);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleWest3);
}

Sprite* Graphics::createPlayerBodyDwarfFemaleWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfFemaleWest4);
}

Sprite* Graphics::createPlayerBodyDwarfMaleEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleEast1);
}

Sprite* Graphics::createPlayerBodyDwarfMaleEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleEast2);
}

Sprite* Graphics::createPlayerBodyDwarfMaleEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleEast3);
}

Sprite* Graphics::createPlayerBodyDwarfMaleEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleEast4);
}

Sprite* Graphics::createPlayerBodyDwarfMaleNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleNorth1);
}

Sprite* Graphics::createPlayerBodyDwarfMaleNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleNorth2);
}

Sprite* Graphics::createPlayerBodyDwarfMaleNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleNorth3);
}

Sprite* Graphics::createPlayerBodyDwarfMaleNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleNorth4);
}

Sprite* Graphics::createPlayerBodyDwarfMaleNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleNorth5);
}

Sprite* Graphics::createPlayerBodyDwarfMaleSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleSouth1);
}

Sprite* Graphics::createPlayerBodyDwarfMaleSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleSouth2);
}

Sprite* Graphics::createPlayerBodyDwarfMaleSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleSouth3);
}

Sprite* Graphics::createPlayerBodyDwarfMaleSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleSouth4);
}

Sprite* Graphics::createPlayerBodyDwarfMaleSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleSouth5);
}

Sprite* Graphics::createPlayerBodyDwarfMaleStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleStandingEast);
}

Sprite* Graphics::createPlayerBodyDwarfMaleStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleStandingNorth);
}

Sprite* Graphics::createPlayerBodyDwarfMaleStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleStandingSouth);
}

Sprite* Graphics::createPlayerBodyDwarfMaleStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleStandingWest);
}

Sprite* Graphics::createPlayerBodyDwarfMaleWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleWest1);
}

Sprite* Graphics::createPlayerBodyDwarfMaleWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleWest2);
}

Sprite* Graphics::createPlayerBodyDwarfMaleWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleWest3);
}

Sprite* Graphics::createPlayerBodyDwarfMaleWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyDwarfMaleWest4);
}

Sprite* Graphics::createPlayerBodyElfFemaleEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleEast1);
}

Sprite* Graphics::createPlayerBodyElfFemaleEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleEast2);
}

Sprite* Graphics::createPlayerBodyElfFemaleEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleEast3);
}

Sprite* Graphics::createPlayerBodyElfFemaleEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleEast4);
}

Sprite* Graphics::createPlayerBodyElfFemaleNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleNorth1);
}

Sprite* Graphics::createPlayerBodyElfFemaleNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleNorth2);
}

Sprite* Graphics::createPlayerBodyElfFemaleNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleNorth3);
}

Sprite* Graphics::createPlayerBodyElfFemaleNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleNorth4);
}

Sprite* Graphics::createPlayerBodyElfFemaleNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleNorth5);
}

Sprite* Graphics::createPlayerBodyElfFemaleSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleSouth1);
}

Sprite* Graphics::createPlayerBodyElfFemaleSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleSouth2);
}

Sprite* Graphics::createPlayerBodyElfFemaleSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleSouth3);
}

Sprite* Graphics::createPlayerBodyElfFemaleSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleSouth4);
}

Sprite* Graphics::createPlayerBodyElfFemaleSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleSouth5);
}

Sprite* Graphics::createPlayerBodyElfFemaleStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleStandingEast);
}

Sprite* Graphics::createPlayerBodyElfFemaleStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleStandingNorth);
}

Sprite* Graphics::createPlayerBodyElfFemaleStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleStandingSouth);
}

Sprite* Graphics::createPlayerBodyElfFemaleStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleStandingWest);
}

Sprite* Graphics::createPlayerBodyElfFemaleWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleWest1);
}

Sprite* Graphics::createPlayerBodyElfFemaleWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleWest2);
}

Sprite* Graphics::createPlayerBodyElfFemaleWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleWest3);
}

Sprite* Graphics::createPlayerBodyElfFemaleWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfFemaleWest4);
}

Sprite* Graphics::createPlayerBodyElfMaleEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleEast1);
}

Sprite* Graphics::createPlayerBodyElfMaleEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleEast2);
}

Sprite* Graphics::createPlayerBodyElfMaleEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleEast3);
}

Sprite* Graphics::createPlayerBodyElfMaleEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleEast4);
}

Sprite* Graphics::createPlayerBodyElfMaleNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleNorth1);
}

Sprite* Graphics::createPlayerBodyElfMaleNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleNorth2);
}

Sprite* Graphics::createPlayerBodyElfMaleNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleNorth3);
}

Sprite* Graphics::createPlayerBodyElfMaleNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleNorth4);
}

Sprite* Graphics::createPlayerBodyElfMaleNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleNorth5);
}

Sprite* Graphics::createPlayerBodyElfMaleSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleSouth1);
}

Sprite* Graphics::createPlayerBodyElfMaleSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleSouth2);
}

Sprite* Graphics::createPlayerBodyElfMaleSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleSouth3);
}

Sprite* Graphics::createPlayerBodyElfMaleSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleSouth4);
}

Sprite* Graphics::createPlayerBodyElfMaleSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleSouth5);
}

Sprite* Graphics::createPlayerBodyElfMaleStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleStandingEast);
}

Sprite* Graphics::createPlayerBodyElfMaleStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleStandingNorth);
}

Sprite* Graphics::createPlayerBodyElfMaleStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleStandingSouth);
}

Sprite* Graphics::createPlayerBodyElfMaleStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleStandingWest);
}

Sprite* Graphics::createPlayerBodyElfMaleWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleWest1);
}

Sprite* Graphics::createPlayerBodyElfMaleWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleWest2);
}

Sprite* Graphics::createPlayerBodyElfMaleWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleWest3);
}

Sprite* Graphics::createPlayerBodyElfMaleWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyElfMaleWest4);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleEast1);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleEast2);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleEast3);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleEast4);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleNorth1);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleNorth2);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleNorth3);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleNorth4);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleNorth5);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleSouth1);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleSouth2);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleSouth3);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleSouth4);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleSouth5);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleStandingEast);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleStandingNorth);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleStandingSouth);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleStandingWest);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleWest1);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleWest2);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleWest3);
}

Sprite* Graphics::createPlayerBodyGnomeFemaleWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeFemaleWest4);
}

Sprite* Graphics::createPlayerBodyGnomeMaleEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleEast1);
}

Sprite* Graphics::createPlayerBodyGnomeMaleEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleEast2);
}

Sprite* Graphics::createPlayerBodyGnomeMaleEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleEast3);
}

Sprite* Graphics::createPlayerBodyGnomeMaleEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleEast4);
}

Sprite* Graphics::createPlayerBodyGnomeMaleNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleNorth1);
}

Sprite* Graphics::createPlayerBodyGnomeMaleNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleNorth2);
}

Sprite* Graphics::createPlayerBodyGnomeMaleNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleNorth3);
}

Sprite* Graphics::createPlayerBodyGnomeMaleNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleNorth4);
}

Sprite* Graphics::createPlayerBodyGnomeMaleNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleNorth5);
}

Sprite* Graphics::createPlayerBodyGnomeMaleSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleSouth1);
}

Sprite* Graphics::createPlayerBodyGnomeMaleSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleSouth2);
}

Sprite* Graphics::createPlayerBodyGnomeMaleSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleSouth3);
}

Sprite* Graphics::createPlayerBodyGnomeMaleSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleSouth4);
}

Sprite* Graphics::createPlayerBodyGnomeMaleSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleSouth5);
}

Sprite* Graphics::createPlayerBodyGnomeMaleStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleStandingEast);
}

Sprite* Graphics::createPlayerBodyGnomeMaleStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleStandingNorth);
}

Sprite* Graphics::createPlayerBodyGnomeMaleStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleStandingSouth);
}

Sprite* Graphics::createPlayerBodyGnomeMaleStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleStandingWest);
}

Sprite* Graphics::createPlayerBodyGnomeMaleWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleWest1);
}

Sprite* Graphics::createPlayerBodyGnomeMaleWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleWest2);
}

Sprite* Graphics::createPlayerBodyGnomeMaleWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleWest3);
}

Sprite* Graphics::createPlayerBodyGnomeMaleWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyGnomeMaleWest4);
}

Sprite* Graphics::createPlayerBodyHumanFemaleEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleEast1);
}

Sprite* Graphics::createPlayerBodyHumanFemaleEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleEast2);
}

Sprite* Graphics::createPlayerBodyHumanFemaleEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleEast3);
}

Sprite* Graphics::createPlayerBodyHumanFemaleEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleEast4);
}

Sprite* Graphics::createPlayerBodyHumanFemaleNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleNorth1);
}

Sprite* Graphics::createPlayerBodyHumanFemaleNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleNorth2);
}

Sprite* Graphics::createPlayerBodyHumanFemaleNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleNorth3);
}

Sprite* Graphics::createPlayerBodyHumanFemaleNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleNorth4);
}

Sprite* Graphics::createPlayerBodyHumanFemaleNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleNorth5);
}

Sprite* Graphics::createPlayerBodyHumanFemaleSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleSouth1);
}

Sprite* Graphics::createPlayerBodyHumanFemaleSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleSouth2);
}

Sprite* Graphics::createPlayerBodyHumanFemaleSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleSouth3);
}

Sprite* Graphics::createPlayerBodyHumanFemaleSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleSouth4);
}

Sprite* Graphics::createPlayerBodyHumanFemaleSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleSouth5);
}

Sprite* Graphics::createPlayerBodyHumanFemaleStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleStandingEast);
}

Sprite* Graphics::createPlayerBodyHumanFemaleStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleStandingNorth);
}

Sprite* Graphics::createPlayerBodyHumanFemaleStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleStandingSouth);
}

Sprite* Graphics::createPlayerBodyHumanFemaleStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleStandingWest);
}

Sprite* Graphics::createPlayerBodyHumanFemaleWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleWest1);
}

Sprite* Graphics::createPlayerBodyHumanFemaleWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleWest2);
}

Sprite* Graphics::createPlayerBodyHumanFemaleWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleWest3);
}

Sprite* Graphics::createPlayerBodyHumanFemaleWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanFemaleWest4);
}

Sprite* Graphics::createPlayerBodyHumanMaleEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleEast1);
}

Sprite* Graphics::createPlayerBodyHumanMaleEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleEast2);
}

Sprite* Graphics::createPlayerBodyHumanMaleEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleEast3);
}

Sprite* Graphics::createPlayerBodyHumanMaleEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleEast4);
}

Sprite* Graphics::createPlayerBodyHumanMaleNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleNorth1);
}

Sprite* Graphics::createPlayerBodyHumanMaleNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleNorth2);
}

Sprite* Graphics::createPlayerBodyHumanMaleNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleNorth3);
}

Sprite* Graphics::createPlayerBodyHumanMaleNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleNorth4);
}

Sprite* Graphics::createPlayerBodyHumanMaleNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleNorth5);
}

Sprite* Graphics::createPlayerBodyHumanMaleSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleSouth1);
}

Sprite* Graphics::createPlayerBodyHumanMaleSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleSouth2);
}

Sprite* Graphics::createPlayerBodyHumanMaleSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleSouth3);
}

Sprite* Graphics::createPlayerBodyHumanMaleSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleSouth4);
}

Sprite* Graphics::createPlayerBodyHumanMaleSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleSouth5);
}

Sprite* Graphics::createPlayerBodyHumanMaleStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleStandingEast);
}

Sprite* Graphics::createPlayerBodyHumanMaleStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleStandingNorth);
}

Sprite* Graphics::createPlayerBodyHumanMaleStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleStandingSouth);
}

Sprite* Graphics::createPlayerBodyHumanMaleStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleStandingWest);
}

Sprite* Graphics::createPlayerBodyHumanMaleWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleWest1);
}

Sprite* Graphics::createPlayerBodyHumanMaleWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleWest2);
}

Sprite* Graphics::createPlayerBodyHumanMaleWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleWest3);
}

Sprite* Graphics::createPlayerBodyHumanMaleWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerBodyHumanMaleWest4);
}

Sprite* Graphics::createPlayerCasperBodyEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperBodyEast1);
}

Sprite* Graphics::createPlayerCasperBodyEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperBodyEast2);
}

Sprite* Graphics::createPlayerCasperBodyNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperBodyNorth1);
}

Sprite* Graphics::createPlayerCasperBodyNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperBodyNorth2);
}

Sprite* Graphics::createPlayerCasperBodySouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperBodySouth1);
}

Sprite* Graphics::createPlayerCasperBodySouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperBodySouth2);
}

Sprite* Graphics::createPlayerCasperBodyStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperBodyStandingEast);
}

Sprite* Graphics::createPlayerCasperBodyStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperBodyStandingNorth);
}

Sprite* Graphics::createPlayerCasperBodyStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperBodyStandingSouth);
}

Sprite* Graphics::createPlayerCasperBodyStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperBodyStandingWest);
}

Sprite* Graphics::createPlayerCasperBodyWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperBodyWest1);
}

Sprite* Graphics::createPlayerCasperBodyWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperBodyWest2);
}

Sprite* Graphics::createPlayerCasperDarkEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperDarkEast1);
}

Sprite* Graphics::createPlayerCasperDarkEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperDarkEast2);
}

Sprite* Graphics::createPlayerCasperDarkNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperDarkNorth1);
}

Sprite* Graphics::createPlayerCasperDarkNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperDarkNorth2);
}

Sprite* Graphics::createPlayerCasperDarkSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperDarkSouth1);
}

Sprite* Graphics::createPlayerCasperDarkSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperDarkSouth2);
}

Sprite* Graphics::createPlayerCasperDarkStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperDarkStandingEast);
}

Sprite* Graphics::createPlayerCasperDarkStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperDarkStandingNorth);
}

Sprite* Graphics::createPlayerCasperDarkStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperDarkStandingSouth);
}

Sprite* Graphics::createPlayerCasperDarkStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperDarkStandingWest);
}

Sprite* Graphics::createPlayerCasperDarkWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperDarkWest1);
}

Sprite* Graphics::createPlayerCasperDarkWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerCasperDarkWest2);
}

Sprite* Graphics::createPlayerHandShieldIronEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronEast1);
}

Sprite* Graphics::createPlayerHandShieldIronEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronEast2);
}

Sprite* Graphics::createPlayerHandShieldIronEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronEast3);
}

Sprite* Graphics::createPlayerHandShieldIronEast4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronEast4);
}

Sprite* Graphics::createPlayerHandShieldIronNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronNorth1);
}

Sprite* Graphics::createPlayerHandShieldIronNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronNorth2);
}

Sprite* Graphics::createPlayerHandShieldIronNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronNorth3);
}

Sprite* Graphics::createPlayerHandShieldIronNorth4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronNorth4);
}

Sprite* Graphics::createPlayerHandShieldIronNorth5Sprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronNorth5);
}

Sprite* Graphics::createPlayerHandShieldIronSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronSouth1);
}

Sprite* Graphics::createPlayerHandShieldIronSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronSouth2);
}

Sprite* Graphics::createPlayerHandShieldIronSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronSouth3);
}

Sprite* Graphics::createPlayerHandShieldIronSouth4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronSouth4);
}

Sprite* Graphics::createPlayerHandShieldIronSouth5Sprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronSouth5);
}

Sprite* Graphics::createPlayerHandShieldIronStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronStandingEast);
}

Sprite* Graphics::createPlayerHandShieldIronStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronStandingNorth);
}

Sprite* Graphics::createPlayerHandShieldIronStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronStandingSouth);
}

Sprite* Graphics::createPlayerHandShieldIronStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronStandingWest);
}

Sprite* Graphics::createPlayerHandShieldIronWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronWest1);
}

Sprite* Graphics::createPlayerHandShieldIronWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronWest2);
}

Sprite* Graphics::createPlayerHandShieldIronWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronWest3);
}

Sprite* Graphics::createPlayerHandShieldIronWest4Sprite()
{
    return Sprite::createWithSpriteFrameName(playerHandShieldIronWest4);
}

Sprite* Graphics::createPlayerHatBlueEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerHatBlueEast);
}

Sprite* Graphics::createPlayerHatBlueNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHatBlueNorth);
}

Sprite* Graphics::createPlayerHatBlueSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHatBlueSouth);
}

Sprite* Graphics::createPlayerHatBlueWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerHatBlueWest);
}

Sprite* Graphics::createPlayerHatNoviceEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerHatNoviceEast);
}

Sprite* Graphics::createPlayerHatNoviceNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHatNoviceNorth);
}

Sprite* Graphics::createPlayerHatNoviceSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHatNoviceSouth);
}

Sprite* Graphics::createPlayerHatNoviceWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerHatNoviceWest);
}

Sprite* Graphics::createPlayerHatProEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerHatProEast);
}

Sprite* Graphics::createPlayerHatProNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHatProNorth);
}

Sprite* Graphics::createPlayerHatProSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHatProSouth);
}

Sprite* Graphics::createPlayerHatProWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerHatProWest);
}

Sprite* Graphics::createPlayerHelmetBearEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetBearEast);
}

Sprite* Graphics::createPlayerHelmetBearNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetBearNorth);
}

Sprite* Graphics::createPlayerHelmetBearSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetBearSouth);
}

Sprite* Graphics::createPlayerHelmetBearWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetBearWest);
}

Sprite* Graphics::createPlayerHelmetEagleEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetEagleEast);
}

Sprite* Graphics::createPlayerHelmetEagleNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetEagleNorth);
}

Sprite* Graphics::createPlayerHelmetEagleSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetEagleSouth);
}

Sprite* Graphics::createPlayerHelmetEagleWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetEagleWest);
}

Sprite* Graphics::createPlayerHelmetIronEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetIronEast);
}

Sprite* Graphics::createPlayerHelmetIronNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetIronNorth);
}

Sprite* Graphics::createPlayerHelmetIronProEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetIronProEast);
}

Sprite* Graphics::createPlayerHelmetIronProNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetIronProNorth);
}

Sprite* Graphics::createPlayerHelmetIronProSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetIronProSouth);
}

Sprite* Graphics::createPlayerHelmetIronProWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetIronProWest);
}

Sprite* Graphics::createPlayerHelmetIronSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetIronSouth);
}

Sprite* Graphics::createPlayerHelmetIronWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetIronWest);
}

Sprite* Graphics::createPlayerHelmetSilverEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetSilverEast);
}

Sprite* Graphics::createPlayerHelmetSilverNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetSilverNorth);
}

Sprite* Graphics::createPlayerHelmetSilverSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetSilverSouth);
}

Sprite* Graphics::createPlayerHelmetSilverWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetSilverWest);
}

Sprite* Graphics::createPlayerHelmetTigerEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetTigerEast);
}

Sprite* Graphics::createPlayerHelmetTigerNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetTigerNorth);
}

Sprite* Graphics::createPlayerHelmetTigerSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetTigerSouth);
}

Sprite* Graphics::createPlayerHelmetTigerWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetTigerWest);
}

Sprite* Graphics::createPlayerHelmetWolfEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetWolfEast);
}

Sprite* Graphics::createPlayerHelmetWolfNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetWolfNorth);
}

Sprite* Graphics::createPlayerHelmetWolfSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetWolfSouth);
}

Sprite* Graphics::createPlayerHelmetWolfWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerHelmetWolfWest);
}

Sprite* Graphics::createPlayerHoodBlackEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerHoodBlackEast);
}

Sprite* Graphics::createPlayerHoodBlackNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHoodBlackNorth);
}

Sprite* Graphics::createPlayerHoodBlackSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHoodBlackSouth);
}

Sprite* Graphics::createPlayerHoodBlackWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerHoodBlackWest);
}

Sprite* Graphics::createPlayerHoodBrownEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerHoodBrownEast);
}

Sprite* Graphics::createPlayerHoodBrownNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHoodBrownNorth);
}

Sprite* Graphics::createPlayerHoodBrownSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerHoodBrownSouth);
}

Sprite* Graphics::createPlayerHoodBrownWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerHoodBrownWest);
}

Sprite* Graphics::createPlayerKerchiefRedEastSprite()
{
    return Sprite::createWithSpriteFrameName(playerKerchiefRedEast);
}

Sprite* Graphics::createPlayerKerchiefRedNorthSprite()
{
    return Sprite::createWithSpriteFrameName(playerKerchiefRedNorth);
}

Sprite* Graphics::createPlayerKerchiefRedSouthSprite()
{
    return Sprite::createWithSpriteFrameName(playerKerchiefRedSouth);
}

Sprite* Graphics::createPlayerKerchiefRedWestSprite()
{
    return Sprite::createWithSpriteFrameName(playerKerchiefRedWest);
}

Sprite* Graphics::createSpawnBrown01Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnBrown01);
}

Sprite* Graphics::createSpawnBrown02Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnBrown02);
}

Sprite* Graphics::createSpawnBrown03Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnBrown03);
}

Sprite* Graphics::createSpawnBrown04Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnBrown04);
}

Sprite* Graphics::createSpawnBrown05Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnBrown05);
}

Sprite* Graphics::createSpawnBrown06Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnBrown06);
}

Sprite* Graphics::createSpawnBrown07Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnBrown07);
}

Sprite* Graphics::createSpawnBrown08Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnBrown08);
}

Sprite* Graphics::createSpawnBrown09Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnBrown09);
}

Sprite* Graphics::createSpawnBrown10Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnBrown10);
}

Sprite* Graphics::createSpawnBrown11Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnBrown11);
}

Sprite* Graphics::createSpawnBrown12Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnBrown12);
}

Sprite* Graphics::createSpawnBrown13Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnBrown13);
}

Sprite* Graphics::createSpawnBrown14Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnBrown14);
}

Sprite* Graphics::createSpawnBrown15Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnBrown15);
}

Sprite* Graphics::createSpawnGreen01Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnGreen01);
}

Sprite* Graphics::createSpawnGreen02Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnGreen02);
}

Sprite* Graphics::createSpawnGreen03Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnGreen03);
}

Sprite* Graphics::createSpawnGreen04Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnGreen04);
}

Sprite* Graphics::createSpawnGreen05Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnGreen05);
}

Sprite* Graphics::createSpawnGreen06Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnGreen06);
}

Sprite* Graphics::createSpawnGreen07Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnGreen07);
}

Sprite* Graphics::createSpawnGreen08Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnGreen08);
}

Sprite* Graphics::createSpawnGreen09Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnGreen09);
}

Sprite* Graphics::createSpawnGreen10Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnGreen10);
}

Sprite* Graphics::createSpawnGreen11Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnGreen11);
}

Sprite* Graphics::createSpawnGreen12Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnGreen12);
}

Sprite* Graphics::createSpawnGreen13Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnGreen13);
}

Sprite* Graphics::createSpawnGreen14Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnGreen14);
}

Sprite* Graphics::createSpawnGreen15Sprite()
{
    return Sprite::createWithSpriteFrameName(spawnGreen15);
}

Sprite* Graphics::createSpellApocalipsis01Sprite()
{
    return Sprite::createWithSpriteFrameName(spellApocalipsis01);
}

Sprite* Graphics::createSpellApocalipsis02Sprite()
{
    return Sprite::createWithSpriteFrameName(spellApocalipsis02);
}

Sprite* Graphics::createSpellApocalipsis03Sprite()
{
    return Sprite::createWithSpriteFrameName(spellApocalipsis03);
}

Sprite* Graphics::createSpellApocalipsis04Sprite()
{
    return Sprite::createWithSpriteFrameName(spellApocalipsis04);
}

Sprite* Graphics::createSpellApocalipsis05Sprite()
{
    return Sprite::createWithSpriteFrameName(spellApocalipsis05);
}

Sprite* Graphics::createSpellApocalipsis06Sprite()
{
    return Sprite::createWithSpriteFrameName(spellApocalipsis06);
}

Sprite* Graphics::createSpellApocalipsis07Sprite()
{
    return Sprite::createWithSpriteFrameName(spellApocalipsis07);
}

Sprite* Graphics::createSpellApocalipsis08Sprite()
{
    return Sprite::createWithSpriteFrameName(spellApocalipsis08);
}

Sprite* Graphics::createSpellApocalipsis09Sprite()
{
    return Sprite::createWithSpriteFrameName(spellApocalipsis09);
}

Sprite* Graphics::createSpellApocalipsis10Sprite()
{
    return Sprite::createWithSpriteFrameName(spellApocalipsis10);
}

Sprite* Graphics::createSpellApocalipsis11Sprite()
{
    return Sprite::createWithSpriteFrameName(spellApocalipsis11);
}

Sprite* Graphics::createSpellApocalipsis12Sprite()
{
    return Sprite::createWithSpriteFrameName(spellApocalipsis12);
}

Sprite* Graphics::createSpellApocalipsis13Sprite()
{
    return Sprite::createWithSpriteFrameName(spellApocalipsis13);
}

Sprite* Graphics::createSpellApocalipsis14Sprite()
{
    return Sprite::createWithSpriteFrameName(spellApocalipsis14);
}

Sprite* Graphics::createSpellApocalipsis15Sprite()
{
    return Sprite::createWithSpriteFrameName(spellApocalipsis15);
}

Sprite* Graphics::createSpellApocalipsis16Sprite()
{
    return Sprite::createWithSpriteFrameName(spellApocalipsis16);
}

Sprite* Graphics::createSpellApocalipsis17Sprite()
{
    return Sprite::createWithSpriteFrameName(spellApocalipsis17);
}

Sprite* Graphics::createSpellApocalipsis18Sprite()
{
    return Sprite::createWithSpriteFrameName(spellApocalipsis18);
}

Sprite* Graphics::createSpellApocalipsis19Sprite()
{
    return Sprite::createWithSpriteFrameName(spellApocalipsis19);
}

Sprite* Graphics::createSpellApocalipsis20Sprite()
{
    return Sprite::createWithSpriteFrameName(spellApocalipsis20);
}

Sprite* Graphics::createSpellApocalipsis21Sprite()
{
    return Sprite::createWithSpriteFrameName(spellApocalipsis21);
}

Sprite* Graphics::createSpellDescargaElectrica01Sprite()
{
    return Sprite::createWithSpriteFrameName(spellDescargaElectrica01);
}

Sprite* Graphics::createSpellDescargaElectrica02Sprite()
{
    return Sprite::createWithSpriteFrameName(spellDescargaElectrica02);
}

Sprite* Graphics::createSpellDescargaElectrica03Sprite()
{
    return Sprite::createWithSpriteFrameName(spellDescargaElectrica03);
}

Sprite* Graphics::createSpellDescargaElectrica04Sprite()
{
    return Sprite::createWithSpriteFrameName(spellDescargaElectrica04);
}

Sprite* Graphics::createSpellDescargaElectrica05Sprite()
{
    return Sprite::createWithSpriteFrameName(spellDescargaElectrica05);
}

Sprite* Graphics::createSpellDescargaElectrica06Sprite()
{
    return Sprite::createWithSpriteFrameName(spellDescargaElectrica06);
}

Sprite* Graphics::createSpellDescargaElectrica07Sprite()
{
    return Sprite::createWithSpriteFrameName(spellDescargaElectrica07);
}

Sprite* Graphics::createSpellDescargaElectrica08Sprite()
{
    return Sprite::createWithSpriteFrameName(spellDescargaElectrica08);
}

Sprite* Graphics::createSpellDescargaElectrica09Sprite()
{
    return Sprite::createWithSpriteFrameName(spellDescargaElectrica09);
}

Sprite* Graphics::createSpellDescargaElectrica10Sprite()
{
    return Sprite::createWithSpriteFrameName(spellDescargaElectrica10);
}

Sprite* Graphics::createSpellDescargaElectrica11Sprite()
{
    return Sprite::createWithSpriteFrameName(spellDescargaElectrica11);
}

Sprite* Graphics::createSpellDescargaElectrica12Sprite()
{
    return Sprite::createWithSpriteFrameName(spellDescargaElectrica12);
}

Sprite* Graphics::createSpellDescargaElectrica13Sprite()
{
    return Sprite::createWithSpriteFrameName(spellDescargaElectrica13);
}

Sprite* Graphics::createSpellDescargaElectrica14Sprite()
{
    return Sprite::createWithSpriteFrameName(spellDescargaElectrica14);
}

Sprite* Graphics::createSpellDescargaElectrica15Sprite()
{
    return Sprite::createWithSpriteFrameName(spellDescargaElectrica15);
}

Sprite* Graphics::createSpellFireStorm01Sprite()
{
    return Sprite::createWithSpriteFrameName(spellFireStorm01);
}

Sprite* Graphics::createSpellFireStorm02Sprite()
{
    return Sprite::createWithSpriteFrameName(spellFireStorm02);
}

Sprite* Graphics::createSpellFireStorm03Sprite()
{
    return Sprite::createWithSpriteFrameName(spellFireStorm03);
}

Sprite* Graphics::createSpellFireStorm04Sprite()
{
    return Sprite::createWithSpriteFrameName(spellFireStorm04);
}

Sprite* Graphics::createSpellFireStorm05Sprite()
{
    return Sprite::createWithSpriteFrameName(spellFireStorm05);
}

Sprite* Graphics::createSpellFireStorm06Sprite()
{
    return Sprite::createWithSpriteFrameName(spellFireStorm06);
}

Sprite* Graphics::createSpellFireStorm07Sprite()
{
    return Sprite::createWithSpriteFrameName(spellFireStorm07);
}

Sprite* Graphics::createSpellFireStorm08Sprite()
{
    return Sprite::createWithSpriteFrameName(spellFireStorm08);
}

Sprite* Graphics::createSpellFireStorm09Sprite()
{
    return Sprite::createWithSpriteFrameName(spellFireStorm09);
}

Sprite* Graphics::createSpellFireStorm10Sprite()
{
    return Sprite::createWithSpriteFrameName(spellFireStorm10);
}

Sprite* Graphics::createSpellFireStorm11Sprite()
{
    return Sprite::createWithSpriteFrameName(spellFireStorm11);
}

Sprite* Graphics::createSpellFireStorm12Sprite()
{
    return Sprite::createWithSpriteFrameName(spellFireStorm12);
}

Sprite* Graphics::createSpellFireStorm13Sprite()
{
    return Sprite::createWithSpriteFrameName(spellFireStorm13);
}

Sprite* Graphics::createSpellFireStorm14Sprite()
{
    return Sprite::createWithSpriteFrameName(spellFireStorm14);
}

Sprite* Graphics::createSpellFireStorm15Sprite()
{
    return Sprite::createWithSpriteFrameName(spellFireStorm15);
}

Sprite* Graphics::createSpellHealPoison0Sprite()
{
    return Sprite::createWithSpriteFrameName(spellHealPoison0);
}

Sprite* Graphics::createSpellHealPoison1Sprite()
{
    return Sprite::createWithSpriteFrameName(spellHealPoison1);
}

Sprite* Graphics::createSpellHealPoison2Sprite()
{
    return Sprite::createWithSpriteFrameName(spellHealPoison2);
}

Sprite* Graphics::createSpellImmobilize0Sprite()
{
    return Sprite::createWithSpriteFrameName(spellImmobilize0);
}

Sprite* Graphics::createSpellImmobilize1Sprite()
{
    return Sprite::createWithSpriteFrameName(spellImmobilize1);
}

Sprite* Graphics::createSpellImmobilize10Sprite()
{
    return Sprite::createWithSpriteFrameName(spellImmobilize10);
}

Sprite* Graphics::createSpellImmobilize11Sprite()
{
    return Sprite::createWithSpriteFrameName(spellImmobilize11);
}

Sprite* Graphics::createSpellImmobilize12Sprite()
{
    return Sprite::createWithSpriteFrameName(spellImmobilize12);
}

Sprite* Graphics::createSpellImmobilize13Sprite()
{
    return Sprite::createWithSpriteFrameName(spellImmobilize13);
}

Sprite* Graphics::createSpellImmobilize14Sprite()
{
    return Sprite::createWithSpriteFrameName(spellImmobilize14);
}

Sprite* Graphics::createSpellImmobilize2Sprite()
{
    return Sprite::createWithSpriteFrameName(spellImmobilize2);
}

Sprite* Graphics::createSpellImmobilize3Sprite()
{
    return Sprite::createWithSpriteFrameName(spellImmobilize3);
}

Sprite* Graphics::createSpellImmobilize4Sprite()
{
    return Sprite::createWithSpriteFrameName(spellImmobilize4);
}

Sprite* Graphics::createSpellImmobilize5Sprite()
{
    return Sprite::createWithSpriteFrameName(spellImmobilize5);
}

Sprite* Graphics::createSpellImmobilize6Sprite()
{
    return Sprite::createWithSpriteFrameName(spellImmobilize6);
}

Sprite* Graphics::createSpellImmobilize7Sprite()
{
    return Sprite::createWithSpriteFrameName(spellImmobilize7);
}

Sprite* Graphics::createSpellImmobilize8Sprite()
{
    return Sprite::createWithSpriteFrameName(spellImmobilize8);
}

Sprite* Graphics::createSpellImmobilize9Sprite()
{
    return Sprite::createWithSpriteFrameName(spellImmobilize9);
}

Sprite* Graphics::createSpellMagicalArrow0Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalArrow0);
}

Sprite* Graphics::createSpellMagicalArrow1Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalArrow1);
}

Sprite* Graphics::createSpellMagicalArrow2Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalArrow2);
}

Sprite* Graphics::createSpellMagicalArrow3Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalArrow3);
}

Sprite* Graphics::createSpellMagicalArrow4Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalArrow4);
}

Sprite* Graphics::createSpellMagicalDart0Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalDart0);
}

Sprite* Graphics::createSpellMagicalDart1Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalDart1);
}

Sprite* Graphics::createSpellMagicalDart2Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalDart2);
}

Sprite* Graphics::createSpellMagicalDart3Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalDart3);
}

Sprite* Graphics::createSpellMagicalDart4Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalDart4);
}

Sprite* Graphics::createSpellMagicalDart5Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalDart5);
}

Sprite* Graphics::createSpellMagicalDart6Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalDart6);
}

Sprite* Graphics::createSpellMagicalDart7Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalDart7);
}

Sprite* Graphics::createSpellMagicalMissile01Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalMissile01);
}

Sprite* Graphics::createSpellMagicalMissile02Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalMissile02);
}

Sprite* Graphics::createSpellMagicalMissile03Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalMissile03);
}

Sprite* Graphics::createSpellMagicalMissile04Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalMissile04);
}

Sprite* Graphics::createSpellMagicalMissile05Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalMissile05);
}

Sprite* Graphics::createSpellMagicalMissile06Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalMissile06);
}

Sprite* Graphics::createSpellMagicalMissile07Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalMissile07);
}

Sprite* Graphics::createSpellMagicalMissile08Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalMissile08);
}

Sprite* Graphics::createSpellMagicalMissile09Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalMissile09);
}

Sprite* Graphics::createSpellMagicalMissile10Sprite()
{
    return Sprite::createWithSpriteFrameName(spellMagicalMissile10);
}

Sprite* Graphics::createSpellParalyze0Sprite()
{
    return Sprite::createWithSpriteFrameName(spellParalyze0);
}

Sprite* Graphics::createSpellParalyze1Sprite()
{
    return Sprite::createWithSpriteFrameName(spellParalyze1);
}

Sprite* Graphics::createSpellParalyze2Sprite()
{
    return Sprite::createWithSpriteFrameName(spellParalyze2);
}

Sprite* Graphics::createSpellParalyze3Sprite()
{
    return Sprite::createWithSpriteFrameName(spellParalyze3);
}

Sprite* Graphics::createSpellParalyze4Sprite()
{
    return Sprite::createWithSpriteFrameName(spellParalyze4);
}

Sprite* Graphics::createSpellParalyze5Sprite()
{
    return Sprite::createWithSpriteFrameName(spellParalyze5);
}

Sprite* Graphics::createSpellParalyze6Sprite()
{
    return Sprite::createWithSpriteFrameName(spellParalyze6);
}

Sprite* Graphics::createSpellParalyze7Sprite()
{
    return Sprite::createWithSpriteFrameName(spellParalyze7);
}

Sprite* Graphics::createSpellParalyze8Sprite()
{
    return Sprite::createWithSpriteFrameName(spellParalyze8);
}

Sprite* Graphics::createSpellParalyze9Sprite()
{
    return Sprite::createWithSpriteFrameName(spellParalyze9);
}

Sprite* Graphics::createSpellStrength0Sprite()
{
    return Sprite::createWithSpriteFrameName(spellStrength0);
}

Sprite* Graphics::createSpellStrength1Sprite()
{
    return Sprite::createWithSpriteFrameName(spellStrength1);
}

Sprite* Graphics::createSpellStrength2Sprite()
{
    return Sprite::createWithSpriteFrameName(spellStrength2);
}

Sprite* Graphics::createSpellStrength3Sprite()
{
    return Sprite::createWithSpriteFrameName(spellStrength3);
}

Sprite* Graphics::createSpellStrength4Sprite()
{
    return Sprite::createWithSpriteFrameName(spellStrength4);
}

Sprite* Graphics::createSpellTownPortalBlue0Sprite()
{
    return Sprite::createWithSpriteFrameName(spellTownPortalBlue0);
}

Sprite* Graphics::createSpellTownPortalBlue1Sprite()
{
    return Sprite::createWithSpriteFrameName(spellTownPortalBlue1);
}

Sprite* Graphics::createSpellTownPortalBlue2Sprite()
{
    return Sprite::createWithSpriteFrameName(spellTownPortalBlue2);
}

Sprite* Graphics::createSpellTownPortalBlue3Sprite()
{
    return Sprite::createWithSpriteFrameName(spellTownPortalBlue3);
}

Sprite* Graphics::createSpellTownPortalBlue4Sprite()
{
    return Sprite::createWithSpriteFrameName(spellTownPortalBlue4);
}

Sprite* Graphics::createSpellTownPortalBlue5Sprite()
{
    return Sprite::createWithSpriteFrameName(spellTownPortalBlue5);
}

Sprite* Graphics::createSpellTownPortalBlue6Sprite()
{
    return Sprite::createWithSpriteFrameName(spellTownPortalBlue6);
}

Sprite* Graphics::createSpellTownPortalBlue7Sprite()
{
    return Sprite::createWithSpriteFrameName(spellTownPortalBlue7);
}

Sprite* Graphics::createSpellTownPortalBlue8Sprite()
{
    return Sprite::createWithSpriteFrameName(spellTownPortalBlue8);
}

Sprite* Graphics::createSpellTownPortalBlue9Sprite()
{
    return Sprite::createWithSpriteFrameName(spellTownPortalBlue9);
}

Sprite* Graphics::createWagonEast1Sprite()
{
    return Sprite::createWithSpriteFrameName(wagonEast1);
}

Sprite* Graphics::createWagonEast2Sprite()
{
    return Sprite::createWithSpriteFrameName(wagonEast2);
}

Sprite* Graphics::createWagonEast3Sprite()
{
    return Sprite::createWithSpriteFrameName(wagonEast3);
}

Sprite* Graphics::createWagonNorth1Sprite()
{
    return Sprite::createWithSpriteFrameName(wagonNorth1);
}

Sprite* Graphics::createWagonNorth2Sprite()
{
    return Sprite::createWithSpriteFrameName(wagonNorth2);
}

Sprite* Graphics::createWagonNorth3Sprite()
{
    return Sprite::createWithSpriteFrameName(wagonNorth3);
}

Sprite* Graphics::createWagonSouth1Sprite()
{
    return Sprite::createWithSpriteFrameName(wagonSouth1);
}

Sprite* Graphics::createWagonSouth2Sprite()
{
    return Sprite::createWithSpriteFrameName(wagonSouth2);
}

Sprite* Graphics::createWagonSouth3Sprite()
{
    return Sprite::createWithSpriteFrameName(wagonSouth3);
}

Sprite* Graphics::createWagonStandingEastSprite()
{
    return Sprite::createWithSpriteFrameName(wagonStandingEast);
}

Sprite* Graphics::createWagonStandingNorthSprite()
{
    return Sprite::createWithSpriteFrameName(wagonStandingNorth);
}

Sprite* Graphics::createWagonStandingSouthSprite()
{
    return Sprite::createWithSpriteFrameName(wagonStandingSouth);
}

Sprite* Graphics::createWagonStandingWestSprite()
{
    return Sprite::createWithSpriteFrameName(wagonStandingWest);
}

Sprite* Graphics::createWagonWest1Sprite()
{
    return Sprite::createWithSpriteFrameName(wagonWest1);
}

Sprite* Graphics::createWagonWest2Sprite()
{
    return Sprite::createWithSpriteFrameName(wagonWest2);
}

Sprite* Graphics::createWagonWest3Sprite()
{
    return Sprite::createWithSpriteFrameName(wagonWest3);
}


// ------------------------------------------------
// convenience functions returning animation frames
// ------------------------------------------------

Vector<SpriteFrame*> Graphics::getBLOODAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(blood01));
    frames.pushBack(frameCache->getSpriteFrameByName(blood02));
    frames.pushBack(frameCache->getSpriteFrameByName(blood03));
    frames.pushBack(frameCache->getSpriteFrameByName(blood04));
    frames.pushBack(frameCache->getSpriteFrameByName(blood05));
    return frames;
}

Vector<SpriteFrame*> Graphics::getFLOOR_MAP_FLOORAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(floorMAPFloor001));
    frames.pushBack(frameCache->getSpriteFrameByName(floorMAPFloor002));
    frames.pushBack(frameCache->getSpriteFrameByName(floorMAPFloor003));
    frames.pushBack(frameCache->getSpriteFrameByName(floorMAPFloor004));
    return frames;
}

Vector<SpriteFrame*> Graphics::getGOLEM_FIRE_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(golemFireEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(golemFireEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(golemFireEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(golemFireEast4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getGOLEM_FIRE_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(golemFireNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(golemFireNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(golemFireNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(golemFireNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(golemFireNorth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getGOLEM_FIRE_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(golemFireSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(golemFireSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(golemFireSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(golemFireSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(golemFireSouth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getGOLEM_FIRE_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(golemFireWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(golemFireWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(golemFireWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(golemFireWest4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getHAND_TORCH_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(handTorchEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(handTorchEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(handTorchEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(handTorchEast4));
    frames.pushBack(frameCache->getSpriteFrameByName(handTorchEast5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getHAND_TORCH_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(handTorchNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(handTorchNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(handTorchNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(handTorchNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(handTorchNorth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getHAND_TORCH_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(handTorchSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(handTorchSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(handTorchSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(handTorchSouth4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getHAND_TORCH_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(handTorchWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(handTorchWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(handTorchWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(handTorchWest4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_CAMPFIREAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(9);
    frames.pushBack(frameCache->getSpriteFrameByName(mapCampFire01));
    frames.pushBack(frameCache->getSpriteFrameByName(mapCampFire02));
    frames.pushBack(frameCache->getSpriteFrameByName(mapCampFire03));
    frames.pushBack(frameCache->getSpriteFrameByName(mapCampFire04));
    frames.pushBack(frameCache->getSpriteFrameByName(mapCampFire05));
    frames.pushBack(frameCache->getSpriteFrameByName(mapCampFire06));
    frames.pushBack(frameCache->getSpriteFrameByName(mapCampFire07));
    frames.pushBack(frameCache->getSpriteFrameByName(mapCampFire08));
    frames.pushBack(frameCache->getSpriteFrameByName(mapCampFire09));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_MISTICALPLACEAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(mapMisticalPlace0));
    frames.pushBack(frameCache->getSpriteFrameByName(mapMisticalPlace1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapMisticalPlace2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_MISTICALPLACEBAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(9);
    frames.pushBack(frameCache->getSpriteFrameByName(mapMisticalPlaceB0));
    frames.pushBack(frameCache->getSpriteFrameByName(mapMisticalPlaceB1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapMisticalPlaceB2));
    frames.pushBack(frameCache->getSpriteFrameByName(mapMisticalPlaceB3));
    frames.pushBack(frameCache->getSpriteFrameByName(mapMisticalPlaceB4));
    frames.pushBack(frameCache->getSpriteFrameByName(mapMisticalPlaceB5));
    frames.pushBack(frameCache->getSpriteFrameByName(mapMisticalPlaceB6));
    frames.pushBack(frameCache->getSpriteFrameByName(mapMisticalPlaceB7));
    frames.pushBack(frameCache->getSpriteFrameByName(mapMisticalPlaceB8));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_PORTAL_BLUEAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(8);
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalBlue0));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalBlue1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalBlue2));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalBlue3));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalBlue4));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalBlue5));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalBlue6));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalBlue7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_PORTAL_CLASICAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(8);
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalClasic0));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalClasic1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalClasic2));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalClasic3));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalClasic4));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalClasic5));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalClasic6));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalClasic7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_PORTAL_CLASICWARMERAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(8);
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalClasicWarmer0));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalClasicWarmer1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalClasicWarmer2));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalClasicWarmer3));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalClasicWarmer4));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalClasicWarmer5));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalClasicWarmer6));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalClasicWarmer7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_PORTAL_GREENAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(8);
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalGreen0));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalGreen1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalGreen2));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalGreen3));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalGreen4));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalGreen5));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalGreen6));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalGreen7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_PORTAL_LIGHTBLUEAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(8);
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalLightBlue0));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalLightBlue1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalLightBlue2));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalLightBlue3));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalLightBlue4));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalLightBlue5));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalLightBlue6));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalLightBlue7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_PORTAL_PINKAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(8);
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalPink0));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalPink1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalPink2));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalPink3));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalPink4));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalPink5));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalPink6));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalPink7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_PORTAL_PURPLEAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(8);
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalPurple0));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalPurple1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalPurple2));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalPurple3));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalPurple4));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalPurple5));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalPurple6));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalPurple7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_PORTAL_YELLOWAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(8);
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalYellow0));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalYellow1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalYellow2));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalYellow3));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalYellow4));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalYellow5));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalYellow6));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPortalYellow7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_POSTER_CASAAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(20);
    frames.pushBack(frameCache->getSpriteFrameByName(mapPosterCasa1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPosterCasa2));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPosterCasa3));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPosterCasa4));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPosterCasa5));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPosterCasa6));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPosterCasa7));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPosterCasa8));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPosterCasa9));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPosterCasa10));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPosterCasa11));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPosterCasa12));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPosterCasa13));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPosterCasa14));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPosterCasa15));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPosterCasa16));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPosterCasa17));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPosterCasa18));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPosterCasa19));
    frames.pushBack(frameCache->getSpriteFrameByName(mapPosterCasa20));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_STATUEAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(11);
    frames.pushBack(frameCache->getSpriteFrameByName(mapStatue01));
    frames.pushBack(frameCache->getSpriteFrameByName(mapStatue02));
    frames.pushBack(frameCache->getSpriteFrameByName(mapStatue03));
    frames.pushBack(frameCache->getSpriteFrameByName(mapStatue04));
    frames.pushBack(frameCache->getSpriteFrameByName(mapStatue05));
    frames.pushBack(frameCache->getSpriteFrameByName(mapStatue06));
    frames.pushBack(frameCache->getSpriteFrameByName(mapStatue07));
    frames.pushBack(frameCache->getSpriteFrameByName(mapStatue08));
    frames.pushBack(frameCache->getSpriteFrameByName(mapStatue09));
    frames.pushBack(frameCache->getSpriteFrameByName(mapStatue10));
    frames.pushBack(frameCache->getSpriteFrameByName(mapStatue11));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_TREE_AAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(6);
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeA1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeA2));
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeA3));
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeA4));
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeA5));
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeA6));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_TREE_BAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeB1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeB2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_TREE_CAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeC1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeC2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_TREE_DAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeD1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeD2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_TREE_DEATHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeDeath1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeDeath2));
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeDeath3));
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeDeath4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_TREE_EAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeE1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeE2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_TREE_FAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeF1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeF2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_TREE_GAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeG1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeG2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_TREE_HAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeH1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeH2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_TREE_IAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeI1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeI2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_TREE_JAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeJ1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeJ2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_TREE_KAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeK1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeK2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_TREE_LAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeL1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeL2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMAP_TREE_MAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeM1));
    frames.pushBack(frameCache->getSpriteFrameByName(mapTreeM2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMEDITATION_BLUEAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(10);
    frames.pushBack(frameCache->getSpriteFrameByName(meditationBlue0));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationBlue1));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationBlue2));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationBlue3));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationBlue4));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationBlue5));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationBlue6));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationBlue7));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationBlue8));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationBlue9));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMEDITATION_EXTREMEAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(10);
    frames.pushBack(frameCache->getSpriteFrameByName(meditationExtreme0));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationExtreme1));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationExtreme2));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationExtreme3));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationExtreme4));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationExtreme5));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationExtreme6));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationExtreme7));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationExtreme8));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationExtreme9));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMEDITATION_NEWBIEAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(10);
    frames.pushBack(frameCache->getSpriteFrameByName(meditationNewbie0));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationNewbie1));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationNewbie2));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationNewbie3));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationNewbie4));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationNewbie5));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationNewbie6));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationNewbie7));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationNewbie8));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationNewbie9));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMEDITATION_REDAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(10);
    frames.pushBack(frameCache->getSpriteFrameByName(meditationRed0));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationRed1));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationRed2));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationRed3));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationRed4));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationRed5));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationRed6));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationRed7));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationRed8));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationRed9));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMEDITATION_YELLOWAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(10);
    frames.pushBack(frameCache->getSpriteFrameByName(meditationYellow0));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationYellow1));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationYellow2));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationYellow3));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationYellow4));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationYellow5));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationYellow6));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationYellow7));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationYellow8));
    frames.pushBack(frameCache->getSpriteFrameByName(meditationYellow9));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_BAT_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobBatEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBatEast2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_BAT_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobBatNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBatNorth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_BAT_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobBatSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBatSouth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_BAT_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobBatWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBatWest2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_BEAR_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(7);
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearEast4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearEast5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearEast6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearEast7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_BEAR_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(7);
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearNorth5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearNorth6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearNorth7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_BEAR_POLAR_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearPolarEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearPolarEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearPolarEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearPolarEast4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_BEAR_POLAR_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearPolarNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearPolarNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearPolarNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearPolarNorth4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_BEAR_POLAR_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearPolarSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearPolarSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearPolarSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearPolarSouth4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_BEAR_POLAR_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearPolarWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearPolarWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearPolarWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearPolarWest4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_BEAR_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(7);
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearSouth5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearSouth6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearSouth7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_BEAR_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(7);
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearWest4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearWest5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearWest6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBearWest7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_BEHOLER_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(mobBeholerEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBeholerEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBeholerEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBeholerEast4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBeholerEast5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_BEHOLER_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(mobBeholerNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBeholerNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBeholerNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBeholerNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBeholerNorth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_BEHOLER_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(mobBeholerSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBeholerSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBeholerSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBeholerSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBeholerSouth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_BEHOLER_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(mobBeholerWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBeholerWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBeholerWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBeholerWest4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBeholerWest5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_BIRD_BLACK_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(mobBirdBlackEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBirdBlackEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBirdBlackEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBirdBlackEast4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBirdBlackEast5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_BIRD_BLACK_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(mobBirdBlackNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBirdBlackNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBirdBlackNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBirdBlackNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBirdBlackNorth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_BIRD_BLACK_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(mobBirdBlackSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBirdBlackSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBirdBlackSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBirdBlackSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBirdBlackSouth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_BIRD_BLACK_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(mobBirdBlackWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBirdBlackWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBirdBlackWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBirdBlackWest4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobBirdBlackWest5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_DRAGON_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(11);
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonEast4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonEast5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonEast6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonEast7));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonEast8));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonEast9));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonEast10));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonEast11));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_DRAGON_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(11);
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonNorth5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonNorth6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonNorth7));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonNorth8));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonNorth9));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonNorth10));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonNorth11));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_DRAGON_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(11);
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonSouth5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonSouth6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonSouth7));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonSouth8));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonSouth9));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonSouth10));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonSouth11));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_DRAGON_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(11);
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonWest4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonWest5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonWest6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonWest7));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonWest8));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonWest9));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonWest10));
    frames.pushBack(frameCache->getSpriteFrameByName(mobDragonWest11));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_ELI_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobEliEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobEliEast2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_ELI_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobEliNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobEliNorth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_ELI_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobEliSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobEliSouth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_ELI_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobEliWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobEliWest2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_ELY_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobElyEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobElyEast2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_ELY_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobElyNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobElyNorth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_ELY_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobElySouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobElySouth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_ELY_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobElyWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobElyWest2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_GOLEM_MAGMA_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(7);
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaEast4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaEast5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaEast6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaEast7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_GOLEM_MAGMA_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(7);
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaNorth5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaNorth6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaNorth7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_GOLEM_MAGMA_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(7);
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaSouth5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaSouth6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaSouth7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_GOLEM_MAGMA_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(7);
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaWest4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaWest5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaWest6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemMagmaWest7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_GOLEM_STONE_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(7);
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneEast4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneEast5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneEast6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneEast7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_GOLEM_STONE_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(7);
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneNorth5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneNorth6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneNorth7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_GOLEM_STONE_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(7);
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneSouth5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneSouth6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneSouth7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_GOLEM_STONE_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(7);
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneWest4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneWest5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneWest6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobGolemStoneWest7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_LEVIATHAN_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(mobLeviathanEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLeviathanEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLeviathanEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLeviathanEast4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_LEVIATHAN_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(mobLeviathanNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLeviathanNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLeviathanNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLeviathanNorth4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_LEVIATHAN_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(mobLeviathanSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLeviathanSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLeviathanSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLeviathanSouth4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_LEVIATHAN_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(mobLeviathanWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLeviathanWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLeviathanWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLeviathanWest4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_LICHE_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(7);
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheEast4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheEast5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheEast6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheEast7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_LICHE_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(7);
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheNorth5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheNorth6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheNorth7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_LICHE_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(7);
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheSouth5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheSouth6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheSouth7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_LICHE_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(7);
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheWest4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheWest5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheWest6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLicheWest7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_LINE_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(6);
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineEast4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineEast5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineEast6));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_LINE_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(6);
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineNorth5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineNorth6));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_LINE_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(6);
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineSouth5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineSouth6));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_LINE_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(6);
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineWest4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineWest5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobLineWest6));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_MERMAID_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(mobMermaidEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobMermaidEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobMermaidEast3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_MERMAID_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(mobMermaidNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobMermaidNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobMermaidNorth3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_MERMAID_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(mobMermaidSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobMermaidSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobMermaidSouth3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_MERMAID_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(mobMermaidWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobMermaidWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobMermaidWest3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_OCTOPUS_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(mobOctopusEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobOctopusEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobOctopusEast3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_OCTOPUS_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(mobOctopusNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobOctopusNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobOctopusNorth3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_OCTOPUS_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(mobOctopusSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobOctopusSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobOctopusSouth3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_OCTOPUS_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(mobOctopusWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobOctopusWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobOctopusWest3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_PARROT_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobParrotEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobParrotEast2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_PARROT_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobParrotNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobParrotNorth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_PARROT_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobParrotSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobParrotSouth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_PARROT_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobParrotWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobParrotWest2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_PIRANHA_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobPiranhaEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobPiranhaEast2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_PIRANHA_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobPiranhaNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobPiranhaNorth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_PIRANHA_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobPiranhaSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobPiranhaSouth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_PIRANHA_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobPiranhaWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobPiranhaWest2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_RABBIT_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobRabbitEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobRabbitEast2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_RABBIT_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobRabbitNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobRabbitNorth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_RABBIT_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobRabbitSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobRabbitSouth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_RABBIT_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobRabbitWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobRabbitWest2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_RAVEN_BLACK_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobRavenBlackEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobRavenBlackEast2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_RAVEN_BLACK_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobRavenBlackNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobRavenBlackNorth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_RAVEN_BLACK_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobRavenBlackSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobRavenBlackSouth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_RAVEN_BLACK_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobRavenBlackWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobRavenBlackWest2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_RAVEN_WHITE_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobRavenWhiteEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobRavenWhiteEast2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_RAVEN_WHITE_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobRavenWhiteNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobRavenWhiteNorth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_RAVEN_WHITE_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobRavenWhiteSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobRavenWhiteSouth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_RAVEN_WHITE_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobRavenWhiteWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobRavenWhiteWest2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_SNAKEDOUBLEHEAD_GREEN_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeDoubleHeadGreenEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeDoubleHeadGreenEast2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_SNAKEDOUBLEHEAD_GREEN_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeDoubleHeadGreenNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeDoubleHeadGreenNorth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_SNAKEDOUBLEHEAD_GREEN_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeDoubleHeadGreenSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeDoubleHeadGreenSouth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_SNAKEDOUBLEHEAD_GREEN_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeDoubleHeadGreenWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeDoubleHeadGreenWest2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_SNAKE_GREEN_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeGreenEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeGreenEast2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_SNAKE_GREEN_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeGreenNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeGreenNorth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_SNAKE_GREEN_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeGreenSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeGreenSouth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_SNAKE_GREEN_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeGreenWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeGreenWest2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_SNAKE_RED_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeRedEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeRedEast2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_SNAKE_RED_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeRedNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeRedNorth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_SNAKE_RED_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeRedSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeRedSouth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_SNAKE_RED_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeRedWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSnakeRedWest2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_SPIDER_BROWN_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderBrownEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderBrownEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderBrownEast3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_SPIDER_BROWN_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderBrownNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderBrownNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderBrownNorth3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_SPIDER_BROWN_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderBrownSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderBrownSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderBrownSouth3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_SPIDER_BROWN_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderBrownWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderBrownWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderBrownWest3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_SPIDER_NORMAL_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderNormalEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderNormalEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderNormalEast3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_SPIDER_NORMAL_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderNormalNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderNormalNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderNormalNorth3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_SPIDER_NORMAL_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderNormalSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderNormalSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderNormalSouth3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_SPIDER_NORMAL_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderNormalWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderNormalWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobSpiderNormalWest3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_TIGER_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(mobTigerEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTigerEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTigerEast3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_TIGER_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(mobTigerNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTigerNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTigerNorth3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_TIGER_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(mobTigerSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTigerSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTigerSouth3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_TIGER_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(mobTigerWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTigerWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTigerWest3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_TURTLE_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(mobTurtleEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTurtleEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTurtleEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTurtleEast4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTurtleEast5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_TURTLE_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(mobTurtleNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTurtleNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTurtleNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTurtleNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTurtleNorth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_TURTLE_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(mobTurtleSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTurtleSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTurtleSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTurtleSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTurtleSouth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_TURTLE_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(mobTurtleWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTurtleWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTurtleWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTurtleWest4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobTurtleWest5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_WILDPIG_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(7);
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigEast4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigEast5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigEast6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigEast7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_WILDPIG_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(7);
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigNorth5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigNorth6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigNorth7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_WILDPIG_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(7);
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigSouth5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigSouth6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigSouth7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getMOB_WILDPIG_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(7);
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigWest4));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigWest5));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigWest6));
    frames.pushBack(frameCache->getSpriteFrameByName(mobWildPigWest7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getNPC_BANK_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(nPCBankEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCBankEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCBankEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCBankEast4));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCBankEast5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getNPC_BANK_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(nPCBankNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCBankNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCBankNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCBankNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCBankNorth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getNPC_BANK_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(nPCBankSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCBankSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCBankSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCBankSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCBankSouth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getNPC_BANK_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(nPCBankWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCBankWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCBankWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCBankWest4));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCBankWest5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getNPC_CLOTHES_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(nPCClothesEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCClothesEast2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getNPC_CLOTHES_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(nPCClothesNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCClothesNorth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getNPC_CLOTHES_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(nPCClothesSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCClothesSouth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getNPC_CLOTHES_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(nPCClothesWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCClothesWest2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getNPC_FOODANDDRINKS_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(nPCFoodAndDrinksEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCFoodAndDrinksEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCFoodAndDrinksEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCFoodAndDrinksEast4));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCFoodAndDrinksEast5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getNPC_FOODANDDRINKS_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(nPCFoodAndDrinksNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCFoodAndDrinksNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCFoodAndDrinksNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCFoodAndDrinksNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCFoodAndDrinksNorth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getNPC_FOODANDDRINKS_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(nPCFoodAndDrinksSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCFoodAndDrinksSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCFoodAndDrinksSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCFoodAndDrinksSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCFoodAndDrinksSouth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getNPC_FOODANDDRINKS_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(nPCFoodAndDrinksWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCFoodAndDrinksWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCFoodAndDrinksWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCFoodAndDrinksWest4));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCFoodAndDrinksWest5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getNPC_POTIONS_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(nPCPotionsEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCPotionsEast2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getNPC_POTIONS_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(nPCPotionsNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCPotionsNorth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getNPC_POTIONS_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(nPCPotionsSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCPotionsSouth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getNPC_POTIONS_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(nPCPotionsWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCPotionsWest2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getNPC_STREETARTIST_AAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(nPCStreetArtistA0));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCStreetArtistA1));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCStreetArtistA2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getNPC_STREETARTIST_BAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(nPCStreetArtistB0));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCStreetArtistB1));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCStreetArtistB2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getNPC_STREETARTIST_CAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(nPCStreetArtistC0));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCStreetArtistC1));
    frames.pushBack(frameCache->getSpriteFrameByName(nPCStreetArtistC2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_DARKELF_FEMALE_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfFemaleEast01));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfFemaleEast02));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfFemaleEast03));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfFemaleEast04));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_DARKELF_FEMALE_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfFemaleNorth01));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfFemaleNorth02));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfFemaleNorth03));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfFemaleNorth04));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfFemaleNorth05));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_DARKELF_FEMALE_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfFemaleSouth01));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfFemaleSouth02));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfFemaleSouth03));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfFemaleSouth04));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfFemaleSouth05));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_DARKELF_FEMALE_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfFemaleWest01));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfFemaleWest02));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfFemaleWest03));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfFemaleWest04));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_DARKELF_MALE_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfMaleEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfMaleEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfMaleEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfMaleEast4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_DARKELF_MALE_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfMaleNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfMaleNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfMaleNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfMaleNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfMaleNorth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_DARKELF_MALE_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfMaleSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfMaleSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfMaleSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfMaleSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfMaleSouth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_DARKELF_MALE_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfMaleWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfMaleWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfMaleWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDarkElfMaleWest4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_DWARF_FEMALE_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfFemaleEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfFemaleEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfFemaleEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfFemaleEast4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_DWARF_FEMALE_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfFemaleNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfFemaleNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfFemaleNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfFemaleNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfFemaleNorth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_DWARF_FEMALE_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfFemaleSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfFemaleSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfFemaleSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfFemaleSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfFemaleSouth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_DWARF_FEMALE_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfFemaleWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfFemaleWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfFemaleWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfFemaleWest4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_DWARF_MALE_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfMaleEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfMaleEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfMaleEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfMaleEast4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_DWARF_MALE_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfMaleNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfMaleNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfMaleNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfMaleNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfMaleNorth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_DWARF_MALE_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfMaleSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfMaleSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfMaleSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfMaleSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfMaleSouth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_DWARF_MALE_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfMaleWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfMaleWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfMaleWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyDwarfMaleWest4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_ELF_FEMALE_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfFemaleEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfFemaleEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfFemaleEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfFemaleEast4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_ELF_FEMALE_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfFemaleNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfFemaleNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfFemaleNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfFemaleNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfFemaleNorth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_ELF_FEMALE_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfFemaleSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfFemaleSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfFemaleSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfFemaleSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfFemaleSouth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_ELF_FEMALE_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfFemaleWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfFemaleWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfFemaleWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfFemaleWest4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_ELF_MALE_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfMaleEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfMaleEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfMaleEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfMaleEast4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_ELF_MALE_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfMaleNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfMaleNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfMaleNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfMaleNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfMaleNorth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_ELF_MALE_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfMaleSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfMaleSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfMaleSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfMaleSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfMaleSouth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_ELF_MALE_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfMaleWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfMaleWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfMaleWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyElfMaleWest4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_GNOME_FEMALE_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeFemaleEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeFemaleEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeFemaleEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeFemaleEast4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_GNOME_FEMALE_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeFemaleNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeFemaleNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeFemaleNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeFemaleNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeFemaleNorth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_GNOME_FEMALE_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeFemaleSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeFemaleSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeFemaleSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeFemaleSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeFemaleSouth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_GNOME_FEMALE_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeFemaleWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeFemaleWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeFemaleWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeFemaleWest4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_GNOME_MALE_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeMaleEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeMaleEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeMaleEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeMaleEast4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_GNOME_MALE_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeMaleNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeMaleNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeMaleNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeMaleNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeMaleNorth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_GNOME_MALE_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeMaleSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeMaleSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeMaleSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeMaleSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeMaleSouth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_GNOME_MALE_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeMaleWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeMaleWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeMaleWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyGnomeMaleWest4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_HUMAN_FEMALE_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanFemaleEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanFemaleEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanFemaleEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanFemaleEast4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_HUMAN_FEMALE_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanFemaleNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanFemaleNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanFemaleNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanFemaleNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanFemaleNorth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_HUMAN_FEMALE_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanFemaleSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanFemaleSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanFemaleSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanFemaleSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanFemaleSouth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_HUMAN_FEMALE_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanFemaleWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanFemaleWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanFemaleWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanFemaleWest4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_HUMAN_MALE_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanMaleEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanMaleEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanMaleEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanMaleEast4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_HUMAN_MALE_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanMaleNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanMaleNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanMaleNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanMaleNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanMaleNorth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_HUMAN_MALE_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanMaleSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanMaleSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanMaleSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanMaleSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanMaleSouth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_BODY_HUMAN_MALE_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanMaleWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanMaleWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanMaleWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerBodyHumanMaleWest4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_CASPER_BODY_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(playerCasperBodyEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerCasperBodyEast2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_CASPER_BODY_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(playerCasperBodyNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerCasperBodyNorth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_CASPER_BODY_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(playerCasperBodySouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerCasperBodySouth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_CASPER_BODY_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(playerCasperBodyWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerCasperBodyWest2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_CASPER_DARK_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(playerCasperDarkEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerCasperDarkEast2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_CASPER_DARK_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(playerCasperDarkNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerCasperDarkNorth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_CASPER_DARK_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(playerCasperDarkSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerCasperDarkSouth2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_CASPER_DARK_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(playerCasperDarkWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerCasperDarkWest2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_HAND_SHIELD_IRON_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerHandShieldIronEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerHandShieldIronEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerHandShieldIronEast3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerHandShieldIronEast4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_HAND_SHIELD_IRON_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerHandShieldIronNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerHandShieldIronNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerHandShieldIronNorth3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerHandShieldIronNorth4));
    frames.pushBack(frameCache->getSpriteFrameByName(playerHandShieldIronNorth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_HAND_SHIELD_IRON_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(playerHandShieldIronSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerHandShieldIronSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerHandShieldIronSouth3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerHandShieldIronSouth4));
    frames.pushBack(frameCache->getSpriteFrameByName(playerHandShieldIronSouth5));
    return frames;
}

Vector<SpriteFrame*> Graphics::getPLAYER_HAND_SHIELD_IRON_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(4);
    frames.pushBack(frameCache->getSpriteFrameByName(playerHandShieldIronWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(playerHandShieldIronWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(playerHandShieldIronWest3));
    frames.pushBack(frameCache->getSpriteFrameByName(playerHandShieldIronWest4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getSPAWN_BROWNAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(15);
    frames.pushBack(frameCache->getSpriteFrameByName(spawnBrown01));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnBrown02));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnBrown03));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnBrown04));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnBrown05));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnBrown06));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnBrown07));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnBrown08));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnBrown09));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnBrown10));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnBrown11));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnBrown12));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnBrown13));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnBrown14));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnBrown15));
    return frames;
}

Vector<SpriteFrame*> Graphics::getSPAWN_GREENAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(15);
    frames.pushBack(frameCache->getSpriteFrameByName(spawnGreen01));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnGreen02));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnGreen03));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnGreen04));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnGreen05));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnGreen06));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnGreen07));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnGreen08));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnGreen09));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnGreen10));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnGreen11));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnGreen12));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnGreen13));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnGreen14));
    frames.pushBack(frameCache->getSpriteFrameByName(spawnGreen15));
    return frames;
}

Vector<SpriteFrame*> Graphics::getSPELL_APOCALIPSISAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(21);
    frames.pushBack(frameCache->getSpriteFrameByName(spellApocalipsis01));
    frames.pushBack(frameCache->getSpriteFrameByName(spellApocalipsis02));
    frames.pushBack(frameCache->getSpriteFrameByName(spellApocalipsis03));
    frames.pushBack(frameCache->getSpriteFrameByName(spellApocalipsis04));
    frames.pushBack(frameCache->getSpriteFrameByName(spellApocalipsis05));
    frames.pushBack(frameCache->getSpriteFrameByName(spellApocalipsis06));
    frames.pushBack(frameCache->getSpriteFrameByName(spellApocalipsis07));
    frames.pushBack(frameCache->getSpriteFrameByName(spellApocalipsis08));
    frames.pushBack(frameCache->getSpriteFrameByName(spellApocalipsis09));
    frames.pushBack(frameCache->getSpriteFrameByName(spellApocalipsis10));
    frames.pushBack(frameCache->getSpriteFrameByName(spellApocalipsis11));
    frames.pushBack(frameCache->getSpriteFrameByName(spellApocalipsis12));
    frames.pushBack(frameCache->getSpriteFrameByName(spellApocalipsis13));
    frames.pushBack(frameCache->getSpriteFrameByName(spellApocalipsis14));
    frames.pushBack(frameCache->getSpriteFrameByName(spellApocalipsis15));
    frames.pushBack(frameCache->getSpriteFrameByName(spellApocalipsis16));
    frames.pushBack(frameCache->getSpriteFrameByName(spellApocalipsis17));
    frames.pushBack(frameCache->getSpriteFrameByName(spellApocalipsis18));
    frames.pushBack(frameCache->getSpriteFrameByName(spellApocalipsis19));
    frames.pushBack(frameCache->getSpriteFrameByName(spellApocalipsis20));
    frames.pushBack(frameCache->getSpriteFrameByName(spellApocalipsis21));
    return frames;
}

Vector<SpriteFrame*> Graphics::getSPELL_DESCARGAELECTRICAAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(15);
    frames.pushBack(frameCache->getSpriteFrameByName(spellDescargaElectrica01));
    frames.pushBack(frameCache->getSpriteFrameByName(spellDescargaElectrica02));
    frames.pushBack(frameCache->getSpriteFrameByName(spellDescargaElectrica03));
    frames.pushBack(frameCache->getSpriteFrameByName(spellDescargaElectrica04));
    frames.pushBack(frameCache->getSpriteFrameByName(spellDescargaElectrica05));
    frames.pushBack(frameCache->getSpriteFrameByName(spellDescargaElectrica06));
    frames.pushBack(frameCache->getSpriteFrameByName(spellDescargaElectrica07));
    frames.pushBack(frameCache->getSpriteFrameByName(spellDescargaElectrica08));
    frames.pushBack(frameCache->getSpriteFrameByName(spellDescargaElectrica09));
    frames.pushBack(frameCache->getSpriteFrameByName(spellDescargaElectrica10));
    frames.pushBack(frameCache->getSpriteFrameByName(spellDescargaElectrica11));
    frames.pushBack(frameCache->getSpriteFrameByName(spellDescargaElectrica12));
    frames.pushBack(frameCache->getSpriteFrameByName(spellDescargaElectrica13));
    frames.pushBack(frameCache->getSpriteFrameByName(spellDescargaElectrica14));
    frames.pushBack(frameCache->getSpriteFrameByName(spellDescargaElectrica15));
    return frames;
}

Vector<SpriteFrame*> Graphics::getSPELL_FIRESTORMAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(15);
    frames.pushBack(frameCache->getSpriteFrameByName(spellFireStorm01));
    frames.pushBack(frameCache->getSpriteFrameByName(spellFireStorm02));
    frames.pushBack(frameCache->getSpriteFrameByName(spellFireStorm03));
    frames.pushBack(frameCache->getSpriteFrameByName(spellFireStorm04));
    frames.pushBack(frameCache->getSpriteFrameByName(spellFireStorm05));
    frames.pushBack(frameCache->getSpriteFrameByName(spellFireStorm06));
    frames.pushBack(frameCache->getSpriteFrameByName(spellFireStorm07));
    frames.pushBack(frameCache->getSpriteFrameByName(spellFireStorm08));
    frames.pushBack(frameCache->getSpriteFrameByName(spellFireStorm09));
    frames.pushBack(frameCache->getSpriteFrameByName(spellFireStorm10));
    frames.pushBack(frameCache->getSpriteFrameByName(spellFireStorm11));
    frames.pushBack(frameCache->getSpriteFrameByName(spellFireStorm12));
    frames.pushBack(frameCache->getSpriteFrameByName(spellFireStorm13));
    frames.pushBack(frameCache->getSpriteFrameByName(spellFireStorm14));
    frames.pushBack(frameCache->getSpriteFrameByName(spellFireStorm15));
    return frames;
}

Vector<SpriteFrame*> Graphics::getSPELL_HEALPOISONAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(spellHealPoison0));
    frames.pushBack(frameCache->getSpriteFrameByName(spellHealPoison1));
    frames.pushBack(frameCache->getSpriteFrameByName(spellHealPoison2));
    return frames;
}

Vector<SpriteFrame*> Graphics::getSPELL_IMMOBILIZEAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(15);
    frames.pushBack(frameCache->getSpriteFrameByName(spellImmobilize0));
    frames.pushBack(frameCache->getSpriteFrameByName(spellImmobilize1));
    frames.pushBack(frameCache->getSpriteFrameByName(spellImmobilize2));
    frames.pushBack(frameCache->getSpriteFrameByName(spellImmobilize3));
    frames.pushBack(frameCache->getSpriteFrameByName(spellImmobilize4));
    frames.pushBack(frameCache->getSpriteFrameByName(spellImmobilize5));
    frames.pushBack(frameCache->getSpriteFrameByName(spellImmobilize6));
    frames.pushBack(frameCache->getSpriteFrameByName(spellImmobilize7));
    frames.pushBack(frameCache->getSpriteFrameByName(spellImmobilize8));
    frames.pushBack(frameCache->getSpriteFrameByName(spellImmobilize9));
    frames.pushBack(frameCache->getSpriteFrameByName(spellImmobilize10));
    frames.pushBack(frameCache->getSpriteFrameByName(spellImmobilize11));
    frames.pushBack(frameCache->getSpriteFrameByName(spellImmobilize12));
    frames.pushBack(frameCache->getSpriteFrameByName(spellImmobilize13));
    frames.pushBack(frameCache->getSpriteFrameByName(spellImmobilize14));
    return frames;
}

Vector<SpriteFrame*> Graphics::getSPELL_MAGICALARROWAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalArrow0));
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalArrow1));
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalArrow2));
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalArrow3));
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalArrow4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getSPELL_MAGICALDARTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(8);
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalDart0));
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalDart1));
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalDart2));
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalDart3));
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalDart4));
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalDart5));
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalDart6));
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalDart7));
    return frames;
}

Vector<SpriteFrame*> Graphics::getSPELL_MAGICALMISSILEAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(10);
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalMissile01));
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalMissile02));
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalMissile03));
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalMissile04));
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalMissile05));
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalMissile06));
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalMissile07));
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalMissile08));
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalMissile09));
    frames.pushBack(frameCache->getSpriteFrameByName(spellMagicalMissile10));
    return frames;
}

Vector<SpriteFrame*> Graphics::getSPELL_PARALYZEAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(10);
    frames.pushBack(frameCache->getSpriteFrameByName(spellParalyze0));
    frames.pushBack(frameCache->getSpriteFrameByName(spellParalyze1));
    frames.pushBack(frameCache->getSpriteFrameByName(spellParalyze2));
    frames.pushBack(frameCache->getSpriteFrameByName(spellParalyze3));
    frames.pushBack(frameCache->getSpriteFrameByName(spellParalyze4));
    frames.pushBack(frameCache->getSpriteFrameByName(spellParalyze5));
    frames.pushBack(frameCache->getSpriteFrameByName(spellParalyze6));
    frames.pushBack(frameCache->getSpriteFrameByName(spellParalyze7));
    frames.pushBack(frameCache->getSpriteFrameByName(spellParalyze8));
    frames.pushBack(frameCache->getSpriteFrameByName(spellParalyze9));
    return frames;
}

Vector<SpriteFrame*> Graphics::getSPELL_STRENGTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(5);
    frames.pushBack(frameCache->getSpriteFrameByName(spellStrength0));
    frames.pushBack(frameCache->getSpriteFrameByName(spellStrength1));
    frames.pushBack(frameCache->getSpriteFrameByName(spellStrength2));
    frames.pushBack(frameCache->getSpriteFrameByName(spellStrength3));
    frames.pushBack(frameCache->getSpriteFrameByName(spellStrength4));
    return frames;
}

Vector<SpriteFrame*> Graphics::getSPELL_TOWNPORTAL_BLUEAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(10);
    frames.pushBack(frameCache->getSpriteFrameByName(spellTownPortalBlue0));
    frames.pushBack(frameCache->getSpriteFrameByName(spellTownPortalBlue1));
    frames.pushBack(frameCache->getSpriteFrameByName(spellTownPortalBlue2));
    frames.pushBack(frameCache->getSpriteFrameByName(spellTownPortalBlue3));
    frames.pushBack(frameCache->getSpriteFrameByName(spellTownPortalBlue4));
    frames.pushBack(frameCache->getSpriteFrameByName(spellTownPortalBlue5));
    frames.pushBack(frameCache->getSpriteFrameByName(spellTownPortalBlue6));
    frames.pushBack(frameCache->getSpriteFrameByName(spellTownPortalBlue7));
    frames.pushBack(frameCache->getSpriteFrameByName(spellTownPortalBlue8));
    frames.pushBack(frameCache->getSpriteFrameByName(spellTownPortalBlue9));
    return frames;
}

Vector<SpriteFrame*> Graphics::getWAGON_EASTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(wagonEast1));
    frames.pushBack(frameCache->getSpriteFrameByName(wagonEast2));
    frames.pushBack(frameCache->getSpriteFrameByName(wagonEast3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getWAGON_NORTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(wagonNorth1));
    frames.pushBack(frameCache->getSpriteFrameByName(wagonNorth2));
    frames.pushBack(frameCache->getSpriteFrameByName(wagonNorth3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getWAGON_SOUTHAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(wagonSouth1));
    frames.pushBack(frameCache->getSpriteFrameByName(wagonSouth2));
    frames.pushBack(frameCache->getSpriteFrameByName(wagonSouth3));
    return frames;
}

Vector<SpriteFrame*> Graphics::getWAGON_WESTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(wagonWest1));
    frames.pushBack(frameCache->getSpriteFrameByName(wagonWest2));
    frames.pushBack(frameCache->getSpriteFrameByName(wagonWest3));
    return frames;
}


// ----------
// animations
// ----------

Animate *Graphics::createBLOODAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getBLOODAnimationFrames(), delay, loops));
}
Animate *Graphics::createFLOOR_MAP_FLOORAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getFLOOR_MAP_FLOORAnimationFrames(), delay, loops));
}
Animate *Graphics::createGOLEM_FIRE_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getGOLEM_FIRE_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createGOLEM_FIRE_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getGOLEM_FIRE_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createGOLEM_FIRE_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getGOLEM_FIRE_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createGOLEM_FIRE_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getGOLEM_FIRE_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createHAND_TORCH_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getHAND_TORCH_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createHAND_TORCH_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getHAND_TORCH_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createHAND_TORCH_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getHAND_TORCH_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createHAND_TORCH_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getHAND_TORCH_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_CAMPFIREAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_CAMPFIREAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_MISTICALPLACEAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_MISTICALPLACEAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_MISTICALPLACEBAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_MISTICALPLACEBAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_PORTAL_BLUEAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_PORTAL_BLUEAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_PORTAL_CLASICAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_PORTAL_CLASICAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_PORTAL_CLASICWARMERAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_PORTAL_CLASICWARMERAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_PORTAL_GREENAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_PORTAL_GREENAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_PORTAL_LIGHTBLUEAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_PORTAL_LIGHTBLUEAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_PORTAL_PINKAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_PORTAL_PINKAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_PORTAL_PURPLEAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_PORTAL_PURPLEAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_PORTAL_YELLOWAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_PORTAL_YELLOWAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_POSTER_CASAAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_POSTER_CASAAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_STATUEAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_STATUEAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_TREE_AAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_TREE_AAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_TREE_BAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_TREE_BAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_TREE_CAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_TREE_CAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_TREE_DAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_TREE_DAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_TREE_DEATHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_TREE_DEATHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_TREE_EAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_TREE_EAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_TREE_FAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_TREE_FAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_TREE_GAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_TREE_GAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_TREE_HAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_TREE_HAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_TREE_IAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_TREE_IAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_TREE_JAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_TREE_JAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_TREE_KAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_TREE_KAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_TREE_LAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_TREE_LAnimationFrames(), delay, loops));
}
Animate *Graphics::createMAP_TREE_MAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMAP_TREE_MAnimationFrames(), delay, loops));
}
Animate *Graphics::createMEDITATION_BLUEAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMEDITATION_BLUEAnimationFrames(), delay, loops));
}
Animate *Graphics::createMEDITATION_EXTREMEAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMEDITATION_EXTREMEAnimationFrames(), delay, loops));
}
Animate *Graphics::createMEDITATION_NEWBIEAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMEDITATION_NEWBIEAnimationFrames(), delay, loops));
}
Animate *Graphics::createMEDITATION_REDAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMEDITATION_REDAnimationFrames(), delay, loops));
}
Animate *Graphics::createMEDITATION_YELLOWAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMEDITATION_YELLOWAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_BAT_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_BAT_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_BAT_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_BAT_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_BAT_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_BAT_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_BAT_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_BAT_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_BEAR_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_BEAR_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_BEAR_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_BEAR_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_BEAR_POLAR_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_BEAR_POLAR_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_BEAR_POLAR_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_BEAR_POLAR_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_BEAR_POLAR_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_BEAR_POLAR_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_BEAR_POLAR_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_BEAR_POLAR_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_BEAR_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_BEAR_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_BEAR_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_BEAR_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_BEHOLER_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_BEHOLER_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_BEHOLER_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_BEHOLER_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_BEHOLER_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_BEHOLER_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_BEHOLER_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_BEHOLER_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_BIRD_BLACK_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_BIRD_BLACK_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_BIRD_BLACK_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_BIRD_BLACK_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_BIRD_BLACK_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_BIRD_BLACK_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_BIRD_BLACK_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_BIRD_BLACK_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_DRAGON_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_DRAGON_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_DRAGON_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_DRAGON_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_DRAGON_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_DRAGON_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_DRAGON_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_DRAGON_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_ELI_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_ELI_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_ELI_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_ELI_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_ELI_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_ELI_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_ELI_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_ELI_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_ELY_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_ELY_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_ELY_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_ELY_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_ELY_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_ELY_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_ELY_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_ELY_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_GOLEM_MAGMA_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_GOLEM_MAGMA_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_GOLEM_MAGMA_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_GOLEM_MAGMA_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_GOLEM_MAGMA_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_GOLEM_MAGMA_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_GOLEM_MAGMA_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_GOLEM_MAGMA_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_GOLEM_STONE_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_GOLEM_STONE_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_GOLEM_STONE_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_GOLEM_STONE_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_GOLEM_STONE_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_GOLEM_STONE_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_GOLEM_STONE_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_GOLEM_STONE_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_LEVIATHAN_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_LEVIATHAN_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_LEVIATHAN_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_LEVIATHAN_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_LEVIATHAN_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_LEVIATHAN_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_LEVIATHAN_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_LEVIATHAN_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_LICHE_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_LICHE_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_LICHE_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_LICHE_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_LICHE_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_LICHE_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_LICHE_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_LICHE_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_LINE_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_LINE_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_LINE_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_LINE_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_LINE_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_LINE_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_LINE_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_LINE_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_MERMAID_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_MERMAID_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_MERMAID_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_MERMAID_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_MERMAID_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_MERMAID_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_MERMAID_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_MERMAID_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_OCTOPUS_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_OCTOPUS_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_OCTOPUS_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_OCTOPUS_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_OCTOPUS_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_OCTOPUS_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_OCTOPUS_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_OCTOPUS_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_PARROT_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_PARROT_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_PARROT_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_PARROT_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_PARROT_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_PARROT_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_PARROT_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_PARROT_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_PIRANHA_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_PIRANHA_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_PIRANHA_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_PIRANHA_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_PIRANHA_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_PIRANHA_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_PIRANHA_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_PIRANHA_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_RABBIT_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_RABBIT_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_RABBIT_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_RABBIT_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_RABBIT_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_RABBIT_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_RABBIT_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_RABBIT_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_RAVEN_BLACK_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_RAVEN_BLACK_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_RAVEN_BLACK_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_RAVEN_BLACK_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_RAVEN_BLACK_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_RAVEN_BLACK_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_RAVEN_BLACK_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_RAVEN_BLACK_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_RAVEN_WHITE_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_RAVEN_WHITE_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_RAVEN_WHITE_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_RAVEN_WHITE_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_RAVEN_WHITE_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_RAVEN_WHITE_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_RAVEN_WHITE_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_RAVEN_WHITE_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_SNAKEDOUBLEHEAD_GREEN_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_SNAKEDOUBLEHEAD_GREEN_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_SNAKEDOUBLEHEAD_GREEN_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_SNAKEDOUBLEHEAD_GREEN_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_SNAKEDOUBLEHEAD_GREEN_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_SNAKEDOUBLEHEAD_GREEN_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_SNAKEDOUBLEHEAD_GREEN_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_SNAKEDOUBLEHEAD_GREEN_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_SNAKE_GREEN_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_SNAKE_GREEN_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_SNAKE_GREEN_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_SNAKE_GREEN_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_SNAKE_GREEN_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_SNAKE_GREEN_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_SNAKE_GREEN_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_SNAKE_GREEN_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_SNAKE_RED_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_SNAKE_RED_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_SNAKE_RED_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_SNAKE_RED_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_SNAKE_RED_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_SNAKE_RED_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_SNAKE_RED_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_SNAKE_RED_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_SPIDER_BROWN_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_SPIDER_BROWN_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_SPIDER_BROWN_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_SPIDER_BROWN_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_SPIDER_BROWN_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_SPIDER_BROWN_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_SPIDER_BROWN_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_SPIDER_BROWN_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_SPIDER_NORMAL_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_SPIDER_NORMAL_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_SPIDER_NORMAL_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_SPIDER_NORMAL_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_SPIDER_NORMAL_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_SPIDER_NORMAL_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_SPIDER_NORMAL_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_SPIDER_NORMAL_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_TIGER_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_TIGER_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_TIGER_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_TIGER_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_TIGER_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_TIGER_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_TIGER_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_TIGER_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_TURTLE_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_TURTLE_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_TURTLE_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_TURTLE_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_TURTLE_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_TURTLE_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_TURTLE_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_TURTLE_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_WILDPIG_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_WILDPIG_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_WILDPIG_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_WILDPIG_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_WILDPIG_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_WILDPIG_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createMOB_WILDPIG_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getMOB_WILDPIG_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createNPC_BANK_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getNPC_BANK_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createNPC_BANK_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getNPC_BANK_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createNPC_BANK_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getNPC_BANK_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createNPC_BANK_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getNPC_BANK_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createNPC_CLOTHES_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getNPC_CLOTHES_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createNPC_CLOTHES_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getNPC_CLOTHES_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createNPC_CLOTHES_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getNPC_CLOTHES_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createNPC_CLOTHES_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getNPC_CLOTHES_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createNPC_FOODANDDRINKS_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getNPC_FOODANDDRINKS_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createNPC_FOODANDDRINKS_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getNPC_FOODANDDRINKS_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createNPC_FOODANDDRINKS_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getNPC_FOODANDDRINKS_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createNPC_FOODANDDRINKS_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getNPC_FOODANDDRINKS_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createNPC_POTIONS_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getNPC_POTIONS_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createNPC_POTIONS_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getNPC_POTIONS_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createNPC_POTIONS_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getNPC_POTIONS_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createNPC_POTIONS_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getNPC_POTIONS_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createNPC_STREETARTIST_AAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getNPC_STREETARTIST_AAnimationFrames(), delay, loops));
}
Animate *Graphics::createNPC_STREETARTIST_BAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getNPC_STREETARTIST_BAnimationFrames(), delay, loops));
}
Animate *Graphics::createNPC_STREETARTIST_CAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getNPC_STREETARTIST_CAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_DARKELF_FEMALE_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_DARKELF_FEMALE_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_DARKELF_FEMALE_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_DARKELF_FEMALE_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_DARKELF_FEMALE_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_DARKELF_FEMALE_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_DARKELF_FEMALE_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_DARKELF_FEMALE_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_DARKELF_MALE_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_DARKELF_MALE_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_DARKELF_MALE_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_DARKELF_MALE_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_DARKELF_MALE_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_DARKELF_MALE_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_DARKELF_MALE_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_DARKELF_MALE_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_DWARF_FEMALE_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_DWARF_FEMALE_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_DWARF_FEMALE_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_DWARF_FEMALE_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_DWARF_FEMALE_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_DWARF_FEMALE_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_DWARF_FEMALE_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_DWARF_FEMALE_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_DWARF_MALE_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_DWARF_MALE_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_DWARF_MALE_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_DWARF_MALE_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_DWARF_MALE_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_DWARF_MALE_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_DWARF_MALE_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_DWARF_MALE_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_ELF_FEMALE_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_ELF_FEMALE_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_ELF_FEMALE_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_ELF_FEMALE_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_ELF_FEMALE_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_ELF_FEMALE_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_ELF_FEMALE_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_ELF_FEMALE_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_ELF_MALE_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_ELF_MALE_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_ELF_MALE_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_ELF_MALE_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_ELF_MALE_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_ELF_MALE_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_ELF_MALE_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_ELF_MALE_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_GNOME_FEMALE_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_GNOME_FEMALE_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_GNOME_FEMALE_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_GNOME_FEMALE_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_GNOME_FEMALE_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_GNOME_FEMALE_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_GNOME_FEMALE_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_GNOME_FEMALE_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_GNOME_MALE_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_GNOME_MALE_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_GNOME_MALE_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_GNOME_MALE_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_GNOME_MALE_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_GNOME_MALE_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_GNOME_MALE_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_GNOME_MALE_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_HUMAN_FEMALE_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_HUMAN_FEMALE_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_HUMAN_FEMALE_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_HUMAN_FEMALE_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_HUMAN_FEMALE_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_HUMAN_FEMALE_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_HUMAN_FEMALE_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_HUMAN_FEMALE_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_HUMAN_MALE_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_HUMAN_MALE_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_HUMAN_MALE_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_HUMAN_MALE_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_HUMAN_MALE_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_HUMAN_MALE_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_BODY_HUMAN_MALE_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_BODY_HUMAN_MALE_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_CASPER_BODY_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_CASPER_BODY_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_CASPER_BODY_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_CASPER_BODY_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_CASPER_BODY_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_CASPER_BODY_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_CASPER_BODY_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_CASPER_BODY_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_CASPER_DARK_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_CASPER_DARK_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_CASPER_DARK_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_CASPER_DARK_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_CASPER_DARK_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_CASPER_DARK_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_CASPER_DARK_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_CASPER_DARK_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_HAND_SHIELD_IRON_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_HAND_SHIELD_IRON_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_HAND_SHIELD_IRON_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_HAND_SHIELD_IRON_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_HAND_SHIELD_IRON_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_HAND_SHIELD_IRON_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createPLAYER_HAND_SHIELD_IRON_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getPLAYER_HAND_SHIELD_IRON_WESTAnimationFrames(), delay, loops));
}
Animate *Graphics::createSPAWN_BROWNAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getSPAWN_BROWNAnimationFrames(), delay, loops));
}
Animate *Graphics::createSPAWN_GREENAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getSPAWN_GREENAnimationFrames(), delay, loops));
}
Animate *Graphics::createSPELL_APOCALIPSISAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getSPELL_APOCALIPSISAnimationFrames(), delay, loops));
}
Animate *Graphics::createSPELL_DESCARGAELECTRICAAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getSPELL_DESCARGAELECTRICAAnimationFrames(), delay, loops));
}
Animate *Graphics::createSPELL_FIRESTORMAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getSPELL_FIRESTORMAnimationFrames(), delay, loops));
}
Animate *Graphics::createSPELL_HEALPOISONAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getSPELL_HEALPOISONAnimationFrames(), delay, loops));
}
Animate *Graphics::createSPELL_IMMOBILIZEAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getSPELL_IMMOBILIZEAnimationFrames(), delay, loops));
}
Animate *Graphics::createSPELL_MAGICALARROWAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getSPELL_MAGICALARROWAnimationFrames(), delay, loops));
}
Animate *Graphics::createSPELL_MAGICALDARTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getSPELL_MAGICALDARTAnimationFrames(), delay, loops));
}
Animate *Graphics::createSPELL_MAGICALMISSILEAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getSPELL_MAGICALMISSILEAnimationFrames(), delay, loops));
}
Animate *Graphics::createSPELL_PARALYZEAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getSPELL_PARALYZEAnimationFrames(), delay, loops));
}
Animate *Graphics::createSPELL_STRENGTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getSPELL_STRENGTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createSPELL_TOWNPORTAL_BLUEAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getSPELL_TOWNPORTAL_BLUEAnimationFrames(), delay, loops));
}
Animate *Graphics::createWAGON_EASTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getWAGON_EASTAnimationFrames(), delay, loops));
}
Animate *Graphics::createWAGON_NORTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getWAGON_NORTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createWAGON_SOUTHAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getWAGON_SOUTHAnimationFrames(), delay, loops));
}
Animate *Graphics::createWAGON_WESTAnimateAction(float delay, unsigned int loops)
{
    return Animate::create(Animation::createWithSpriteFrames(getWAGON_WESTAnimationFrames(), delay, loops));
}

}; // namespace