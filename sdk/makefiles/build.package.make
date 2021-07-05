ifeq ($(TARGET),)
TARGET=$(strip $(NAME))
endif

.PHONY: $(TARGET)
$(TARGET):

clean::
	@true #silence "Nothing to be done for `clean'." message
ifneq ($(TB_SDK_RESULT_DIR),)
	@touch "$(TB_SDK_RESULT_DIR)/success$(POSTFIX)"
endif