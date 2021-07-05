<?xml version="1.0" ?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="text"/>
  <xsl:template match="plugin">
    <xsl:value-of select="@name"/>
  </xsl:template>
</xsl:stylesheet>
