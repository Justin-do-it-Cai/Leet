class Solution:
    def entityParser(self, text: str) -> str:
        special_chars = {
            "&quot;": "\"",
            "&apos;": "'",
            "&amp;": "&",
            "&gt;": ">",
            "&lt;": "<",
            "&frasl;": "/"
        }

        # The order of replacement is important. We must replace "&amp;" last to handle cases like "&amp;gt;"
        for entity, char in special_chars.items():
            if entity != "&amp;":
                text = text.replace(entity, char)
        
        # Replace "&amp;" at the end
        text = text.replace("&amp;", "&")#&放在最后转换防止二次转换。exp:&amp;gt;

        return text